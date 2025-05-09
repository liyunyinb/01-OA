#pragma once



#ifndef _customer_DTO_
#define _customer_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������ݴ������,����ò���������Ҫ
 */
class CustomerBillDTO : public oatpp::DTO
{
	DTO_INIT(CustomerBillDTO, DTO);
	// �ͻ�����;
	DTO_FIELD(String, customercode);
	DTO_FIELD_INFO(customercode) {
		info->description = ZH_WORDS_GETTER("field.customer-code");
	}
	// ����ȫ��
	DTO_FIELD(String, fullchinesename);;
	DTO_FIELD_INFO(fullchinesename) {
		info->description = ZH_WORDS_GETTER("field.full-chinese-name");
	}
};



/**
 * ʾ����ҳ�������
 */
class CustomerBillPageDTO : public PageDTO<CustomerBillDTO::Wrapper>
{

	DTO_INIT(CustomerBillPageDTO, PageDTO<CustomerBillDTO::Wrapper>);



};




#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_