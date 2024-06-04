#pragma once

#include <string>

#include "http/HttpResponse.h"
#include "TlsClientConfig.h"
#include "TlsResponse.h"
#include "TlsRequest.h"

#define TLS_CLIENT_METHOD_DECLARATION(method) \
    method##Response method(method##Request &request);

namespace httplib {
    class Client;
}

namespace VolcengineTls {

class TlsClient {
public:
    TlsClient(const TlsClientConfig &config);
    void getErrorInfo(std::shared_ptr<HttpResponse> &inner_resp, TlsResponse &resp);

    TLS_CLIENT_METHOD_DECLARATION(CreateProject);
    TLS_CLIENT_METHOD_DECLARATION(DeleteProject);
    TLS_CLIENT_METHOD_DECLARATION(ModifyProject);
    TLS_CLIENT_METHOD_DECLARATION(DescribeProject);
    TLS_CLIENT_METHOD_DECLARATION(DescribeProjects);
    TLS_CLIENT_METHOD_DECLARATION(CreateTopic);
    TLS_CLIENT_METHOD_DECLARATION(DeleteTopic);
    TLS_CLIENT_METHOD_DECLARATION(ModifyTopic);
    TLS_CLIENT_METHOD_DECLARATION(DescribeTopic);
    TLS_CLIENT_METHOD_DECLARATION(DescribeTopics);
    TLS_CLIENT_METHOD_DECLARATION(DescribeShards);
    TLS_CLIENT_METHOD_DECLARATION(CreateIndex);
    TLS_CLIENT_METHOD_DECLARATION(DeleteIndex);
    TLS_CLIENT_METHOD_DECLARATION(ModifyIndex);
    TLS_CLIENT_METHOD_DECLARATION(DescribeIndex);
    TLS_CLIENT_METHOD_DECLARATION(PutLogs);
    TLS_CLIENT_METHOD_DECLARATION(PutLogsV2);
    TLS_CLIENT_METHOD_DECLARATION(DescribeCursor);
    TLS_CLIENT_METHOD_DECLARATION(ConsumeLogs);
    TLS_CLIENT_METHOD_DECLARATION(SearchLogs);
    TLS_CLIENT_METHOD_DECLARATION(SearchLogsV2);
    TLS_CLIENT_METHOD_DECLARATION(DescribeLogContext);
    TLS_CLIENT_METHOD_DECLARATION(DescribeHistogram);
    TLS_CLIENT_METHOD_DECLARATION(WebTracks);
    TLS_CLIENT_METHOD_DECLARATION(CreateDownloadTask);
    TLS_CLIENT_METHOD_DECLARATION(DescribeDownloadTasks);
    TLS_CLIENT_METHOD_DECLARATION(DescribeDownloadUrl);
    TLS_CLIENT_METHOD_DECLARATION(CreateHostGroup);
    TLS_CLIENT_METHOD_DECLARATION(DeleteHostGroup);
    TLS_CLIENT_METHOD_DECLARATION(ModifyHostGroup);
    TLS_CLIENT_METHOD_DECLARATION(DescribeHostGroups);
    TLS_CLIENT_METHOD_DECLARATION(DescribeHostGroup);
    TLS_CLIENT_METHOD_DECLARATION(DeleteHost);
    TLS_CLIENT_METHOD_DECLARATION(DescribeHostGroupRules);
    TLS_CLIENT_METHOD_DECLARATION(ModifyHostGroupsAutoUpdate);
    TLS_CLIENT_METHOD_DECLARATION(DeleteAbnormalHosts);
    TLS_CLIENT_METHOD_DECLARATION(CreateRule);
    TLS_CLIENT_METHOD_DECLARATION(DeleteRule);
    TLS_CLIENT_METHOD_DECLARATION(ModifyRule);
    TLS_CLIENT_METHOD_DECLARATION(DescribeRule);
    TLS_CLIENT_METHOD_DECLARATION(DescribeRules);
    TLS_CLIENT_METHOD_DECLARATION(ApplyRuleToHostGroups);
    TLS_CLIENT_METHOD_DECLARATION(DeleteRuleFromHostGroups);
    TLS_CLIENT_METHOD_DECLARATION(CreateAlarmNotifyGroup);
    TLS_CLIENT_METHOD_DECLARATION(DeleteAlarmNotifyGroup);
    TLS_CLIENT_METHOD_DECLARATION(ModifyAlarmNotifyGroup);
    TLS_CLIENT_METHOD_DECLARATION(DescribeAlarmNotifyGroups);
    TLS_CLIENT_METHOD_DECLARATION(CreateAlarm);
    TLS_CLIENT_METHOD_DECLARATION(DeleteAlarm);
    TLS_CLIENT_METHOD_DECLARATION(ModifyAlarm);
    TLS_CLIENT_METHOD_DECLARATION(DescribeAlarms);
    TLS_CLIENT_METHOD_DECLARATION(OpenKafkaConsumer);
    TLS_CLIENT_METHOD_DECLARATION(CloseKafkaConsumer);
    TLS_CLIENT_METHOD_DECLARATION(DescribeKafkaConsumer);

private:
    TlsClientConfig config_;
    std::shared_ptr<httplib::Client> longlinkCli_;
};

}