#pragma once

#ifndef _COMPANYNAME_DTO_
#define _COMPANYNAME_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//��ȡ״̬�����б�
class CompanyNameDTO : public oatpp::DTO
{
	DTO_INIT(CompanyNameDTO, oatpp::DTO);

	//Ψһ��ʶ��
	DTO_FIELD(List<String>, id) = {};
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("company.field.id");
	}

	// ��ҵ����
	DTO_FIELD(List<String>, code) = {};
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("company.field.code");
	}

	// ��ҵ����
	DTO_FIELD(List<String>, name) = {};
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("company.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
