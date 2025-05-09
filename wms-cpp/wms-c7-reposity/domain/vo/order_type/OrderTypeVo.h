#pragma once

#ifndef _ORDERTYPEVO_H_
#define _ORDERTYPEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/order_type/OrderTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���������͵�������ʾJsonVO����
 */
class OrderTypeVO : public JsonVO<OrderTypeDTO::Wrapper> {
    DTO_INIT(OrderTypeVO, JsonVO<OrderTypeDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class OrderTypePageJsonVO : public JsonVO<OrderTypePageDTO::Wrapper> 
{
    DTO_INIT(OrderTypePageJsonVO, JsonVO<OrderTypePageDTO::Wrapper>);
};

/**
 * �������������б���ʾJsonVO����������Ӧ���ͻ���
 */
class OrderTypeNameVO : public JsonVO<OrderTypeNamePageDTO::Wrapper> {
    DTO_INIT(OrderTypeNameVO, JsonVO<OrderTypeNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDERTYPEVO_H_
