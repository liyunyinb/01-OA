#pragma once
#ifndef _REMOVAL_DO_
#define _REMOVAL_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class RemovalDO
{
	// Ψһ����
	CC_SYNTHESIZE(string, id, Id);
	// ԭʼ���ݱ���order_id  
	CC_SYNTHESIZE(string, order_id, Order_id);
	//  ��Ʒ����goods_id
	CC_SYNTHESIZE(string, goods_id, Goods_id);
	// ��Ʒ����
	CC_SYNTHESIZE(string, goods_name, Goods_name);
	CC_SYNTHESIZE(string , goods_qua, Goods_qua);
public:
	RemovalDO() {
		id = "";
		order_id = "";
		goods_id = "";
		goods_name = "";
		goods_qua = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RemovalDO> PtrRemovalDO;
#endif // !_SAMPLE_DO_