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
#ifndef _COSTDETAILAHEAD_DAO_
#define _COSTDETAILAHEAD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/public-do/DayCostDO.h"
#include "../../domain/query/cost-detail-ahead/CostDetailQuery.h"

typedef std::shared_ptr<DayCostDO> PtrDayCostDO;

/**
 * ʾ�������ݿ����ʵ��
 */
class CostDetailAheadDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    CostDetailAheadDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const CostDetailQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������CostDetailQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const CostDetailQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const CostDetailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<DayCostDO> selectWithPage(const CostDetailQuery::Wrapper& query);
	// ͨ��������ѯ����
	std::list<DayCostDO> selectByName(const string& name);
	// ͨ��ID��ѯ����
	PtrDayCostDO selectById(uint64_t id);

	/*
	���ﻹ����Ӻܶ��ѯ����
	*/

	// ��������
	uint64_t insert(const DayCostDO& iObj);
	// �޸�����
	int update(const DayCostDO& uObj);
	// ͨ��IDɾ������
	int deleteById(const string& id);
};
#endif // !_SAMPLE_DAO_
