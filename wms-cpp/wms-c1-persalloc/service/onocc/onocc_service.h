#ifndef _ONOCC_SERVICE_
#define _ONOCC_SERVICE_

#include <list>
#include "domain/query/onocc/onocc_query.h"
#include "domain/dto/onocc/onocc_dto.h"
#include "domain/vo/onocc/onocc_vo.h"

class EsService
{
public:
	// ��ҳ��ѯ��������
	EsPageDTO::Wrapper listAll(const EsQuery::Wrapper& query);
	// ��������
	std::string saveData(const EsAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�����
	bool updateData(const EsDTO::Wrapper& dto,const PayloadDTO& payload);
};

#endif