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
	security_token(""),
        region(""),
        timeout_millisecond(0),
        disable_retry(false),
        api_version("0.3.0"),
        use_long_link(true) {}

    std::string scheme;
    std::string endpoint;
    std::string access_key_id;
    std::string access_key_secret;
    std::string security_token;
    std::string region;
    int timeout_millisecond;
    bool disable_retry;
    std::string api_version;
    bool use_long_link;

    void setApiVersion(std::string api_version) {
        this->api_version = api_version;
    }
};

}
