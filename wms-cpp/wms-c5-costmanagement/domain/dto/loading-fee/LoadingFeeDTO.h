#pragma once

#ifndef _LOADINGFEE_DTO_
#define _LOADINGFEE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���װ�������ݴ������
 */
class LoadingFeeDTO : public oatpp::DTO
{
	DTO_INIT(LoadingFeeDTO, DTO);
	//����
	DTO_FIELD(String, fee);
	DTO_FIELD_INFO(fee) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.fee");
	}
	//������
	DTO_FIELD(String, Operator);//operator�ǹؼ��֣����Ը�ΪOperator
	DTO_FIELD_INFO(Operator) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.operator");
	}
	//��������
	DTO_FIELD(String, operateDate);
	DTO_FIELD_INFO(operateDate) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.operateDate");
	}
	//����
	DTO_FIELD(String, orderNo);
	DTO_FIELD_INFO(orderNo) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.orderNo");
	}
	//��Ʒ
	DTO_FIELD(String, goods);
	DTO_FIELD_INFO(goods) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.goods");
	}
	//��Ʒ����
	DTO_FIELD(String, goodsName);
	DTO_FIELD_INFO(goodsName) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.goodsName");
	}
	//װ����
	DTO_FIELD(Int32, goodsNum);
	DTO_FIELD_INFO(goodsNum) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.goodsNum");
	}
	//װ������
	DTO_FIELD(Float64, goodsWeight);
	DTO_FIELD_INFO(goodsWeight) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.goodsWeight");
	}
	//����RMB
	DTO_FIELD(Float64, feeRMB);
	DTO_FIELD_INFO(feeRMB) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.feeRMB");
	}
	//����
	DTO_FIELD(Float64, price);
	DTO_FIELD_INFO(price) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.price");
	}
};

/**
 * ���װ���ѷ�ҳ���ݴ������
 */
class LoadingFeePageDTO : public PageDTO<LoadingFeeDTO::Wrapper>
{
	DTO_INIT(LoadingFeePageDTO, PageDTO<LoadingFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LOADINGFEE_DTO_