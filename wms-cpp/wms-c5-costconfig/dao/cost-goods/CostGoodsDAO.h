#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Jane
 @Date: 2025/03/05 14:23:49

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
#ifndef _COSTGOODS_DAO_
#define _COSTGOODS_DAO_
#include "BaseDAO.h"
#include "domain/do/public-do/GoodsClassDO.h"
#include "domain/query/cost-goods/BillingProductCategoryQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CostGoodsDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const BillingProductCategoryQuery::Wrapper& query, SqlParams& params);
public:

	// ͨ��codeɾ������
	int deleteByCode(string code);

	uint64_t insert(const GoodsClassDO& iObj);
	
	// ��ѯ����
	std::list<GoodsClassDO> select();
};
#endif // !_COSTGOODS_DAO_
