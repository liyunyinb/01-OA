#pragma once

#ifndef _EDUCATION_DO_
#define _EDUCATION_DO_
#include "../DoInclude.h"

class EduBaseDO
{
	// ѧ������
	CC_SYNTHESIZE(string, educode, EduCode);
	// ѧ������
	CC_SYNTHESIZE(string, eduname, EduName);
	EduBaseDO()
	{
		educode = "";
		eduname = "";
	}
};

class EducationDO
{
	//�ֶ�id
	CC_SYNTHESIZE(string, id, Id);
	// ѧ������
	CC_SYNTHESIZE(string, educode, EduCode);
	// ѧ������
	CC_SYNTHESIZE(string, eduname, EduName);
	CC_SYNTHESIZE(string, create_name, Create_name);
	CC_SYNTHESIZE(string, create_by, Create_by);
	CC_SYNTHESIZE(string, create_date, Create_date);
	CC_SYNTHESIZE(string, update_name, Update_name);
	CC_SYNTHESIZE(string, update_by, Update_by);
	CC_SYNTHESIZE(string, update_date, Update_date);
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
public:
	EducationDO() {
		id = "";
		educode = "";
		eduname = "";
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

// ��EducationDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<EducationDO> PtrEducationDO;
#endif // !_Education_DO_