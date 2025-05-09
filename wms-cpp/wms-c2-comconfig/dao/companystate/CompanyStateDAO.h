#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
 @Date: 2025/2/26 23:16:14

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
#ifndef _COMPANYSTATE_DAO_
#define _COMPANYSTATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/companystate/CompanyStateDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CompanyStateDAO : public BaseDAO
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
public:
	// ��������
	uint64_t insert(const CompanyStateDO& iObj);
	// �޸�����
	int update(const CompanyStateDO& uObj);
	//ͨ��id����ɾ������
	int deleteById(vector<string>& ids);
};
#endif
