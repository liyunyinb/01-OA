#pragma once
#ifndef _COMDEG_QUERY_
#define _COMDEG_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��˾�ȼ���ҳ��ѯ����
 */
class ComdegQuery : public PageQuery
{
	DTO_INIT(ComdegQuery, PageQuery);

	//��ҵ�ȼ�����
	API_DTO_FIELD_DEFAULT(String, degname, ZH_WORDS_GETTER("com.field.degname"));

	//��ҵ�ȼ�����
	API_DTO_FIELD_DEFAULT(String, degcode, ZH_WORDS_GETTER("com.field.degcode"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMDEG_QUERY_