#pragma once
#ifndef _ENTERPRISE_QUERY_
#define _ENTERPRISE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ״̬��Ϣ�б�  �������ƣ����룬Ψһ��ʶ
 */

class CompanyNameQueryStatus : public PageQuery
{
	DTO_INIT(CompanyNameQueryStatus, PageQuery);
	// ��ҵ״̬����
	API_DTO_FIELD_DEFAULT(String, inform, ZH_WORDS_GETTER("company.field.name"));


};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ENTERPRISE_QUERY_
