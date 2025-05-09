#pragma once

#ifndef _PIS_SERVICE_
#define _PIS_SERVICE_
#include <list>
#include "domain/vo/ba_qm_sta/PisVO.h"
#include "domain/query/ba_qm_sta/PisQuery.h"
#include "domain/dto/ba_qm_sta/PisDTO.h"

class PisService
{
public:
	// ��ҳ��ѯ��������
	PisPageDTO::Wrapper listAll(const PisQuery::Wrapper& query);
	// ��������
	std::string saveData(const PisAddDTO::Wrapper& dto,const PayloadDTO& payload);
	// �޸�����
	bool updateData(const PisDTO::Wrapper& dto, const PayloadDTO& payload);

	// ͨ��code��ѯ����
	//PisDTO::Wrapper getByCode(const string& code);
	// ͨ��sta��ѯ��������
	//PisDTO::Wrapper getByName(const string& name);
};

#endif // !_SAMPLE_SERVICE_
