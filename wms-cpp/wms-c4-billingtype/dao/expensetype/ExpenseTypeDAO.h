#pragma once
#ifndef _EXPENSETYPEDAO_
#define _EXPENSETYPEDAO_
#include "BaseDAO.h"
#include "../../domain/do/expensetype/ExpenseTypeDO.h"
#include "../../domain/query/expensetype/ExpenseTypeQuery.h"

/**
 * �������ݿ����ʵ��
 */
class ExpenseTypeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    ListGoodsDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const ListgoodsQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������ListgoodsQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ExpenseTypeQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ExpenseTypeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ExpenseTypeDO> selectWithPage(const ExpenseTypeQuery::Wrapper& query);
	// ��ѯ����---����ҳ
	std::list<ExpenseTypeDO> selectWithConditions(const ExpenseTypeQuery::Wrapper& query);
};
#endif // !_EXPENSETYPEDAO_
