#pragma once
#pragma once
#ifndef _BILLINGNAME_DO_
#define _BILLINGNAME_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class BillingNameDO
{
	// Ψһ����
	CC_SYNTHESIZE(string, id, Id); 
	CC_SYNTHESIZE(string, cost_code,Cost_code);
	CC_SYNTHESIZE(string, cost_name,Cost_name);
	CC_SYNTHESIZE(string, cost_type_code,Cost_type_code);
public:
	BillingNameDO() {
		id = "";
		cost_code = "";
		cost_name = "";
		cost_type_code = "";
	}
};

// ��BillingNameDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<BillingNameDO> PtrBillingNameDO;
#endif // !_BILLINGNAME_DO_