#pragma once
#ifndef CITYTYPE_H_
#define CITYTYPE_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CityTypeNameDTO : public oatpp::DTO {
	DTO_INIT(CityTypeNameDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("citytype.uniq_id");
	}

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("citytype.name");
	}
};


class CityTypeDTO : public oatpp::DTO {
	DTO_INIT(CityTypeDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("citytype.uniq_id");
	}

	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("citytype.code");
	}

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("citytype.name");
	}

};

class CitytypeBaseDTO : public oatpp::DTO
{
	DTO_INIT(CitytypeBaseDTO, DTO);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("citytype.name");
	}
	// ����
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("citytype.code");
	}
};


/**
 * ʾ����ҳ�������
 */
class CityTypePageDTO : public PageDTO<CityTypeDTO::Wrapper>
{
	DTO_INIT(CityTypePageDTO, PageDTO<CityTypeDTO::Wrapper>);
};

/**
 * ��������ɾ�����ݴ������
 */
class CitytypeDeleteDTO : public CitytypeBaseDTO
{
	DTO_INIT(CitytypeDeleteDTO, CitytypeBaseDTO); // ע������ĸ�����Ҫ��ȷ���
	// Ψһ��ʶ
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("citytype.uniq_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
