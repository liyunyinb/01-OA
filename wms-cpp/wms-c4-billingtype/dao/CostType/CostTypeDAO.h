#pragma once
#ifndef _COST_TYPE__DAO_
#define _COST_TYPE__DAO_
#include "BaseDAO.h"
#include "../../domain/do/CostType/CostTypeDO.h"
#include "../../domain/query/billingtype/CostTypeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CostTypeDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const CostTypeQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ�Ʒ���������������
	uint64_t count(const CostTypeQuery::Wrapper& query);
	// ��ҳ��ѯ������������
	std::list<CostTypeDO> selectWithPage(const CostTypeQuery::Wrapper& query);
	// ͨ��������ѯ����
	std::list<CostTypeDO> selectByName(const string& name);
	// ͨ��ID��ѯ����
	PtrCostTypeDO selectById(uint64_t id);
	// ���������������
	uint64_t insert(const CostTypeDO& iObj);
	// �޸ķ�����������
	int update(const  CostTypeDO& uObj);
	// ͨ��IDɾ��������������
	int deleteById(uint64_t id);
};
#endif // !_COST_TYPE__DAO_
