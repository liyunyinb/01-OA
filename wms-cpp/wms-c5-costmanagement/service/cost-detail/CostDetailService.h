#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/4 14:26

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
#ifndef _COST_DETAIL_SERVICE_
#define _COST_DETAIL_SERVICE_
#include "../../domain/dto/cost-detail/CostDetailDTO.h"
#include "oatpp/core/Types.hpp"
/**
 * "�Ʒѹ���-������ϸ"�ķ���ʵ��
 */
class CostDetailService
{
public:
	//����id��ȡ����,�޸�id��Ӧ���������
	bool charge(const oatpp::String& id);
	//����idȡ����ȡ����,�޸�id��Ӧ���������
	bool discharge(const oatpp::String& id);
	//��������
	uint64_t addData(const CostExportDTO* dto);
	//��ѯȫ������
	vector<vector<string>> exportAll(const oatpp::List<oatpp::String>& ids);
};

#endif // !_COST_DETAIL_SERVICE_

