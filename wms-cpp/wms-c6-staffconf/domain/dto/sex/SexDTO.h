#pragma once
#ifndef _SEX_DTO_
#define _SEX_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ա��������ݴ������
 */
class SexAddDTO : public oatpp::DTO
{
	DTO_INIT(SexAddDTO, DTO);
	//�ֶ�id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sex.filed.id");
	}
	// �Ա����
	DTO_FIELD(String, sexcode);
	DTO_FIELD_INFO(sexcode) {
		info->description = ZH_WORDS_GETTER("sex.filed.sexcode");
	}
	// �Ա�����
	DTO_FIELD(String, age);
	DTO_FIELD_INFO(sexname) {
		info->description = ZH_WORDS_GETTER("sex.filed.sexname");
	}

	}
};

/**
 * �Ա������
 */
class SexDTO : public SexAddDTO
{
	DTO_INIT(SexDTO, SexAddDTO);
	// �Ա����
	DTO_FIELD(String, sexcode);
	DTO_FIELD_INFO(sexcode) {
		info->description = ZH_WORDS_GETTER("sex.filed.sexcode");
	}
};

/**
 * ʾ����ҳ�������
 */
class SexPageDTO : public PageDTO<SampleDTO::Wrapper>
{
	DTO_INIT(SexPageDTO, PageDTO<SampleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Sex_DTO_