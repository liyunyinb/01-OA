#pragma once
/*
wangye 2025 02 28
*/
#ifndef _WORKSTATE_DO_
#define _WORKSTATE_DO_
#include "../DoInclude.h"

/**
 * ����״̬���ݿ�ʵ����
 */
class WorkStateDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����������
	CC_SYNTHESIZE(string, create_name, Create_name);
	// �����˵�¼����
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ��������
	CC_SYNTHESIZE(string, create_date, Create_date);
	// ����������
	CC_SYNTHESIZE(string, update_name, Update_name);
	// �����˵�½����
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ��������
	CC_SYNTHESIZE(string, update_date, Update_date);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// ������˾
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	// ����״̬����
	CC_SYNTHESIZE(string, work_sta_code, Work_sta_code);
	// ����״̬����
	CC_SYNTHESIZE(string, work_sta_name, Work_sta_name);
public:
	WorkStateDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		work_sta_code = "";
		work_sta_name = "";
	}
};

#endif // !_WORKSTATE_DO_
