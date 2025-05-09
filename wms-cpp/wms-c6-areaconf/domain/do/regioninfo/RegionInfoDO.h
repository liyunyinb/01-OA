#pragma once
/*
 @Author: 002
 @Date: 2025.3.7
*/
#ifndef _REGION_INFO_DO_
#define _REGION_INFO_DO_
#include "../DoInclude.h"
class RegionInfoDO
{
	// id
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
	// Ƭ������
	CC_SYNTHESIZE(string, region_code, Region_code);
	// Ƭ������
	CC_SYNTHESIZE(string, region_name, Region_name);
	// �ص���ʱ
	CC_SYNTHESIZE(double, region_rdata, Region_rdata);
public:
	RegionInfoDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		region_code = "";
		region_name = "";
		region_rdata = -1;
	}
};

class RegionNameDO
{
	// ����
	CC_SYNTHESIZE(string, area_name, Name);
	CC_SYNTHESIZE(string, id, Id);
public:
	RegionNameDO() {
		area_name = "";
		id = "";
	}
};

// ��RegionAddDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<RegionInfoDO> PtrRegionInfoDO;
typedef std::shared_ptr<RegionNameDO> PtrRegionNameDO;
#endif 