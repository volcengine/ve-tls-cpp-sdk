#pragma once

#include "../thirdparty/nlohmann/json.hpp"
#include <string>
#include <memory>
#include <map>

inline std::string ToTitleCase(const std::string &v) {
    if (v.size() <= 0) return v;
    std::string res = ""; res.push_back(v[0]);
    res[0] += res[0] >= 'a' && res[0] <= 'z' ? 'A' - 'a' : 0;
    for (int i=1; i<v.size(); i++) {
        if (v[i] == '_') {
            if (i < v.size()-1) {
                res += v[i+1] + 'A' - 'a';
                i++;
            }
        } else res += v[i];
    }
    return res;
}

// Title case
#define NLOHMANN_JSON_FROM_TITLE_CASE(v1) nlohmann_json_t.v1 = nlohmann_json_j.value(ToTitleCase(#v1), nlohmann_json_default_obj.v1);

#define NLOHMANN_JSON_PTR_TO_TITLE_CASE(v1) if (nlohmann_json_t.v1 != nullptr) nlohmann_json_j[ToTitleCase(#v1)] = *(nlohmann_json_t.v1);

#define NLOHMANN_JSON_TO_TITLE_CASE(v1) nlohmann_json_j[ToTitleCase(#v1)] = nlohmann_json_t.v1;

// Response macro
#define COMMON_JSON_DEF(Type, ...)  \
    void from_json(const nlohmann::json& nlohmann_json_j, Type& nlohmann_json_t) { const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM_TITLE_CASE, __VA_ARGS__)) } \
    void to_json(nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO_TITLE_CASE, __VA_ARGS__)) }

#define COMMON_JSON_DEC(Type) \
    void from_json(const nlohmann::json& nlohmann_json_j, Type& nlohmann_json_t); \
    void to_json(nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t);

// Request macro
#define COMMON_TLS_QUERY_JSON_DEFINITION(Type, ...)  \
    void Type::MakeQueryParamJson(nlohmann::json& v) { \
        auto innerLambda = [](nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t) { \
            NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_PTR_TO_TITLE_CASE, __VA_ARGS__)) \
        }; \
        return innerLambda(v, *this); \
    }

#define EMPTY_TLS_QUERY_JSON_DEFINITION(Type, ...) \
    void Type::MakeQueryParamJson(nlohmann::json& nlohmann_json_j) {}

#define COMMON_TLS_HEADER_JSON_DEFINITION(Type, ...)  \
    void Type::MakeHeaderParamJson(nlohmann::json& v) { \
        auto innerLambda = [](nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t) { \
            NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_PTR_TO_TITLE_CASE, __VA_ARGS__)) \
        }; \
        return innerLambda(v, *this); \
    }

#define EMPTY_TLS_HEADER_JSON_DEFINITION(Type, ...) \
    void Type::MakeHeaderParamJson(nlohmann::json& nlohmann_json_j) {}

#define COMMON_TLS_BODY_JSON_DEFINITION(Type, ...)  \
    void Type::MakeBodyParamJson(nlohmann::json& v) { \
        auto innerLambda = [](nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t) { \
            NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_PTR_TO_TITLE_CASE, __VA_ARGS__)) \
        }; \
        return innerLambda(v, *this); \
    }

#define EMPTY_TLS_BODY_JSON_DEFINITION(Type, ...) \
    void Type::MakeBodyParamJson(nlohmann::json& nlohmann_json_j) {}
