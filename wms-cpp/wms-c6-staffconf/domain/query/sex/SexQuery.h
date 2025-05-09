#pragma once
#ifndef _SEX_QUERY_
#define _SEX_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class SexQuery : public PageQuery
{
	DTO_INIT(SexQuery, PageQuery);
	// �ֶ�id
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
	DTO_FIELD(String, sexname);
	DTO_FIELD_INFO(sexname) {
		info->description = ZH_WORDS_GETTER("sample.field.sexnaame");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SEX_QUERY_
