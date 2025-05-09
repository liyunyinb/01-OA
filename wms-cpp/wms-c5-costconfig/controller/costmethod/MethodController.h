#pragma once
#ifndef _METHODCONTROLLER_H_
#define _METHODCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/costmethod/BillMethodQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/costmethod/MethodVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class MethodController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(MethodController);
public:
	ENDPOINT_INFO(queryAll)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("method.queryall"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_GET, "cost-config/cost-method/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(methodquery, BillmethodQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryall(methodquery));
	}
	ENDPOINT_INFO(query) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("method.query"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MethodPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "pronut_code", ZH_WORDS_GETTER("pronut_code"), "123", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pronut_name", ZH_WORDS_GETTER("pronut_name"), "by t", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/cost-config/cost-method/query", query, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(methodquery, BillmethodQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuery(methodquery,authObject->getPayload()));
	}
	ENDPOINT_INFO(addme) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("method.add"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/cost-config/cost-method/add", addme, BODY_DTO(MethodAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddme(dto));
	}

	// 3.1 ����Ʒѷ�ʽ�޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("method.modify"), modifyme, StringJsonVO::Wrapper);
	// 3.2 ����Ʒѷ�ʽ�޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cost-config/cost-method/modify", modifyme, BODY_DTO(MethodDTO::Wrapper, dto), execModifyme(dto));
private:
	// ��ѯ����
	MethodPageJsonVO::Wrapper execQuery(const BillmethodQuery::Wrapper& query,const PayloadDTO& payload);
	MethodPageJsonVO::Wrapper execQueryall(const BillmethodQueryomit::Wrapper& query);
	StringJsonVO::Wrapper execAddme(const MethodAddDTO::Wrapper& dto);
    StringJsonVO::Wrapper execModifyme(const MethodDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_