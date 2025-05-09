#pragma once
#ifndef _ORDERTYPEQUERY_H_
#define _ORDERTYPEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ȡ���������б�����ݴ���ģ��
 */
class OrderTypeQuery : public PageQuery
{
	DTO_INIT(OrderTypeQuery, PageQuery);
	// �������ʹ���
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("order_type.field.order_type_code"));
	// ������������
	API_DTO_FIELD_DEFAULT(String, order_type_name, ZH_WORDS_GETTER("order_type.field.order_type_name"));
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_ORDERTYPEQUERY_H_