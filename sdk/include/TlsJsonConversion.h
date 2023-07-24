#pragma once

#include "TlsModel.h"
#include "TlsRequest.h"
#include "TlsResponse.h"
#include "utils/HeaderUtils.h"
#include "thirdparty/nlohmann/json.hpp"

namespace VolcengineTls {
    // Model
    COMMON_JSON_DEC(HostInfo)
    COMMON_JSON_DEC(LogTemplate)
    COMMON_JSON_DEC(KubernetesRule)
    COMMON_JSON_DEC(Receiver)
    COMMON_JSON_DEC(RequestCycle)
    COMMON_JSON_DEC(QueryRequest)
    COMMON_JSON_DEC(Advanced)
    COMMON_JSON_DEC(AlarmNotifyGroupInfo)
    COMMON_JSON_DEC(AlarmInfo)
    COMMON_JSON_DEC(AnalysisResult)
    COMMON_JSON_DEC(ContainerRule)
    COMMON_JSON_DEC(ExcludePath)
    COMMON_JSON_DEC(FilterKeyRegex)
    COMMON_JSON_DEC(ExtractRule)
    COMMON_JSON_DEC(FullTextInfo)
    COMMON_JSON_DEC(HistogramInfo)
    COMMON_JSON_DEC(HostGroupInfo)
    COMMON_JSON_DEC(ParsePathRule)
    COMMON_JSON_DEC(ShardHashKey)
    COMMON_JSON_DEC(Plugin) // TODO: 检查 TitleCase
    COMMON_JSON_DEC(UserDefineRule)
    COMMON_JSON_DEC(RuleInfo)
    COMMON_JSON_DEC(HostGroupHostsRulesInfo)
    COMMON_JSON_DEC(ValueInfo)
    COMMON_JSON_DEC(KeyValueInfo)
    COMMON_JSON_DEC(ProjectInfo)
    COMMON_JSON_DEC(QueryResp)
    COMMON_JSON_DEC(TaskInfo)
    COMMON_JSON_DEC(TopicInfo)
    
    // Project
    COMMON_JSON_DEC(CreateProjectResponse)
    COMMON_JSON_DEC(DeleteProjectResponse)
    COMMON_JSON_DEC(ModifyProjectResponse)
    COMMON_JSON_DEC(DescribeProjectResponse)
    COMMON_JSON_DEC(DescribeProjectsResponse)

    // Topic
    COMMON_JSON_DEC(CreateTopicResponse)
    COMMON_JSON_DEC(DeleteTopicResponse)
    COMMON_JSON_DEC(ModifyTopicResponse)
    COMMON_JSON_DEC(DescribeTopicResponse)
    COMMON_JSON_DEC(DescribeTopicsResponse)

    // Shard
    COMMON_JSON_DEC(DescribeShardsResponse)

    // Index
    COMMON_JSON_DEC(CreateIndexResponse)
    COMMON_JSON_DEC(DeleteIndexResponse)
    COMMON_JSON_DEC(ModifyIndexResponse)
    COMMON_JSON_DEC(DescribeIndexResponse)

    // Log
    COMMON_JSON_DEC(PutLogsResponse)
    COMMON_JSON_DEC(DescribeCursorResponse)
    COMMON_JSON_DEC(ConsumeLogsResponse)
    COMMON_JSON_DEC(SearchLogsResponse)
    COMMON_JSON_DEC(DescribeLogContextResponse)
    COMMON_JSON_DEC(DescribeHistogramResponse)
    COMMON_JSON_DEC(WebTracksResponse)
    
    // Download task
    COMMON_JSON_DEC(CreateDownloadTaskResponse)
    COMMON_JSON_DEC(DescribeDownloadTasksResponse)
    COMMON_JSON_DEC(DescribeDownloadUrlResponse)

    // Host group
    COMMON_JSON_DEC(CreateHostGroupResponse)
    COMMON_JSON_DEC(DeleteHostGroupResponse)
    COMMON_JSON_DEC(ModifyHostGroupResponse)
    COMMON_JSON_DEC(DescribeHostGroupsResponse)
    COMMON_JSON_DEC(DescribeHostGroupResponse)
    COMMON_JSON_DEC(DescribeHostsResponse)
    COMMON_JSON_DEC(DeleteHostResponse)
    COMMON_JSON_DEC(DescribeHostGroupRulesResponse)
    COMMON_JSON_DEC(ModifyHostGroupsAutoUpdateResponse)
    COMMON_JSON_DEC(DeleteAbnormalHostsResponse)

    // Rule
    COMMON_JSON_DEC(CreateRuleResponse)
    COMMON_JSON_DEC(DeleteRuleResponse)
    COMMON_JSON_DEC(ModifyRuleResponse)
    COMMON_JSON_DEC(DescribeRuleResponse)
    COMMON_JSON_DEC(DescribeRulesResponse)
    COMMON_JSON_DEC(ApplyRuleToHostGroupsResponse)
    COMMON_JSON_DEC(DeleteRuleFromHostGroupsResponse)

    // Alarm notify
    COMMON_JSON_DEC(CreateAlarmNotifyGroupResponse)
    COMMON_JSON_DEC(DeleteAlarmNotifyGroupResponse)
    COMMON_JSON_DEC(ModifyAlarmNotifyGroupResponse)
    COMMON_JSON_DEC(DescribeAlarmNotifyGroupsResponse)

    // Alarm
    COMMON_JSON_DEC(CreateAlarmResponse)
    COMMON_JSON_DEC(DeleteAlarmResponse)
    COMMON_JSON_DEC(ModifyAlarmResponse)
    COMMON_JSON_DEC(DescribeAlarmsResponse)

    // Kafka consumer
    COMMON_JSON_DEC(OpenKafkaConsumerResponse)
    COMMON_JSON_DEC(CloseKafkaConsumerResponse)
    COMMON_JSON_DEC(DescribeKafkaConsumerResponse)
}