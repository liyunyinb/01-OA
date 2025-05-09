#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/22 17:24:12

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
#ifndef _COSTSX_QUERY_
#define _COSTSX_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ��Ʒ����Բ�ѯ����
 * ��ҳ���� + ��������(���Ա�����������Ƶ�)
 */
class CostSxQuery : public PageQuery
{
	DTO_INIT(CostSxQuery, PageQuery);
	// �ͻ����Ա���
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("CostSxQuery.filed.code"));

	// �ͻ���������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("CostSxQuery.filed.name"));

	// ����������
	API_DTO_FIELD_DEFAULT(String, createName, ZH_WORDS_GETTER("CostSxQuery.field.create_name"));

	// ������ID
	API_DTO_FIELD_DEFAULT(String, createBy, ZH_WORDS_GETTER("CostSxQuery.field.create_by"));

	// ����������
	API_DTO_FIELD_DEFAULT(String, updateName, ZH_WORDS_GETTER("CostSxQuery.field.update_name"));

	// ������ID
	API_DTO_FIELD_DEFAULT(String, updateBy, ZH_WORDS_GETTER("CostSxQuery.field.update_by"));

	// ������֯����
	API_DTO_FIELD_DEFAULT(String, sysOrgCode, ZH_WORDS_GETTER("CostSxQuery.field.sys_org_code"));

	// ������˾����
	API_DTO_FIELD_DEFAULT(String, sysCompanyCode, ZH_WORDS_GETTER("CostSxQuery.field.sys_company_code"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COSTSX_QUERY_