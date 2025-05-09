#pragma once
#ifndef _ENTERPRISE_DAO_
#define _ENTERPRISE_DAO_
#include "BaseDAO.h"
#include "domain/dto/enterpriseDTO.h"
#include "domain/do/enterpriseDO.h"
#include "domain/query/enterprisePageQuery.h"
#include "domain/do/enterpriseDO.h"
#include "RedisClient.h"
#include "domain/do/EnterpriseDoMapper.h"
class enterpriseDAO : public BaseDAO
{
public:
	//������ҵ������Ϣ
	uint64_t insert(const EnterpriseDO& enterpriseInfo);

	//��ҵ�������ݷ�ҳ��ѯ
	std::list<EnterpriseDO> selectWithPage(const enterprisePageQuery::Wrapper& query);

	//��ȡ��ҵ��������
	std::list<EnterpriseDO> getEnterpriseName();


	uint64_t count(const enterprisePageQuery::Wrapper& query);

	//��ѯ����������
	std::string queryCondionBuilder(const enterprisePageQuery::Wrapper& query, SqlParams& params);
};
#endif