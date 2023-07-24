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
    
};

class CreateProjectRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> project_name;
    std::shared_ptr<std::string> region;
    std::shared_ptr<std::string> description;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateProjectRequest)
};

class DeleteProjectRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> project_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteProjectRequest)
};

class ModifyProjectRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> project_id;
    std::shared_ptr<std::string> project_name;
    std::shared_ptr<std::string> description;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyProjectRequest)
};

class DescribeProjectRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> project_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeProjectRequest)
};

class DescribeProjectsRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> project_id;
    std::shared_ptr<std::string> project_name;
    std::shared_ptr<bool> is_full_name;
    std::shared_ptr<int> page_number;
    std::shared_ptr<int> page_size;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeProjectsRequest)
};

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

class DeleteTopicRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteTopicRequest)
};

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

class DescribeTopicRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeTopicRequest)
};

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

class DescribeShardsRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<int> page_number;
    std::shared_ptr<int> page_size;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeShardsRequest)
};

class CreateIndexRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<FullTextInfo> full_text;
    std::shared_ptr<std::vector<KeyValueInfo>> key_value;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateIndexRequest)
};

class DeleteIndexRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteIndexRequest)
};

class ModifyIndexRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<FullTextInfo> full_text;
    std::shared_ptr<std::vector<KeyValueInfo>> key_value;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyIndexRequest)
};

class DescribeIndexRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeIndexRequest)
};

class PutLogsRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<std::string> hash_key;
    std::shared_ptr<std::string> compression;
    std::shared_ptr<pb::LogGroupList> log_group_list;
    TLS_REQUEST_COMMON_METHOD_DECLARATION(PutLogsRequest)
};

class PutLogsV2Request : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<std::string> hash_key;
    std::shared_ptr<std::string> compression;
    std::shared_ptr<std::string> source;
    std::shared_ptr<std::string> filename;
    std::shared_ptr<std::vector<LogItem>> logs;
};

class DescribeCursorRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<int> shard_id;
    std::shared_ptr<std::string> from;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeCursorRequest)
};

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

class DescribeHistogramRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<std::string> query;
    std::shared_ptr<int> start_time;
    std::shared_ptr<int> end_time;
    std::shared_ptr<int> interval;
    
    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHistogramRequest)
};

class WebTracksRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> project_id;
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<std::vector<std::map<std::string, std::string>>> logs;
    std::shared_ptr<std::string> source;
    std::shared_ptr<std::string> compression;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(WebTracksRequest)
};

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

class DescribeDownloadTasksRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;
    std::shared_ptr<int> page_number;
    std::shared_ptr<int> page_size;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeDownloadTasksRequest)
};

class DescribeDownloadUrlRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> task_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeDownloadUrlRequest)
};

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

class DeleteHostGroupRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> host_group_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteHostGroupRequest)
};

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

class DescribeHostGroupRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> host_group_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHostGroupRequest)
};

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

class DescribeHostsRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> host_group_id;
    std::shared_ptr<std::string> ip;
    std::shared_ptr<int> heartbeat_status;
    std::shared_ptr<int> page_number;
    std::shared_ptr<int> page_size;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHostsRequest)
};

class DeleteHostRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> host_group_id;
    std::shared_ptr<std::string> ip;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteHostRequest)
};

class DescribeHostGroupRulesRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> host_group_id;
    std::shared_ptr<int> page_number;
    std::shared_ptr<int> page_size;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeHostGroupRulesRequest)
};

class ModifyHostGroupsAutoUpdateRequest : public TlsRequest {
public:
    std::shared_ptr<std::vector<std::string>> host_group_ids;
    std::shared_ptr<bool> auto_update;
    std::shared_ptr<std::string> update_start_time;
    std::shared_ptr<std::string> update_end_time;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyHostGroupsAutoUpdateRequest)
};

class DeleteAbnormalHostsRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> host_group_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteAbnormalHostsRequest)
};

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

class DeleteRuleRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> rule_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteRuleRequest)
};

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

class DescribeRuleRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> rule_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeRuleRequest)
};

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

class ApplyRuleToHostGroupsRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> rule_id;
    std::shared_ptr<std::vector<std::string>> host_group_ids;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(ApplyRuleToHostGroupsRequest)
};

class DeleteRuleFromHostGroupsRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> rule_id;
    std::shared_ptr<std::vector<std::string>> host_group_ids;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteRuleFromHostGroupsRequest)
};

class CreateAlarmNotifyGroupRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> alarm_notify_group_name;
    std::shared_ptr<std::vector<std::string>> notify_type;
    std::shared_ptr<std::vector<Receiver>> receivers;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(CreateAlarmNotifyGroupRequest)
};

class DeleteAlarmNotifyGroupRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> alarm_notify_group_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteAlarmNotifyGroupRequest)
};

class ModifyAlarmNotifyGroupRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> alarm_notify_group_id;
    std::shared_ptr<std::string> alarm_notify_group_name;
    std::shared_ptr<std::vector<std::string>> notify_type;
    std::shared_ptr<std::vector<Receiver>> receivers;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(ModifyAlarmNotifyGroupRequest)
};

class DescribeAlarmNotifyGroupsRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> alarm_notify_group_name;
    std::shared_ptr<std::string> alarm_notify_group_id;
    std::shared_ptr<std::string> receiver_name;
    std::shared_ptr<int> page_number;
    std::shared_ptr<int> page_size;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeAlarmNotifyGroupsRequest)
};

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

class DeleteAlarmRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> alarm_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DeleteAlarmRequest)
};

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

class OpenKafkaConsumerRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(OpenKafkaConsumerRequest)
};

class CloseKafkaConsumerRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(CloseKafkaConsumerRequest)
};

class DescribeKafkaConsumerRequest : public TlsRequest {
public:
    std::shared_ptr<std::string> topic_id;

    TLS_REQUEST_COMMON_METHOD_DECLARATION(DescribeKafkaConsumerRequest)
};


} // Namespace