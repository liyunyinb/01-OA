#pragma once
#ifndef _MOVE_DO_
#define _MOVE_DO_
#include "domain/do/DoInclude.h"

class MoveDO {
	CC_SYNTHESIZE(string, move_date, MoveDate);        //��������/�ƶ�����
	CC_SYNTHESIZE(string, kuctype, KucType);							   // �������
	CC_SYNTHESIZE(string, ku_wei_bian_ma, KuWeiBianMa);			   // ��λ
	CC_SYNTHESIZE(string, bin_id, BinId);				   // ����
	CC_SYNTHESIZE(string, cus_code, CusCode);			   // ����
	CC_SYNTHESIZE(string, zhong_wen_qch, ZhongWenQch);			   // ��������
	CC_SYNTHESIZE(string, goods_id, GoodsId);				   // ��Ʒ����
	CC_SYNTHESIZE(string, goods_qua, GoodsQua);			   // ��Ʒ����
	CC_SYNTHESIZE(string, shp_ming_cheng, ShpMingCheng);		   // ��Ʒ����
	CC_SYNTHESIZE(string, goods_pro_data, GoodsProData);   // ��������
	CC_SYNTHESIZE(string, bzhi_qi, BzhiQi);	   // ������
	CC_SYNTHESIZE(string, goods_unit, GoodsUnit);				   // ��λ
	CC_SYNTHESIZE(string, stt_sta, SttSta);			   // ״̬
	
	

public:
	MoveDO()
	{
		move_date = "";
		kuctype = "";
		ku_wei_bian_ma = "";
		bin_id = "";
		cus_code = "";
		zhong_wen_qch = "";
		goods_id = "";
		goods_qua = "";
		shp_ming_cheng = "";
		goods_pro_data = "";
		bzhi_qi = "";
		goods_unit = "";
		stt_sta = "";
		
	}
};
// ��MoveDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<MoveDO> PtrMoveDO;
#endif // !_MOVE_DO_