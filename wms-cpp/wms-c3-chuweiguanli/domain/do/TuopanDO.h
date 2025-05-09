#pragma once
/*

*/
#ifndef _TUOPANDO_H_
#define _TUOPANDO_H_
#include "DoInclude.h"

class TuopanDO{
	CC_SYNTHESIZE(string, id, Id);//Ψһ��ʶ ����
	CC_SYNTHESIZE(string, create_name, CreateName);//����������
	CC_SYNTHESIZE(string, create_by, CreateBy);//�����˵�¼����
	CC_SYNTHESIZE(string, create_date, CreateDate);//��������
	CC_SYNTHESIZE(string, update_name, UpdateName);//����������
	CC_SYNTHESIZE(string, update_by, UpdateBy);//�����˵�¼����
	CC_SYNTHESIZE(string, update_date, UpdateDate);//��������
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);//��������
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);//������˾
	CC_SYNTHESIZE(string, bpm_status,BpmStatus);//����״̬
	CC_SYNTHESIZE(string, tin_id, TinId);//���̺�
	CC_SYNTHESIZE(string, tin_sort, TinSort);//����˳��
	CC_SYNTHESIZE(string, bin_id, BinId);//��λ
	CC_SYNTHESIZE(string, tin_status, TinStatus);//����״̬

public:
	TuopanDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		bpm_status = "";
		tin_id = "";
		tin_sort = "";
		bin_id = "";
		tin_status = "";
	}

};
// ��TuopanDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<TuopanDO> PtrTuopanDO;
#endif // !_TUOPANDO_H_