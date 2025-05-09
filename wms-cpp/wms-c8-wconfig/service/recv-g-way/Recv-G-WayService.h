#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: èͷ����
 @Date: 2025/03/10 16:09:12

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.ations under the License.
*/
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/recv-g-way/Recv-G-Way-FileVo.h"
#include "domain/query/recv-g-way/Recv-G-Way-FileQuery.h"
#include "domain/dto/recv-g-way/Recv-G-WayFileDto.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class Recv_G_WayService
{
public:
	// ��ҳ��ѯ��������
	Recv_G_WayAllDto::Wrapper listAll(const Recv_G_WayQuery::Wrapper& query);
	
	// ��������
	int saveData(const Recv_G_WayAddDto::Wrapper& dto,string name, string realname, string orgcode, string companycode);
	// �޸�����
	bool updateData(const Recv_G_WayEditDto::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const string id);
	//�������
	std::string DefPutData(const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_

