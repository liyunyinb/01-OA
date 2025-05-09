#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fycc
 @Date: 2025/2/23 20:50:21

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
#ifndef _COMPANYSTATE_DO_
#define _COMPANYSTATE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class CompanyStateDO
{
	//id��
	CC_SYNTHESIZE(string, id, Id);
	// �ͻ�����
	CC_SYNTHESIZE(string, clientid, ClientId);
	// �ͻ�����
	CC_SYNTHESIZE(string, clientname, ClientName);
	// װ̬
	CC_SYNTHESIZE(string, state, State);

	//payload��ش����
	//�û�����
	CC_SYNTHESIZE(string, username, UserName);
	//�û���¼����
	CC_SYNTHESIZE(string, loginname, LoginName);
	//����
	CC_SYNTHESIZE(string, date, Date);
	//��������
	CC_SYNTHESIZE(string, orgdept, OrgDept);
	//������˾
	CC_SYNTHESIZE(string, orgcompany, OrgCompany);
public:
	CompanyStateDO() {
		id = "";
		clientid = "";
		clientname = "";
		state = "";

		username = "";
		loginname = "";
		date = "";
		orgdept = "";
		orgcompany = "";
	}
};

// ��CompanyInfoDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CompanyStateDO> PtrCompanyStateDO;
#endif 
