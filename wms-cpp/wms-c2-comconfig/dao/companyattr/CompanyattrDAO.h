#pragma once
/*
  @Author: laughter
*/
#ifndef _COMPANYATTR_DAO_
#define _COMPANYATTR_DAO_
#include "BaseDAO.h"
#include "../../domain/do/companyattr/CompanyattrDO.h"
#include "../../domain/query/companyattr/CompanyattrQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CompanyattrDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const CompanyattrQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const CompanyattrQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<CompanyattrDO> selectWithPage(const CompanyattrQuery::Wrapper& query);
	// ��������
	uint64_t insert(const CompanyattrIdDO& iObj);
	//�޸�����
	int update(const CompanyattrIdDO& uObj);
	//// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_

