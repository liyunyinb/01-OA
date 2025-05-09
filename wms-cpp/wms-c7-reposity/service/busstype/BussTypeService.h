#pragma once
#ifndef _BUSSTYPE_SERVICE_
#define _BUSSTYPE_SERVICE_
#include <list>
#include "../../domain/dto/busstype/BussTypeDTO.h"
#include "../../domain/query/busstype/BussTypeQuery.h"
#include "../../domain/vo/busstype/BussTypeVO.h"

class BussTypeService {
public:
	// ��ҳ��ѯ��������
	BussTypeListPageDTO::Wrapper listAll(const BussTypeQuery::Wrapper& query);
	// ͨ��ҵ������Name��ѯ��������
	BussTypeListPageDTO::Wrapper getByName(string id);
	// ͨ��ҵ������Code��ѯ��������
	BussTypeListPageDTO::Wrapper getByCode(string code);
	// ͨ��ҵ������Text��ѯ��������
	BussTypeListPageDTO::Wrapper getByText(string text);
	// ��������
	uint64_t saveData(const BussTypeAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const BussTypeAddDTO::Wrapper& dto);
};
#endif // !_BUSSTYPE_SERVICE_
