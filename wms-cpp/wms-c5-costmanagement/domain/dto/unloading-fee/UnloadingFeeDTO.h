#pragma once

#ifndef _UNLOADINGFEE_DTO_
#define _UNLOADINGFEE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ж�������ݴ������
 */
class UnloadingFeeDTO : public oatpp::DTO
{
	DTO_INIT(UnloadingFeeDTO, DTO);
	//����
	DTO_FIELD(String, fee);
	DTO_FIELD_INFO(fee) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.fee");
	}
	//������
	DTO_FIELD(String, acceptor);
	DTO_FIELD_INFO(acceptor) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.acceptor");
	}
	//��������
	DTO_FIELD(String, acceptDate);
	DTO_FIELD_INFO(acceptDate) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.acceptorDate");
	}
	//����
	DTO_FIELD(String, orderNo);
	DTO_FIELD_INFO(orderNo) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.orderNo");
	}
	//��Ʒ
	DTO_FIELD(String, goods);
	DTO_FIELD_INFO(goods) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.goods");
	}
	//��Ʒ����
	DTO_FIELD(String, goodsName);
	DTO_FIELD_INFO(goodsName) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.goodsName");
	}
	//ж����
	DTO_FIELD(Int32, unloadingNum);
	DTO_FIELD_INFO(unloadingNum) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.unloadingNum");
	}
	//ж������
	DTO_FIELD(Float64, unloadingWeight);
	DTO_FIELD_INFO(unloadingWeight) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.unloadingWeight");
	}
	//����RMB
	DTO_FIELD(Float64, feeRMB);
	DTO_FIELD_INFO(feeRMB) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.feeRMB");
	}
	//����
	DTO_FIELD(Float64, price);
	DTO_FIELD_INFO(price) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.price");
	}
};

/**
 * ���ж���ѷ�ҳ���ݴ������
 */
class UnloadingFeePageDTO : public PageDTO<UnloadingFeeDTO::Wrapper>
{
	DTO_INIT(UnloadingFeePageDTO, PageDTO<UnloadingFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNLOADINGFEE_DO_