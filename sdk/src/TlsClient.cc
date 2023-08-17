#include <cstdio>
#include <chrono>

#include "http/Credential.h"
#include "http/SignKeyInfo.h"
#include "http/SignV4.h"
#include "http/Http.h"
#include "TlsRequest.h"
#include "TlsResponse.h"
#include "TlsClient.h"
#include "TlsJsonConversion.h"
#include "thirdparty/nlohmann/json.hpp"
#include "thirdparty/httplib/httplib.h"
#include "lz4.h"

std::string toLower(const std::string &str) {
    std::string res = "";
    for (int i=0; i<str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            res += str[i] + 'a' - 'A';
        }
    } return res;
}

static void processNullField(const std::string &src, std::string &res) {
    res = "";
    int pos = 0;
    while (pos < src.size()) {
        if (src.substr(pos, 5) == ":null") {
            while(res.size() && (res.back() != ' ' && res.back() != '{' && res.back() != ',')) res.pop_back();
            if (res.back() == ',') res.pop_back();
            pos += 5;
        } else {
            res += src[pos];
            pos += 1;
        }
    }
}

#define PROCESS_EXCEPTION_BEGIN \
    try {
#define PROCESS_EXCEPTION_END \
    } catch (std::exception &ex) { \
        resp.error_code = "CaughtException"; \
        resp.error_message = ex.what(); \
        return resp; \
    }

#define TLS_CLIENT_METHOD_DEFINITION(METHOD) \
    METHOD##Response TlsClient::METHOD(METHOD##Request &request) { \
        METHOD##Response resp = METHOD##Response(); \
        PROCESS_EXCEPTION_BEGIN \
        if (this->config_.endpoint.empty()) { \
            resp.error_code = "InvalidParam"; \
            resp.error_message = "Lack necessary parameter: endpoint"; \
            return resp; \
        } \
        if (this->config_.region.empty()) { \
            resp.error_code = "InvalidParam"; \
            resp.error_message = "Lack necessary parameter: region"; \
            return resp; \
        } \
        if (request.CheckValidation() == false) { \
            resp.error_code = "InvalidParam"; \
            resp.error_message = "Lack necessary parameter, please check request"; \
            return resp; \
        } \
        std::shared_ptr<Credential> credential = std::make_shared<Credential>(); { \
            credential->setAccessKeyId(this->config_.access_key_id); \
            credential->setAccessKeySecret(this->config_.access_key_secret); \
        } \
        SignV4 signer = SignV4(credential, this->config_.region); \
        std::shared_ptr<HttpRequest> inner_request = std::make_shared<HttpRequest>(); { \
            inner_request->scheme = this->config_.scheme; \
            inner_request->method = request.Method(); \
            inner_request->host = this->config_.endpoint; \
            if (#METHOD == "SearchLogsV2"){  \
                inner_request->path = "/SearchLogs";                   \
            } else {                         \
                inner_request->path = "/" #METHOD;                       \
            }                                \
            std::string  version=request.getApiVersion();  \
            if(#METHOD == "SearchLogsV2"){    \
                inner_request->headers["x-tls-apiversion"] ="0.3.0";  \
            }\
            else if(!version.empty()){    \
                inner_request->headers["x-tls-apiversion"] = version;                       \
            }else {                          \
                inner_request->headers["x-tls-apiversion"] = config_.api_version;  \
            }                            \
            inner_request->content_type = request.ContentType(); \
            nlohmann::json j; \
            request.MakeBodyParamJson(j); \
            if (j.is_object()) \
                inner_request->body = j.dump(); \
            j = nlohmann::json(); \
            request.MakeHeaderParamJson(j); \
            if (j.is_object()) for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) { \
                std::string key_string = it.key(); \
                std::string value_string = it.value().is_string() ? it.value().get<std::string>() : it.value().dump(); \
                inner_request->headers[key_string] = value_string; \
            } \
            j = nlohmann::json(); \
            request.MakeQueryParamJson(j); \
            if (j.is_object()) for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) { \
                std::string key_string = it.key(); \
                std::string value_string = it.value().is_string() ? it.value().get<std::string>() : it.value().dump(); \
                inner_request->queries[key_string] = value_string; \
            } \
        } \
        signer.calcAndSetAuthorization(inner_request); \
        auto inner_resp = this->config_.disable_retry == false ? HttpUtils::SendHttpRequestWithRetry(*inner_request, this->config_.timeout_millisecond, longlinkCli_) : HttpUtils::SendHttpRequest(*inner_request, this->config_.timeout_millisecond, longlinkCli_); \
        std::string real_body; \
        processNullField(inner_resp->body, real_body); \
        auto inner_resp_body_json = nlohmann::json::parse(real_body.c_str()); \
        try { \
            from_json(inner_resp_body_json, resp); \
        } catch (std::exception &ex) { \
            fprintf(stderr, "encountered exception when parse json %s\n", ex.what()); \
        } \
        resp.request_id = inner_resp->request_id; \
        resp.http_status_code = inner_resp->status_code; \
        return resp; \
        PROCESS_EXCEPTION_END \
    }
    

namespace VolcengineTls {

TlsClient::TlsClient(const TlsClientConfig &config) {
    this->config_ = config;
    this->longlinkCli_ = nullptr;
    if (this->config_.use_long_link == true) {
        std::string endpoint = config.scheme + config.endpoint;
        longlinkCli_ = std::make_shared<httplib::Client>(endpoint);
        longlinkCli_->set_keep_alive(true);
        longlinkCli_->enable_server_certificate_verification(false);
        if (config.timeout_millisecond > 0) {
            longlinkCli_->set_read_timeout(config.timeout_millisecond / 1000, config.timeout_millisecond % 1000 * 1000);
        }
    }
}

PutLogsResponse TlsClient::PutLogs(PutLogsRequest &request) {
    PutLogsResponse resp = PutLogsResponse();
    PROCESS_EXCEPTION_BEGIN
    if (this->config_.endpoint.empty()) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter: Endpoint";
        return resp;
    }
    if (this->config_.region.empty()) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter: region";
        return resp;
    }
    if (request.CheckValidation() == false) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter, please check request";
        return resp;
    }
    std::shared_ptr<Credential> credential = std::make_shared<Credential>(); {
        credential->setAccessKeyId(this->config_.access_key_id);
        credential->setAccessKeySecret(this->config_.access_key_secret);
    }
    SignV4 signer = SignV4(credential, this->config_.region);

    std::shared_ptr<HttpRequest> inner_request = std::make_shared<HttpRequest>(); {
        inner_request->scheme = this->config_.scheme;
        inner_request->method = request.Method();
        inner_request->host = this->config_.endpoint;
        inner_request->path = "/PutLogs";

        request.log_group_list->SerializeToString(&(inner_request->body));
        inner_request->headers["x-tls-bodyrawsize"] = ::to_string(inner_request->body.size());
        inner_request->headers["x-tls-apiversion"] = config_.api_version;
        if (request.hash_key != nullptr) {
            inner_request->headers["x-tls-hashkey"] = *(request.hash_key);
        }

        if (request.compression != nullptr && toLower(*request.compression) == "lz4") {
            inner_request->headers["x-tls-compression"] = "lz4";
            int lz4_bound = LZ4_compressBound(inner_request->body.size());
            int buf_size = 64;
            while (buf_size < lz4_bound)
                buf_size *= 2;
            char *buf = new char[buf_size];
            int sz = LZ4_compress_default(inner_request->body.c_str(), buf, inner_request->body.size(), buf_size);
            inner_request->body = std::string(buf, buf + sz);
            delete[] buf;
        }

        nlohmann::json j;
        j = nlohmann::json();
        request.MakeHeaderParamJson(j);
        if (j.is_object()) for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
            std::string key_string = it.key();
            std::string value_string = it.value().is_string() ? it.value().get<std::string>() : it.value().dump();
            inner_request->headers[key_string] = value_string;
        }

        j = nlohmann::json();
        request.MakeQueryParamJson(j);
        if (j.is_object()) for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
            std::string key_string = it.key();
            std::string value_string = it.value().is_string() ? it.value().get<std::string>() : it.value().dump();
            inner_request->queries[key_string] = value_string;
        }
    }

    signer.calcAndSetAuthorization(inner_request);
    auto inner_resp = this->config_.disable_retry == false ? HttpUtils::SendHttpRequestWithRetry(*inner_request, this->config_.timeout_millisecond, longlinkCli_) : HttpUtils::SendHttpRequest(*inner_request, this->config_.timeout_millisecond, longlinkCli_);
    resp.request_id = inner_resp->request_id;
    resp.http_status_code = inner_resp->status_code;
    return resp;
    PROCESS_EXCEPTION_END
}

PutLogsV2Response TlsClient::PutLogsV2(PutLogsV2Request &request) {
    PutLogsRequest inner_request = PutLogsRequest(); {
        inner_request.topic_id = request.topic_id;
        inner_request.compression = request.compression;
        inner_request.hash_key = request.hash_key;
    }
    auto pb = std::make_shared<pb::LogGroupList>(); {
        auto log_group = pb->add_loggroups();
        if (request.source != nullptr)
            log_group->set_source(*request.source);
        if (request.filename != nullptr)
            log_group->set_filename(*request.filename);
        if (request.logs != nullptr) for (auto log_item : *request.logs) {
            auto log = log_group->add_logs();
            if (log_item.time == 0) {
                log_item.time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            }
            log->set_time(log_item.time);
            for (auto &log_value : log_item.log_content) {
                auto log_content = log->add_contents();
                log_content->set_key(log_value.first);
                log_content->set_value(log_value.second);
            }
        }
    }
    inner_request.log_group_list = pb;
    auto inner_response = this->PutLogs(inner_request);
    PutLogsV2Response response = inner_response;
    return response;
}

TLS_CLIENT_METHOD_DEFINITION(DescribeCursor);

ConsumeLogsResponse TlsClient::ConsumeLogs(ConsumeLogsRequest &request) {
    ConsumeLogsResponse resp = ConsumeLogsResponse();
    PROCESS_EXCEPTION_BEGIN
    if (this->config_.endpoint.empty()) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter: Endpoint";
        return resp;
    }
    if (this->config_.region.empty()) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter: region";
        return resp;
    }
    if (request.CheckValidation() == false) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter, please check request";
        return resp;
    }
    std::shared_ptr<Credential> credential = std::make_shared<Credential>(); {
        credential->setAccessKeyId(this->config_.access_key_id);
        credential->setAccessKeySecret(this->config_.access_key_secret);
    }
    SignV4 signer = SignV4(credential, this->config_.region);

    std::shared_ptr<HttpRequest> inner_request = std::make_shared<HttpRequest>(); {
        inner_request->scheme = this->config_.scheme;
        inner_request->method = request.Method();
        inner_request->host = this->config_.endpoint;
        inner_request->path = "/ConsumeLogs";
        inner_request->headers["x-tls-apiversion"] = config_.api_version;
        inner_request->content_type = request.ContentType();

        nlohmann::json j;
        request.MakeBodyParamJson(j);
        if (j.is_object())
            inner_request->body = j.dump();

        j = nlohmann::json();
        request.MakeHeaderParamJson(j);
        if (j.is_object()) for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
            std::string key_string = it.key();
            std::string value_string = it.value().is_string() ? it.value().get<std::string>() : it.value().dump();
            inner_request->headers[key_string] = value_string;
        }

        j = nlohmann::json();
        request.MakeQueryParamJson(j);
        if (j.is_object()) for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
            std::string key_string = it.key();
            std::string value_string = it.value().is_string() ? it.value().get<std::string>() : it.value().dump();
            inner_request->queries[key_string] = value_string;
        }
    }

    signer.calcAndSetAuthorization(inner_request);
    auto inner_resp = this->config_.disable_retry == false ? HttpUtils::SendHttpRequestWithRetry(*inner_request, this->config_.timeout_millisecond, longlinkCli_) : HttpUtils::SendHttpRequest(*inner_request, this->config_.timeout_millisecond, longlinkCli_);
    resp.request_id = inner_resp->request_id;
    resp.http_status_code = inner_resp->status_code;
    if (inner_resp->headers.count("X-Tls-Cursor")) {
        resp.cursor = inner_resp->headers["X-Tls-Cursor"];
    }
    if (inner_resp->headers.count("X-Tls-Count")) {
        resp.count = inner_resp->headers["X-Tls-Count"];
    }
    if (resp.http_status_code == 200 && inner_resp->body.size() > 0) {
        if (request.compression != nullptr && toLower(*request.compression) == "lz4") {
            const char* compressed_string = inner_resp->body.c_str();
            size_t compressed_size = inner_resp->body.size();
            size_t uncompressed_size;
            char* uncompressed_string;
            // 获取解压后字符串的长度
            uncompressed_size = LZ4_decompress_safe(
                compressed_string, 
                uncompressed_string, 
                compressed_size - 4,  // 减去压缩前4个字节存储的字符串长度
                sizeof(uncompressed_string)
            );
            if (uncompressed_size <= 0) {
                resp.error_code = "ClientError";
                resp.error_message = "Failed to decompress response body";
                return resp;
            }
            uncompressed_string = (char*)malloc(uncompressed_size + 1);
            if (uncompressed_string == NULL) {
                resp.error_code = "ClientError";
                resp.error_message = "Failed to decompress response body, memory not enough";
                return resp;
            }
            int result = LZ4_decompress_safe(
                compressed_string + 4,  // 跳过前4个字节
                uncompressed_string,
                compressed_size - 4,
                uncompressed_size
            );
            if (result <= 0) {
                resp.error_code = "ClientError";
                resp.error_message = "Failed to decompress response body";
                return resp;
            }
            uncompressed_string[uncompressed_size] = '\0';
            resp.log_group_list.ParseFromString(std::string(uncompressed_string, uncompressed_string+uncompressed_size));
            free(uncompressed_string);
        } else {
            resp.log_group_list.ParseFromString(inner_resp->body);
        }
    }
    return resp;
    PROCESS_EXCEPTION_END
}

WebTracksResponse TlsClient::WebTracks(WebTracksRequest &request) {
    WebTracksResponse resp = WebTracksResponse();
    PROCESS_EXCEPTION_BEGIN
    if (this->config_.endpoint.empty()) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter: Endpoint";
        return resp;
    }
    if (this->config_.region.empty()) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter: region";
        return resp;
    }
    if (request.CheckValidation() == false) {
        resp.error_code = "InvalidParam";
        resp.error_message = "Lack necessary parameter, please check request";
        return resp;
    }
    std::shared_ptr<Credential> credential = std::make_shared<Credential>(); {
        credential->setAccessKeyId(this->config_.access_key_id);
        credential->setAccessKeySecret(this->config_.access_key_secret);
    }
    SignV4 signer = SignV4(credential, this->config_.region);

    std::shared_ptr<HttpRequest> inner_request = std::make_shared<HttpRequest>(); {
        inner_request->scheme = this->config_.scheme;
        inner_request->method = request.Method();
        inner_request->host = this->config_.endpoint;
        inner_request->path = "/WebTracks";
        inner_request->headers["x-tls-apiversion"] = config_.api_version;
        inner_request->content_type = request.ContentType();

        nlohmann::json j;
        request.MakeBodyParamJson(j);
        if (j.is_object())
            inner_request->body = j.dump();

        inner_request->headers["x-tls-bodyrawsize"] = ::to_string(inner_request->body.size());

        if (request.compression != nullptr && toLower(*request.compression) == "lz4") {
            inner_request->headers["x-tls-compression"] = "lz4";
            int lz4_bound = LZ4_compressBound(inner_request->body.size());
            int buf_size = 64;
            while (buf_size < lz4_bound)
                buf_size *= 2;
            char *buf = new char[buf_size];
            int sz = LZ4_compress_default(inner_request->body.c_str(), buf, inner_request->body.size(), buf_size);
            inner_request->body = std::string(buf, buf + sz);
            delete[] buf;
        }
        
        j = nlohmann::json();
        request.MakeQueryParamJson(j);
        if (j.is_object()) for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
            std::string key_string = it.key();
            std::string value_string = it.value().is_string() ? it.value().get<std::string>() : it.value().dump();
            inner_request->queries[key_string] = value_string;
        }
    }

    signer.calcAndSetAuthorization(inner_request);
    auto inner_resp = this->config_.disable_retry == false ? HttpUtils::SendHttpRequestWithRetry(*inner_request, this->config_.timeout_millisecond, longlinkCli_) : HttpUtils::SendHttpRequest(*inner_request, this->config_.timeout_millisecond, longlinkCli_);
    resp.request_id = inner_resp->request_id;
    resp.http_status_code = inner_resp->status_code;
    return resp;
    PROCESS_EXCEPTION_END
}


TLS_CLIENT_METHOD_DEFINITION(CreateProject);
TLS_CLIENT_METHOD_DEFINITION(DeleteProject);
TLS_CLIENT_METHOD_DEFINITION(ModifyProject);
TLS_CLIENT_METHOD_DEFINITION(DescribeProject);
TLS_CLIENT_METHOD_DEFINITION(DescribeProjects);
TLS_CLIENT_METHOD_DEFINITION(CreateTopic);
TLS_CLIENT_METHOD_DEFINITION(DeleteTopic);
TLS_CLIENT_METHOD_DEFINITION(ModifyTopic);
TLS_CLIENT_METHOD_DEFINITION(DescribeTopic);
TLS_CLIENT_METHOD_DEFINITION(DescribeTopics);
TLS_CLIENT_METHOD_DEFINITION(DescribeShards);
TLS_CLIENT_METHOD_DEFINITION(CreateIndex);
TLS_CLIENT_METHOD_DEFINITION(DeleteIndex);
TLS_CLIENT_METHOD_DEFINITION(ModifyIndex);
TLS_CLIENT_METHOD_DEFINITION(DescribeIndex);
TLS_CLIENT_METHOD_DEFINITION(SearchLogs);
TLS_CLIENT_METHOD_DEFINITION(SearchLogsV2);
TLS_CLIENT_METHOD_DEFINITION(DescribeLogContext);
TLS_CLIENT_METHOD_DEFINITION(DescribeHistogram);
TLS_CLIENT_METHOD_DEFINITION(CreateDownloadTask);
TLS_CLIENT_METHOD_DEFINITION(DescribeDownloadTasks);
TLS_CLIENT_METHOD_DEFINITION(DescribeDownloadUrl);
TLS_CLIENT_METHOD_DEFINITION(CreateHostGroup);
TLS_CLIENT_METHOD_DEFINITION(DeleteHostGroup);
TLS_CLIENT_METHOD_DEFINITION(ModifyHostGroup);
TLS_CLIENT_METHOD_DEFINITION(DescribeHostGroups);
TLS_CLIENT_METHOD_DEFINITION(DescribeHostGroup);
TLS_CLIENT_METHOD_DEFINITION(DeleteHost);
TLS_CLIENT_METHOD_DEFINITION(DescribeHostGroupRules);
TLS_CLIENT_METHOD_DEFINITION(ModifyHostGroupsAutoUpdate);
TLS_CLIENT_METHOD_DEFINITION(DeleteAbnormalHosts);
TLS_CLIENT_METHOD_DEFINITION(CreateRule);
TLS_CLIENT_METHOD_DEFINITION(DeleteRule);
TLS_CLIENT_METHOD_DEFINITION(ModifyRule);
TLS_CLIENT_METHOD_DEFINITION(DescribeRule);
TLS_CLIENT_METHOD_DEFINITION(DescribeRules);
TLS_CLIENT_METHOD_DEFINITION(ApplyRuleToHostGroups);
TLS_CLIENT_METHOD_DEFINITION(DeleteRuleFromHostGroups);
TLS_CLIENT_METHOD_DEFINITION(CreateAlarmNotifyGroup);
TLS_CLIENT_METHOD_DEFINITION(DeleteAlarmNotifyGroup);
TLS_CLIENT_METHOD_DEFINITION(ModifyAlarmNotifyGroup);
TLS_CLIENT_METHOD_DEFINITION(DescribeAlarmNotifyGroups);
TLS_CLIENT_METHOD_DEFINITION(CreateAlarm);
TLS_CLIENT_METHOD_DEFINITION(DeleteAlarm);
TLS_CLIENT_METHOD_DEFINITION(ModifyAlarm);
TLS_CLIENT_METHOD_DEFINITION(DescribeAlarms);
TLS_CLIENT_METHOD_DEFINITION(OpenKafkaConsumer);
TLS_CLIENT_METHOD_DEFINITION(CloseKafkaConsumer);
TLS_CLIENT_METHOD_DEFINITION(DescribeKafkaConsumer);

}