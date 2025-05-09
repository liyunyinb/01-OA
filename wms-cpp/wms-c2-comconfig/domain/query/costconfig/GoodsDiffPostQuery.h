#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/2/22 14:33

*/
#ifndef _GOODS_DIFF_POST_QUERY_
#define _GOODS_DIFF_POST_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �̵���ҵ�ȼ���ҳ��ѯ����
 */
class GoodsDiffPostQuery : public PageQuery
{
	DTO_INIT(GoodsDiffPostQuery, PageQuery);

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

	//��������--��ʼ
	API_DTO_FIELD_DEFAULT(String, create_date_start, ZH_WORDS_GETTER("goods.field.create_date_start"));

	//��������--��ֹ
	API_DTO_FIELD_DEFAULT(String, create_date_end, ZH_WORDS_GETTER("goods.field.create_date_end"));
};


/**
 * �����̵���ҵ�ȼ�����---�в�ѯ����
 */
class ExportGoodsDiffPostQuery : public GoodsDiffPostQuery
{
	DTO_INIT(ExportGoodsDiffPostQuery, GoodsDiffPostQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GOODS_DIFF_POST_QUERY_