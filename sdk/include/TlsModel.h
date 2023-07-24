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

struct LogTemplate {
    std::string type;
    std::string format;
};

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

struct RequestCycle {
    std::string type;
    int time;
};

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

struct ExcludePath {
    std::string type;
    std::string value;
};

struct FilterKeyRegex {
    std::string key;
    std::string regex;
};

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