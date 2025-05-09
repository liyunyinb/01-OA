#pragma once

#ifndef _customer_VO_
#define _customer_VO_

#include "../../GlobalInclude.h"
#include "../../dto/customer-bill/CustomerBillDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����--------------����������
 */
class CustomerBillJsonVO : public JsonVO<CustomerBillDTO::Wrapper> {
	DTO_INIT(CustomerBillJsonVO, JsonVO<CustomerBillDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CustomerBillPageJsonVO : public JsonVO<CustomerBillPageDTO::Wrapper> {
	DTO_INIT(CustomerBillPageJsonVO, JsonVO<CustomerBillPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_