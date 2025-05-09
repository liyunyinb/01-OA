#pragma once
#ifndef _EDU_DAO_
#define _EDU_DAO_
#include "BaseDAO.h"
#include "../domain/do/education/EducationDO.h"
#include "../domain/query/education/EduQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class EduDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������EduQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const EduQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const EduQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<EducationDO> selectWithPage(const EduQuery::Wrapper& query);
	std::list<EduBaseDO> select();
	// ��������
	bool insert(const EducationDO& iObj);
	void insert(const list<EducationDO>& obj);
};
#endif // !_SAMPLE_DAO_