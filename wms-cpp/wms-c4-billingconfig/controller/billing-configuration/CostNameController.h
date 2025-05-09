#pragma once

#ifndef _COST_NAME_CONTROLLER_
#define _COST_NAME_CONTROLLER_

#include "domain/vo/billing-configuration/CostNameVO.h"
#include "domain/query/billing-configuration/CostNameQuery.h"
#include "domain/dto/billing-configuration/CostNameDTO.h"
#include "domain/vo/BaseJsonVO.h"
#include"domain/do/billing-configuration/CostNameDO.h"
#include"dao/billing-configuration/CostNameDAO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �������ƿ���������ʾ����������ؽӿڵ�ʹ��
 */
class CostNameController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(CostNameController);

public:
    
    // ��ȡ���������б�ȫ����
    ENDPOINT_INFO(queryCostNameListAll) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.list.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(CostNameJsonVO);
        //API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "cost_type_code", ZH_WORDS_GETTER("cost.field.type_code"), "", false);
    }
    ENDPOINT(API_M_GET, "/billing-configuration/query-all",   queryCostNameListAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����Ϊ Query ����ģ��
        API_HANDLER_QUERY_PARAM(costListQuery, CostNameQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryCostNameListAll(costListQuery));
    }

    // ��ȡ���������б�����+��ҳ��
    ENDPOINT_INFO(queryCostNameListWithCondition) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.list.condition.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(CostNamePageJsonVO);
        // �����ҳ��ѯ��������
        API_DEF_ADD_PAGE_PARAMS();
        // ����������ѯ��������
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("cost.field.code"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cost_code", ZH_WORDS_GETTER("cost.field.code"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cost_name", ZH_WORDS_GETTER("cost.field.name"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cost_type_code", ZH_WORDS_GETTER("cost.field.type_code"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "create_name", ZH_WORDS_GETTER("cost.field.create_name"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "create_by", ZH_WORDS_GETTER("cost.field.create_by"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("cost.field.create_date"), "", false);
       // API_DEF_ADD_QUERY_PARAMS(String, "update_name", ZH_WORDS_GETTER("cost.field.update_name"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "update_by", ZH_WORDS_GETTER("cost.field.update_by"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "update_date", ZH_WORDS_GETTER("cost.field.update_date"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "sys_org_code", ZH_WORDS_GETTER("cost.field.sys_org_code"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "sys_company_code", ZH_WORDS_GETTER("cost.field.sys_company_code"), "", false);
    }
    ENDPOINT(API_M_GET, "/billing-configuration/query-by-page", queryCostNameListWithCondition, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����Ϊ Query ����ģ��
        API_HANDLER_QUERY_PARAM(costPageQuery, CostNameQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryCostNameListWithCondition(costPageQuery));
    }

    

    // ¼���������
    ENDPOINT_INFO(addCostName) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.post.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);


    }
    ENDPOINT(API_M_POST, "/billing-configuration/add-cost-name", addCostName, BODY_DTO(CostAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execAddCostName(dto, authObject->getPayload()));
    }

    //�����޸Ľӿ�����
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("cost.put.summary"), modifyCostName, StringJsonVO::Wrapper);
    //�����޸Ľӿڴ���
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/billing-configuration/modify-cost-name", modifyCostName, BODY_DTO(CostModifyDTO::Wrapper, dto), execModifyCostName(dto, authObject->getPayload()));
    

private:
    // ��ȡ���������б�ȫ����
    CostNameJsonVO::Wrapper execQueryCostNameListAll(const CostNameQuery::Wrapper& costPageQuery);

    // ��ȡ���������б�����+��ҳ��
    CostNamePageJsonVO::Wrapper execQueryCostNameListWithCondition(const CostNameQuery::Wrapper& costPageQuery);

    // ¼���������
    StringJsonVO::Wrapper execAddCostName(const CostAddDTO::Wrapper& dto,const PayloadDTO& payload);

    // �޸ķ�������
    StringJsonVO::Wrapper execModifyCostName(const CostModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_COST_NAME_CONTROLLER_