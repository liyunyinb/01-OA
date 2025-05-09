#pragma once
#ifndef _METHOD_DAO_
#define _METHOD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/cost-way/CostwayDO.h"
#include "../../domain/query/costmethod/BillMethodQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
//class SampleDAO : public BaseDAO
//{
//private:
//	//************************************
//	// Method:      queryConditionBuilder
//	// FullName:    SampleDAO::queryConditionBuilder
//	// Access:      private 
//	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
//	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
//	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
//	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
//	//************************************
//	inline std::string queryConditionBuilder(const SampleQuery::Wrapper& query, SqlParams& params);
//public:
//	// ͳ����������
//	uint64_t count(const SampleQuery::Wrapper& query);
//	// ��ҳ��ѯ����
//	std::list<SampleDO> selectWithPage(const SampleQuery::Wrapper& query);
//	// ͨ��������ѯ����
//	std::list<SampleDO> selectByName(const string& name);
//	// ͨ��ID��ѯ����
//	PtrSampleDO selectById(uint64_t id);
//	// ��������
//	uint64_t insert(const SampleDO& iObj);
//	// �޸�����
//	int update(const SampleDO& uObj);
//	// ͨ��IDɾ������
//	int deleteById(uint64_t id);
//};
class MethodDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const BillmethodQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const BillmethodQuery::Wrapper& query);
	//// ��ҳ��ѯ����
	std::list<CostwayDO> selectWithPage(const BillmethodQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//std::list<SampleDO> selectByName(const string& name);
	//// ͨ��ID��ѯ����
	//PtrSampleDO selectById(uint64_t id);
	// ��������
	string insert(const MethodDO& iObj);
	//// �޸�����
	int update(const MethodDO& uObj);

	std::list<CostwayDO> qalldao();
	//// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
