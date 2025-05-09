#pragma once

#ifndef _UNLOADINGFEE_DO_
#define _UNLOADINGFEE_DO_
#include "DoInclude.h"

//���ж�������ݿ�ʵ����
class UnloadingFeeDO
{
	// ����
	CC_SYNTHESIZE(string, fee, Fee);
	//������
	CC_SYNTHESIZE(string, acceptor, Acceptor);
	//��������
	CC_SYNTHESIZE(string, acceptDate, AcceptDate);
	//����
	CC_SYNTHESIZE(string, orderNo, OrderNo);
	//��Ʒ
	CC_SYNTHESIZE(string, goods, Goods);
	//��Ʒ����
	CC_SYNTHESIZE(string, goodsName, GoodsName);
	//ж����
	CC_SYNTHESIZE(int, unloadingNum, UnloadingNum);
	//ж������
	CC_SYNTHESIZE(double, unloadingWeight, UnloadingWeight);
	//����RMB
	CC_SYNTHESIZE(double, feeRMB, FeeRMB);
	//����
	CC_SYNTHESIZE(double, price, Price);
};

// ��UnloadingFeeDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<UnloadingFeeDO> PtrUnloadingFeeDO;
#endif // !_UNLOADINGFEE_DO_