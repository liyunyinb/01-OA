#pragma once
#ifndef _ADDITION_DAO_
#define _ADDITION_DAO_
#include "BaseDAO.h"
//#include "../../domain/do/sample/SampleDO.h"
#include "../../domain/do/addition-adjustment/AdditionDO.h"
//#include "../../domain/do/"
//#include "../../domain/query/sample/SampleQuery.h"
//#include "../../domain/query/removal-adjustment/RemovalQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class AdditionDAO : public BaseDAO
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
//	inline std::string queryConditionBuilder(const RemovalQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	//uint64_t count(const RemovalQuery::Wrapper& query);
	// ��ҳ��ѯ����
	//std::list<RemovalDO> selectWithPage(const RemovalQuery::Wrapper& query);
	// ͨ��������ѯ����
	//std::list<SampleDO> selectByName(const string& name);
	// ͨ��ID��ѯ����
	//PtrRemovalDO selectById(const string& id);
	// ��������
	//uint64_t insert(const SampleDO& iObj);
	// �޸�����
	int update(const AdditionDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_