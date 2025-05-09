#pragma once

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class MyController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(MyController);
public:
    ENDPOINT_INFO(root) {
        info->summary = ZH_WORDS_GETTER("api.summary");
       
    }

    ENDPOINT_INFO(test) {
        info->summary = ZH_WORDS_GETTER("api.summary");
        //�������������
        API_DEF_ADD_PAGE_PARAMS();
        //��Ӧ��ʽ����
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }

    ENDPOINT("GET", "/", root) {
        return createResponse(Status::CODE_200, ZH_WORDS_GETTER("test"));
    }


    ENDPOINT("GET", "/test", test, QUERIES(QueryParams,params)) {
        //������ѯ����
        API_HANDLER_QUERY_PARAM(query, PageQuery, params);
        //��Ӧ������
        API_HANDLER_RESP_VO(excuteTest(query));
    }

private:
    StringJsonVO::Wrapper excuteTest(const PageQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section