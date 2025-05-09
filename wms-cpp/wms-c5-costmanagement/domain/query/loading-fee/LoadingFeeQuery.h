#pragma once

#ifndef _LOADINGFEE_QUERY_
#define _LOADINGFEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���װ���ѷ�ҳ��ѯ����
 */
class LoadingFeeQuery : public PageQuery
{
	DTO_INIT(LoadingFeeQuery, PageQuery);
	//������
	DTO_FIELD(String, Operator);
	DTO_FIELD_INFO(Operator) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.operator");
	}
	//����������ʼֵ
	DTO_FIELD(String, operateDate_begin);
	DTO_FIELD_INFO(operateDate_begin) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.operateDate_begin");
	}
	//����������ֵֹ
	DTO_FIELD(String, operateDate_end);
	DTO_FIELD_INFO(operateDate_end) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.operateDate_end");
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
};

#endif // !_LOADINGFEE_QUERY_