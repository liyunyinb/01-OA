#pragma once
// ================================================================
// @FileName��    
// @Author��    cslr
// @Date��   2025-2-22
// Summary��  
//================================================================
#ifndef _LADMOD_QUERY_
#define _LADMOD_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ʾ����ҳ��ѯ����
 */
class LadModQuery : public PageQuery
{
	DTO_INIT(LadModQuery, PageQuery);
	// �����ʽ����
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("lad.field.code");
	}
	// �����ʽ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("lad.field.name");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_