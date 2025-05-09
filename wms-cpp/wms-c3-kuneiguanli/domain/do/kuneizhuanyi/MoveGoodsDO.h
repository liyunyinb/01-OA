#pragma once
#include "domain/do/DoInclude.h"

class MoveGoodsDO {
	CC_SYNTHESIZE(string, id, Id);							   // ����
	CC_SYNTHESIZE(string, create_name, CreateName);			   // ����������
	CC_SYNTHESIZE(string, create_by, CreateBy);				   // �����˵�¼����
	CC_SYNTHESIZE(string, create_date, CreateDate);			   // ��������
	CC_SYNTHESIZE(string, update_name, UpdateName);			   // ����������
	CC_SYNTHESIZE(string, update_by, UpdateBy);				   // �����˵�¼����
	CC_SYNTHESIZE(string, update_date, UpdateDate);			   // ��������
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);		   // ��������
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);   // ������˾
	CC_SYNTHESIZE(string, order_type_code, OrderTypeCode);	   // ԭʼ��������
	CC_SYNTHESIZE(string, order_id, OrderId);				   // ԭʼ���ݱ���
	CC_SYNTHESIZE(string, order_id_i, OrderIdI);			   // ԭʼ��������Ŀ
	CC_SYNTHESIZE(string, goods_id, GoodsId);			       // ��Ʒ����
	CC_SYNTHESIZE(string, goods_name, GoodsName);			   // ��Ʒ����
	CC_SYNTHESIZE(string, goods_qua, GoodsQua);				   // ����
	CC_SYNTHESIZE(string, goods_pro_data, GoodsProData);	   // ��������
	CC_SYNTHESIZE(string, goods_unit, GoodsUnit);			   // ��λ
	CC_SYNTHESIZE(string, cus_code, CusCode);				   // �ͻ�����
	CC_SYNTHESIZE(string, cus_name, CusName);				   // �ͻ�����
	CC_SYNTHESIZE(string, tin_from, TinFrom);				   // Դ����
	CC_SYNTHESIZE(string, tin_id, TinId);					   // ������
	CC_SYNTHESIZE(string, bin_from, BinFrom);				   // Դ��λ
	CC_SYNTHESIZE(string, bin_to, BinTo);					   // ����λ
	CC_SYNTHESIZE(string, move_sta, MoveSta);				   // ״̬
	CC_SYNTHESIZE(string, to_cus_code, ToCusCode);			   // ת�ƿͻ�
	CC_SYNTHESIZE(string, to_cus_name, ToCusName);			   // ת�ƿͻ�����
	CC_SYNTHESIZE(string, base_unit, BaseUnit);				   // ������λ
	CC_SYNTHESIZE(string, base_goodscount, BaseGoodscount);       // ������λ����
	CC_SYNTHESIZE(string, to_goods_pro_data, ToGoodsProData);  // ����������
	CC_SYNTHESIZE(string, run_sta, RunSta);					   // ִ��״̬

public:
	MoveGoodsDO()
	{
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		order_type_code = "";
		order_id = "";
		order_id_i = "";
		goods_id = "";
		goods_name = "";
		goods_qua = "";
		goods_pro_data = "";
		goods_unit = "";
		cus_code = "";
		cus_name = "";
		tin_from = "";
		tin_id = "";
		bin_from = "";
		bin_to = "";
		move_sta = "";
		to_cus_code = "";
		to_cus_name = "";
		base_unit = "";
		base_goodscount = "";
		to_goods_pro_data = "";
		run_sta = "";
	}
};

// ��������ָ��
using PtrMoveGoodsDO = std::shared_ptr<MoveGoodsDO>;