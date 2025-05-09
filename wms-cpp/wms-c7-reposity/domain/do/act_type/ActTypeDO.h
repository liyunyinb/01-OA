#pragma once
#ifndef _ACTTYPEDO_H_
#define _ACTTYPEDO_H_
#include "../DoInclude.h"

class ActTypeDO {
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// ��ҵ���ʹ���
	CC_SYNTHESIZE(string, act_type_code, ActTypeCode);
	// ��ҵ��������
	CC_SYNTHESIZE(string, act_type_name, ActTypeName);
	// ҵ�񻷽�
	CC_SYNTHESIZE(string, oper_step_code, OperStepCode);
	// ��������
    CC_SYNTHESIZE(string, create_date, CreateDate);
	// ����������
    CC_SYNTHESIZE(string, create_name, CreateName);
	// �����˵�¼����
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// ��������
    CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// ������˾
    CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);


public:
	ActTypeDO() : id(""), act_type_code(""), act_type_name(""), oper_step_code(""){}
	ActTypeDO(string id, string act_type_code, string act_type_name, string oper_step_code)
	{
		this->id = id;
		this->act_type_code = act_type_code;
		this->act_type_name = act_type_name;
		this->oper_step_code = oper_step_code;
	}
};

typedef std::shared_ptr<ActTypeDO> PtrActTypeDO;

#endif // !_ACTTYPEDO_H_