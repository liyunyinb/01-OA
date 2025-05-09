#pragma once
#ifndef _GOODSSTATECONTROLLERDO_H_
#define _GOODSSTATECONTROLLERDO_H_ 
#include "../DoInclude.h"
class GoodsStateControllerDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ��������
	CC_SYNTHESIZE(string, create_name, Create_name);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ��������
	CC_SYNTHESIZE(string, create_date, Create_date);
	// ��������
	CC_SYNTHESIZE(string, update_name, Update_name);
	// ��������
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ��������
	CC_SYNTHESIZE(string, update_date, Update_date);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// ������˾
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	// Ʒ�ʴ���
	CC_SYNTHESIZE(string, qm_sta_code, Qm_sta_code);
	// Ʒ�ʴ�������
	CC_SYNTHESIZE(string, qm_sta_name, Qm_sta_name);
public:
	GoodsStateControllerDO()
	{
		id = " ";
		create_name = " ";
		create_by = " ";
		create_date = " ";
		update_name = " ";
		update_by = " ";
		update_date = " ";
		sys_org_code = " ";
		sys_company_code = " ";
		qm_sta_code = " ";
		qm_sta_name = " ";
	}
};

//��goodsstateDO����һ����������ʹ��

typedef std::shared_ptr<GoodsStateControllerDO> PtrGoodsStateControllerDO;
#endif // !_GOODSSTATECONTROLLERDO_H_