#pragma once
#ifndef _COST_TYPE__SERVICE_
#define _COST_TYPE__SERVICE_
#include <list>
#include "domain/vo/billingtype/CostVO.h"
#include "domain/query/billingtype/CostTypeQuery.h"
#include "domain/dto/billingtype/CostDTO.h"

/**
 *  �������ͷ���ʵ��
 */
class CostTypeService
{
public:
	// ��ҳ��ѯ������������
	CostListPageDTO::Wrapper listAll(const CostTypeQuery::Wrapper& query);
	// ͨ��ID��ѯ����������������
	CostListDTO::Wrapper getById(uint64_t id);
	// ���������������
	uint64_t saveData(const  GetCostDTO::Wrapper& dto);
	uint64_t saveData(const  GetCostDTO::Wrapper& dto,const PayloadDTO& payload);
	// �޸ķ�����������
	bool updateData(const  ModifyCostDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_COST_TYPE__SERVICE_

