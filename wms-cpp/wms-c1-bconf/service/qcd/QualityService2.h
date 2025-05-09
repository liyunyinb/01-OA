#pragma once
#ifndef _QUALITYSERVICE_H_
#define _QUALITYSERVICE_H_
#include <list>
#include "domain/vo/qcd/QualityVO2.h"
#include "domain/query/qcd/QualityQuery2.h"
#include "domain/dto/qcd/QualityDTO2.h"
class QualityService
{
public:
	// ͨ��IDɾ������
	int removeData(const std::vector<std::int32_t>& ids);
	// ��ҳ��ѯ��������
	std::list<QualityDTO::Wrapper>  QueryAll(const QualityQuery::Wrapper& query);
	// ��������
	bool importData(const std::vector<std::vector<std::string>>& data, const PayloadDTO& payload);
};
#endif // !_QUALITYSERVICE_H_
