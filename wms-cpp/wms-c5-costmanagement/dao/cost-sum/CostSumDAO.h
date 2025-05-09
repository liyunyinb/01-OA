#pragma once
#ifndef _COSTSUM_DAO_
#define _COSTSUM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CostSumDO.h"
#include "../../domain/dto/cost-sum-dto/CostSumDTO.h"
#include "../../domain/query/cost-sum-query/CostSumQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CostSumDAO : public BaseDAO
{
private:
	inline std::string QueryConditionBuilder(const CostSumQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯ����
	std::list<CostSumDO> selectWithPage(const CostSumQuery::Wrapper& query);
	uint64_t count(const CostSumQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_