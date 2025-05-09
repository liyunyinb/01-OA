/*
* @Author: laughter
*/
#pragma once
#ifndef _COMPANYATTR_CONTROLLER_
#define _COMPANYATTR_CONTROLLER_

#include "domain/GlobalInclude.h"
#include"domain/query/companyattr/CompanyattrQuery.h"
#include"domain/vo/companyattr/CompanyattrVO.h"
#include"domain/dto/companyattr/CompanyattrDTO.h"
#include"domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
��ҵ����������Ϣ����
*/

class CompanyattrController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(CompanyattrController);
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.attribute.query"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyattrPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "com_type_code", ZH_WORDS_GETTER("company.attribute.id"), "01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "com_type_name", ZH_WORDS_GETTER("company.attribute.name"), ZH_WORDS_GETTER("company.attribute.nameex"), false);
	}

	ENDPOINT(API_M_GET, "/entattr/get-entattrnamelist", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(companyQuery, CompanyattrQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(companyQuery,authObject->getPayload()));
	}

	//����
	ENDPOINT_INFO(addCompanyAttr) {
		
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.attribute.add"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyattrJsonVO);
	}

	ENDPOINT(API_M_POST, "/entattr/add-entattr", addCompanyAttr, BODY_DTO(CompanyattrListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		
		API_HANDLER_RESP_VO(execAdd(dto, authObject->getPayload()));
	}

	//// �޸�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("company.attribute.mod"), modifyCompanyAttr, CompanyAttrJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/entattr/mod-entattr", modifyCompanyAttr, BODY_DTO(CompanyattrIdListDTO::Wrapper, dto), execModify(dto, authObject->getPayload()));


private:
	//��ҵ���Է�ҳ��ѯ
	CompanyattrPageJsonVO::Wrapper execQueryAll(const CompanyattrQuery::Wrapper& query, const PayloadDTO& payload);  //��ҳ��ѯ
	//��ҵ�����޸�
	Uint64JsonVO::Wrapper execModify(const CompanyattrIdListDTO::Wrapper& dto, const PayloadDTO& payload);
	//��ҵ�������
	Uint64JsonVO::Wrapper execAdd(const CompanyattrListDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_ENTERPRISE_CONTROLLER_