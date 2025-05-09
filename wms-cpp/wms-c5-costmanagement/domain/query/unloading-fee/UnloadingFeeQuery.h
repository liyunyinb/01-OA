#pragma once

#ifndef _UNLOADINGFEE_QUERY_
#define _UNLOADINGFEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ж���ѷ�ҳ��ѯ����
 */

class UnloadingFeeQuery : public PageQuery
{
	DTO_INIT(UnloadingFeeQuery, PageQuery);
	//������
	DTO_FIELD(String, acceptor);
	DTO_FIELD_INFO(acceptor) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.acceptor");
	}
	//����������ʼֵ
	DTO_FIELD(String, acceptDate_begin);
	DTO_FIELD_INFO(acceptDate_begin) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.acceptDate_begin");
	}
	//����������ֵֹ
	DTO_FIELD(String, acceptDate_end);
	DTO_FIELD_INFO(acceptDate_end) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.acceptDate_end");
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
};

#include OATPP_CODEGEN_END(DTO)
#endif // _UNLOADINGFEE_DO_