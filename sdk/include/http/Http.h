#pragma once

#include <cstdio>
#include <memory>
#include <vector>
#include <map>
#include "HttpResponse.h"
#include "HttpRequest.h"
using namespace std;

namespace VolcengineTls {

class HttpUtils {
public:
    static std::shared_ptr<HttpResponse> SendHttpRequest(HttpRequest &req, int timeout_millisecond = 0);
    static std::shared_ptr<HttpResponse> SendHttpRequestWithRetry(HttpRequest &req, int timeout_millisecond = 0);
};



}