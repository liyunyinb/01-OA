#pragma once

#ifndef _ENTERPRISE_SERVICE_
#define _ENTERPRISE_SERVICE_
#include <list>
#include "domain/dto/enterpriseDTO.h"
#include "domain/query/enterprisePageQuery.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/enterpriseJsonVO.h"

#include <chrono>
#include "../lib-common/include/SimpleDateTimeFormat.h"
class enterpriseService
{
public:
	//������ҵ������Ϣ
	uint64_t saveData(const addEnterpriseDTO::Wrapper& enterpriseInfo, const PayloadDTO& payload);
	//��ҳ��ѯ
	enterprisePageDTO::Wrapper  listAll(const enterprisePageQuery::Wrapper& query);
	//��ȡ��ҵ���������б�
	enterpriseNameDTO::Wrapper getEnterpriseName();//const PageQuery::Wrapper& query

};
#endif
