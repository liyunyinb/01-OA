#pragma once
#ifndef _QUERY_DAO_
#define _QUERY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/BinDO.h"
#include "../../domain/query/kongchuwei/DaoChuKongChuWeiQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class QueryDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const DaoChuKongChuWeiQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const DaoChuKongChuWeiQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<BinDO> selectWithPage(const DaoChuKongChuWeiQuery::Wrapper& query);
	
};
#endif // !_QUERY_DAO_