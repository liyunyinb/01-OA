#pragma once
#ifndef _COMPANYINFODTO_
#define _COMPANYINFODTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ������Ϣ���ݴ������
 */
class CompanyBaseeDTO : public oatpp::DTO
{
	// ��ʼ��
	DTO_INIT(CompanyBaseeDTO, DTO);

	// ��˾����
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("company.field.code"));

	// ��˾���ļ��
	API_DTO_FIELD_DEFAULT(String, ChineseFullName, ZH_WORDS_GETTER("company.field.ChineseFullName"));

	// ��˾����ȫ��
	API_DTO_FIELD_DEFAULT(String, ChineseSampleName, ZH_WORDS_GETTER("company.field.ChineseSampleName"));

	// ��˾��ַ
	API_DTO_FIELD_DEFAULT(String, ChineseAddr, ZH_WORDS_GETTER("company.field.ChineseAddr"));

	// ��˾Ӣ�ļ��
	API_DTO_FIELD_DEFAULT(String, EnglishSampleName, ZH_WORDS_GETTER("company.field.EnglishSampleName"));

	// ��˾Ӣ��ȫ��
	API_DTO_FIELD_DEFAULT(String, EnglishFullName, ZH_WORDS_GETTER("company.field.EnglishFullName"));
};


class CompanyListDTO : public CompanyBaseeDTO
{
	// ��ʼ��
	DTO_INIT(CompanyListDTO, CompanyBaseeDTO);
	// Ψһ��ʶ
 	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("company.field.id"));
};



//��˾��Ϣ��ҳ�������
class CompanyListPageDTO : public PageDTO<CompanyListDTO::Wrapper>
{
	DTO_INIT(CompanyListPageDTO, PageDTO<CompanyListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANY_DTO_