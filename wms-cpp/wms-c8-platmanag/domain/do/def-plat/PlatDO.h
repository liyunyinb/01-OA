#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mao
 @Date: 2025/2/27 16:17:41

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _Plat_DO_
#define _Plat_DO_
#include "../DoInclude.h"

/**
 * ��̨���ݿ�ʵ����
 */
class PlatDO
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
	// ��̨����
	CC_SYNTHESIZE(string, platform_code, PlatformCode);
	// ��̨����
	CC_SYNTHESIZE(string, platform_name, PlatformName);
	// ͣ��
	CC_SYNTHESIZE(string, platform_del, PlatformDel);
	// ��Աset/get����
#define GETSETFUNCTION(type,member) \
	type get##member() const { return member; } \
	void set##member(type value) { member = value; }

public:
	PlatDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		platform_code = "";
		platform_name = "";
		platform_del = "";
	}

	GETSETFUNCTION(string, id);
	GETSETFUNCTION(string, create_name);
	GETSETFUNCTION(string, create_by);
	GETSETFUNCTION(string, create_date);
	GETSETFUNCTION(string, update_name);
	GETSETFUNCTION(string, update_by);
	GETSETFUNCTION(string, update_date);
	GETSETFUNCTION(string, sys_org_code);
	GETSETFUNCTION(string, sys_company_code);
	GETSETFUNCTION(string, platform_code);
	GETSETFUNCTION(string, platform_name);
	GETSETFUNCTION(string, platform_del);

};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<PlatDO> PtrPlatDO;
#endif // !_Plat_DO_
