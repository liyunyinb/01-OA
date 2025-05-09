#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: killerqueen
 @Date: 2025/2/24 20:40:33

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
#ifndef _ATTRIINFO_SERVICE_
#define _ATTRIINFO_SERVICE_
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"
#include "stdafx.h"
#include "domain/dto/companyattributes/AttriInfoDTO.h"


class AttriService
{
public:
	// ͨ��id����ɾ������
	bool removeData(vector<string> id);
	// ����com_type_code com_type_name �Ĳ�ѯ���
	vector<std::vector<std::string>> getData();
	// �������������ϴ������ݿ�
	uint64_t saveData(const AttriInfoJsonDTO::Wrapper& dto);
};

#endif