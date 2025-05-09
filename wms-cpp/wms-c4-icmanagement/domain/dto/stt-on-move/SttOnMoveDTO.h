#pragma once

#ifndef _STT_ON_MOVE_DTO_
#define _STT_ON_MOVE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*	�����̵�������ݶ����б���ʾ����
*/
class SttOnMoveBaseDTO : public oatpp::DTO 
{
	DTO_INIT(SttOnMoveBaseDTO, oatpp::DTO);

	// �ƶ�����
	API_DTO_FIELD_DEFAULT(String, last_move, ZH_WORDS_GETTER("sttOnMove.field.lastMove"));
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
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_qua, ZH_WORDS_GETTER("sttOnMove.field.goodsQua"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("sttOnMove.field.shpMingCheng"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, goods_pro_data, ZH_WORDS_GETTER("sttOnMove.field.goodsProData"));
	// ������
	API_DTO_FIELD_DEFAULT(String, goods_save_date, ZH_WORDS_GETTER("sttOnMove.field.bzhiQi"));
	// ��λ
	API_DTO_FIELD_DEFAULT(String, goods_unit, ZH_WORDS_GETTER("sttOnMove.field.goodsUnit"));
	// ������λ
	API_DTO_FIELD_DEFAULT(String, base_unit, ZH_WORDS_GETTER("sttOnMove.field.baseUnit"));
	// �̵�״̬
	API_DTO_FIELD_DEFAULT(String, stt_sta, ZH_WORDS_GETTER("sttOnMove.field.sttSta"));
};


/*
* �����̵��б���󣬴�Ψһ��ʶ
*/
class SttOnMoveListDTO : public SttOnMoveBaseDTO
{
	DTO_INIT(SttOnMoveListDTO, SttOnMoveBaseDTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sttOnMove.field.id"));
};

/*
* �������������ݶ���
*/
class SttOnMoveDetailDTO : public SttOnMoveListDTO
{
	DTO_INIT(SttOnMoveDetailDTO, SttOnMoveListDTO);
	// �ƶ�״̬
	API_DTO_FIELD_DEFAULT(String,move_sta,ZH_WORDS_GETTER("sttOnMove.field.move_sta"));
	// ����
	API_DTO_FIELD_DEFAULT(String, sys_org_code,ZH_WORDS_GETTER("sttOnMove.field.sys_org_code"));
	// ��˾
	API_DTO_FIELD_DEFAULT(String, sys_company_code,ZH_WORDS_GETTER("sttOnMove.field.sys_company_code"));
};

/*
* �����̵��ҳ��ѯ�������
*/
class SttOnMovePageDTO : public PageDTO<SttOnMoveListDTO::Wrapper>
{
	DTO_INIT(SttOnMovePageDTO, PageDTO<SttOnMoveListDTO::Wrapper>);
};

/*
* �ɶ����������̵�����DTO�����������ѯid����,Ҳ���ڷ��ز�ѯ�ɹ���id
*/
class SttOnMoveInsertTaskDTO : public oatpp::DTO
{
	DTO_INIT(SttOnMoveInsertTaskDTO,DTO);

	API_DTO_FIELD_DEFAULT(Vector<String>,ids,ZH_WORDS_GETTER("sttOnMove.field.ids"));
};

#include OATPP_CODEGEN_END(DTO)

#endif