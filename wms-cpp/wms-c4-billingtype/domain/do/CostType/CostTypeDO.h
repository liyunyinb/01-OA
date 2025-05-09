#pragma once
#ifndef _COST_TYPE_DO_
#define _COST_TYPE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class CostTypeDO
{
	// ���id
	CC_SYNTHESIZE(uint64_t, id, Id);
	//���ô���
	CC_SYNTHESIZE(string, cost_code, Cost_code);
	//��������
	CC_SYNTHESIZE(string, cost_name, Cost_name);
	//��������
	CC_SYNTHESIZE(string, cost_type, Cost_type);
	//����������
	CC_SYNTHESIZE(string, create_name, Create_name);
	//����ʱ��
	CC_SYNTHESIZE(string, create_date, Create_date);
	//�����ߣ�fangtang����
	CC_SYNTHESIZE(string, create_by, Create_by);
	//�޸�����
	CC_SYNTHESIZE(string, update_name, Update_name);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_date, Update_date);

	// �������š���˾������fangtang����
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// ������˾  
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);

public:
	CostTypeDO() {
		id = 1;
		cost_code = "";
		cost_name = "";
		cost_type = "";
		create_by = "";
		create_name = "";
		create_date = "";
		update_name = "";
		update_date = "";
	}
};

// ��CostTypeDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CostTypeDO> PtrCostTypeDO;
#endif // !_COST_TYPE_DO_
