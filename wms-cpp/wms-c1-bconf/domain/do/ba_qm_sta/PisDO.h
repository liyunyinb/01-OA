#pragma once

#ifndef _PIS_DO_
#define _PIS_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class PisDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// Ʒ��״̬����
	CC_SYNTHESIZE(string, code, Code);
	// Ʒ��״̬����
	CC_SYNTHESIZE(string, name, Name);
	// ������Ϣ
	CC_SYNTHESIZE(string, create_name, Create_Name);
	CC_SYNTHESIZE(string, create_by, Create_By);
	CC_SYNTHESIZE(string, update_name, Update_Name);
	CC_SYNTHESIZE(string, update_by, Update_By);
	CC_SYNTHESIZE(string, update_date, Update_Date);
	CC_SYNTHESIZE(string, sys_org_code, Sys_Org_Code);
	CC_SYNTHESIZE(string, sys_company_code, Sys_Company_Code);

public:
	PisDO() {
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<PisDO> PtrPisDO;
#endif // !_SAMPLE_DO_
