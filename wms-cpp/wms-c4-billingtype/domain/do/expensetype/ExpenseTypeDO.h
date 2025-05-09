#pragma once
#ifndef _EXPENSETYPEDO_
#define _EXPENSETYPEDO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ExpenseTypeDO
{
	// ���id
	CC_SYNTHESIZE(string, id, Id);
	//����������
	CC_SYNTHESIZE(string, create_name, Create_name);
	//�����˵�¼����
	CC_SYNTHESIZE(string, create_by, Create_by);
	//����ʱ��
	CC_SYNTHESIZE(string, create_date, Create_date);
	//����������
	CC_SYNTHESIZE(string, update_name, Update_name);
	//�������˵�¼����
	CC_SYNTHESIZE(string, update_by, Update_by)
	//����ʱ��
	CC_SYNTHESIZE(string, update_date, Update_date);
	//��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//������˾
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	//���ô���
	CC_SYNTHESIZE(string, cost_type_code, Cost_type_code);
	//��������
	CC_SYNTHESIZE(string, cost_type_name, Cost_type_name);
	//ͣ��
	CC_SYNTHESIZE(string, cost_type_del, Cost_type_del);


public:
	ExpenseTypeDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		cost_type_code = "";
		cost_type_name = "";
		cost_type_del = "";
	}
};

// ��CostTypeDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ExpenseTypeDO> PtrExpenseTypeDO;
#endif // !_EXPENSETYPEDO_
