#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mao
 @Date: 2025/2/27 16:12:16

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
#ifndef _DEFPLAT_DAO_
#define _DEFPLAT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/def-plat/PlatDO.h"
//#include "../../domain/query/sample/SampleQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DefPlatDAO : public BaseDAO
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
	//inline std::string queryConditionBuilder(const SampleQuery::Wrapper& query, SqlParams& params);
public:
	// ͨ��IDɾ������
	uint64_t deleteById(string id);
	// �޸�����
	uint64_t update(string id,const PlatDO& uObj);
	// ��ѯ��������
	std::list<PlatDO> queryAll();
	
};
#endif // !_DEFPLAT_DAO_
