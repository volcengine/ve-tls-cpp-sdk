#include <map>
#include <string>
#include <vector>
#include "TlsModel.h"
#include "TlsRequest.h"
#include "thirdparty/nlohmann/json.hpp"
#include "TlsJsonConversion.h"
#include "utils/HeaderUtils.h"

namespace VolcengineTls {

    // CreateProjectRequest
    bool CreateProjectRequest::CheckValidation() {
        return this->project_name == nullptr ? false:
            this->region == nullptr ? false : true;
    }
    std::string CreateProjectRequest::Method() {
        return "POST";
    }
    std::string CreateProjectRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CreateProjectRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CreateProjectRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CreateProjectRequest, project_name, region, description)
    
    // DeleteProjectRequest
    bool DeleteProjectRequest::CheckValidation() {
        return true;
    }
    std::string DeleteProjectRequest::Method() {
        return "DELETE";
    }
    std::string DeleteProjectRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteProjectRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteProjectRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteProjectRequest, project_id)

    // ModifyProjectRequest
    bool ModifyProjectRequest::CheckValidation() {
        return this->project_id == nullptr ? false :
            true;
    }
    std::string ModifyProjectRequest::Method() {
        return "PUT";
    }
    std::string ModifyProjectRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ModifyProjectRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ModifyProjectRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ModifyProjectRequest, project_id, project_name, description)

    // DescribeProjectRequest
    bool DescribeProjectRequest::CheckValidation() {
        return this->project_id == nullptr ? false :
            true;
    }
    std::string DescribeProjectRequest::Method() {
        return "GET";
    }
    std::string DescribeProjectRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeProjectRequest, project_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeProjectRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeProjectRequest)    

    // DescribeProjectsRequest
    bool DescribeProjectsRequest::CheckValidation() {
        return true;
    }
    std::string DescribeProjectsRequest::Method() {
        return "GET";
    }
    std::string DescribeProjectsRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeProjectsRequest, project_id, project_name, is_full_name, page_number, page_size)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeProjectsRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeProjectsRequest)

    // CreateTopicRequest
    bool CreateTopicRequest::CheckValidation() {
        return this->topic_name == nullptr ? false :
            this->project_id == nullptr ? false :
            this->ttl == nullptr ? false :
            this->shard_count == nullptr ? false :
            true;
    }
    std::string CreateTopicRequest::Method() {
        return "POST";
    }
    std::string CreateTopicRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CreateTopicRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CreateTopicRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CreateTopicRequest, topic_name, project_id, ttl, shard_count, auto_split, max_split_shard, enable_tracking, time_key, time_format, description)   

    // DeleteTopicRequest
    bool DeleteTopicRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string DeleteTopicRequest::Method() {
        return "DELETE";
    }
    std::string DeleteTopicRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteTopicRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteTopicRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteTopicRequest, topic_id)  

    // ModifyTopicRequest
    bool ModifyTopicRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string ModifyTopicRequest::Method() {
        return "PUT";
    }
    std::string ModifyTopicRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ModifyTopicRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ModifyTopicRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ModifyTopicRequest, topic_id, topic_name, ttl, auto_split, max_split_shard, enable_tracking, time_key, time_format, description) 

    // DescribeTopicRequest
    bool DescribeTopicRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string DescribeTopicRequest::Method() {
        return "GET";
    }
    std::string DescribeTopicRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeTopicRequest, topic_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeTopicRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeTopicRequest) 

    // DescribeTopicsRequest
    bool DescribeTopicsRequest::CheckValidation() {
        return this->project_id == nullptr ? false : true;
    }
    std::string DescribeTopicsRequest::Method() {
        return "GET";
    }
    std::string DescribeTopicsRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeTopicsRequest, project_id, page_number, page_size, topic_name, is_full_name, topic_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeTopicsRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeTopicsRequest)

    // DescribeShardsRequest
    bool DescribeShardsRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string DescribeShardsRequest::Method() {
        return "GET";
    }
    std::string DescribeShardsRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeShardsRequest, topic_id, page_number, page_size)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeShardsRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeShardsRequest) 

    // CreateIndexRequest
    bool CreateIndexRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string CreateIndexRequest::Method() {
        return "POST";
    }
    std::string CreateIndexRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CreateIndexRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CreateIndexRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CreateIndexRequest, topic_id, full_text, key_value)

    // DeleteIndexRequest
    bool DeleteIndexRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string DeleteIndexRequest::Method() {
        return "DELETE";
    }
    std::string DeleteIndexRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteIndexRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteIndexRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteIndexRequest, topic_id) 

    // ModifyIndexRequest
    bool ModifyIndexRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string ModifyIndexRequest::Method() {
        return "PUT";
    }
    std::string ModifyIndexRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ModifyIndexRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ModifyIndexRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ModifyIndexRequest, topic_id, full_text, key_value) 

    // DescribeIndexRequest
    bool DescribeIndexRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string DescribeIndexRequest::Method() {
        return "GET";
    }
    std::string DescribeIndexRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeIndexRequest, topic_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeIndexRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeIndexRequest) 

    bool PutLogsRequest::CheckValidation() {
        return this->topic_id == nullptr ? false :
            this->log_group_list == nullptr ? false : true;
    }
    std::string PutLogsRequest::Method() {
        return "POST";
    }
    std::string PutLogsRequest::ContentType() {
        return "application/protobuf";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(PutLogsRequest, topic_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(PutLogsRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(PutLogsRequest)

    // DescribeCursorRequest 
    bool DescribeCursorRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : 
            this->shard_id == nullptr ? false :
            this->from == nullptr ? false : true;
    }
    std::string DescribeCursorRequest::Method() {
        return "GET";
    }
    std::string DescribeCursorRequest::ContentType() {
        return "application/json";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeCursorRequest, topic_id, shard_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeCursorRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DescribeCursorRequest, from)

    // ConsumeLogsRequest
    bool ConsumeLogsRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : 
            this->shard_id == nullptr ? false :
            this->cursor == nullptr ? false : true;
    }
    std::string ConsumeLogsRequest::Method() {
        return "GET";
    }
    std::string ConsumeLogsRequest::ContentType() {
        return "application/json";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(ConsumeLogsRequest, topic_id, shard_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ConsumeLogsRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ConsumeLogsRequest, cursor, end_cursor, log_group_count, compression) 

    // SearchLogsRequest
    bool SearchLogsRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : 
            this->query == nullptr ? false :
            this->start_time == nullptr ? false :
            this->end_time == nullptr ? false : true;
    }
    std::string SearchLogsRequest::Method() {
        return "POST";
    }
    std::string SearchLogsRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(SearchLogsRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(SearchLogsRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(SearchLogsRequest, topic_id, query, start_time, end_time, limit, context, sort) 

    // DescribeLogContextRequest
    bool DescribeLogContextRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : 
            this->context_flow == nullptr ? false :
            this->package_offset == nullptr ? false :
            this->source == nullptr ? false : true;
    }
    std::string DescribeLogContextRequest::Method() {
        return "POST";
    }
    std::string DescribeLogContextRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DescribeLogContextRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeLogContextRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DescribeLogContextRequest, topic_id, context_flow, package_offset, source, prev_logs, next_logs) 

    // DescribeHistogramRequest
    bool DescribeHistogramRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : 
            this->query == nullptr ? false :
            this->start_time == nullptr ? false :
            this->end_time == nullptr ? false : true;
    }
    std::string DescribeHistogramRequest::Method() {
        return "POST";
    }
    std::string DescribeHistogramRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DescribeHistogramRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeHistogramRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DescribeHistogramRequest, topic_id, query, start_time, end_time, interval) 

    // WebTracksRequest TODO: 单独实现 WebTracks
    bool WebTracksRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : 
            this->project_id == nullptr ? false :
            this->logs == nullptr ? false : true;
    }
    std::string WebTracksRequest::Method() {
        return "POST";
    }
    std::string WebTracksRequest::ContentType() {
        return "application/json";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(WebTracksRequest, project_id, topic_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(WebTracksRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(WebTracksRequest, source, logs) 

    // CreateDownloadTaskRequest
    bool CreateDownloadTaskRequest::CheckValidation() {
        return this->task_name == nullptr ? false : 
            this->topic_id == nullptr ? false :
            this->query == nullptr ? false :
            this->start_time == nullptr ? false :
            this->end_time == nullptr ? false :
            this->data_format == nullptr ? false :
            this->sort == nullptr ? false :
            this->limit == nullptr ? false :
            this->compression == nullptr ? false : true;
    }
    std::string CreateDownloadTaskRequest::Method() {
        return "POST";
    }
    std::string CreateDownloadTaskRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CreateDownloadTaskRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CreateDownloadTaskRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CreateDownloadTaskRequest, task_name, topic_id, query, start_time, end_time, data_format, sort, limit, compression)

    // DescribeDownloadTasksRequest
    bool DescribeDownloadTasksRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string DescribeDownloadTasksRequest::Method() {
        return "GET";
    }
    std::string DescribeDownloadTasksRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeDownloadTasksRequest, topic_id, page_number, page_size)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeDownloadTasksRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeDownloadTasksRequest) 

    // DescribeDownloadUrlRequest
    bool DescribeDownloadUrlRequest::CheckValidation() {
        return this->task_id == nullptr ? false : true;
    }
    std::string DescribeDownloadUrlRequest::Method() {
        return "GET";
    }
    std::string DescribeDownloadUrlRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeDownloadUrlRequest, task_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeDownloadUrlRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeDownloadUrlRequest) 

    // CreateHostGroupRequest
    bool CreateHostGroupRequest::CheckValidation() {
        return true;
    }
    std::string CreateHostGroupRequest::Method() {
        return "POST";
    }
    std::string CreateHostGroupRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CreateHostGroupRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CreateHostGroupRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CreateHostGroupRequest, host_group_name, host_group_type, host_ip_list, host_identifier, auto_update, update_start_time, update_end_time, service_logging)

    // DeleteHostGroupRequest
    bool DeleteHostGroupRequest::CheckValidation() {
        return this->host_group_id == nullptr ? false : true;
    }
    std::string DeleteHostGroupRequest::Method() {
        return "DELETE";
    }
    std::string DeleteHostGroupRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteHostGroupRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteHostGroupRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteHostGroupRequest, host_group_id)

    // ModifyHostGroupRequest
    bool ModifyHostGroupRequest::CheckValidation() {
        return this->host_group_id == nullptr ? false : true;
    }
    std::string ModifyHostGroupRequest::Method() {
        return "PUT";
    }
    std::string ModifyHostGroupRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ModifyHostGroupRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ModifyHostGroupRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ModifyHostGroupRequest, host_group_id, host_group_name, host_group_type, host_ip_list, host_identifier, auto_update, update_start_time, update_end_time, service_logging) 

    // DescribeHostGroupRequest
    bool DescribeHostGroupRequest::CheckValidation() {
        return this->host_group_id == nullptr ? false : true;
    }
    std::string DescribeHostGroupRequest::Method() {
        return "GET";
    }
    std::string DescribeHostGroupRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeHostGroupRequest, host_group_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeHostGroupRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeHostGroupRequest) 

    // DescribeHostGroupsRequest
    bool DescribeHostGroupsRequest::CheckValidation() {
        return true;
    }
    std::string DescribeHostGroupsRequest::Method() {
        return "GET";
    }
    std::string DescribeHostGroupsRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeHostGroupsRequest, host_group_id, host_group_name, page_number, page_size, auto_update, host_identifier, service_logging)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeHostGroupsRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeHostGroupsRequest) 

    // DescribeHostsRequest
    bool DescribeHostsRequest::CheckValidation() {
        return this->host_group_id == nullptr ? false : 
            this->ip == nullptr ? false : true;
    }
    std::string DescribeHostsRequest::Method() {
        return "GET";
    }
    std::string DescribeHostsRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeHostsRequest, host_group_id, ip, heartbeat_status, page_number, page_size)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeHostsRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeHostsRequest) 

    // DeleteHostRequest
    bool DeleteHostRequest::CheckValidation() {
        return this->host_group_id == nullptr ? false : true;
    }
    std::string DeleteHostRequest::Method() {
        return "DELETE";
    }
    std::string DeleteHostRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteHostRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteHostRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteHostRequest, host_group_id, ip)

    // DescribeHostGroupRulesRequest
    bool DescribeHostGroupRulesRequest::CheckValidation() {
        return this->host_group_id == nullptr ? false : true;
    }
    std::string DescribeHostGroupRulesRequest::Method() {
        return "GET";
    }
    std::string DescribeHostGroupRulesRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeHostGroupRulesRequest, host_group_id, page_number, page_size)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeHostGroupRulesRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeHostGroupRulesRequest) 

    // ModifyHostGroupsAutoUpdateRequest
    bool ModifyHostGroupsAutoUpdateRequest::CheckValidation() {
        return this->host_group_ids == nullptr ? false : true;
    }
    std::string ModifyHostGroupsAutoUpdateRequest::Method() {
        return "PUT";
    }
    std::string ModifyHostGroupsAutoUpdateRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ModifyHostGroupsAutoUpdateRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ModifyHostGroupsAutoUpdateRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ModifyHostGroupsAutoUpdateRequest, host_group_ids, auto_update, update_start_time, update_end_time)

    // DeleteAbnormalHostsRequest
    bool DeleteAbnormalHostsRequest::CheckValidation() {
        return this->host_group_id == nullptr ? false : true;
    }
    std::string DeleteAbnormalHostsRequest::Method() {
        return "DELETE";
    }
    std::string DeleteAbnormalHostsRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteAbnormalHostsRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteAbnormalHostsRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteAbnormalHostsRequest, host_group_id) 

    // CreateRuleRequest
    bool CreateRuleRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : 
            this->rule_name == nullptr ? false : true;
    }
    std::string CreateRuleRequest::Method() {
        return "POST";
    }
    std::string CreateRuleRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CreateRuleRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CreateRuleRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CreateRuleRequest, topic_id, rule_name, paths, exclude_paths, log_type, extract_rule, user_define_rule, log_sample, input_type, container_rule)

    // DeleteRuleRequest
    bool DeleteRuleRequest::CheckValidation() {
        return this->rule_id == nullptr ? false : true;
    }
    std::string DeleteRuleRequest::Method() {
        return "DELETE";
    }
    std::string DeleteRuleRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteRuleRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteRuleRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteRuleRequest, rule_id)

    // ModifyRuleRequest
    bool ModifyRuleRequest::CheckValidation() {
        return this->rule_id == nullptr ? false : true;
    }
    std::string ModifyRuleRequest::Method() {
        return "PUT";
    }
    std::string ModifyRuleRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ModifyRuleRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ModifyRuleRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ModifyRuleRequest, rule_id, rule_name, paths, log_type, extract_rule, exclude_paths, log_sample, user_define_rule, input_type, container_rule)

    // DescribeRuleRequest
    bool DescribeRuleRequest::CheckValidation() {
        return this->rule_id == nullptr ? false : true;
    }
    std::string DescribeRuleRequest::Method() {
        return "GET";
    }
    std::string DescribeRuleRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeRuleRequest, rule_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeRuleRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeRuleRequest) 

    // DescribeRulesRequest
    bool DescribeRulesRequest::CheckValidation() {
        return this->project_id == nullptr ? false : true;
    }
    std::string DescribeRulesRequest::Method() {
        return "GET";
    }
    std::string DescribeRulesRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeRulesRequest, project_id, rule_id, rule_name, topic_id, topic_name, page_number, page_size)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeRulesRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeRulesRequest) 

    // ApplyRuleToHostGroupsRequest
    bool ApplyRuleToHostGroupsRequest::CheckValidation() {
        return this->rule_id == nullptr ? false : 
            this->host_group_ids == nullptr ? false : true;
    }
    std::string ApplyRuleToHostGroupsRequest::Method() {
        return "PUT";
    }
    std::string ApplyRuleToHostGroupsRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ApplyRuleToHostGroupsRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ApplyRuleToHostGroupsRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ApplyRuleToHostGroupsRequest, rule_id, host_group_ids)

    // DeleteRuleFromHostGroupsRequest
    bool DeleteRuleFromHostGroupsRequest::CheckValidation() {
        return this->rule_id == nullptr ? false : 
            this->host_group_ids == nullptr ? false : true;
    }
    std::string DeleteRuleFromHostGroupsRequest::Method() {
        return "PUT";
    }
    std::string DeleteRuleFromHostGroupsRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteRuleFromHostGroupsRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteRuleFromHostGroupsRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteRuleFromHostGroupsRequest, rule_id, host_group_ids)

    // CreateAlarmNotifyGroupRequest
    bool CreateAlarmNotifyGroupRequest::CheckValidation() {
        return this->alarm_notify_group_name == nullptr ? false : 
            this->notify_type == nullptr ? false : 
            this->receivers == nullptr ? false : true;
    }
    std::string CreateAlarmNotifyGroupRequest::Method() {
        return "POST";
    }
    std::string CreateAlarmNotifyGroupRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CreateAlarmNotifyGroupRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CreateAlarmNotifyGroupRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CreateAlarmNotifyGroupRequest, alarm_notify_group_name, notify_type, receivers)

    // DeleteAlarmNotifyGroupRequest
    bool DeleteAlarmNotifyGroupRequest::CheckValidation() {
        return this->alarm_notify_group_id == nullptr ? false : true;
    }
    std::string DeleteAlarmNotifyGroupRequest::Method() {
        return "DELETE";
    }
    std::string DeleteAlarmNotifyGroupRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteAlarmNotifyGroupRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteAlarmNotifyGroupRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteAlarmNotifyGroupRequest, alarm_notify_group_id)

    // ModifyAlarmNotifyGroupRequest
    bool ModifyAlarmNotifyGroupRequest::CheckValidation() {
        return this->alarm_notify_group_id == nullptr ? false : true;
    }
    std::string ModifyAlarmNotifyGroupRequest::Method() {
        return "PUT";
    }
    std::string ModifyAlarmNotifyGroupRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ModifyAlarmNotifyGroupRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ModifyAlarmNotifyGroupRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ModifyAlarmNotifyGroupRequest, alarm_notify_group_id, alarm_notify_group_name, notify_type, receivers)

    // DescribeAlarmNotifyGroupsRequest
    bool DescribeAlarmNotifyGroupsRequest::CheckValidation() {
        return true;
    }
    std::string DescribeAlarmNotifyGroupsRequest::Method() {
        return "GET";
    }
    std::string DescribeAlarmNotifyGroupsRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeAlarmNotifyGroupsRequest, alarm_notify_group_name, alarm_notify_group_id, receiver_name, page_number, page_size)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeAlarmNotifyGroupsRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeAlarmNotifyGroupsRequest) 

    // CreateAlarmRequest
    bool CreateAlarmRequest::CheckValidation() {
        return this->alarm_name == nullptr ? false : 
            this->project_id == nullptr ? false :
            this->query_request == nullptr ? false :
            this->request_cycle == nullptr ? false :
            this->condition == nullptr ? false :
            this->alarm_period == nullptr ? false :
            this->alarm_notify_group == nullptr ? false : true;
    }
    std::string CreateAlarmRequest::Method() {
        return "POST";
    }
    std::string CreateAlarmRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CreateAlarmRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CreateAlarmRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CreateAlarmRequest, alarm_name, project_id, status, query_request, request_cycle, condition, trigger_period, alarm_period, alarm_notify_group, user_define_msg)

    // DeleteAlarmRequest
    bool DeleteAlarmRequest::CheckValidation() {
        return this->alarm_id == nullptr ? false : true;
    }
    std::string DeleteAlarmRequest::Method() {
        return "DELETE";
    }
    std::string DeleteAlarmRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(DeleteAlarmRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DeleteAlarmRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(DeleteAlarmRequest, alarm_id)

    // ModifyAlarmRequest
    bool ModifyAlarmRequest::CheckValidation() {
        return this->alarm_id == nullptr ? false : true;
    }
    std::string ModifyAlarmRequest::Method() {
        return "PUT";
    }
    std::string ModifyAlarmRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(ModifyAlarmRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(ModifyAlarmRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(ModifyAlarmRequest, alarm_id, alarm_name, status, query_request, request_cycle, condition, trigger_period, alarm_period, alarm_notify_group, user_define_msg)

    // DescribeAlarmsRequest
    bool DescribeAlarmsRequest::CheckValidation() {
        return this->project_id == nullptr ? false : true;
    }
    std::string DescribeAlarmsRequest::Method() {
        return "GET";
    }
    std::string DescribeAlarmsRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeAlarmsRequest, project_id, alarm_name, alarm_id, topic_id, topic_name, status, page_number, page_size)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeAlarmsRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeAlarmsRequest) 

    // OpenKafkaConsumerRequest
    bool OpenKafkaConsumerRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string OpenKafkaConsumerRequest::Method() {
        return "PUT";
    }
    std::string OpenKafkaConsumerRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(OpenKafkaConsumerRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(OpenKafkaConsumerRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(OpenKafkaConsumerRequest, topic_id)

    // CloseKafkaConsumerRequest
    bool CloseKafkaConsumerRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string CloseKafkaConsumerRequest::Method() {
        return "PUT";
    }
    std::string CloseKafkaConsumerRequest::ContentType() {
        return "application/json";
    }
    EMPTY_TLS_QUERY_JSON_DEFINITION(CloseKafkaConsumerRequest)
    EMPTY_TLS_HEADER_JSON_DEFINITION(CloseKafkaConsumerRequest)
    COMMON_TLS_BODY_JSON_DEFINITION(CloseKafkaConsumerRequest, topic_id)

    // DescribeKafkaConsumerRequest
    bool DescribeKafkaConsumerRequest::CheckValidation() {
        return this->topic_id == nullptr ? false : true;
    }
    std::string DescribeKafkaConsumerRequest::Method() {
        return "GET";
    }
    std::string DescribeKafkaConsumerRequest::ContentType() {
        return "";
    }
    COMMON_TLS_QUERY_JSON_DEFINITION(DescribeKafkaConsumerRequest, topic_id)
    EMPTY_TLS_HEADER_JSON_DEFINITION(DescribeKafkaConsumerRequest)
    EMPTY_TLS_BODY_JSON_DEFINITION(DescribeKafkaConsumerRequest) 

} // Namespace
