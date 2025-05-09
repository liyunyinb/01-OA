#pragma once
#ifndef _EXPIRATION_DATE_EARLY_WARNING_CONTROLLER_
#define _EXPIRATION_DATE_EARLY_WARNING_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/expiration-date-early-warning/ExpirationDateEarlyWarningQuery.h"
#include "domain/vo/expiration-date-early-warning/ExpirationDateEarlyWarningVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ExpirationDateEarlyWarningController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ExpirationDateEarlyWarningController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryListOfWarning) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("EWM.getthewarninglist"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpirationDateEarlyWarningPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "productcode", ZH_WORDS_GETTER("EWM.productcode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customerproductcode", ZH_WORDS_GETTER("EWM.customerproductcode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "productname", ZH_WORDS_GETTER("EWM.productname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customercode", ZH_WORDS_GETTER("EWM.customercode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customername", ZH_WORDS_GETTER("EWM.customername"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "productiondate", ZH_WORDS_GETTER("EWM.productiondate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "expirationdate", ZH_WORDS_GETTER("EWM.expirationdate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "The lower value of the remaining ratio", ZH_WORDS_GETTER("EWM.The lower value of the remaining ratio"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "The upper value of the remaining ratio", ZH_WORDS_GETTER("EWM.The upper value of the remaining ratio"), "", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/warningmanagement/expiration-date-early-warning/query-list-of-warning", queryListOfWarning, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpirationDateEarlyWarningQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryListOfWarning(userQuery, authObject->getPayload()));
	}


private:
	// 3.3 ��ʾ��ҳ��ѯ����
	ExpirationDateEarlyWarningPageJsonVO::Wrapper execQueryListOfWarning(const ExpirationDateEarlyWarningQuery::Wrapper& query, const PayloadDTO& payload);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPIRATION_DATE_EARLY_WARNING_CONTROLLER_