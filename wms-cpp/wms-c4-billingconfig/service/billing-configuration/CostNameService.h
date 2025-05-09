#pragma once
#ifndef _COST_NAME_SERVICE_
#define _COST_NAME_SERVICE_
#include <list>
#include "domain/vo/billing-configuration/CostNameVO.h"
#include "domain/query/billing-configuration/CostNameQuery.h"
#include "domain/dto/billing-configuration/CostNameDTO.h"


class CostNameService
{
public:
    // ��ѯ��������
    CostListDTO::Wrapper listAll(const CostNameQuery::Wrapper& query);
    // ��ҳ��ѯ��������
    CostListPageDTO::Wrapper listAllByPage(const CostNameQuery::Wrapper& query);
    // ��������
    bool saveData(const CostAddDTO::Wrapper& dto, const PayloadDTO& payload);
    // �޸�����
    bool updateData(const CostModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif