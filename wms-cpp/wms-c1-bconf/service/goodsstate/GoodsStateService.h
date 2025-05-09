#pragma once
#ifndef _GOODSSTATESERVICE_H_
#define _GOODSSTATESERVICE_H_
#include <list>
#include "domain/vo/goodsstate/GoodsStateVO.h"
#include "domain/query/goodsstate/GoodStateQuery.h"
#include "domain/dto/goodsstate/GoodStateDTO.h"
class GoodsStateService
{
public:
	// ����ɾ������
	bool removeDates(const std::vector<std::string>& ids);
	// ��ҳ��ѯ��������
	std::list<GoodStateDTO::Wrapper>  QueryAll(const GoodStateQuery::Wrapper& query);
	//��������
	bool importData(const std::vector<std::vector<std::string>>& data);
};
#endif // !_GOODSSTATESERVICE_H_
