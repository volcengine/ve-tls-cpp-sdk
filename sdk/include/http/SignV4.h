#pragma once
#include <list>
#include <memory>
#include <chrono>
#include <map>
#include <vector>
#include <set>
#include "http/Credential.h"
#include "http/SignKeyInfo.h"
#include "HttpRequest.h"

namespace VolcengineTls {
typedef std::time_t (*func)();

static const char* emptySHA256 = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";
static const char* unsignedPayload = "UNSIGNED-PAYLOAD";
static const char* signPrefix = "HMAC-SHA256";
static const char* authorization = "Authorization";

// static const char* v4Algorithm = "X-Tls-Algorithm";
// static const char* v4Credential = "X-Tls-Credential";
// static const char* v4Date = "X-Tls-Date";
// static const char* v4Expires = "X-Tls-Expires";
// static const char* v4SignedHeaders = "X-Tls-SignedHeaders";
// static const char* v4Signature = "X-Tls-Signature";
static const char* v4SignatureLower = "x-tls-signature";
// static const char* v4ContentSHA256 = "X-Content-Sha256";
// static const char* v4SecurityToken = "X-Tls-Security-Token";
static const char* v4Prefix = "x-";
static const std::set<char> nonEscape = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '_', '.', '~'};
class SignV4 {
public:
    SignV4() = default;
    SignV4(const std::shared_ptr<Credential>& credential, std::string region);
    ~SignV4() = default;

    static bool isSigningHeader(const std::string& key, bool isSigningQuery);
    static bool isSigningQuery(const std::string& key);

    void calcAndSetAuthorization(const std::shared_ptr<HttpRequest> &req);

    static std::string uriEncode(const std::string& in, bool encodeSlash);
    static std::string encodeQuery(std::vector<std::pair<std::string, std::string>> query);

private:
    std::vector<std::pair<std::string, std::string>> signedHeader(const std::map<std::string, std::string>& header,
                                                                  bool isSignedQuery);

    std::vector<std::pair<std::string, std::string>> signedQuery(const std::map<std::string, std::string>& query,
                                                                 std::map<std::string, std::string> extra);

    static std::string canonicalRequest(const std::string& method, const std::string& path,
                                        const std::string& contentSha256,
                                        std::vector<std::pair<std::string, std::string>> header,
                                        std::vector<std::pair<std::string, std::string>> query);

    std::string doSign(const std::string& method, const std::string& path, const std::string& contentSha256,
                       const std::vector<std::pair<std::string, std::string>>& header,
                       const std::vector<std::pair<std::string, std::string>>& query, std::time_t now,
                       const Credential& cred);

    static std::string encodePath(const std::string& path);

    static std::time_t utcTimeNow() {
        return time(nullptr);
    }

    std::shared_ptr<Credential> credential_;
    std::string region_;
};
}  // Namespace
