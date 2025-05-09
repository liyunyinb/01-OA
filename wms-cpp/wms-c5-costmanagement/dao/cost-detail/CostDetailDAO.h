#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/4 14:42

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
#ifndef _COST__DETAIL_DAO_
#define _COST__DETAIL_DAO_
#include "BaseDAO.h"
#include "../../domain/do/public-do/DayCostDO.h"
#include "oatpp/core/Types.hpp"
/**
 * "�Ʒѹ���-������ϸ"���ݿ����ʵ��
 */
class CostDetailDAO : public BaseDAO
{
private:
	
public:
	//��ȡ����
	int charge(const oatpp::String& id);
	//ȡ����ȡ����
	int discharge(const oatpp::String& id);
	//�������
	uint64_t insert(const DayCostDO& iObj);
	//����ȫ������
	list<DayCostDO> exportAll(const oatpp::List<oatpp::String>& ids);
	//��id����
	DayCostDO selectById(const oatpp::String& id);
};
#endif // !_COST__DETAIL_DAO_
