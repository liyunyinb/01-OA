#pragma once

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/customer-bill/CustomerBillVO.h"
#include "domain/query/customer-bill/CustomerBillQuery.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include "string"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class CustormerBillController : public oatpp::web::server::api::ApiController {

    // 2 ����������������
    API_ACCESS_DECLARE(CustormerBillController);

public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(Customer_Bill) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("api.seek_customer_bill"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CustomerBillPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "customercode", ZH_WORDS_GETTER("field.customer-code"), "001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fullchinesename", ZH_WORDS_GETTER("field.full-chinese-name"), ZH_WORDS_GETTER("field.sample"), false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/cost-management/customer-bill/query", Customer_Bill, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, CustomerBillQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySample(Query, authObject->getPayload()));
	}



	// ����δ���˵������ӿ�
	// ��������
	ENDPOINT_INFO(unsettled) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("field.export"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "customercode", ZH_WORDS_GETTER("field.customer-code"), "1250", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("bill.filename"), "file/text.xlsx", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/cost-management/customer-bill/export-unsettled", unsettled, QUERIES(QueryParams, queryFile)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(file, UnsettledQuery, queryFile);

		return execExportFile(file);

	}


	// �����ڼ��˵������ӿ�
	// ��������
	ENDPOINT_INFO(period) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("field.export1"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "customercode", ZH_WORDS_GETTER("field.customer-code"), "1250", true);
		API_DEF_ADD_QUERY_PARAMS(String, "startdate", ZH_WORDS_GETTER("field.begin"), "2020-01-23 00:00:00", true);
		API_DEF_ADD_QUERY_PARAMS(String, "enddate", ZH_WORDS_GETTER("field.end"), "2020-01-29 00:00:00", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("bill.filename"), "file/tsxt.xlsx", true);//���������������˵

	}
	// ����˵�
	ENDPOINT(API_M_GET, "/cost-management/customer-bill/export-period", period, QUERIES(QueryParams, queryFile)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(file, PeriodQuery, queryFile);

		return execperiodFile(file);
	}
	


private:

	// ִ��δ���ļ���������
	std::shared_ptr<OutgoingResponse> execExportFile(const UnsettledQuery::Wrapper& file);
	// ִ���ڼ��ļ���������
	std::shared_ptr<OutgoingResponse> execperiodFile(const PeriodQuery::Wrapper& file);

	// 3.3 ��ʾ��ҳ��ѯ����
	CustomerBillPageJsonVO::Wrapper execQuerySample(const CustomerBillQuery::Wrapper& query, const PayloadDTO& payload);
};





#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section