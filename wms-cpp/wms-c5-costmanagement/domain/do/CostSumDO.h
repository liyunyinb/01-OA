#pragma once
#ifndef _COSTSUM_DO_
#define _COSTSUM_DO_
#include "DoInclude.h"

//���װ�������ݿ�ʵ����
class CostSumDO
{
	// ����
	CC_SYNTHESIZE(string, id, ID);
	//������
	CC_SYNTHESIZE(string, cost_data, cost_date);//operator ��һ���ؼ���
	//��������
	CC_SYNTHESIZE(string, cus_code, client_c);
	//����
	CC_SYNTHESIZE(string, cus_name, client_name);
	//��Ʒ
	CC_SYNTHESIZE(string, cost_code,cost_c );
	//��Ʒ����
	CC_SYNTHESIZE(string, cost_name, cost_name);
	//��Ʒ��
	CC_SYNTHESIZE(string, cost_js, Cost_Js);
	//��Ʒ����
	CC_SYNTHESIZE(string, yuanj,org_price);
	//����RMB
	CC_SYNTHESIZE(string, bhsj, no_tax);
	//����
	CC_SYNTHESIZE(string, shuie, Tax);
	CC_SYNTHESIZE(string, cost_sl, Number);
	CC_SYNTHESIZE(string, hansj, tax_price);
	CC_SYNTHESIZE(string, cost_unit, Unit);
};

// ��LoadingFeeDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CostSumDO> PtrCostSumDO;
#endif // _LOADINGFEE_DO_