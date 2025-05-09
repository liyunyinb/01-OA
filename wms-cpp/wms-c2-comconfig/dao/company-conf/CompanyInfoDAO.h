#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/13 14:23:49

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
#ifndef _COMPANYINFODAO_
#define _COMPANYINFODAO_
#include "BaseDAO.h"
#include "../../domain/do/company-conf/CompanyInfoDO.h"
#include "domain/query/company-conf/CompanyInfoQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class CompanyInfoDAO : public BaseDAO
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
	inline std::string queryComdegBuilder(const CompanyInfoQuery::Wrapper& query, SqlParams& params);

public:
	// ͳ����������
	uint64_t count(const CompanyInfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<CompanyInfoDO> selectWithPage(const CompanyInfoQuery::Wrapper& query);
	// ͨ��ID��ѯ����
	PtrCompanyInfoDO selectDetail(uint64_t id);
};
#endif // !_SAMPLE_DAO_

