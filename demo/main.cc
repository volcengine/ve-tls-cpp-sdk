#include <cstdio>
#include <ve-tls-cpp-sdk/TlsClient.h>
#include <ve-tls-cpp-sdk/TlsClientConfig.h>
#include <ve-tls-cpp-sdk/TlsRequest.h>
#include <ve-tls-cpp-sdk/TlsJsonConversion.h>
#include <ve-tls-cpp-sdk/TlsResponse.h>
#include <ve-tls-cpp-sdk/thirdparty/nlohmann/json.hpp>

using namespace VolcengineTls;

#define CHECK_RUN_TEST(test) \
    if (runTest[test] == "YES")
#define RUN(test) \
    auto resp = cli.test(request); \
    nlohmann::json j = resp; \
    printf("Resp: %s\n", j.dump().c_str());

int main() {
    std::map<std::string, std::string> runTest = {
        // Project
        {"CreateProject", "NO"},
        {"DeleteProject", "NO"},
        {"ModifyProject", "NO"},
        {"DescribeProject", "NO"},
        {"DescribeProjects", "NO"},
        // Topic
        {"CreateTopic", "NO"},
        {"DeleteTopic", "NO"},
        {"ModifyTopic", "NO"},
        {"DescribeTopic", "NO"},
        {"DescribeTopics", "NO"},
        // Shards
        {"DescribeShards", "NO"},
        // Index
        {"CreateIndex", "NO"},
        {"DeleteIndex", "NO"},
        {"ModifyIndex", "NO"},
        {"DescribeIndex", "NO"},
        // Log
        {"PutLogs", "NO"},
        {"PutLogsLZ4", "NO"},
        {"PutLogsV2", "NO"},
        {"DescribeCursor", "NO"},
        {"ConsumeLogs", "NO"},
        {"ConsumeLogsLZ4", "NO"},
        {"WebTracks", "NO"},
        {"WebTracksLZ4", "NO"},
        {"SearchLogs", "NO"},
        {"DescribeHistogram", "NO"},
        // Download task
        {"CreateDownloadTask", "NO"},
        {"DescribeDownloadTasks", "NO"},
        {"DescribeDownloadUrl", "NO"},
        // Host group
        {"CreateHostGroup", "NO"},
        {"ModifyHostGroup", "NO"},
        {"DescribeHostGroup", "NO"},
        {"DescribeHostGroups", "NO"},
        {"DescribeHosts", "NO"},
        {"DeleteHostGroup", "NO"},
        {"DeleteHost", "NO"},
        {"DescribeHostGroupRules", "NO"},
        {"ModifyHostGroupsAutoUpdate", "NO"},
        {"DeleteAbnormalHosts", "NO"},
        // Rule
        {"CreateRule", "NO"},
        {"ModifyRule", "NO"},
        {"DescribeRule", "NO"},
        {"DescribeRules", "NO"},
        {"ApplyRuleToHostGroups", "NO"},
        {"DeleteRuleFromHostGroups", "NO"},
        {"DeleteRule", "NO"},
        // AlarmNotifyGroup
        {"CreateAlarmNotifyGroup", "NO"},
        {"ModifyAlarmNotifyGroup", "NO"},
        {"DescribeAlarmNotifyGroups", "NO"},
        {"DeleteAlarmNotifyGroup", "NO"},
        // Alarm
        {"CreateAlarm", "NO"},
        {"DeleteAlarm", "NO"},
        {"ModifyAlarm", "NO"},
        {"DescribeAlarms", "NO"},
        // Kafka protocol
        {"OpenKafkaConsumer", "NO"},
        {"CloseKafkaConsumer", "NO"},
        {"DescribeKafkaConsumer", "NO"}
    };

    TlsClientConfig cfg; {
        // Create client
        cfg.scheme = "http://";
        cfg.endpoint = "Your endpoint";
        cfg.access_key_id = "Your access key";
        cfg.access_key_secret = "Your access key secret";
        cfg.region = "Your region";
    }
    TlsClient cli = TlsClient(cfg);
    
    // Project
    CHECK_RUN_TEST("CreateProject") {
        CreateProjectRequest request; {
            request.region = std::make_shared<std::string>("cn-guilin-boe");
            request.description = std::make_shared<std::string>("eren test cpp sdk");
            request.project_name = std::make_shared<std::string>("cppsdkunittest");
        }
        RUN(CreateProject);
    }

    CHECK_RUN_TEST("DeleteProject") {
        DeleteProjectRequest request; {
            request.project_id = std::make_shared<std::string>("a1bfd715-e6cc-4a80-b857-32f9b7b86831");
        }
        RUN(DeleteProject);
    }

    CHECK_RUN_TEST("ModifyProject") {
        ModifyProjectRequest request; {
            request.project_id = std::make_shared<std::string>("XXX");
            request.project_name = std::make_shared<std::string>("cppsdktestmodifyprojectname");
        }
        RUN(ModifyProject);
    }

    CHECK_RUN_TEST("DescribeProject") {
        DescribeProjectRequest request; {
            request.project_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeProject);
    }

    CHECK_RUN_TEST("DescribeProjects") {
        DescribeProjectsRequest request; {
        }
        RUN(DescribeProjects);
    }

    // Topic
    CHECK_RUN_TEST("CreateTopic") {
        CreateTopicRequest request; {
            request.topic_name = std::make_shared<std::string>("cpptesttopic");
            request.project_id = std::make_shared<std::string>("XXX");
            request.ttl = std::make_shared<int>(7);
            request.shard_count = std::make_shared<int>(2);
            request.auto_split = std::make_shared<bool>(true);
            request.max_split_shard = std::make_shared<int>(10);
        }
        RUN(CreateTopic);
    }

    CHECK_RUN_TEST("DeleteTopic") {
        DeleteTopicRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
        }
        RUN(DeleteTopic);
    }

    CHECK_RUN_TEST("ModifyTopic") {
        ModifyTopicRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.topic_name = std::make_shared<std::string>("cppsdktestmodifytopic");
        }
        RUN(ModifyTopic);
    }

    CHECK_RUN_TEST("DescribeTopic") {
        DescribeTopicRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeTopic);
    }

    CHECK_RUN_TEST("DescribeTopics") {
        DescribeTopicsRequest request; {
            request.project_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeTopics);
    }

    // Shards
    CHECK_RUN_TEST("DescribeShards") {
        DescribeShardsRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeShards);
    }

    // Index
    CHECK_RUN_TEST("CreateIndex") {
        CreateIndexRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.full_text = std::make_shared<FullTextInfo>();
            request.full_text->delimiter = ",";
            request.full_text->case_sensitive = true;        
        }
        RUN(CreateIndex);
    }

    CHECK_RUN_TEST("DeleteIndex") {
        DeleteIndexRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
        }
        RUN(DeleteIndex);
    }

    CHECK_RUN_TEST("ModifyIndex") {
        ModifyIndexRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.full_text = std::make_shared<FullTextInfo>();
            request.full_text->delimiter = ",";
        }
        RUN(ModifyIndex)
    }

    CHECK_RUN_TEST("DescribeIndex") {
        DescribeIndexRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeIndex);
    }

    // Logs
    CHECK_RUN_TEST("PutLogs") {
        auto pb = std::make_shared<pb::LogGroupList>();
        auto log_group = pb->add_loggroups();
        auto log = log_group->add_logs();
        log->set_time(time(nullptr));
        auto log_content = log->add_contents();
        log_content->set_key("cpptestkey");
        log_content->set_value("cpptestvalue");
        PutLogsRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.log_group_list = pb;
        }
        RUN(PutLogs);
    }

    CHECK_RUN_TEST("PutLogsLZ4") {
        auto pb = std::make_shared<pb::LogGroupList>();
        auto log_group = pb->add_loggroups();
        auto log = log_group->add_logs();
        log->set_time(time(nullptr));
        auto log_content = log->add_contents();
        log_content->set_key("cpptestkey");
        log_content->set_value("cpptestvalue");

        PutLogsRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.compression = std::make_shared<std::string>("lz4");
            request.log_group_list = pb;
        }
        RUN(PutLogs)
    }

    CHECK_RUN_TEST("PutLogsV2") {
        PutLogsV2Request request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.source = std::make_shared<std::string>("sdkut");
            request.filename = std::make_shared<std::string>("utstdout");
            request.logs = std::make_shared<std::vector<LogItem>>();
            request.logs->push_back(LogItem());
            (*request.logs)[0].log_content["cpptestkey"] = "cpptestvalue";
        }
        RUN(PutLogsV2)
    }

    CHECK_RUN_TEST("DescribeCursor") {
        DescribeCursorRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.shard_id = std::make_shared<int>(1);
            request.from = std::make_shared<std::string>("begin");
        }
        RUN(DescribeCursor);
    }

    CHECK_RUN_TEST("ConsumeLogs") {
        ConsumeLogsRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.shard_id = std::make_shared<int>(1);
            request.cursor = std::make_shared<std::string>("NjNmZWY1MTAtMi0wMDAwMDAwMDAwMDAwMDAwLTAwMDAwLTE=");
        }
        RUN(ConsumeLogs);
    }

    CHECK_RUN_TEST("ConsumeLogsLZ4") {
        ConsumeLogsRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.shard_id = std::make_shared<int>(1);
            request.compression = std::make_shared<std::string>("lz4");
            request.cursor = std::make_shared<std::string>("XXX");
        }
        RUN(ConsumeLogs);
    }

    CHECK_RUN_TEST("WebTracks") {
        WebTracksRequest request; {
            request.project_id = std::make_shared<std::string>("XXX");
            request.topic_id = std::make_shared<std::string>("XXX");
            request.logs = std::make_shared<std::vector<std::map<std::string, std::string>>>();
            std::map<std::string, std::string> log; {
                log["webtrackstestkey"] = "webtrackstestvalue";
            }
            request.logs->push_back(log);
        }
        RUN(WebTracks);
    }

    CHECK_RUN_TEST("WebTracksLZ4") {
        WebTracksRequest request; {
            request.project_id = std::make_shared<std::string>("XXX");
            request.topic_id = std::make_shared<std::string>("XXX");
            request.logs = std::make_shared<std::vector<std::map<std::string, std::string>>>();
            request.compression = std::make_shared<std::string>("lz4");
            std::map<std::string, std::string> log; {
                log["webtrackstestkey"] = "webtrackstestvalue";
            }
            request.logs->push_back(log);
        }
        RUN(WebTracks);
    }

    CHECK_RUN_TEST("SearchLogs") {
        SearchLogsRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.start_time = std::make_shared<int>(1678080000);
            request.end_time = std::make_shared<int>(1678085187);
            request.query = std::make_shared<std::string>("cpptestvalue");
            request.limit = std::make_shared<int>(30);
        }
        RUN(SearchLogs);
    }

    CHECK_RUN_TEST("DescribeHistogram") {
        DescribeHistogramRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.start_time = std::make_shared<int>(1678080000);
            request.end_time = std::make_shared<int>(1678085187);
            request.interval = std::make_shared<int>(100);
        }
        RUN(DescribeHistogram);
    }

    // Download task
    CHECK_RUN_TEST("CreateDownloadTask") {
        CreateDownloadTaskRequest request; {
            request.task_name = std::make_shared<std::string>("cppsdktestdownload");
            request.topic_id = std::make_shared<std::string>("XXX");
            request.query = std::make_shared<std::string>("cpptestvalue");
            request.start_time = std::make_shared<int>(1678080000);
            request.end_time = std::make_shared<int>(1678085187);
            request.data_format = std::make_shared<std::string>("json");
            request.sort = std::make_shared<std::string>("asc");
            request.limit = std::make_shared<int>(30);
            request.compression = std::make_shared<std::string>("gzip");
        }
        RUN(CreateDownloadTask);
    }

    CHECK_RUN_TEST("DescribeDownloadTasks") {
        DescribeDownloadTasksRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.page_number = std::make_shared<int>(1);
            request.page_size = std::make_shared<int>(20);
        }
        RUN(DescribeDownloadTasks);
    }

    CHECK_RUN_TEST("DescribeDownloadUrl") {
        DescribeDownloadUrlRequest request; {
            request.task_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeDownloadUrl);
    }

    // HostGroup
    CHECK_RUN_TEST("CreateHostGroup") {
        CreateHostGroupRequest request; {
            request.host_group_name = std::make_shared<std::string>("cppsdktesthostgroup");
            request.host_group_type = std::make_shared<std::string>("Label");
            request.host_identifier = std::make_shared<std::string>("cppsdk");
        }
        RUN(CreateHostGroup);
    }

    CHECK_RUN_TEST("ModifyHostGroup") {
        ModifyHostGroupRequest request; {
            request.host_group_id = std::make_shared<std::string>("XXX");
            request.host_group_name = std::make_shared<std::string>("cppsdktestmodifyname");
        }
        RUN(ModifyHostGroup);
    }

    CHECK_RUN_TEST("DescribeHostGroup") {
        DescribeHostGroupRequest request; {
            request.host_group_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeHostGroup);
    }

    CHECK_RUN_TEST("DescribeHostGroups") {
        DescribeHostGroupsRequest request; {
        }
        RUN(DescribeHostGroups);
    }

    CHECK_RUN_TEST("DeleteHostGroup") {
        DeleteHostGroupRequest request; {
            request.host_group_id = std::make_shared<std::string>("XXX");
        }
        RUN(DeleteHostGroup);
    }

    CHECK_RUN_TEST("DeleteHost") {
        DeleteHostRequest request; {
            request.host_group_id = std::make_shared<std::string>("XXX");
            request.ip = std::make_shared<std::string>("XXX");
        }
        RUN(DeleteHost);
    }

    CHECK_RUN_TEST("DescribeHostGroupRules") {
        DescribeHostGroupRulesRequest request; {
            request.host_group_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeHostGroupRules);
    }

    CHECK_RUN_TEST("ModifyHostGroupsAutoUpdate") {
        ModifyHostGroupsAutoUpdateRequest request; {
            request.host_group_ids = std::make_shared<std::vector<std::string>>();
            request.host_group_ids->push_back("XXX");
            request.auto_update = std::make_shared<bool>(true);
            request.update_start_time = std::make_shared<std::string>("00:00");
            request.update_end_time = std::make_shared<std::string>("02:00");
        }
        RUN(ModifyHostGroupsAutoUpdate);
    }

    CHECK_RUN_TEST("DeleteAbnormalHosts") {
        DeleteAbnormalHostsRequest request; {
            request.host_group_id = std::make_shared<std::string>("XXX");
        }
        RUN(DeleteAbnormalHosts);
    }

    // Rule
    CHECK_RUN_TEST("CreateRule") {
        CreateRuleRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
            request.rule_name = std::make_shared<std::string>("cppsdktestrule");
            request.paths = std::make_shared<std::vector<std::string>>();
            request.paths->push_back("/cppsdk");
        }
        RUN(CreateRule);
    }

    CHECK_RUN_TEST("ModifyRule") {
        ModifyRuleRequest request; {
            request.rule_id = std::make_shared<std::string>("XXX");
            request.rule_name = std::make_shared<std::string>("cppsdktestmodifyrule");
        }
        RUN(ModifyRule);
    }

    CHECK_RUN_TEST("DescribeRule") {
        DescribeRuleRequest request; {
            request.rule_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeRule);
    }

    CHECK_RUN_TEST("DescribeRules") {
        DescribeRulesRequest request; {
            request.project_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeRules);
    }

    CHECK_RUN_TEST("ApplyRuleToHostGroups") {
        ApplyRuleToHostGroupsRequest request; {
            request.rule_id = std::make_shared<std::string>("XXX");
            request.host_group_ids = std::make_shared<std::vector<std::string>>();
            request.host_group_ids->push_back("XXX");
        }
        RUN(ApplyRuleToHostGroups);
    }

    CHECK_RUN_TEST("DeleteRuleFromHostGroups") {
        DeleteRuleFromHostGroupsRequest request; {
            request.rule_id = std::make_shared<std::string>("XXX");
            request.host_group_ids = std::make_shared<std::vector<std::string>>();
            request.host_group_ids->push_back("XXX");
        }
        RUN(DeleteRuleFromHostGroups);
    }

    CHECK_RUN_TEST("DeleteRule") {
        DeleteRuleRequest request; {
            request.rule_id = std::make_shared<std::string>("XXX");
        }
        RUN(DeleteRule);
    }

    // AlarmNotifyGroup
    CHECK_RUN_TEST("CreateAlarmNotifyGroup") {
        CreateAlarmNotifyGroupRequest request; {
            request.alarm_notify_group_name = std::make_shared<std::string>("cppsdkalarmnotify");
            request.notify_type = std::make_shared<std::vector<std::string>>();
            request.notify_type->push_back("Trigger");
            request.receivers = std::make_shared<std::vector<Receiver>>();
            request.receivers->push_back(Receiver());
            (*request.receivers)[0].receiver_type = "User";
            (*request.receivers)[0].receiver_names = {"project_test_tls"};
            (*request.receivers)[0].receiver_channels = {"Sms"};
            (*request.receivers)[0].start_time = "00:00:00";
            (*request.receivers)[0].end_time = "23:59:59";
        }
        RUN(CreateAlarmNotifyGroup);
    }

    CHECK_RUN_TEST("ModifyAlarmNotifyGroup") {
        ModifyAlarmNotifyGroupRequest request; {
            request.alarm_notify_group_id = std::make_shared<std::string>("XXX");
            request.alarm_notify_group_name = std::make_shared<std::string>("cppsdktestmodifyname");
        }
        RUN(ModifyAlarmNotifyGroup);
    }

    CHECK_RUN_TEST("DescribeAlarmNotifyGroups") {
        DescribeAlarmNotifyGroupsRequest request; {
        }
        RUN(DescribeAlarmNotifyGroups);
    }

    CHECK_RUN_TEST("DeleteAlarmNotifyGroup") {
        DeleteAlarmNotifyGroupRequest request; {
            request.alarm_notify_group_id = std::make_shared<std::string>("XXX");
        }
        RUN(DeleteAlarmNotifyGroup);
    }

    // Alarm
    CHECK_RUN_TEST("CreateAlarm") {
        CreateAlarmRequest request; {
            request.alarm_name = std::make_shared<std::string>( "cppsdktestalarm");
            request.project_id = std::make_shared<std::string>("XXX");
            request.query_request = std::make_shared<std::vector<QueryRequest>>(); {
                request.query_request->push_back(QueryRequest());
                (*request.query_request)[0].topic_id = "XXX";
                (*request.query_request)[0].query = "test";
                (*request.query_request)[0].number = 1;
                (*request.query_request)[0].start_time_offset = 0;
                (*request.query_request)[0].end_time_offset = 0; 
            }
            request.request_cycle = std::make_shared<RequestCycle>(); {
                request.request_cycle->type = "Period";
                request.request_cycle->time = 10;
            }
            request.condition = std::make_shared<std::string>("$1.errNum>0");
            request.alarm_period = std::make_shared<int>(30);
            request.alarm_notify_group = std::make_shared<std::vector<std::string>>(); {
                request.alarm_notify_group->push_back("XXX");
            }
            request.trigger_period = std::make_shared<int>(2);
        }
        RUN(CreateAlarm);
    }
    
    CHECK_RUN_TEST("ModifyAlarm") {
        ModifyAlarmRequest request; {
            request.alarm_id = std::make_shared<std::string>("XXX");
            request.alarm_name = std::make_shared<std::string>("cppsdktestmodifyname");
        }
        RUN(ModifyAlarm);
    }

    CHECK_RUN_TEST("DescribeAlarms") {
        DescribeAlarmsRequest request; {
            request.project_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeAlarms);
    }

    CHECK_RUN_TEST("DeleteAlarm") {
        DeleteAlarmRequest request; {
            request.alarm_id = std::make_shared<std::string>("XXX");
        }
        RUN(DeleteAlarm);
    }

    // Kafka consumer
    CHECK_RUN_TEST("OpenKafkaConsumer") {
        OpenKafkaConsumerRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
        }
        RUN(OpenKafkaConsumer);
    }

    CHECK_RUN_TEST("CloseKafkaConsumer") {
        CloseKafkaConsumerRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
        }
        RUN(CloseKafkaConsumer);
    }

    CHECK_RUN_TEST("DescribeKafkaConsumer") {
        DescribeKafkaConsumerRequest request; {
            request.topic_id = std::make_shared<std::string>("XXX");
        }
        RUN(DescribeKafkaConsumer);
    }
    return 0;
}