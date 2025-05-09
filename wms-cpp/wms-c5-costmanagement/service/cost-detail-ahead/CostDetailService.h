#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: whx
 @Date: 2025/3/5 14:23:49

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
#ifndef _COSTDETAIL_SERVICE_
#define _COSTDETAIL_SERVICE_
#include <list>
#include "domain/vo/cost-detail-ahead/CostDetialVO.h"
#include "domain/query/cost-detail-ahead/CostDetailQuery.h"
#include "domain/dto/cost-detail-ahead/CostDetialDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CostDetailService
{
public:
	// ��ҳ��ѯ��������
	CostDetailListPageDTO::Wrapper listAll(const CostDetailQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	CostDetailBaseDTO::Wrapper getById(uint64_t id);
	// ��������
	uint64_t saveData(const CostDetailAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�����
	bool updateData(const CostDetailEditDTO::Wrapper& dto, const PayloadDTO& payload);
	// ͨ��IDɾ������
	bool removeData(const string& id);
	// ͨ�����IDɾ����������
	bool removeBatchData(const vector<string>& id);

};

#endif // !_COSTDETAIL_SERVICE_

