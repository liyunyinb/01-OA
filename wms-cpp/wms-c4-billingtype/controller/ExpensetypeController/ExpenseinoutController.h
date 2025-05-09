#pragma once

#ifndef _EXPENSEINOUTCONTROLLER_H_
#define _EXPENSEINOUTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/query/expensetype/ExpenseTypeQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class ExpenseinoutController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ExpenseinoutController);
public:





	/*������������*/
	ENDPOINT_INFO(exportExpenceType) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expense.download.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_QUERY_PARAMS(String, "cost_type_code", ZH_WORDS_GETTER("expense.field.cost_code"),"",false);
		API_DEF_ADD_QUERY_PARAMS(String, "cost_type_name", ZH_WORDS_GETTER("expense.field.cost_type_name"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "cost_type_del", ZH_WORDS_GETTER("expense.field.cost_type_del"), "", false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/expense/download", exportExpenceType, QUERIES(QueryParams, exportParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪExportGoodsDiffPostQuery����ģ��
		API_HANDLER_QUERY_PARAM(exportQuery, ExpenseTypeQuery, exportParams);
		// ����ִ�к�����Ӧ���

		return execExportData(exportQuery);
	}

	//�����������
	ENDPOINT_INFO(uploadExpenceType) {
		//    // ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expense.upload.summary"));
		API_DEF_ADD_AUTH();
	}

	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/expense/upload", uploadExpenceType, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadExpenceType(request, authObject->getPayload()));


private: // ����ӿ�ִ�к���
	// ִ���ϴ��ļ�����
	StringJsonVO::Wrapper execUploadExpenceType(std::shared_ptr<IncomingRequest> request,const PayloadDTO& payload);
	// ִ���ļ����ش���
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportData(const ExpenseTypeQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPENSEINOUTCONTROLLER_H_