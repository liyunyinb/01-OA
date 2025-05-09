#pragma once
#ifndef _PRODUCT_QUERY_
#define _PRODUCT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ʒ��ҳ��ѯ����
 */
class Productquery : public PageQuery
{
	DTO_INIT(Productquery, PageQuery);
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, categoryname, ZH_WORDS_GETTER("product.field.categoryname"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, categorynum, ZH_WORDS_GETTER("product.field.categorynum"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, categorylevel, ZH_WORDS_GETTER("product.field.categorylevel"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODUCT_QUERY_