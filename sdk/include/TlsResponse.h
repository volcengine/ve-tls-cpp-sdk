#pragma once

#include <string>
#include <vector>
#include <map>
#include "TlsModel.h"
#include "Tls.pb.h"
#include "thirdparty/nlohmann/json.hpp"

namespace VolcengineTls {

class TlsResponse {
public:
    std::string request_id;
    std::string error_code;
    std::string error_message;
    int http_status_code;
};

class CreateProjectResponse : public TlsResponse {
public:
    std::string project_id;
};

class DeleteProjectResponse : public TlsResponse {
public:
};

class ModifyProjectResponse : public TlsResponse {
public:
};

class DescribeProjectResponse : public TlsResponse {
public:
    std::string project_name;
    std::string project_id;
    std::string description;
    std::string create_time;
    std::string inner_net_domain;
    int topic_count;
};

class DescribeProjectsResponse : public TlsResponse {
public:
    int total;
    std::vector<ProjectInfo> projects;
};

class CreateTopicResponse : public TlsResponse {
public:
    std::string topic_id;
};

class DeleteTopicResponse : public TlsResponse {
};

class ModifyTopicResponse : public TlsResponse {
};

class DescribeTopicResponse : public TlsResponse {
public:
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

class DescribeTopicsResponse : public TlsResponse {
public:
    int total;
    std::vector<TopicInfo> topics;
};

class DescribeShardsResponse : public TlsResponse {
public:
    int total;
    std::vector<QueryResp> shards;
};

class CreateIndexResponse : public TlsResponse {
public:
    std::string topic_id;
};

class DeleteIndexResponse : public TlsResponse {
};

class ModifyIndexResponse : public TlsResponse {
};

class DescribeIndexResponse : public TlsResponse {
public:
    std::string topic_id;
    FullTextInfo full_text;
    std::vector<KeyValueInfo> key_value;
    std::string create_time;
    std::string modify_time;
};

class PutLogsResponse : public TlsResponse {
};

class PutLogsV2Response : public PutLogsResponse {
public:
    PutLogsV2Response(){}
    PutLogsV2Response(const PutLogsResponse& r) : PutLogsResponse(r) {}
};

class DescribeCursorResponse : public TlsResponse {
public:
    std::string cursor;
};

class ConsumeLogsResponse : public TlsResponse {
public:
    std::string cursor;
    std::string count;
    pb::LogGroupList log_group_list;
};

class SearchLogsResponse : public TlsResponse {
public:
    std::string result_status;
    int hit_count;
    bool list_over;
    bool analysis;
    int count;
    int limit;
    std::string context;
    nlohmann::json logs;
    AnalysisResult analysis_result;
};

class DescribeLogContextResponse : public TlsResponse {
public:
    nlohmann::json log_context_infos;
    bool prev_over;
    bool next_over;
};

class DescribeHistogramResponse : public TlsResponse {
public:
    std::string result_status;
    int interval;
    int total_count;
    std::vector<HistogramInfo> histogram_infos;
};

class WebTracksResponse : public TlsResponse {
};

class CreateDownloadTaskResponse : public TlsResponse {
public:
    std::string task_id;
};

class DescribeDownloadTasksResponse : public TlsResponse {
public:
    int total;
    std::vector<TaskInfo> tasks;
};

class DescribeDownloadUrlResponse : public TlsResponse {
public:
    std::string download_url;
};

class CreateHostGroupResponse : public TlsResponse {
public:
    std::string host_group_id;
};

class DeleteHostGroupResponse : public TlsResponse {
};

class ModifyHostGroupResponse : public TlsResponse {
};

class DescribeHostGroupsResponse : public TlsResponse {
public:
    int total;
    std::vector<HostGroupHostsRulesInfo> host_group_hosts_rules_infos;
};

class DescribeHostGroupResponse : public TlsResponse {
public:
    HostGroupHostsRulesInfo host_group_hosts_rules_info;
};

class DescribeHostsResponse : public TlsResponse {
public:
    int total;
    std::vector<HostInfo> host_infos;
};

class DeleteHostResponse : public TlsResponse {
};

class DescribeHostGroupRulesResponse : public TlsResponse {
public:
    int total;
    std::vector<RuleInfo> rule_infos;
};

class ModifyHostGroupsAutoUpdateResponse : public TlsResponse {
};

class DeleteAbnormalHostsResponse : public TlsResponse {
};

class CreateRuleResponse : public TlsResponse {
public:
    std::string rule_id;
};

class DeleteRuleResponse : public TlsResponse {
};

class ModifyRuleResponse : public TlsResponse {
};

class DescribeRuleResponse : public TlsResponse {
public:
    std::string project_id;
    std::string project_name;
    std::string topic_id;
    std::string topic_name;
    RuleInfo rule_info;
    std::vector<HostGroupInfo> host_group_infos;
};

class DescribeRulesResponse : public TlsResponse {
public:
    int total;
    std::vector<RuleInfo> rule_infos;
};

class ApplyRuleToHostGroupsResponse : public TlsResponse {
};

class DeleteRuleFromHostGroupsResponse : public TlsResponse {
};

class CreateAlarmNotifyGroupResponse : public TlsResponse {
public:
    std::string alarm_notify_group_id;
};

class DeleteAlarmNotifyGroupResponse : public TlsResponse {
};

class ModifyAlarmNotifyGroupResponse : public TlsResponse {
};

class DescribeAlarmNotifyGroupsResponse : public TlsResponse {
public:
    int total;
    std::vector<AlarmNotifyGroupInfo> alarm_notify_groups;
};

class CreateAlarmResponse : public TlsResponse {
public:
    std::string alarm_id;
};

class DeleteAlarmResponse : public TlsResponse {
};

class ModifyAlarmResponse : public TlsResponse {
};

class DescribeAlarmsResponse : public TlsResponse {
public:
    int total;
    std::vector<AlarmInfo> alarms;
};

class OpenKafkaConsumerResponse : public TlsResponse {
};

class CloseKafkaConsumerResponse : public TlsResponse {
};

class DescribeKafkaConsumerResponse : public TlsResponse {
public:
    bool allow_consume;
    std::string consume_topic;
};


} // Namespace