#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/3/10 14:33

*/
#ifndef _REVIEW_STT_QUERY_
#define _REVIEW_STT_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���̷�ҳ��ѯ����
 */
class ReviewSttQuery : public PageQuery
{
	DTO_INIT(ReviewSttQuery, PageQuery);

	// ��λ
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("goods.field.bin_id"));

	// ����
	API_DTO_FIELD_DEFAULT(String, tin_id, ZH_WORDS_GETTER("goods.field.tin_id"));

	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("goods.field.goods_id"));

	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("goods.field.goods_name"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, goods_pro_data, ZH_WORDS_GETTER("goods.field.goods_pro_data"));

	// ����
	API_DTO_FIELD_DEFAULT(String, goods_batch, ZH_WORDS_GETTER("goods.field.goods_batch"));

	// ��������--�ͻ����ƣ�
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("goods.field.cus_name"));

	// ����--�ͻ���
	API_DTO_FIELD_DEFAULT(String, cus, ZH_WORDS_GETTER("goods.field.cus"));

	// �̵�״̬
	API_DTO_FIELD_DEFAULT(String, stt_sta, ZH_WORDS_GETTER("goods.field.stt_sta"));
};


/**
 * ������������---�в�ѯ����
 */
class ExportReviewSttQuery : public ReviewSttQuery
{
	DTO_INIT(ExportReviewSttQuery, ReviewSttQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REVIEW_STT_QUERY_