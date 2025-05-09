#pragma once
#ifndef _ENTERPRISESTATUSDO_
#define _ENTERPRISESTATUSDO_
#include "../DoInclude.h"

class EnterpriseStatusDO
{
	// ���
	CC_SYNTHESIZE(string, enterpriseid, kehuzhuangtai_code);
	// ��ҵ��
	CC_SYNTHESIZE(string, enterprisename, kehuzhuangtai_name);
	// ״̬
	CC_SYNTHESIZE(string, status, cus_sta_del);
public:
	EnterpriseStatusDO() {
		enterpriseid = "C001";
		enterprisename = "�ͻ�1";
		status = "Y";
	}
};

class EnterpriseStatusListDO
{
	// Ψһ����
	CC_SYNTHESIZE(string, statusonlyid, id);
	// ���
	CC_SYNTHESIZE(string, enterpriseid, kehuzhuangtai_code);
	// ��ҵ��
	CC_SYNTHESIZE(string, enterprisename, kehuzhuangtai_name);
public:
	EnterpriseStatusListDO() {
		statusonlyid = " ";
		enterpriseid = "C001";
		enterprisename = "�ͻ�1";
	}
};

// ��DO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<EnterpriseStatusDO> PtrEnterpriseStatusDO;
typedef std::shared_ptr<EnterpriseStatusListDO> PtrEnterpriseStatusListDO;
#endif // !_ENTERPRISESTATUSDO_
