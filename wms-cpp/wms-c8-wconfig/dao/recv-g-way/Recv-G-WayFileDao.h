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
#ifndef _RECV_G_WAY_DAO_
#define _RECV_G_WAY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/recv-g-way/Recv-G-WayFileDo.h"
#include "../../domain/query/recv-g-way/Recv-G-Way-FileQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class Recv_G_WayDAO : public BaseDAO
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
	inline std::string Recv_G_WayqueryConditionBuilder(const Recv_G_WayQuery::Wrapper& query, SqlParams& params);
	std::string getCurrentDateTime();
public:
	// ͳ����������
	uint64_t count(const Recv_G_WayQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<Recv_G_WayDO> selectWithPage(const Recv_G_WayQuery::Wrapper& query);
	// ��������
	int insert(const Recv_G_WayDO& iObj, string name, string realname, string orgcode, string companycode);
	// �޸�����
	int update(const Recv_G_WayDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_SAMPLE_DAO_
