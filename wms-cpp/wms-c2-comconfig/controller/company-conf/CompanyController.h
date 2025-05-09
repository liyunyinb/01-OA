#pragma once

#ifndef _COMPANY_CONTROLLER_
#define _COMPANY_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/company-conf/CompanyInfoVO.h"
#include "domain/query/company-conf/CompanyInfoQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class CompanyController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(CompanyController);
public:

	// ��ѯ������ҵ��Ϣ
	ENDPOINT_INFO(queryALL) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.query-all.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("company.field.code"), "a01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ChineseSampleName", ZH_WORDS_GETTER("company.field.ChineseSampleName"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ChineseFullName", ZH_WORDS_GETTER("company.field.ChineseFullName"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ChineseAddr", ZH_WORDS_GETTER("company.field.ChineseAddr"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "EnglishSampleName", ZH_WORDS_GETTER("company.field.EnglishSampleName"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "EnglishFullName", ZH_WORDS_GETTER("company.field.EnglishFullName"), "2", false);
	}
	ENDPOINT(API_M_GET, "/cominfo/get-cominfolist", queryALL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(compQuery, CompanyInfoQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryALL(compQuery));
	}

	// ��ѯ������ҵ��Ϣ
	ENDPOINT_INFO(queryDETAIL) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("company.query-all.detail"), CompanyInfoVOJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("company.field.code"), 1, true);
	}
	// 3.2 ����ID��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/cominfo/get-cominfodetail", queryDETAIL, QUERY(Int64, id), execQueryDETAIL(id));
	//ENDPOINT_INFO(queryDETAIL) {
	//    // ����ӿڱ���
	//    API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.query-all.detail"));
	//    // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//    API_DEF_ADD_AUTH();
	//    // ������Ӧ������ʽ
	//    API_DEF_ADD_RSP_JSON_WRAPPER(CompanyPageJsonVO);
	//    // �����ҳ��ѯ��������
	//    API_DEF_ADD_PAGE_PARAMS();
	//    // ����������ѯ��������
	//    API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("company.field.code"), "a01", false);
	//}
	//ENDPOINT(API_M_GET, "/cominfo/get-cominfodetail", queryDETAIL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	//    API_HANDLER_QUERY_PARAM(compQuery, CompanyInfoQuery, queryParams);
	//    // ����ִ�к�����Ӧ���
	//    API_HANDLER_RESP_VO(execQueryDETAIL(compQuery));
	//}

private:
	// ��ѯ������Ϣ
	CompanyPageJsonVO::Wrapper execQueryALL(const CompanyInfoQuery::Wrapper& query);
	// ��ѯ������Ϣ
	CompanyInfoVOJsonVO::Wrapper execQueryDETAIL(const Int64& id);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_COMPANY_CONTROLLER_