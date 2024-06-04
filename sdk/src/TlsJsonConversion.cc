#include "TlsJsonConversion.h"
#include "thirdparty/nlohmann/json.hpp"

namespace VolcengineTls {
    // Model
    COMMON_JSON_DEF(HostInfo, ip, log_collector_version, heartbeat_status)
    COMMON_JSON_DEF(LogTemplate, type, format)
    COMMON_JSON_DEF(KubernetesRule, namespace_name_regex, workload_type, workload_name_regex, include_pod_label_regex, exclude_pod_label_regex, pod_name_regex, annotation_tag, label_tag)
    COMMON_JSON_DEF(Receiver, receiver_type, receiver_names, receiver_channels, start_time, end_time)
    COMMON_JSON_DEF(RequestCycle, type, time)
    COMMON_JSON_DEF(QueryRequest, topic_id, topic_name, query, number, start_time_offset, end_time_offset)
    COMMON_JSON_DEF(Advanced, close_inactive, close_removed, close_renamed, close_e_o_f, close_timeout)
    COMMON_JSON_DEF(AlarmNotifyGroupInfo, alarm_notify_group_name, alarm_notify_group_id, notify_type, receiver, create_time, modify_time)
    COMMON_JSON_DEF(AlarmInfo, alarm_id, project_id, status, query_request, request_cycle, condition, trigger_period, alarm_period, alarm_notify_group, user_define_msg, create_time, modify_time)
    COMMON_JSON_DEF(AnalysisResult, schema, type, data)
    COMMON_JSON_DEF(ContainerRule, stream, container_name_regex, include_container_label_regex, exclude_container_label_regex, include_container_env_regex, exclude_container_env_regex, env_tag, kubernetes_rule)
    COMMON_JSON_DEF(ExcludePath, type, value)
    COMMON_JSON_DEF(FilterKeyRegex, key, regex)
    COMMON_JSON_DEF(ExtractRule, delimiter, begin_regex, log_regex, keys, time_key, time_format, filter_key_regex, un_match_up_load_switch, un_match_log_key, log_template)
    COMMON_JSON_DEF(FullTextInfo, case_sensitive, delimiter, include_chinese)
    COMMON_JSON_DEF(HistogramInfo, time, count)
    COMMON_JSON_DEF(HostGroupInfo, host_group_id, host_group_name, host_group_type, host_identifier, host_count, normal_heartbeat_status_count, abnormal_heartbeat_status_count, rule_count, create_time, modify_time, auto_update, update_start_time, update_end_time, agent_latest_version, service_logging)
    COMMON_JSON_DEF(ParsePathRule, path_sample, regex, keys)
    COMMON_JSON_DEF(ShardHashKey, hash_key)
    COMMON_JSON_DEF(Plugin, processors)
    COMMON_JSON_DEF(UserDefineRule, parse_path_rule, shard_hash_key, enable_raw_log, fields, plugin, advanced, tail_files)
    COMMON_JSON_DEF(RuleInfo, topic_id, topic_name, rule_id, rule_name, paths, log_type, extract_rule, exclude_paths, log_sample, user_define_rule, create_time, modify_time, input_type, container_rule)
    COMMON_JSON_DEF(HostGroupHostsRulesInfo, host_group_info, host_infos, rule_infos)
    COMMON_JSON_DEF(ValueInfo, value_type, delimiter, case_sensitive, include_chinese, sql_flag, json_keys)
    COMMON_JSON_DEF(KeyValueInfo, key, value)
    COMMON_JSON_DEF(ProjectInfo, project_name, project_id, description, create_time, inner_net_domain, topic_count)
    COMMON_JSON_DEF(QueryResp, topic_id, shard_id, inclusive_begin_key, exclusive_end_key, status, modify_time)
    COMMON_JSON_DEF(TaskInfo, task_id, task_name, topic_id, query, start_time, end_time, data_format, task_status, compression, create_time, log_size, log_count)
    COMMON_JSON_DEF(TopicInfo, topic_name, project_id, topic_id, ttl, create_time, modify_time, shard_count, description, auto_split, max_split_shard, enable_tracking, time_key, time_format)

    COMMON_JSON_DEF(TlsResponse, error_code, error_message, request_id, http_status_code)

    // Project
    COMMON_JSON_DEF(CreateProjectResponse, error_code, error_message, request_id, http_status_code, project_id)
    COMMON_JSON_DEF(DeleteProjectResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(ModifyProjectResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeProjectResponse, error_code, error_message, request_id, http_status_code, project_name, project_id, description, create_time, inner_net_domain, topic_count)
    COMMON_JSON_DEF(DescribeProjectsResponse, error_code, error_message, request_id, http_status_code, total, projects)

    // Topic
    COMMON_JSON_DEF(CreateTopicResponse, error_code, error_message, request_id, http_status_code, topic_id)
    COMMON_JSON_DEF(DeleteTopicResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(ModifyTopicResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeTopicResponse, error_code, error_message, request_id, http_status_code, topic_name, project_id, topic_id, ttl, create_time, modify_time, shard_count, description, auto_split, max_split_shard, enable_tracking, time_key, time_format)
    COMMON_JSON_DEF(DescribeTopicsResponse, error_code, error_message, request_id, http_status_code, total, topics)

    // Shard
    COMMON_JSON_DEF(DescribeShardsResponse, error_code, error_message, request_id, http_status_code, total, shards)

    // Index
    COMMON_JSON_DEF(CreateIndexResponse, error_code, error_message, request_id, http_status_code, topic_id)
    COMMON_JSON_DEF(DeleteIndexResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(ModifyIndexResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeIndexResponse, error_code, error_message, request_id, http_status_code, topic_id, full_text, key_value, create_time, modify_time)

    // Log
    COMMON_JSON_DEF(PutLogsResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(PutLogsV2Response, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeCursorResponse, error_code, error_message, request_id, http_status_code, cursor)
    COMMON_JSON_DEF(ConsumeLogsResponse, error_code, error_message, request_id, http_status_code, cursor, count)
    COMMON_JSON_DEF(SearchLogsResponse, error_code, error_message, request_id, http_status_code, result_status, hit_count, list_over, analysis, count, limit, context, logs, analysis_result)
    COMMON_JSON_DEF(SearchLogsV2Response, error_code, error_message, request_id, http_status_code, result_status, hit_count, list_over, analysis, count, limit, context, logs, analysis_result)
    COMMON_JSON_DEF(DescribeLogContextResponse, error_code, error_message, request_id, http_status_code, log_context_infos, prev_over, next_over)
    COMMON_JSON_DEF(DescribeHistogramResponse, error_code, error_message, request_id, http_status_code, result_status, interval, total_count, histogram_infos)
    COMMON_JSON_DEF(WebTracksResponse, error_code, error_message, request_id, http_status_code)
    
    // Download task
    COMMON_JSON_DEF(CreateDownloadTaskResponse, error_code, error_message, request_id, http_status_code, task_id)
    COMMON_JSON_DEF(DescribeDownloadTasksResponse, error_code, error_message, request_id, http_status_code, total, tasks)
    COMMON_JSON_DEF(DescribeDownloadUrlResponse, error_code, error_message, request_id, http_status_code, download_url)

    // Host group
    COMMON_JSON_DEF(CreateHostGroupResponse, error_code, error_message, request_id, http_status_code, host_group_id)
    COMMON_JSON_DEF(DeleteHostGroupResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(ModifyHostGroupResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeHostGroupsResponse, error_code, error_message, request_id, http_status_code, total, host_group_hosts_rules_infos)
    COMMON_JSON_DEF(DescribeHostGroupResponse, error_code, error_message, request_id, http_status_code, host_group_hosts_rules_info)
    COMMON_JSON_DEF(DescribeHostsResponse, error_code, error_message, request_id, http_status_code, total, host_infos)
    COMMON_JSON_DEF(DeleteHostResponse, error_code,  error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeHostGroupRulesResponse, error_code, error_message, request_id, http_status_code, total, rule_infos)
    COMMON_JSON_DEF(ModifyHostGroupsAutoUpdateResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DeleteAbnormalHostsResponse, error_code, error_message, request_id, http_status_code)

    // Rule
    COMMON_JSON_DEF(CreateRuleResponse, error_code, error_message, request_id, http_status_code, rule_id)
    COMMON_JSON_DEF(DeleteRuleResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(ModifyRuleResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeRuleResponse, error_code, error_message, request_id, http_status_code, project_id, project_name, topic_id, topic_name, rule_info, host_group_infos)
    COMMON_JSON_DEF(DescribeRulesResponse, error_code, error_message, request_id, http_status_code, total, rule_infos)
    COMMON_JSON_DEF(ApplyRuleToHostGroupsResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DeleteRuleFromHostGroupsResponse, error_code, error_message, request_id, http_status_code)

    // Alarm notify
    COMMON_JSON_DEF(CreateAlarmNotifyGroupResponse, error_code, error_message, request_id, http_status_code, alarm_notify_group_id)
    COMMON_JSON_DEF(DeleteAlarmNotifyGroupResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(ModifyAlarmNotifyGroupResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeAlarmNotifyGroupsResponse, error_code, error_message, request_id, http_status_code, total, alarm_notify_groups)

    // Alarm
    COMMON_JSON_DEF(CreateAlarmResponse, error_code, error_message, request_id, http_status_code, alarm_id)
    COMMON_JSON_DEF(DeleteAlarmResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(ModifyAlarmResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeAlarmsResponse, error_code, error_message, request_id, http_status_code, total, alarms)

    // Kafka consumer
    COMMON_JSON_DEF(OpenKafkaConsumerResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(CloseKafkaConsumerResponse, error_code, error_message, request_id, http_status_code)
    COMMON_JSON_DEF(DescribeKafkaConsumerResponse, error_code, error_message, request_id, http_status_code, allow_consume, consume_topic)
}
