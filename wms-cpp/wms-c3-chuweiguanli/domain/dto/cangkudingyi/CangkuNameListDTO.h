#pragma once

#ifndef _CANGKUNAMELISTDTO_H_
#define _CANGKUNAMELLISTDTO_H_

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	��ȡ�ֿ������б� ���ݴ������
class CangkuNameListDTO : public oatpp::DTO
{
	DTO_INIT(CangkuNameListDTO, DTO);

	//	�ֿ�ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("Cangku.info.id");
	}

	//	�ֿ�����
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_name");
	}

	//	�ֿ����
	DTO_FIELD(String, store_code);
	DTO_FIELD_INFO(store_code) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_code");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // _CANGKUNAMELLISTDTO_H_
