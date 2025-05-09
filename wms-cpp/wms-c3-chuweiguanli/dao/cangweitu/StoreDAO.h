#pragma once
#ifndef _STORE_DAO_
#define _STORE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/WvDO.h"
#include "../../domain/query/cangweitu/HuoQuCangWeiShuJuQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class StoreDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const HuoQuCangWeiShuJuQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯ����
	std::list<WvDO> selectWithPage(const HuoQuCangWeiShuJuQuery::Wrapper& query);
	
};
#endif // !_STORE_DAO_