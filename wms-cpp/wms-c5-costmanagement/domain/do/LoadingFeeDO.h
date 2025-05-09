#pragma once

#ifndef _LOADINGFEE_DO_
#define _LOADINGFEE_DO_
#include "DoInclude.h"

//���װ�������ݿ�ʵ����
class LoadingFeeDO
{
	// ����
	CC_SYNTHESIZE(string, fee, Fee);
	//������
	CC_SYNTHESIZE(string, Operator, XOperator);//operator ��һ���ؼ���
	//��������
	CC_SYNTHESIZE(string, operateDate, OperateDate);
	//����
	CC_SYNTHESIZE(string, orderNo, OrderNo);
	//��Ʒ
	CC_SYNTHESIZE(string, goods, Goods);
	//��Ʒ����
	CC_SYNTHESIZE(string, goodsName, GoodsName);
	//��Ʒ��
	CC_SYNTHESIZE(int, goodsNum, GoodsNum);
	//��Ʒ����
	CC_SYNTHESIZE(double, goodsWeight, GoodsWeight);
	//����RMB
	CC_SYNTHESIZE(double, feeRMB, FeeRMB);
	//����
	CC_SYNTHESIZE(double, price, Price);
};

// ��LoadingFeeDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<LoadingFeeDO> PtrLoadingFeeDO;
#endif // _LOADINGFEE_DO_