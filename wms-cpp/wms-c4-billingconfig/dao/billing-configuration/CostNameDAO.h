#pragma once

#ifndef _COST_NAME_DAO_
#define _COST_NAME_DAO_
#include "BaseDAO.h"
#include "../../domain/do/billing-configuration/CostNameDO.h"
#include "../../domain/query/billing-configuration/CostNameQuery.h"
#include<iostream>

/**
 * �����������ݷ��ʶ���
 */
class CostNameDAO : public BaseDAO
{
private:
	// ��ѯ����������
	inline std::string queryConditionBuilder(const CostNameQuery::Wrapper& query, SqlParams& params);

public:

	// ͳ����������
	uint64_t count(const CostNameQuery::Wrapper& query);
	//��ȡȫ����������
    std::list<CostNameDO> selectAll(const CostNameQuery::Wrapper& query);

	// ��ҳ��ѯ����
	std::list<CostNameDO> selectWithPage(const CostNameQuery::Wrapper& query);



	// ��������
	int insert(const CostNameDO& iObj, const PayloadDTO& payload);

	// �޸�����
	int update(const CostNameDO& uObj, const PayloadDTO& payload);

	
};
#endif // !_COST_NAME_DAO_