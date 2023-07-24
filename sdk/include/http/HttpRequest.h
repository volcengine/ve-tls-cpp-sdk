#pragma once

#include <ctime>
#include <string>
#include <openssl/hmac.h>
#include "utils/BaseUtils.h"

namespace VolcengineTls {

struct HttpRequest {
public:
    std::string scheme;
    std::string method;
    std::string host;
    std::string path;
    std::string content_type;
    std::map<std::string, std::string> headers;
    std::map<std::string, std::string> queries;
    std::string body;
};


} // Namespace

