#pragma once
#ifndef _ENTERPRISESTATUSSERVICE_
#define _ENTERPRISESTATUSSERVICE_
#include <list>
#include "domain/vo/md-cus-other/EnterpriseVO.h"
#include "domain/query/md-cus-other/EnterpriseQuery.h"
#include "domain/dto/md-cus-other/EnterpriseDTO.h"


class EnterpriseStatusService
{
public:
	// ��ҳ��ѯ������ҵ״̬����
	EnterpriseListPageDTO::Wrapper queryAll(const EnterpriseQuery::Wrapper& query);
	// ��ȡ������ҵ״̬�����б�
	EnterpriseStatusListDTO::Wrapper queryForList();
};

#endif // !_ENTERPRISESTATUSSERVICE_
