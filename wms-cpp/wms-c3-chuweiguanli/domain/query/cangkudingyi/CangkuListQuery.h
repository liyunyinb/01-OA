#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ֿ��ҳ��ѯ����
 */
class CangkuListQuery : public PageQuery
{
	DTO_INIT(CangkuListQuery, PageQuery);
	// �ֿ����
	DTO_FIELD(String, store_code);
	DTO_FIELD_INFO(store_code) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_code");
	}
	// �ֿ�����
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_name");
	}
	// �ֿ�����
	DTO_FIELD(String, store_text);
	DTO_FIELD_INFO(store_text) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_text");
	}
};

#include OATPP_CODEGEN_END(DTO)