#include <cstdio>
#include <mutex>
#include <chrono>
#include <random>
#include <openssl/sha.h>
#include "http/HttpRequest.h"
#include "http/HttpResponse.h"
#include "http/Http.h"
#include "thirdparty/httplib/httplib.h"

namespace VolcengineTls {

static std::mutex retry_mutex;
static int retry_counter = 0;
static int retry_counter_max = 50;
static int retry_interval_ms = 100;

long long calculate_sleep_ms(long long current_timestamp, long long quit_timestamp) {
    if (retry_counter <= 0 || current_timestamp >= quit_timestamp) {
        return 0;
    } 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, retry_counter);
    int v = dis(gen) * retry_interval_ms;
    if (current_timestamp + v >= quit_timestamp) {
        return quit_timestamp - current_timestamp;
    }
    else {
        return v;
    }
}

void increase_retry_counter() {
    std::lock_guard<std::mutex> lglg(retry_mutex);
    if (retry_counter < retry_counter_max)
        retry_counter += 1;
    return;
}

void decrease_retry_counter() {
    std::lock_guard<std::mutex> lglg(retry_mutex);
    if (retry_counter > 0) {
        retry_counter -= 1;
    }
    return;
}

std::shared_ptr<HttpResponse> HttpUtils::SendHttpRequestWithRetry(HttpRequest &req, int timeout_millisecond, std::shared_ptr<httplib::Client> longlinkCli) {
    std::shared_ptr<HttpResponse> resp;
    auto quit_timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() + timeout_millisecond;
    while (true) {
        resp = HttpUtils::SendHttpRequest(req, timeout_millisecond, longlinkCli);
        int need_retry = 0;
        if (resp->status_code <= 0 || resp->status_code == 429 || resp->status_code == 500 || resp->status_code == 502 || resp->status_code == 503 || resp->status_code == 504)  {
            increase_retry_counter();
            need_retry = 1;
        } else decrease_retry_counter();
        if (need_retry == 0) {
            return resp;
        }
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        if (now >= quit_timestamp) {
            return resp;
        }
        auto sleep_ms = calculate_sleep_ms(now, quit_timestamp);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_ms)); 
    }
    return resp;
}

std::shared_ptr<HttpResponse> HttpUtils::SendHttpRequest(HttpRequest &req, int timeout_millisecond, std::shared_ptr<httplib::Client> longlinkCli) {
    std::shared_ptr<httplib::Client> cli;
    if (longlinkCli != nullptr) {
        cli = longlinkCli;
    } else {
        std::string endpoint = req.scheme + req.host;
        cli = std::make_shared<httplib::Client>(endpoint);
        if (timeout_millisecond > 0) {
            cli->set_read_timeout(timeout_millisecond / 1000, timeout_millisecond % 1000 * 1000);
        }
        cli->enable_server_certificate_verification(false);
    }

    httplib::Headers headers; {
        for (auto headerValue : req.headers) {
            headers.insert(headerValue);
        }
        headers.emplace("User-Agent", TLS_CPP_SDK_USER_AGENT);
    }
    httplib::Params params; {
        for (auto paramValue : req.queries) {
            params.insert(paramValue);
        }
    }

    std::shared_ptr<HttpResponse> resp = make_shared<HttpResponse>();
    auto innerResp = cli->CustomRequest(req.method, req.path, headers, params, req.body, req.content_type);
    if ((int)innerResp.error() != 0) {
        resp->status_code = -(int)innerResp.error();
        resp->error_code = "NetworkError";
        resp->error_message = httplib::to_string(innerResp.error());

        return resp;
    }

    for (auto iter : innerResp->headers) {
        resp->headers[iter.first] = iter.second;
    }
    if (innerResp->has_header("X-Tls-Requestid") > 0) {
        resp->request_id = innerResp->get_header_value("X-Tls-Requestid");
    }
    resp->status_code = innerResp->status;
    resp->body = innerResp->body;

    return resp;
}


}