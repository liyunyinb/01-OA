#pragma once
#ifndef _ENTERPRISE_CONTROLLER_
#define _ENTERPRISE_CONTROLLER_
#include<iostream>
#include "ApiHelper.h"
#include "../../domain/dto/enterpriseDTO.h"
#include "../../domain/vo/enterpriseJsonVO.h"
#include "./domain/vo/enterpriseJsonVO.h"
#include "./domain/dto/enterpriseDTO.h"
#include "./domain/query/PageQuery.h"
#include "./domain/query/enterprisePageQuery.h"
#include "./service/enterpriseService.h"
#include "../lib-oatpp/include/jwt/jwt.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class enterpriseController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(enterpriseController);
public:
    // TODO - more endpoints here
    //������ҵ������Ϣ�˵�
    ENDPOINT_INFO(addEnterprise) {
        // ����ӿڱ���
        //API_DEF_ADD_TITLE("addEnterprise");
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("indclas.func.add"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        //���Ӳ�ѯ��������
        info->queryParams.add<String>("enterpriseClassificationCode").description = ZH_WORDS_GETTER("indclas.field.code");
        info->queryParams.add<String>("enterpriseClassificationName").description = ZH_WORDS_GETTER("indclas.field.name");
        info->queryParams.add<UInt64>("stopInfo").description = ZH_WORDS_GETTER("indclas.field.stopInfo");

        //����Ĭ��ֵ
        info->queryParams["enterpriseClassificationCode"].addExample("default", String("NULL"));
        info->queryParams["enterpriseClassificationName"].addExample("default", String("NULL"));
        info->queryParams["stopInfo"].addExample("default", UInt64(1));
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(addEnterpriseJsonVO);
        info->addConsumes<addEnterpriseDTO::Wrapper>("application/json");
    }
    ENDPOINT(API_M_POST, "/indclas/add-indclas", addEnterprise, BODY_DTO(addEnterpriseDTO::Wrapper, enterpriseInfo), API_HANDLER_AUTH_PARAME) {
        auto payload = authObject->getPayload();//������Ϣ
        API_HANDLER_RESP_VO(execAddEnterprise(enterpriseInfo, payload));
    }

    //��ҳ��ѯ
    ENDPOINT_INFO(enterprisePageQuery) {

        // ����ӿڱ���
        //API_DEF_ADD_TITLE("enterprisePageQuery");
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("indclas.func.query-all"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();

        //���Ӳ�ѯ��������
        //info->queryParams.add<String>("enterpriseClassificationCode").description = "queryCode";
        info->queryParams.add<String>("enterpriseClassificationCode").description = ZH_WORDS_GETTER("indclas.field.code");
        //info->queryParams.add<String>("enterpriseClassificationName").description = "queryName";
        info->queryParams.add<String>("enterpriseClassificationName").description = ZH_WORDS_GETTER("indclas.field.name");
        //info->queryParams.add<UInt64>("pageIndex").description = "queryPageIndex";
        info->queryParams.add<UInt64>("pageIndex").description=ZH_WORDS_GETTER("indclas.field.pageIndex");
        //info->queryParams.add<UInt64>("pageSize").description = "queryPageSize";
        info->queryParams.add<UInt64>("pageSize").description=ZH_WORDS_GETTER("indclas.field.pagesize");
        //���Ӳ�ѯ����Ĭ��ֵ
        info->queryParams["enterpriseClassificationCode"].addExample("default", String("NULL"));
        info->queryParams["enterpriseClassificationName"].addExample("default", String("NULL"));
        info->queryParams["pageIndex"].addExample("default", UInt64(1));
        info->queryParams["pageSize"].addExample("default", UInt64(10));

        //������Ӧ��ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(enterprisePageJsonVO);
    }
    ENDPOINT(API_M_GET, "/indclas/get-indclaslist", enterprisePageQuery, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(userQuery, enterprisePageQuery, queryParams);
        API_HANDLER_RESP_VO(execEnterprisePageQuery(userQuery));
    }

    //��ѯ��ҵ��������
    ENDPOINT_INFO(getEnterpriseName) {
        // ����ӿڱ���
        //API_DEF_ADD_TITLE("getEnterpriseName");
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("indclas.func.get-name"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        //���Ӳ�ѯ��������
        //info->queryParams.add<String>("enterpriseClassificationName").description = "queryName";
        //���Ӳ�ѯ����Ĭ��ֵ
        //info->queryParams["enterpriseClassificationName"].addExample("default", String("NULL"));
        //������Ӧ��ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(enterpriseNameJsonVO);
    }
    ENDPOINT(API_M_GET, "/indclas/get-indclasnamelist", getEnterpriseName, API_HANDLER_AUTH_PARAME) {//, QUERIES(QueryParams, queryParams)
        //API_HANDLER_QUERY_PARAM(userQuery, PageQuery, queryParams);
        API_HANDLER_RESP_VO(execGetEnterpriseName());//userQuery
    }


private:
    addEnterpriseJsonVO::Wrapper execAddEnterprise(const addEnterpriseDTO::Wrapper& enterpriseInfo, const PayloadDTO& payload);
    enterprisePageJsonVO::Wrapper execEnterprisePageQuery(const enterprisePageQuery::Wrapper& query);
    enterpriseNameJsonVO::Wrapper execGetEnterpriseName();
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section


#endif // _ENTERPRISE_CONTROLLER_
