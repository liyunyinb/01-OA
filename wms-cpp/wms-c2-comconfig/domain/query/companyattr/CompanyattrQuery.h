#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_QUERY_
#define _COMPANYATTR_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ��ҳ��ѯ����
 */
class CompanyattrQuery : public PageQuery
{
	DTO_INIT(CompanyattrQuery, PageQuery);
	// ��ҵ�û�����
	API_DTO_FIELD_DEFAULT(String, com_type_code, ZH_WORDS_GETTER("company.attribute.id"));
	//��ҵ�û�����
	API_DTO_FIELD_DEFAULT(String, com_type_name, ZH_WORDS_GETTER("company.attribute.name"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANYATTR_QUERY_