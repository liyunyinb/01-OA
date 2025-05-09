#pragma once
#ifndef _COMPANY_QUERY_
#define _COMPANY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ��Ϣʾ����ҳ��ѯ����
 */
class CompanyInfoQuery : public PageQuery
{
	DTO_INIT(CompanyInfoQuery, PageQuery);
 	// ��˾����
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("company.field.code"));
	// ��˾���ļ��
	API_DTO_FIELD_DEFAULT(String, ChineseSampleName, ZH_WORDS_GETTER("company.field.ChineseSampleName"));
	// ��˾����ȫ��
	API_DTO_FIELD_DEFAULT(String, ChineseFullName, ZH_WORDS_GETTER("company.field.ChineseFullName"));
	// ���ĵ�ַ
	API_DTO_FIELD_DEFAULT(String, ChineseAddr, ZH_WORDS_GETTER("company.field.ChineseAddr"));
	// ��˾Ӣ�ļ��
	API_DTO_FIELD_DEFAULT(String, EnglishSampleName, ZH_WORDS_GETTER("company.field.EnglishSampleName"));
	// ��˾Ӣ��ȫ��
	API_DTO_FIELD_DEFAULT(String, EnglishFullName, ZH_WORDS_GETTER("company.field.EnglishFullName"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANYQUERY_