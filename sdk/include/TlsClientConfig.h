#pragma once

#include <string>
#include <vector>

namespace VolcengineTls {

class TlsClientConfig {
public:
    TlsClientConfig():
        scheme(""),
        endpoint(""),
        access_key_id(""),
        access_key_secret(""),
        region(""),
        timeout_millisecond(0),
        disable_retry(false) {}

    std::string scheme;
    std::string endpoint;
    std::string access_key_id;
    std::string access_key_secret;
    std::string region;
    int timeout_millisecond;
    bool disable_retry;
};

}