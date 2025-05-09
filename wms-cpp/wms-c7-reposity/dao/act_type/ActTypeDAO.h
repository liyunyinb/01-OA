#pragma once
#ifndef _ACTTYPEDAO_H_
#define _ACTTYPEDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/act_type/ActTypeDO.h"
#include "../../domain/query/act_type/ActTypeQuery.h"

/**
 * ��ȡ��ҵ�����б�¼����ҵ���� ���ݿ����ʵ��
 */
class ActTypeDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const ActTypeQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯ����
	std::list<ActTypeDO> selectWithPage(const ActTypeQuery::Wrapper& query);
	// ��������
	uint64_t insert(const ActTypeDO& iObj);
	// ͳ����������
	uint64_t count(const ActTypeQuery::Wrapper& query);
};


#endif // !_ACTTYPEDAO_H_