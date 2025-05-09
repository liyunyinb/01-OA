#pragma once
#ifndef _INVENTORY_DO_
#define _INVENTORY_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class InventoryPDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	//�̵���
	CC_SYNTHESIZE(string, stt_name, Stt_name);
	//�̵�����
	CC_SYNTHESIZE(string, stt_date, Stt_date);
	// ��λ
	CC_SYNTHESIZE(string, bin_id, Bin_id);
	//����
	CC_SYNTHESIZE(string, tin_id, Tin_id);
	//��Ʒ����
	CC_SYNTHESIZE(string, goods_id, Goods_id);
	//��Ʒ����
	CC_SYNTHESIZE(string, goods_name, Goods_name);
	//��Ŀ����
	CC_SYNTHESIZE(string, goods_qua, Goods_qua);
	//��λ
	CC_SYNTHESIZE(string, goods_unit, Goods_unit);
	// ��������
	CC_SYNTHESIZE(string, goods_pro_data, Goods_pro_data);
	// �̵�����
	CC_SYNTHESIZE(string, stt_qua, Stt_qua);
	//����
	CC_SYNTHESIZE(string, cus_code, Cus_code);
	//��������
	CC_SYNTHESIZE(string, cus_id, Cus_id);
	//�̵�״̬
	CC_SYNTHESIZE(string, stt_sta, Stt_sta);
public:
	InventoryPDO() {
		id = "";
		stt_name = "Li Hua";
		stt_date = "2099-12-31";
		bin_id = "X1-1-03";
		tin_id = "";
		goods_id = "";
		goods_name = "";
		goods_qua = "";
		goods_unit = "��";
		goods_pro_data = "2099-12-31";
		stt_qua = "";
		cus_code = "halo";
		cus_id = "X00001";
		stt_sta = "";
	}
};

// ��InventoryPDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<InventoryPDO> PtrInventoryPDO;
#endif // !_INVENTORY_DO_