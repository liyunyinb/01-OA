#pragma once
/*
 @Author: S4turday
 @Date: 2025��3��8��15:35:04

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
#ifndef _QUALITY_DAO_
#define _QUALITY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/quality/QualityDO.h"
#include "../../domain/query/quality/QualityQuery.h"

/**
 * Ʒ�ʴ������ݿ����ʵ��
 */
class QualityDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    QualityDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const QualityQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������QualityQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const QualityQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const QualityQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<QualityDO> selectWithPage(const QualityQuery::Wrapper& query);
	// ͨ��Ʒ�ʴ������Ʋ�ѯ����
	std::list<QualityDO> selectByName(const string& name);
	// ͨ��Ʒ�ʴ����ѯ����
	std::list<QualityDO> selectByCode(const string& code);
	// ��������
	uint64_t insert(const QualityDO& iObj);
	// �޸�����
	int update(const QualityDO& uObj);
};
#endif // !_QUALITY_DAO_