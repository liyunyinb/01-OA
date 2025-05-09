#pragma once

#ifndef _QUALITY_QUERY_
#define _QUALITY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Ʒ�ʴ����ҳ��ѯ����
 */
class QualityQuery : public PageQuery
{
	DTO_INIT(QualityQuery, PageQuery);
	// Ʒ�ʴ��� 
	API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("quality.qm_qa_code"));

	// Ʒ�ʴ�������
	API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("quality.qm_qa_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUALITY_QUERY_