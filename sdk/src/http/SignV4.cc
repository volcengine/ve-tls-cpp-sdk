#include "http/SignV4.h"
#include "http/Credential.h"
#include "utils/BaseUtils.h"

#include <ctime>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <cstring>
#include <thread>

namespace VolcengineTls {
SignV4::SignV4(const std::shared_ptr<Credential>& credential, std::string region) : region_(std::move(region)) {
    credential_ = credential;
}
std::string joinMapToString(const std::vector<std::pair<std::string, std::string>>& KVs) {
    std::vector<std::string> keys(KVs.size());
    for (int i = 0; i < KVs.size(); ++i) {
        keys[i] = KVs[i].first;
    }
    std::sort(keys.begin(), keys.end());
    std::string ret;
    for (auto& key : keys) {
        if (key != keys[0]) {
            ret.append(";");
        }
        ret.append(key);
    }
    return ret;
}

bool compareByPairKey(const std::pair<std::string, std::string>& dataA,
                      const std::pair<std::string, std::string>& dataB) {
    return dataA.first < dataB.first;
}

void SignV4::calcAndSetAuthorization(const std::shared_ptr<HttpRequest> &req) {
    std::time_t now = utcTimeNow();
    const std::string& date = TimeUtils::transTimeToFormat(now, iso8601Layout);
    req->headers["X-Date"] = date;
    if (req->body.size() > 0)
       req->headers["X-Content-Sha256"] = CryptoUtils::sha256Sum((char*)req->body.c_str(), req->body.size());

    auto signedHeader = this->signedHeader(req->headers, false);


    std::map<std::string, std::string> extra;
    auto signedQuery = this->signedQuery(req->queries, extra);
    std::sort(signedHeader.begin(), signedHeader.end(), compareByPairKey);
    Credential &cred = *credential_;

    std::string contentSha256;
    if (req->body.size() > 0)
        contentSha256 = CryptoUtils::sha256Sum((char*)req->body.c_str(), req->body.size());
    // if (req->headers.count(v4ContentSHA256)) {
    //     contentSha256 = req->headers.find(v4ContentSHA256)->second;
    // }

    std::string sig =
            this->doSign(req->method, req->path, contentSha256, signedHeader, signedQuery, now, cred);
    std::string credential;
    credential.append(cred.getAccessKeyId())
            .append("/")
            .append(TimeUtils::transTimeToFormat(now, yyyyMMdd))
            .append("/")
            .append(region_)
            .append("/TLS/request");
    auto keys = joinMapToString(signedHeader);

    std::stringstream auth;
    auth << "HMAC-SHA256 Credential=" << credential << ", SignedHeaders=" << keys << ", Signature=" << sig;
    req->headers["Authorization"] = auth.str();
    if (!cred.getSecurityToken().empty()) {
        req->headers["X-Security-Token"] = cred.getSecurityToken();
    }
    return;
}

bool SignV4::isSigningHeader(const std::string& key, bool isSigningQuery) {
    if (key.empty()) {
        return false;
    }
    bool isCT = std::strcmp("content-type", key.c_str()) == 0;
    bool isV4Prefix = StringUtils::startsWithIgnoreCase(key, v4Prefix);
    return (isCT && !isSigningQuery) || isV4Prefix;
}

bool SignV4::isSigningQuery(const std::string& key) {
    return std::strcmp(v4SignatureLower, key.c_str()) != 0;
}

std::vector<std::pair<std::string, std::string>> SignV4::signedHeader(const std::map<std::string, std::string>& header,
                                                                      bool isSignedQuery) {
    std::vector<std::pair<std::string, std::string>> signedRes;
    if (header.empty())
        return signedRes;
    auto iter = header.begin();
    for (; iter != header.end(); iter++) {
        if (!iter->first.empty()) {
            std::string key(iter->first);
            std::string kk = StringUtils::toLower(key);
            if (this->isSigningHeader(kk, isSignedQuery)) {
                signedRes.emplace_back(kk, iter->second);
            }
        }
    }
    return signedRes;
}

std::vector<std::pair<std::string, std::string>> SignV4::signedQuery(const std::map<std::string, std::string>& query,
                                                                     std::map<std::string, std::string> extra) {
    std::vector<std::pair<std::string, std::string>> signedRes;
    if (!query.empty()) {
        for (const auto& iter : query) {
            if (this->isSigningQuery(StringUtils::toLower(iter.first))) {
                signedRes.emplace_back(iter.first, iter.second);
            }
        }
    }
    if (!extra.empty()) {
        auto iter = extra.begin();
        for (; iter != extra.end(); iter++) {
            if (this->isSigningQuery(StringUtils::toLower(iter->first))) {
                signedRes.emplace_back(iter->first, iter->second);
            }
        }
    }
    return signedRes;
}

std::string SignV4::uriEncode(const std::string& in, bool encodeSlash) {
    int hexCount = 0;
    // uint8_t uint8Char[in.length()];
    uint8_t *uint8Char = new uint8_t[in.length()];
    for (int i = 0; i < in.length(); i++) {
        uint8Char[i] = (uint8_t)(in[i]);
        if (uint8Char[i] == '/') {
            if (encodeSlash) {
                hexCount++;
            }
        } else if (nonEscape.count(uint8Char[i]) == 0) {
            hexCount++;
        }
    }
    char *encoded = new char[in.length() + 2 * hexCount];
    memset(encoded, 0, in.length() + 2 * hexCount);
    // char encoded[in.length() + 2 * hexCount];
    for (int i = 0, j = 0; i < in.length(); i++) {
        if (uint8Char[i] == '/') {
            if (encodeSlash) {
                encoded[j] = '%';
                encoded[j + 1] = '2';
                encoded[j + 2] = 'F';
                j += 3;
            } else {
                encoded[j] = uint8Char[i];
                j++;
            }
        } else if (nonEscape.count(uint8Char[i]) == 0) {
            encoded[j] = '%';
            encoded[j + 1] = "0123456789ABCDEF"[uint8Char[i] >> 4];
            encoded[j + 2] = "0123456789ABCDEF"[uint8Char[i] & 15];
            j += 3;
        } else {
            encoded[j] = uint8Char[i];
            j++;
        }
    }
    std::string ret(encoded, encoded + in.length() + 2 * hexCount);
    delete []encoded;
    delete []uint8Char;
    return ret;
}

std::string SignV4::encodePath(const std::string& path) {
    if (path.empty()) {
        return "/";
    }
    return uriEncode(path, false);
}

std::string SignV4::encodeQuery(std::vector<std::pair<std::string, std::string>> query) {
    if (query.empty())
        return "";
    std::sort(query.begin(), query.end(), compareByPairKey);
    std::string buf;
    auto iter = query.begin();
    while (iter != query.end()) {
        if (iter != query.begin()) {
            buf.append("&");
        }
        auto keyEscaped = uriEncode(iter->first, true);
        buf.append(keyEscaped);
        buf.append("=");
        auto v = uriEncode(iter->second, true);
        buf.append(v);
        iter++;
    }
    return buf;
}

std::string SignV4::canonicalRequest(const std::string& method, const std::string& path,
                                     const std::string& contentSha256,
                                     std::vector<std::pair<std::string, std::string>> header,
                                     std::vector<std::pair<std::string, std::string>> query) {
    auto split = "\n";
    std::string buf;

    buf.append(method).append(split).append(encodePath(path)).append(split);

    buf.append(encodeQuery(std::move(query))).append(split);

    std::vector<std::string> keys;
    std::sort(header.begin(), header.end(), compareByPairKey);
    for (const std::pair<std::string, std::string>& entry : header) {
        auto key = entry.first;
        keys.emplace_back(key);

        buf.append(key);
        buf.append(":");
        buf.append(entry.second);
        buf.append("\n");
    }
    buf.append(split);

    auto iter = keys.begin();
    while (iter != keys.end()) {
        if (iter != keys.begin()) {
            buf.append(";");
        }
        buf.append(*iter);
        iter++;
    }
    buf.append(split);

    if (!contentSha256.empty()) {
        buf.append(contentSha256);
    } else {
        buf.append(emptySHA256);
    }
    return buf;
}

std::string SignV4::doSign(const std::string& method, const std::string& path, const std::string& contentSha256,
                           const std::vector<std::pair<std::string, std::string>>& header,
                           const std::vector<std::pair<std::string, std::string>>& query, std::time_t now,
                           const Credential& cred) {
    std::string split = "\n";
    std::string buf;

    std::string req = this->canonicalRequest(method, path, contentSha256, header, query);

    buf.append(signPrefix).append(split);

    buf.append(TimeUtils::transTimeToFormat(now, iso8601Layout)).append(split);

    std::string date = TimeUtils::transTimeToFormat(now, yyyyMMdd);
    buf.append(date).append("/").append(region_).append("/TLS/request").append(split);

    unsigned char sum[32];
    SHA256((unsigned char*)req.c_str(), req.length(), sum);
    std::string hexSum(StringUtils::stringToHex(sum, 32));
    buf.append(hexSum);

    unsigned int mdLen = 32;
    unsigned char unsignedDate[32];
    HMAC(EVP_sha256(), cred.getAccessKeySecret().c_str(), cred.getAccessKeySecret().size(),
         reinterpret_cast<const unsigned char*>(date.c_str()), date.size(), unsignedDate, &mdLen);
    unsigned char unsignedRegion[32];
    HMAC(EVP_sha256(), unsignedDate, 32, reinterpret_cast<const unsigned char*>(region_.c_str()), region_.size(),
         unsignedRegion, &mdLen);
    unsigned char unsignedService[32];
    HMAC(EVP_sha256(), unsignedRegion, 32, reinterpret_cast<const unsigned char*>("TLS"), 3, unsignedService, &mdLen);
    unsigned char signK[32];
    HMAC(EVP_sha256(), unsignedService, 32, reinterpret_cast<const unsigned char*>("request"), 7, signK, &mdLen);
    unsigned char sig[32];
    HMAC(EVP_sha256(), signK, 32, reinterpret_cast<const unsigned char*>(buf.c_str()), buf.size(), sig, &mdLen);
    return StringUtils::stringToHex(sig, 32);
}
}  // namespace VolcengineTls
