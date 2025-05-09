#pragma once

#ifndef _TUOPAN_DTO_
#define _TUOPAN_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б�������ݶ���
 */

class TuopanBaseDTO : public oatpp::DTO
{
	DTO_INIT(TuopanBaseDTO, DTO);

	// ���̺�
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.id");
	}
	// ����˳��
	DTO_FIELD(String, tin_sort);
	DTO_FIELD_INFO(tin_sort) {
		info->description = ZH_WORDS_GETTER("tuopan.field.order");
	}
	// ��λ
	DTO_FIELD(String, bin_id);
	DTO_FIELD_INFO(bin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.place");
	}
	// ����״̬
	DTO_FIELD(String, tin_status);
	DTO_FIELD_INFO(tin_status) {
		info->description = ZH_WORDS_GETTER("tuopan.field.status");
	}
	// ����״̬
	DTO_FIELD(String, bpm_status);
	DTO_FIELD_INFO(bpm_status) {
		info->description = ZH_WORDS_GETTER("tuopan.field.bpm_status");
	}
	// ��������
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("tuopan.field.sys_org_code");
	}
	// ������˾
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("tuopan.field.sys_company_code");
	}
};

/**
 * �����б������
 */

class TuopanDTO : public TuopanBaseDTO
{
	DTO_INIT(TuopanDTO, TuopanBaseDTO);

	// ����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("tuopan.id");
	}
};

/*
* ���̷�ҳ�������
*/
class TuopanPageDTO : public PageDTO<TuopanDTO::Wrapper>
{
	DTO_INIT(TuopanPageDTO, PageDTO<TuopanDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TUOPAN_DTO_