#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2022/10/25 11:36:29

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
#ifndef _DELETEQUERY_QUERY_
#define _DELETEQUERY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ��Ʒѷ�ʽ��ѯ����
 */
class DeleteQuery : public PageQuery
{
	DTO_INIT(DeleteQuery, PageQuery);
	//�Ʒѷ�ʽid
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("CostConfig.delete.id"));
	// �Ʒѷ�ʽ����
	API_DTO_FIELD_DEFAULT(String, prount_code, ZH_WORDS_GETTER("CostConfig.delete.code"));
	// �Ʒѷ�ʽ����
	API_DTO_FIELD_DEFAULT(String, prount_name, ZH_WORDS_GETTER("CostConfig.delete.name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEQUERY_QUERY_