#pragma once
#ifndef _ORDERTYPEDTO_H_
#define _ORDERTYPEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ¼�붩������DTO
*/ 
class OrderTypeAddDTO : public oatpp::DTO
{
	DTO_INIT(OrderTypeAddDTO, DTO);
	// �������ʹ���
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("order_type.field.order_type_code"));
	// ������������
	API_DTO_FIELD_DEFAULT(String, order_type_name, ZH_WORDS_GETTER("order_type.field.order_type_name"));
};

/**
 * ����һ����ȡ�������͵����ݴ���ģ�ͣ�����id
 */
class OrderTypeDTO : public OrderTypeAddDTO
{
	DTO_INIT(OrderTypeDTO, OrderTypeAddDTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("order_type.field.order_type_id"));
};

// ��ȡ�������������б�(����id)
// ...
class InitDTO : public oatpp::DTO
{
	DTO_INIT(InitDTO, DTO);
};

class OrderTypeNameDTO : public oatpp::DTO
{
	DTO_INIT(OrderTypeNameDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("order_type.field.order_type_id"));
	API_DTO_FIELD_DEFAULT(String, order_type_name, ZH_WORDS_GETTER("order_type.field.order_type_name"));
};

class OrderTypeNamePageDTO : public PageDTO<OrderTypeNameDTO::Wrapper>
{
	DTO_INIT(OrderTypeNamePageDTO, PageDTO);
};

/**
*  ���������б��ҳ�������
*/
class OrderTypePageDTO : public PageDTO<OrderTypeDTO::Wrapper>
{
	DTO_INIT(OrderTypePageDTO, PageDTO);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERTYPEDTO_H_
