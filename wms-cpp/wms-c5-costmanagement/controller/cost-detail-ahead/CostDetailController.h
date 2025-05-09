#pragma once

#ifndef _COST_CONTROLLER_
#define _COST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/cost-detail-ahead/CostDetialDTO.h"
#include "domain/vo/cost-detail-ahead/CostDetialVO.h"
#include "domain/query/cost-detail-ahead/CostDetailQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ������ϸ���� ����������ʾ�����ӿڵ�ʹ��
 */
class CostDetialController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CostDetialController);
	// 3 ����ӿ�
public:
	// 3.1 �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(querypageAll) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.pagequery"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CostDetailListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "cusCode", ZH_WORDS_GETTER("cost.field.cus_code"), "X00001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cusName", ZH_WORDS_GETTER("cost.field.cus_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costCode", ZH_WORDS_GETTER("cost.field.cost_code"), "2001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costName", ZH_WORDS_GETTER("cost.field.cost_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costDateBegin", ZH_WORDS_GETTER("cost.field.cost_date"), "2025-02-19 00:00:00", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costDateEnd", ZH_WORDS_GETTER("cost.field.cost_date"), "2025-02-25 00:00:00", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costOrigin", ZH_WORDS_GETTER("cost.field.cost_ori"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "note", ZH_WORDS_GETTER("cost.field.beizhu"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costState", ZH_WORDS_GETTER("cost.field.cost_sta"), "", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/cost-management/cost-detail/query-cost", querypageAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(costDetailQuery, CostDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPageAll(costDetailQuery));
	}
	/*
	// 3.1 ����������ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.query"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CostDetailJsonVO);
		
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "cusCode", ZH_WORDS_GETTER("cost.field.cus_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cusName", ZH_WORDS_GETTER("cost.field.cus_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costCode", ZH_WORDS_GETTER("cost.field.cost_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costName", ZH_WORDS_GETTER("cost.field.cost_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costDateBegin", ZH_WORDS_GETTER("cost.field.cost_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costDateEnd", ZH_WORDS_GETTER("cost.field.cost_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costOrigin", ZH_WORDS_GETTER("cost.field.cost_ori"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "note", ZH_WORDS_GETTER("cost.field.beizhu"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costState", ZH_WORDS_GETTER("cost.field.cost_sta"), "", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/cost-detail/query-cost", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(costQuery, CostDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(costQuery, authObject->getPayload()));
	}*/



	// 3.1 ����¼�������ϸ�ӿ�����
	ENDPOINT_INFO(addCost) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.post.add"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
	}
	// 3.2 ����¼�������ϸ�ӿڴ���
	ENDPOINT(API_M_POST, "/cost-management/cost-detail/add-cost", addCost, BODY_DTO(CostDetailAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddCost(dto, authObject->getPayload()));
	}

	// 3.1 ����༭������ϸ�ӿ�����
	ENDPOINT_INFO(editCost) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.put.edit"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
	}
	// 3.2 ���������ϸ�ӿڴ���
	ENDPOINT(API_M_PUT, "/cost-management/cost-detail/edit-cost", editCost, BODY_DTO(CostDetailEditDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		 //����ִ�к�����Ӧ���/cost-detail
		API_HANDLER_RESP_VO(execeditCost(dto, authObject->getPayload()));
	}


	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeCostById) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost.delete.summary"), StringJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("cost.field.id"), "", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-management/cost-detail/by-id/{id}", removeCostById, PATH(String, id), execRemoveCost(id));



	// 3.1 ��������ɾ���ӿ�����
	ENDPOINT_INFO(removeCostAll) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost.delete.all"), StringJsonVO::Wrapper);

		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(List<String>, "ids", ZH_WORDS_GETTER("cost.field.ids"), {}, true);
	}
	// 3.2 ��������ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-management/cost-detail/remove-batch", removeCostAll, BODY_DTO(List<String>, ids), execRemoveAllCost(ids));


private:
	// 3.3 ��ʾ��ҳ��ѯ����
	CostDetailListPageJsonVO::Wrapper execQueryPageAll(const CostDetailQuery::Wrapper& query);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddCost(const CostDetailAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 ��ʾ�޸�����
	StringJsonVO::Wrapper execeditCost(const CostDetailEditDTO::Wrapper& dto, const PayloadDTO& payload);
	
	// 3.3 ��ʾ����ɾ������
	StringJsonVO::Wrapper execRemoveCost(const String& id);
	// 3.3 ��ʾ����ɾ������
	StringJsonVO::Wrapper execRemoveAllCost(const List<String>& ids);


};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COST_CONTROLLER_

