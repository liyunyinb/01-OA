#pragma once

#include "../DoInclude.h"

using namespace std;

class BaActTypeDO
{
    // ����
    CC_SYNTHESIZE(string, id, Id);
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
    // ��ҵ���ʹ���
    CC_SYNTHESIZE(string, act_type_code, ActTypeCode);
    // ��ҵ��������
    CC_SYNTHESIZE(string, act_type_name, ActTypeName);
    // ҵ�񻷽�
    CC_SYNTHESIZE(string, oper_step_code, OperStepCode);

public:
    BaActTypeDO()
    {
        id = "";
        create_name = "";
        create_by = "";
        create_date = "";
        update_name = "";
        update_by = "";
        update_date = "";
        sys_org_code = "";
        sys_company_code = "";
        act_type_code = "";
        act_type_name = "";
        oper_step_code = "";
    }
};

// ��������ָ������
typedef std::shared_ptr<BaActTypeDO> PtrBaActTypeDO;
