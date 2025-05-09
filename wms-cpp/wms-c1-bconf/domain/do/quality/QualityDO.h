#pragma once
/*
 @Author: S4turday
 @Date: 2025��3��8��15:40:17

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
#ifndef _QUALITY_DO_
#define _QUALITY_DO_
#include "../DoInclude.h"

/**
 * Ʒ�ʴ������ݿ�ʵ����
 */
class QualityDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����������
	CC_SYNTHESIZE(string, create_name, Create_Name);
	// �����˵�¼����
	CC_SYNTHESIZE(string, create_by, Create_By);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_date, Create_Date);
	// ����������
	CC_SYNTHESIZE(string, update_name, Update_Name);
	// �����˵�¼����
	CC_SYNTHESIZE(string, update_by, Update_By);
	// ����ʱ��
	CC_SYNTHESIZE(string, update_date, Update_Date);
	// Ʒ�ʴ�������
	CC_SYNTHESIZE(string, qm_qa_name, Name);
	// Ʒ�ʴ���
	CC_SYNTHESIZE(string, qm_qa_code, Code);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_Org_Code);
	// ������˾
	CC_SYNTHESIZE(string, sys_company_code, Sys_Company_Code);	
public:
	QualityDO() {
		id = "";
		qm_qa_name = "";
		qm_qa_code = "";
	}
};

// ��QualityDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<QualityDO> PtrQualityDO;
#endif // !_QUALITY_DO_
