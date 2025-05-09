#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _COSTTYPE_DAO_
#define _COSTTYPE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/costtype/costtypeDO.h"
#include "../../domain/query/costtype/costtypeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class costtypeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    costtypeDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const costtypeQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������costtypeQuery����̬������ѯ������ز���
	//************************************
	//inline std::string queryConditionBuilder(const costtypeQuery::Wrapper& query, SqlParams& params);
public:
	//// ͳ����������
	//uint64_t count(const costtypeQuery::Wrapper& query);
	//// ��ҳ��ѯ����
	//std::list<costtypeDO> selectWithPage(const costtypeQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//std::list<costtypeDO> selectByName(const string& name);
	//// ͨ��ID��ѯ����
	//PtrcosttypeDO selectById(uint64_t id);
	//// ��������
	//uint64_t insert(const costtypeDO& iObj);
	//// �޸�����
	//int update(const costtypeDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);

	int deleteById(string id);
	int deleteByIds(const std::vector<std::string>& ids);
};
#endif // !_SAMPLE_DAO_
