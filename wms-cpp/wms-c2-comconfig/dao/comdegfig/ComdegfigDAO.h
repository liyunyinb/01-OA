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
#ifndef _COMDEG_DAO_
#define _COMDEG_DAO_
#include "BaseDAO.h"
#include "domain/do/condegfig/ComdegfigDO.h"
#include "domain/query/comdeg/ComdegQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ComdegfigDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryComdegBuilder
	// FullName:    ComdegDAO::queryComdegBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const ComdegQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������ComdegQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryComdegBuilder(const ComdegQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ComdegQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ComdegfigDO> selectWithPage(const ComdegQuery::Wrapper& query);
	// ͨ����ҵ�ȼ����Ʋ�ѯ����
	std::list<ComdegfigDO> selectByDegName(const string& name);
	// ͨ����ҵ�ȼ������ѯ����
	std::list<ComdegfigDO> selectByDegCode(const string& code);
	// ͨ��ID��ѯ����
	PtrComdegfigDO selectById(string id);
	// ��������
	uint64_t insert(const ComdegfigDO& iObj);

	/*
	// �޸�����
	int update(const ComdegfigDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	*/
	
};
#endif // !_SAMPLE_DAO_
