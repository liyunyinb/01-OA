#pragma once

#ifndef _PIS_DAO_
#define _PIS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ba_qm_sta/PisDO.h"
#include "../../domain/query/ba_qm_sta/PisQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PisDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const PisQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const PisQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<PisDO> selectWithPage(const PisQuery::Wrapper& query);
	// ͨ��Ʒ��״̬�����ѯ����
	//PtrPisDO selectByCode(const string& code);
	// ͨ��Ʒ��״̬���Ʋ�ѯ����
	//PtrPisDO selectByName(const string& name);
	// ����Ʒ��״̬����
	std::string insert(const PisDO& iObj);
	// ͨ��Ʒ��״̬�����޸�����
	int update(const PisDO& uObj);
};
#endif // !_SAMPLE_DAO_
