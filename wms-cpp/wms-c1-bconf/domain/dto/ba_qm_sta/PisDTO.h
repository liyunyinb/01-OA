#pragma once

#ifndef _PIS_DTO_
#define _PIS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ������Ʒ��״̬���ݴ������
 */
class PisAddDTO : public oatpp::DTO
{
	DTO_INIT(PisAddDTO, DTO);
	// Ʒ��״̬����
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("pis.field.qm_sta_code");
	}
	// Ʒ��״̬����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("pis.field.qm_sta_name");
	}
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("pis.field.id");
	}
};

/**
 * ʾ���������
 */
class PisDTO : public PisAddDTO
{
	DTO_INIT(PisDTO, PisAddDTO);
	//// ���
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("pis.field.id");
	//}
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("qis.field.id"));
};

/**
 * ʾ����ҳ�������
 */
class PisPageDTO : public PageDTO<PisDTO::Wrapper>
{
	DTO_INIT(PisPageDTO, PageDTO<PisDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
