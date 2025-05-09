#pragma once
#ifndef _QUALITYDO_H_
#define _QUALITYDO_H_ 
#include "../DoInclude.h"
class QualityDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	// ����������
	CC_SYNTHESIZE(string, create_name, Create_name);
	// �����˵�¼����
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ��������
	CC_SYNTHESIZE(string, create_date, Create_date);
	// ����������
	CC_SYNTHESIZE(string, update_name, Update_name);
	// �����˵�¼����
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ��������
	CC_SYNTHESIZE(string, update_date, Update_date);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// ������˾
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	// Ʒ�ʴ���
	CC_SYNTHESIZE(string, qm_qa_code, Qm_qa_code);
	// Ʒ�ʴ�������
	CC_SYNTHESIZE(string, qm_qa_name, Qm_qa_name);
public:
	QualityDO()
	{
		id = " ";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		qm_qa_code = "";
		qm_qa_name = "";
	}
};

#endif // !_QUALITYDO_H_