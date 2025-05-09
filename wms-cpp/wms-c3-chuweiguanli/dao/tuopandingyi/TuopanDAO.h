#pragma once
#ifndef _TUOPAN_DAO_
#define _TUOPAN_DAO_
#include "BaseDAO.h"
#include "../../domain/do/TuopanDO.h"
#include "../../domain/query/tuopandingyi/TuopanQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class TuopanDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    TuopanDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const TuopanQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������TuopanQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const TuopanQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const TuopanQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<TuopanDO> selectWithPage(const TuopanQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//std::list<SampleDO> selectByName(const string& name);
	//// ͨ��ID��ѯ����
	//PtrSampleDO selectById(uint64_t id);
	//// ��������
	//uint64_t insert(const SampleDO& iObj);
	// �޸�����
	int update(const TuopanDO& uObj);
	// ����ɾ������
	int deleteById(string id);
};
#endif // !_TUOPAN_DAO_