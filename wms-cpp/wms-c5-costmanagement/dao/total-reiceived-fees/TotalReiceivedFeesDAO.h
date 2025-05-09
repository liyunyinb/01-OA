#pragma once
#ifndef _TOTAL_DAO_
#define _TOTAL_DAO_

#include "BaseDAO.h"
#include "domain/query/total-reiceived-fees/TotalReiceivedFeesQuery.h"
#include "domain/do/public-do/DayCostDO.h"

class TotalReiceivedFeesDAO:BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const TotalReiceivedFeesQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<DayCostDO> selectWithPage(const TotalReiceivedFeesQuery::Wrapper& query);

};



#endif // !_TOTAL_DAO_
