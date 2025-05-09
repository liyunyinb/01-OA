#pragma once

#ifndef _PIS_QUERY_
#define _PIS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class PisQuery : public PageQuery
{
	DTO_INIT(PisQuery, PageQuery);

	// Ʒ��״̬����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("pis.field.qm_sta_name");
	}
	// Ʒ��״̬����
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("pis.field.qm_sta_code");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
