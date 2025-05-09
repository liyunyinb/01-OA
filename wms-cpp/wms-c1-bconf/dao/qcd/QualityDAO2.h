#pragma once
#ifndef _QUALITYDAO_H_
#define _QUALITYDAO_H_
#include "BaseDAO.h"
#include "domain/query/qcd/QualityQuery2.h"
#include "domain/do/qcd/QualityDO2.h"

class QualityDAO : public BaseDAO
{
public:
	// ͨ��IDɾ������
	int deleteById(string id);
	// ����ɾ������
	int deleteByIds(const std::vector<std::int32_t>& ids);
	//ͳ����������
	uint64_t count(const QualityQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<QualityDO> QueryWithPage(const QualityQuery::Wrapper& query);
	// ��������
	uint64_t insert2(const QualityDO& iObj);
};
#endif // ! _QUALITYDAO_H_	