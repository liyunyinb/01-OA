#pragma once
#include "../wms-c7-reposity/domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class tyleadDTO : public oatpp::DTO
{
	DTO_INIT(tyleadDTO, DTO);
	// ҵ�����ʹ���
	DTO_FIELD(String, num);
	DTO_FIELD_INFO(num) {
		info->description = ZH_WORDS_GETTER("tylead.num");
	}
	// ҵ����������
	DTO_FIELD(String,name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("tylead.name");
	}
	// ҵ�����ͱ�ע
	DTO_FIELD(String, desc);
	DTO_FIELD_INFO(desc) {
		info->description = ZH_WORDS_GETTER("tylead.desc");
	}
	// ���
	DTO_FIELD(UInt16, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("tylead.id");
	}
};


