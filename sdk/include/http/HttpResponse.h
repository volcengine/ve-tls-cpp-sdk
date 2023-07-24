#pragma once

#include <cstdio>
#include <map>
using namespace std;

struct HttpResponse {
    int status_code;
    std::string request_id;
    std::map<std::string, std::string> headers;
    std::string body;
};
