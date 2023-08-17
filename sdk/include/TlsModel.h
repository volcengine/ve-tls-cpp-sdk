#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>

namespace VolcengineTls {

    struct HostInfo {
        std::string ip;
        std::string log_collector_version;
        int heartbeat_status;
    };
    /**
     * @param type   日志模板的类型：Nginx
     * @param format 日志模板内容
     */
    struct LogTemplate {
        std::string type;
        std::string format;
    };
    /**
     * @param namespace_name_regex 待采集的 Kubernetes Namespace 名称，不指定 Namespace 名称时表示采集全部容器
     * @param workload_type 通过工作负载的类型指定采集的容器，仅支持选择一种类型
     * @param workload_name_regex 通过工作负载的名称指定待采集的容器
     * @param pod_name_regex Pod名称用于指定待采集的容器
     * @param include_pod_label_regex Pod Label 白名单用于指定待采集的容器
     * @param exclude_pod_label_regex 通过 Pod Label 黑名单指定不采集的容器，不启用表示采集全部容器
     * @param annotation_tag 是否将 Kubernetes Annotation 作作为日志标签，添加到原始日志数据中
     * @param label_tag 是否将 Kubernetes Label 作为日志标签，添加到原始日志数据中
     */
    struct KubernetesRule {
        std::string namespace_name_regex;
        std::string workload_type;
        std::string workload_name_regex;
        std::map<std::string, std::string> include_pod_label_regex;
        std::map<std::string, std::string> exclude_pod_label_regex;
        std::string pod_name_regex;
        std::map<std::string, std::string> annotation_tag;
        std::map<std::string, std::string> label_tag;
    };

    struct Receiver {
        std::string receiver_type;
        std::vector<std::string> receiver_names;
        std::vector<std::string> receiver_channels;
        std::string start_time;
        std::string end_time;
        std::string webhook;
    };
    /**
     * @param type 执行周期类型，Period：周期执行，Fixed：定期执行
     * @param time 告警任务执行的周期，或者定期执行的时间点。单位为分钟，取值范围为 1~1440
     */
    struct RequestCycle {
        std::string type;
        int time;
    };
/**
 * @param topic_id 日志主题 ID
 * @param topic_name 日志主题名称
 * @param query 查询语句，支持的最大长度为 1024
 * @param number 告警对象序号；从 1 开始递增
 * @param start_time_offset 查询范围起始时间相对当前的历史时间，单位为分钟，取值为非正，最大值为 0，最小值为 -1440
 * @param end_time_offset 查询范围终止时间相对当前的历史时间，单位为分钟，取值为非正，须大于StartTimeOffset，最大值为 0，最小值为 -1440
 */
    struct QueryRequest {
        std::string topic_id;
        std::string topic_name;
        std::string query;
        int number;
        int start_time_offset;
        int end_time_offset;
    };

    struct Advanced {
        int close_inactive;
        bool close_removed;
        bool close_renamed;
        bool close_e_o_f;
        int close_timeout;
    };

    struct AlarmNotifyGroupInfo {
        std::string alarm_notify_group_name;
        std::string alarm_notify_group_id;
        std::vector<std::string> notify_type;
        std::vector<Receiver> receiver;
        std::string create_time;
        std::string modify_time;
    };

    struct AlarmInfo {
        std::string name;
        std::string alarm_id;
        std::string project_id;
        bool status;
        std::vector<QueryRequest> query_request;
        RequestCycle request_cycle;
        std::string condition;
        int trigger_period;
        int alarm_period;
        std::vector<AlarmNotifyGroupInfo> alarm_notify_group;
        std::string user_define_msg;
        std::string create_time;
        std::string modify_time;
    };

    struct AnalysisResult {
        std::vector<std::string> schema;
        std::map<std::string, std::string> type;
        std::vector<std::map<std::string, std::string>> data;
    };
/**
 * @param stream 采集模式
 * @param container_name_regex 待采集的容器名称
 * @param include_container_label_regex 指定待采集的容器，不启用白名单时指定采集全部容器
 * @param exclude_container_label_regex Label 黑名单用于指定不采集的容器范围，不启用黑名单时表示采集全部容器
 * @param include_container_env_regex 容器环境变量白名单通过容器环境变量指定待采集的容器，不启用白名单时表示指定采集全部容器
 * @param exclude_container_env_regex 容器环境变量黑名单用于指定不采集的容器范围，不启用黑名单时表示采集全部容器
 * @param env_tag 是否将环境变量作为日志标签，添加到原始日志数据中
 * @param kubernetes_rule Kubernetes 容器的采集规则
 */
    struct ContainerRule {
        std::string stream;
        std::string container_name_regex;
        std::map<std::string, std::string> include_container_label_regex;
        std::map<std::string, std::string> exclude_container_label_regex;
        std::map<std::string, std::string> include_container_env_regex;
        std::map<std::string, std::string> exclude_container_env_regex;
        std::map<std::string, std::string> env_tag;
        KubernetesRule kubernetes_rule;
    };
    /**
     * @param type  采集路径类型，File或Path
     * @param value 采集绝对路径
     */
    struct ExcludePath {
        std::string type;
        std::string value;
    };
    /**
     * @param key   过滤字段的名称
     * @param regex 过滤字段的日志内容需要匹配的正则表达式
     */
    struct FilterKeyRegex {
        std::string key;
        std::string regex;
    };
/**
 * @param delimiter 日志分隔符
 * @param begin_regex 第一行日志需要匹配的正则表达式
 * @param log_regex 整条日志需要匹配的正则表达式
 * @param keys 日志字段名称
 * @param time_key 日志时间字段的字段名称
 * @param time_format 时间字段的解析格式
 * @param filter_key_regex 过滤规则列表
 * @param un_match_up_load_switch 是否上传解析失败的日志
 * @param log_template 根据指定的日志模板自动提取日志字段
 * @param un_match_log_key 当上传解析失败的日志时，解析失败的日志的 key 名称
 */
    struct ExtractRule {
        std::string delimiter;
        std::string begin_regex;
        std::string log_regex;
        std::vector<std::string> keys;
        std::string time_key;
        std::string time_format;
        std::vector<FilterKeyRegex> filter_key_regex;
        bool un_match_up_load_switch;
        std::string un_match_log_key;
        LogTemplate log_template;
    };
    /**
     * @param case_sensitive  是否大小写敏感
     * @param delimiter      全文索引的分词符
     * @param include_chinese 是否包含中文
     */
    struct FullTextInfo {
        bool case_sensitive;
        std::string delimiter;
        bool include_chinese;
    };

    struct HistogramInfo {
        int time;
        int count;
    };

    struct HostGroupInfo {
        std::string host_group_id;
        std::string host_group_name;
        std::string host_group_type;
        std::string host_identifier;
        int host_count;
        int normal_heartbeat_status_count;
        int abnormal_heartbeat_status_count;
        int rule_count;
        std::string create_time;
        std::string modify_time;
        bool auto_update;
        std::string update_start_time;
        std::string update_end_time;
        std::string agent_latest_version;
        bool service_logging;
    };

    struct ParsePathRule {
        std::string path_sample;
        std::string regex;
        std::vector<std::string> keys;
    };

    struct ShardHashKey {
        std::string hash_key;
    };

    struct Plugin {
        std::vector<std::map<std::string, std::string>> processors;
    };
    /**
     * @param parse_path_rule 解析采集路径的规则
     * @param shard_hash_key  路由日志分区的规则
     * @param enable_raw_log  是否上传原始日志
     * @param plugin        LogCollector 插件配置
     * @param advanced       LogCollector 扩展配置
     * @param tail_files       LogCollector 采集策略，即指定 LogCollector 采集增量日志还是全量日志
     */
    struct UserDefineRule {
        ParsePathRule parse_path_rule;
        ShardHashKey shard_hash_key;
        bool enable_raw_log;
        std::map<std::string, std::string> fields;
        Plugin plugin;
        Advanced advanced;
        bool tail_files;
    };

    struct RuleInfo {
        std::string topic_id;
        std::string topic_name;
        std::string rule_id;
        std::string rule_name;
        std::vector<std::string> paths;
        std::string log_type;
        ExtractRule extract_rule;
        std::vector<ExcludePath> exclude_paths;
        std::string log_sample;
        UserDefineRule user_define_rule;
        std::string create_time;
        std::string modify_time;
        int input_type;
        ContainerRule container_rule;
    };

    struct HostGroupHostsRulesInfo {
        HostGroupInfo host_group_info;
        std::vector<HostInfo> host_infos;
        std::vector<RuleInfo> rule_infos;
    };

    struct KeyValueInfo;
    struct ValueInfo {
        std::string value_type;
        std::string delimiter;
        bool case_sensitive;
        bool include_chinese;
        bool sql_flag;
        std::vector<KeyValueInfo> json_keys;
    };
    /**
     * @param key   需要配置键值索引的字段名称
     * @param value 需要配置键值索引的字段描述信息
     */
    struct KeyValueInfo {
        std::string key;
        ValueInfo value;
    };

    class ProjectInfo {
    public:
        std::string project_name;
        std::string project_id;
        std::string description;
        std::string create_time;
        std::string inner_net_domain;
        int topic_count;
    };

    struct QueryResp {
        std::string topic_id;
        int shard_id;
        std::string inclusive_begin_key;
        std::string exclusive_end_key;
        std::string status;
        std::string modify_time;
        std::string stop_write_time;
    };

    struct TaskInfo {
        std::string task_id;
        std::string task_name;
        std::string topic_id;
        std::string query;
        std::string start_time;
        std::string end_time;
        std::string data_format;
        std::string task_status;
        std::string compression;
        std::string create_time;
        int64_t log_size;
        int64_t log_count;
    };

    struct TopicInfo {
        std::string topic_name;
        std::string project_id;
        std::string topic_id;
        int ttl;
        std::string create_time;
        std::string modify_time;
        int shard_count;
        std::string description;
        bool auto_split;
        int max_split_shard;
        bool enable_tracking;
        std::string time_key;
        std::string time_format;
    };

    struct LogItem {
        long long time;
        std::map<std::string, std::string> log_content;
    };

} // namespace