#pragma once

#ifndef _COST_NAME_DO_
#define _COST_NAME_DO_
#include "../DoInclude.h"

/**
 * �����������ݶ���
 */
class CostNameDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	// ���ô���
	CC_SYNTHESIZE(string, cost_code, CostCode);
	// ��������
	CC_SYNTHESIZE(string, cost_name, CostName);
	// �������ʹ���
	CC_SYNTHESIZE(string, cost_type_code, CostTypeCode);
	// ����������
	CC_SYNTHESIZE(string, create_name, CreateName);
	// �����˵�¼����
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// ��������
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// ����������
	CC_SYNTHESIZE(string, update_name, UpdateName);
	// �����˵�¼����
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	// ��������
	CC_SYNTHESIZE(string, update_date, UpdateDate);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// ������˾
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);

public:
	CostNameDO() {
		id = "";
		cost_code = "";
		cost_name = "";
		cost_type_code = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
	}
};

// �����������ݶ���ָ������
typedef std::shared_ptr<CostNameDO> PtrCostNameDO;
#endif // !_COST_NAME_DO_