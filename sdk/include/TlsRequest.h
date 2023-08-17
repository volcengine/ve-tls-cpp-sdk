#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Tls.pb.h"
#include "TlsModel.h"
#include "thirdparty/nlohmann/json.hpp"

#define TLS_REQUEST_COMMON_METHOD_DECLARATION(Type) \
    bool CheckValidation(); \
    std::string Method(); \
    std::string ContentType(); \
    void MakeQueryParamJson(nlohmann::json &nlohmann_json_j); \
    void MakeHeaderParamJson(nlohmann::json &nlohmann_json_j); \
    void MakeBodyParamJson(nlohmann::json &nlohmann_json_j);

namespace VolcengineTls {

    class TlsRequest {
    private:
        std::string api_version;
    public:
        std::string getApiVersion() {
            return this->api_version;
        }

        TlsRequest() {
        }

        TlsRequest(std::string api_version) {
            this->api_version = api_version;
        }

    };

    /**
     * @param project_name 日志项目的名称
     * @param region      地域
     * @param description 日志项目描述信息
     */
    class CreateProjectRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> project_name;
        std::shared_ptr<std::string> region;
        std::shared_ptr<std::string> description;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateProjectRequest)
    };

    /**
     * @param project_id 日志项目 ID
     */
    class DeleteProjectRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> project_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteProjectRequest)
    };
    /**
     * @param project_id   日志主题所属的日志项目 ID
     * @param project_name 日志项目的名称
     * @param description 日志项目描述信息
     */
    class ModifyProjectRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> project_id;
        std::shared_ptr<std::string> project_name;
        std::shared_ptr<std::string> description;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyProjectRequest)
    };
    /**
     * @param project_id 日志项目 ID
     */
    class DescribeProjectRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> project_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeProjectRequest)
    };

    /**
     * @param project_id 日志项目 ID
     * @param project_name 日志项目的名称
     * @param is_full_name 根据project_name筛选时，是否精确匹配
     * @param page_number 分页查询时的页码。默认为 1
     * @param page_size 分页大小。默认为 20，最大为 100
     */
    class DescribeProjectsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> project_id;
        std::shared_ptr<std::string> project_name;
        std::shared_ptr<bool> is_full_name;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeProjectsRequest)
    };
    /**
     * @param project_id 日志项目 ID
     * @param topic_name 日志主题名称
     * @param ttl 日志在日志服务中的保存时间,单位天。默认30天
     * @param shardCount 日志分区的数量，默认创建 1 个分区，取值范围为 1～10
     * @param auto_split 是否开启分区的自动分裂功能，默认true
     * @param max_split_shard 分区的最大分裂数
     * @param enable_tracking 是否开启 WebTracking 功能
     * @param time_key 日志时间字段的字段名称
     * @param time_format 时间字段的解析格式
     * @param description 日志主题描述
     */
    class CreateTopicRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_name;
        std::shared_ptr<std::string> project_id;
        std::shared_ptr<int> ttl;
        std::shared_ptr<int> shard_count;
        std::shared_ptr<bool> auto_split;
        std::shared_ptr<int> max_split_shard;
        std::shared_ptr<bool> enable_tracking;
        std::shared_ptr<std::string> time_key;
        std::shared_ptr<std::string> time_format;
        std::shared_ptr<std::string> description;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateTopicRequest)
    };

    /**
     * @param topic_id 日志主题 ID
     */
    class DeleteTopicRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteTopicRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     * @param topic_name 日志主题名称
     * @param ttl 日志在日志服务中的保存时间,单位天。默认30天
     * @param shardCount 日志分区的数量，默认创建 1 个分区，取值范围为 1～10
     * @param auto_split 是否开启分区的自动分裂功能，默认true
     * @param max_split_shard 分区的最大分裂数
     * @param enable_tracking 是否开启 WebTracking 功能
     * @param time_key 日志时间字段的字段名称
     * @param time_format 时间字段的解析格式
     * @param description 日志主题描述
     */
    class ModifyTopicRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_name;
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<int> ttl;
        std::shared_ptr<int> shard_count;
        std::shared_ptr<bool> auto_split;
        std::shared_ptr<int> max_split_shard;
        std::shared_ptr<bool> enable_tracking;
        std::shared_ptr<std::string> time_key;
        std::shared_ptr<std::string> time_format;
        std::shared_ptr<std::string> description;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyTopicRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     */
    class DescribeTopicRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeTopicRequest)
    };
    /**
     * @param project_id 日志项目 ID
     * @param topic_id 日志主题 ID
     * @param topic_name 日志主题名称
     * @param is_full_name 根据topic_name筛选时，是否精确匹配
     * @param page_number 分页查询时的页码。默认为 1
     * @param page_size 分页大小。默认为 20，最大为 100
     */
    class DescribeTopicsRequest : public TlsRequest {
    public:
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;
        std::shared_ptr<bool> is_full_name;
        std::shared_ptr<std::string> project_id;
        std::shared_ptr<std::string> topic_name;
        std::shared_ptr<std::string> topic_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeTopicsRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     * @param page_number 分页查询时的页码。默认为 1
     * @param page_size 分页大小。默认为 20，最大为 100
     */
    class DescribeShardsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeShardsRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     * @param full_text 全文索引配置
     * @param key_value 键值索引配置
     */
    class CreateIndexRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<FullTextInfo> full_text;
        std::shared_ptr<std::vector<KeyValueInfo>> key_value;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateIndexRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     */
    class DeleteIndexRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteIndexRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     * @param full_text 全文索引配置
     * @param key_value 键值索引配置
     */
    class ModifyIndexRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<FullTextInfo> full_text;
        std::shared_ptr<std::vector<KeyValueInfo>> key_value;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyIndexRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     */
    class DescribeIndexRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeIndexRequest)
    };
    /**
     * @param log_group_list 日志列表
     * @param topic_id      日志主题 ID
     * @param hash_key      路由 Shard 的key
     * @param compression 压缩格式，支持lz4、zlib
     */
    class PutLogsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> hash_key;
        std::shared_ptr<std::string> compression;
        std::shared_ptr<pb::LogGroupList> log_group_list;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(PutLogsRequest)
    };
    /**
     * @param logs 日志列表
     * @param topic_id      日志主题 ID
     * @param hash_key      路由 Shard 的key
     * @param compression 压缩格式，支持lz4、zlib
     * @param source 日志来源，一般使用机器 IP 作为标识
     * @param filename 日志路径
     */
    class PutLogsV2Request : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> hash_key;
        std::shared_ptr<std::string> compression;
        std::shared_ptr<std::string> source;
        std::shared_ptr<std::string> filename;
        std::shared_ptr<std::vector<LogItem>> logs;
    };
    /**
     * @param topic_id 要获取日志游标的日志主题 ID
     * @param shard_id 日志分区的 ID
     * @param from 时间点（Unix 时间戳，以秒为单位）或者字符串 begin、end
     */
    class DescribeCursorRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<int> shard_id;
        std::shared_ptr<std::string> from;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeCursorRequest)
    };
    /**
     * @param topic_id 要获取日志游标的日志主题 ID
     * @param shard_id 日志分区的 ID
     * @param cursor 开始游标
     * @param log_group_count 想要返回的最大 logGroup 数量
     * @param compression 压缩格式，支持lz4、zlib
     */
    class ConsumeLogsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<int> shard_id;
        std::shared_ptr<std::string> cursor;
        std::shared_ptr<std::string> end_cursor;
        std::shared_ptr<int> log_group_count;
        std::shared_ptr<std::string> compression;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ConsumeLogsRequest)
    };
    /**
     * @param topic_id 要获取日志游标的日志主题 ID
     * @param query 查询分析语句
     * @param start_time 查询开始时间点，精确到毫秒
     * @param end_time 查询结束时间点，精确到毫秒
     * @param limit 返回的日志条数，最大值为 100
     * @param context 检索上下文
     * @param sort 仅检索不分析时，日志的排序方式，生序asc降序desc
     */
    class SearchLogsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> query;
        std::shared_ptr<int> start_time;
        std::shared_ptr<int> end_time;
        std::shared_ptr<int> limit;
        std::shared_ptr<std::string> context;
        std::shared_ptr<std::string> sort;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(SearchLogsRequest)
    };
    /**
     * @param topic_id 要获取日志游标的日志主题 ID
     * @param query 查询分析语句
     * @param start_time 查询开始时间点，精确到毫秒
     * @param end_time 查询结束时间点，精确到毫秒
     * @param limit 返回的日志条数，最大值为 100
     * @param context 检索上下文
     * @param sort 仅检索不分析时，日志的排序方式，生序asc降序desc
     */
    class SearchLogsV2Request : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> query;
        std::shared_ptr<int> start_time;
        std::shared_ptr<int> end_time;
        std::shared_ptr<int> limit;
        std::shared_ptr<std::string> context;
        std::shared_ptr<std::string> sort;

        SearchLogsV2Request() : TlsRequest("0.3.0") {};

        TLS_REQUEST_COMMON_METHOD_DECLARATION(SearchLogsV2Request)
    };
    /**
     * @param topic_id 要获取日志游标的日志主题 ID
     * @param context_flow 日志所在的 LogGroup 的 ID
     * @param package_offset 日志在 LogGroup 的序号
     * @param source 日志来源主机 IP
     * @param prev_logs 日志的上文日志条数
     * @param next_logs 日志的下文日志条数
     */
    class DescribeLogContextRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> context_flow;
        std::shared_ptr<int> package_offset;
        std::shared_ptr<std::string> source;
        std::shared_ptr<int> prev_logs;
        std::shared_ptr<int> next_logs;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeLogContextRequest)
    };
    /**
     * @param topic_id 要获取日志游标的日志主题 ID
     * @param query 查询分析语句
     * @param start_time 查询开始时间点，精确到毫秒
     * @param end_time 查询结束时间点，精确到毫秒
     * @param interval 直方图的子区间长度。单位为毫秒
     */
    class DescribeHistogramRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> query;
        std::shared_ptr<int> start_time;
        std::shared_ptr<int> end_time;
        std::shared_ptr<int> interval;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHistogramRequest)
    };
    /**
     * @param project_id 日志项目 ID
     * @param topic_id 日志主题 ID
     * @param logs 日志内容
     * @param compression 压缩格式，支持lz4、zlib
     * @param source 日志来源，一般使用机器 IP 作为标识
     */
    class WebTracksRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> project_id;
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::vector<std::map<std::string, std::string>>> logs;
        std::shared_ptr<std::string> source;
        std::shared_ptr<std::string> compression;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(WebTracksRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     * @param task_name 下载任务名称
     * @param query 查询分析语句
     * @param start_time 查询开始时间点，精确到毫秒
     * @param end_time 查询结束时间点，精确到毫秒
     * @param data_format 导出的文件格式，支持设置为：csv、json
     * @param limit 返回的日志条数，最大值为 100
     * @param compression 导出文件的压缩类型，目前仅支持设置为 gzip
     * @param sort 仅检索不分析时，日志的排序方式，生序asc降序desc
     */
    class CreateDownloadTaskRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> task_name;
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> query;
        std::shared_ptr<int> start_time;
        std::shared_ptr<int> end_time;
        std::shared_ptr<std::string> data_format;
        std::shared_ptr<std::string> sort;
        std::shared_ptr<int> limit;
        std::shared_ptr<std::string> compression;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateDownloadTaskRequest)
    };

    /**
    * @param topic_id 日志主题 ID
    * @param page_number 分页查询时的页码。默认为 1
    * @param page_size 分页大小。默认为 20，最大为 100
     */
    class DescribeDownloadTasksRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeDownloadTasksRequest)
    };
    /**
     * @param task_id 下载任务的任务 ID
     */
    class DescribeDownloadUrlRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> task_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeDownloadUrlRequest)
    };

    /**
     * @param host_group_name 机器组的名称
     * @param host_group_type 机器组的类型：IP、Label
     * @param host_ip_list 机器 IP 列表
     * @param host_identifier 机器标识。HostGroupType 为 Label 时必选
     * @param auto_update 机器组服务器中安装的 LogCollector 是否开启自动升级功能
     * @param update_start_time 自动升级的开始时间
     * @param update_end_time 自动升级的结束时间
     * @param service_logging 是否开启 Logcollector 服务日志功能
     */
    class CreateHostGroupRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_name;
        std::shared_ptr<std::string> host_group_type;
        std::shared_ptr<std::vector<std::string>> host_ip_list;
        std::shared_ptr<std::string> host_identifier;
        std::shared_ptr<bool> auto_update;
        std::shared_ptr<std::string> update_start_time;
        std::shared_ptr<std::string> update_end_time;
        std::shared_ptr<bool> service_logging;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateHostGroupRequest)
    };
    /**
     * @param host_group_id 机器组 ID
     */
    class DeleteHostGroupRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteHostGroupRequest)
    };
    /**
     * @param host_group_id 机器组 ID
     * @param host_group_name 机器组的名称
     * @param host_group_type 机器组的类型：IP、Label
     * @param host_ip_list 机器 IP 列表
     * @param host_identifier 机器标识。HostGroupType 为 Label 时必选
     * @param auto_update 机器组服务器中安装的 LogCollector 是否开启自动升级功能
     * @param update_start_time 自动升级的开始时间
     * @param update_end_time 自动升级的结束时间
     * @param service_logging 是否开启 Logcollector 服务日志功能
     */
    class ModifyHostGroupRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_id;
        std::shared_ptr<std::string> host_group_name;
        std::shared_ptr<std::string> host_group_type;
        std::shared_ptr<std::vector<std::string>> host_ip_list;
        std::shared_ptr<std::string> host_identifier;
        std::shared_ptr<bool> auto_update;
        std::shared_ptr<std::string> update_start_time;
        std::shared_ptr<std::string> update_end_time;
        std::shared_ptr<bool> service_logging; // Modify 的要小心

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyHostGroupRequest)
    };
    /**
     * @param host_group_id 机器组 ID
     */
    class DescribeHostGroupRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHostGroupRequest)
    };
    /**
    * @param host_group_id 机器组 ID
    * @param host_group_name 机器组的名称
    * @param page_number 分页查询时的页码。默认为 1
    * @param page_size 分页大小。默认为 20，最大为 100
    * @param auto_update 机器组服务器中安装的 LogCollector 是否开启自动升级功能
    * @param host_identifier 机器标识。HostGroupType 为 Label 时必选
    * @param service_logging 是否开启 Logcollector 服务日志功能
    */
    class DescribeHostGroupsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_id;
        std::shared_ptr<std::string> host_group_name;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;
        std::shared_ptr<bool> auto_update;
        std::shared_ptr<std::string> host_identifier;
        std::shared_ptr<bool> service_logging;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHostGroupsRequest)
    };
    /**
    * @param host_group_id 机器组 ID
    * @param ip 机器 IP
    * @param page_number 分页查询时的页码。默认为 1
    * @param page_size 分页大小。默认为 20，最大为 100
    * @param heartbeat_status 机器心跳状态
    */
    class DescribeHostsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_id;
        std::shared_ptr<std::string> ip;
        std::shared_ptr<int> heartbeat_status;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHostsRequest)
    };
    /**
    * @param host_group_id 机器组 ID
    * @param ip 机器 IP
    */
    class DeleteHostRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_id;
        std::shared_ptr<std::string> ip;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteHostRequest)
    };
    /**
    * @param host_group_id 机器组 ID
    * @param page_number 分页查询时的页码。默认为 1
    * @param page_size 分页大小。默认为 20，最大为 100
    */
    class DescribeHostGroupRulesRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_id;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHostGroupRulesRequest)
    };
    /**
    * @param host_group_id 机器组 ID
    * @param auto_update 机器组服务器中安装的 LogCollector 是否开启自动升级功能
    * @param update_start_time 自动升级的开始时间
    * @param update_end_time 自动升级的结束时间
    */
    class ModifyHostGroupsAutoUpdateRequest : public TlsRequest {
    public:
        std::shared_ptr<std::vector<std::string>> host_group_ids;
        std::shared_ptr<bool> auto_update;
        std::shared_ptr<std::string> update_start_time;
        std::shared_ptr<std::string> update_end_time;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyHostGroupsAutoUpdateRequest)
    };
    /**
    * @param host_group_id 机器组 ID
    */
    class DeleteAbnormalHostsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> host_group_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteAbnormalHostsRequest)
    };

    /**
     * @param topic_id 日志主题 ID
     * @param rule_name 采集配置的名称
     * @param paths 采集路径列表
     * @param exclude_paths 采集黑名单列表
     * @param log_type 采集模式
     * @param extract_rule 日志提取规则
     * @param user_define_rule 用户自定义的采集规则
     * @param log_sample 日志样例
     * @param input_type 采集类型 0：（默认）宿主机日志文件，1：K8s 容器标准输出，2：K8s 容器内日志文件
     * @param container_rule 容器采集规则
     */
    class CreateRuleRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> rule_name;
        std::shared_ptr<std::vector<std::string>> paths;
        std::shared_ptr<std::vector<ExcludePath>> exclude_paths;
        std::shared_ptr<std::string> log_type;
        std::shared_ptr<ExtractRule> extract_rule;
        std::shared_ptr<UserDefineRule> user_define_rule;
        std::shared_ptr<std::string> log_sample;
        std::shared_ptr<int> input_type;
        std::shared_ptr<ContainerRule> container_rule;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateRuleRequest)
    };
    /**
    * @param rule_id 采集配置的 ID
    */
    class DeleteRuleRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> rule_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteRuleRequest)
    };
    /**
    * @param rule_id 采集配置的 ID
    * @param rule_name 采集配置的名称
     * @param paths 采集路径列表
     * @param exclude_paths 采集黑名单列表
     * @param log_type 采集模式
     * @param extract_rule 日志提取规则
     * @param user_define_rule 用户自定义的采集规则
     * @param log_sample 日志样例
     * @param input_type 采集类型 0：（默认）宿主机日志文件，1：K8s 容器标准输出，2：K8s 容器内日志文件
     * @param container_rule 容器采集规则
    */
    class ModifyRuleRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> rule_id;
        std::shared_ptr<std::string> rule_name;
        std::shared_ptr<std::vector<std::string>> paths;
        std::shared_ptr<std::string> log_type;
        std::shared_ptr<ExtractRule> extract_rule;
        std::shared_ptr<std::vector<ExcludePath>> exclude_paths;
        std::shared_ptr<std::string> log_sample;
        std::shared_ptr<UserDefineRule> user_define_rule;
        std::shared_ptr<int> input_type;
        std::shared_ptr<ContainerRule> container_rule;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyRuleRequest)
    };
    /**
    * @param rule_id 采集配置的 ID
    */
    class DescribeRuleRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> rule_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeRuleRequest)
    };
    /**
     * @param project_id 日志项目 ID
     * @param topic_id 日志主题 ID
     * @param topic_name 日志主题名称
    * @param rule_id 采集配置的 ID
    * @param rule_name 采集配置的名称
     * @param page_number 分页查询时的页码。默认为 1
     * @param page_size 分页大小。默认为 20，最大为 100
     */
    class DescribeRulesRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> project_id;
        std::shared_ptr<std::string> rule_id;
        std::shared_ptr<std::string> rule_name;
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> topic_name;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeRulesRequest)
    };
    /**
    * @param rule_id 采集配置的 ID
    * @param host_group_ids 机器组id列表
     */
    class ApplyRuleToHostGroupsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> rule_id;
        std::shared_ptr<std::vector<std::string>> host_group_ids;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ApplyRuleToHostGroupsRequest)
    };
    /**
    * @param rule_id 采集配置的 ID
    * @param host_group_ids 机器组id列表
     */
    class DeleteRuleFromHostGroupsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> rule_id;
        std::shared_ptr<std::vector<std::string>> host_group_ids;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteRuleFromHostGroupsRequest)
    };
    /**
     * @param alarm_notify_group_name 告警通知组名称
     * @param notify_type           告警通知的类型 Trigger告警触发、Recovery告警恢复
     * @param receivers            接收告警的 IAM 用户列表
     */
    class CreateAlarmNotifyGroupRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> alarm_notify_group_name;
        std::shared_ptr<std::vector<std::string>> notify_type;
        std::shared_ptr<std::vector<Receiver>> receivers;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateAlarmNotifyGroupRequest)
    };
    /**
    * @param alarm_notify_group_id 告警通知组 ID
     */
    class DeleteAlarmNotifyGroupRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> alarm_notify_group_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteAlarmNotifyGroupRequest)
    };
    /**
     * @param alarm_notify_group_id 告警通知组 ID
     * @param alarm_notify_group_name 告警通知组名称
     * @param notify_type           告警通知的类型 Trigger告警触发、Recovery告警恢复
     * @param receivers            接收告警的 IAM 用户列表
     */
    class ModifyAlarmNotifyGroupRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> alarm_notify_group_id;
        std::shared_ptr<std::string> alarm_notify_group_name;
        std::shared_ptr<std::vector<std::string>> notify_type;
        std::shared_ptr<std::vector<Receiver>> receivers;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyAlarmNotifyGroupRequest)
    };
    /**
     * @param alarm_notify_group_id 告警通知组 ID
     * @param alarm_notify_group_name 告警通知组名称
     * @param receiver_name 接收告警的 IAM 用户名称
     * @param page_number 分页查询时的页码。默认为 1
     * @param page_size 分页大小。默认为 20，最大为 100
     */
    class DescribeAlarmNotifyGroupsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> alarm_notify_group_name;
        std::shared_ptr<std::string> alarm_notify_group_id;
        std::shared_ptr<std::string> receiver_name;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeAlarmNotifyGroupsRequest)
    };

    /**
     * @param alarm_name 告警策略名称
     * @param project_id 日志项目 ID
     * @param status 是否开启告警策略
     * @param query_request 检索分析语句，可配置 1~3 条
     * @param request_cycle 告警任务的执行周期
     * @param condition 告警触发条件
     * @param trigger_period 触发告警持续周期。最小值为 1，最大值为10。
     * @param alarm_period 告警重复的周期
     * @param alarm_notify_group alarmNotifyGroup 告警对应的通知列表
     * @param user_define_msg 告警通知的内容。
     */
    class CreateAlarmRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> alarm_name;
        std::shared_ptr<std::string> project_id;
        std::shared_ptr<bool> status;
        std::shared_ptr<std::vector<QueryRequest>> query_request;
        std::shared_ptr<RequestCycle> request_cycle;
        std::shared_ptr<std::string> condition;
        std::shared_ptr<int> trigger_period;
        std::shared_ptr<int> alarm_period;
        std::shared_ptr<std::vector<std::string>> alarm_notify_group;
        std::shared_ptr<std::string> user_define_msg;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateAlarmRequest)
    };
/**
* @param alarm_id 报警id
 */
    class DeleteAlarmRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> alarm_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteAlarmRequest)
    };
    /**
     * @param alarm_id 报警id
     * @param alarm_name 告警策略名称
     * @param status 是否开启告警策略
     * @param query_request 检索分析语句，可配置 1~3 条
     * @param request_cycle 告警任务的执行周期
     * @param condition 告警触发条件
     * @param trigger_period 触发告警持续周期。最小值为 1，最大值为10。
     * @param alarm_period 告警重复的周期
     * @param alarm_notify_group alarmNotifyGroup 告警对应的通知列表
     * @param user_define_msg 告警通知的内容。
     */
    class ModifyAlarmRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> alarm_id;
        std::shared_ptr<std::string> alarm_name;
        std::shared_ptr<bool> status;
        std::shared_ptr<std::vector<QueryRequest>> query_request;
        std::shared_ptr<RequestCycle> request_cycle;
        std::shared_ptr<std::string> condition;
        std::shared_ptr<int> trigger_period;
        std::shared_ptr<int> alarm_period;
        std::shared_ptr<std::vector<std::string>> alarm_notify_group;
        std::shared_ptr<std::string> user_define_msg;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyAlarmRequest)
    };
    /**
     * @param alarm_name 告警策略名称
     * @param project_id 日志项目 ID
     * @param alarm_id 报警id
     * @param status 是否开启告警策略
     * @param topic_id 日志主题 ID
     * @param topic_name 日志主题名称
     * @param page_number 分页查询时的页码。默认为 1
     * @param page_size 分页大小。默认为 20，最大为 100
     */
    class DescribeAlarmsRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> project_id;
        std::shared_ptr<std::string> alarm_name;
        std::shared_ptr<std::string> alarm_id;
        std::shared_ptr<std::string> topic_id;
        std::shared_ptr<std::string> topic_name;
        std::shared_ptr<bool> status;
        std::shared_ptr<int> page_number;
        std::shared_ptr<int> page_size;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeAlarmsRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     */
    class OpenKafkaConsumerRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(OpenKafkaConsumerRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     */
    class CloseKafkaConsumerRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(CloseKafkaConsumerRequest)
    };
    /**
     * @param topic_id 日志主题 ID
     */
    class DescribeKafkaConsumerRequest : public TlsRequest {
    public:
        std::shared_ptr<std::string> topic_id;

        TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeKafkaConsumerRequest)
    };


} // Namespace