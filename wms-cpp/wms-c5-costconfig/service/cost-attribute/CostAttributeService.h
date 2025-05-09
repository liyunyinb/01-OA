#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/26 11:14:56

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
#ifndef _COST_ATTRIBUTE_SERVICE_
#define _COST_ATTRIBUTE_SERVICE_
#include <list>
#include "domain/vo/cost-attribute/CostSxVO.h"
#include "domain/query/cost-attribute/CostSxQuery.h"
#include "domain/dto/cost-attribute/CostSxDTO.h"
#include "domain/query/cost-attribute/CostAttributeQuery.h"
#include "domain/dto/cost-attribute/CostAttributeDTO.h"
#include "domain/vo/cost-attribute/CostAttributeVO.h"
#include "domain/do/cost-attribute/CostAttributeDO.h"

/**
 * �����ͻ����Ե���ɾ�Ĳ�
 */
class CostAttributeService
{
public:
	
	// �޸Ŀͻ����� 
	bool update(const CostSxModifyDTO::Wrapper& dto);
	// ���ӿͻ�����
	string insert(const CostSxAddDTO::Wrapper& dto);

	CostSxNameListPageDTO::Wrapper listName(const CostSxQuery::Wrapper& query);

	CostSxPageDTO::Wrapper listAll(const CostSxQuery::Wrapper& query);

    // ɾ���ͻ��Ʒ�����
    bool DeleteCostAttribute(const string& id);
    // ����ͻ��Ʒ�����
    uint64_t ImportCostAttribute(const ImportCostAttributeDTO::Wrapper& dto);
    // �����ͻ��Ʒ�����
    list<CostAttributeDO> ExportCostAttribute();
};

#endif // !_COST_ATTRIBUTE_SERVICE_

