#pragma once

#ifndef _STT_ON_MOVE_QUERY_
#define _STT_ON_MOVE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �����̵��ҳ��ѯ����
*/
class SttOnMoveQuery : public PageQuery
{
	DTO_INIT(SttOnMoveQuery, PageQuery);

	//�����ƶ�����
	API_DTO_FIELD_DEFAULT(String, last_move_start,ZH_WORDS_GETTER("sttOnMove.field.lastMoveStart"));
	// �����ƶ�����
	API_DTO_FIELD_DEFAULT(String, last_move_end,ZH_WORDS_GETTER("sttOnMove.field.lastMoveEnd"));
	// �������
	API_DTO_FIELD_DEFAULT(String, cktype, ZH_WORDS_GETTER("sttOnMove.field.kuctype"));
	// ��λ or ��λ����
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("sttOnMove.field.kuWeiBianMa"));
	// ����
	API_DTO_FIELD_DEFAULT(String, tin_id, ZH_WORDS_GETTER("sttOnMove.field.binId"));
	// ����
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("sttOnMove.field.cusCode"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("sttOnMove.field.zhongWenQch"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("sttOnMove.field.goodsId"));
	// ��С��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_qua_min, ZH_WORDS_GETTER("sttOnMove.field.goodsQuaMin"));
	// �����Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_qua_max, ZH_WORDS_GETTER("sttOnMove.field.goodsQuaMax"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("sttOnMove.field.shpMingCheng"));
	// ������������
	API_DTO_FIELD_DEFAULT(String, goods_pro_data_start, ZH_WORDS_GETTER("sttOnMove.field.goodsProDataStart"));
	// ������������
	API_DTO_FIELD_DEFAULT(String, goods_pro_data_end, ZH_WORDS_GETTER("sttOnMove.field.goodsProDataEnd"));
};

#include OATPP_CODEGEN_END(DTO)

#endif