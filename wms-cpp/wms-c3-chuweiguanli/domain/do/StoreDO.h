#pragma once
#ifndef STOREDO
#define STOREDO
#include "DoInclude.h"

class StoreDO
{
	CC_SYNTHESIZE(string, id, Id); // Ψһ��ʶ ����
	CC_SYNTHESIZE(string, store_code, StoreCode); // �ֿ����
	CC_SYNTHESIZE(string, store_name, StoreName); // �ֿ�����
	CC_SYNTHESIZE(string, store_text, StoreText); // �ֿ�����
	CC_SYNTHESIZE(string, create_name, CreateName); // ����������
	CC_SYNTHESIZE(string, create_by, CreateBy); // �����˵�¼����
	CC_SYNTHESIZE(string, create_date, CreateDate); // ��������
	CC_SYNTHESIZE(string, update_name, UpdateName); // ����������
	CC_SYNTHESIZE(string, update_by, UpdateBy); // �����˵�¼����
	CC_SYNTHESIZE(string, update_date, UpdateDate); // ��������
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode); // ��������
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode); // ������˾
public:
	StoreDO() {
		id = "";
		store_code = "";
		store_name = "";
		store_text = "";
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

#endif // !STOREDO