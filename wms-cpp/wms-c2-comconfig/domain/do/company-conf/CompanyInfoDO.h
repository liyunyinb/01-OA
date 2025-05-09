#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/13 11:52:32

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
#ifndef _COMPANYINFODO_
#define _COMPANYINFODO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class CompanyInfoDO
{
	// Ψһ����
	CC_SYNTHESIZE(string, id, Id);
	//��˾����
	CC_SYNTHESIZE(string, code, Code);
	// ��˾���ļ��
	CC_SYNTHESIZE(string, zh_name, Zh_name);
	// ��˾����ȫ��
	CC_SYNTHESIZE(string, zh_aname, Zh_aname);
	// ��˾���ĵ�ַ
	CC_SYNTHESIZE(string, zh_addr, Zh_addr);
	//��˾Ӣ�ļ��
	CC_SYNTHESIZE(string, en_name, En_name);
	//��˾Ӣ��ȫ��
	CC_SYNTHESIZE(string, en_aname, En_aname);
public:
	CompanyInfoDO() {
		code = "";
		zh_name = "";
		zh_aname = "";
		zh_addr = "";
		en_name = "";
		en_aname = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CompanyInfoDO> PtrCompanyInfoDO;
#endif // !_SAMPLE_DO_

