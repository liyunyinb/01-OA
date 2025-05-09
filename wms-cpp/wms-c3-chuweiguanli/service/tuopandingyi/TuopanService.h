#pragma once
#ifndef _TUOPAN_SERVICE_
#define _TUOPAN_SERVICE_
#include <list>
#include "domain/dto/tuopandingyi/TuopanDTO.h"
#include "domain/query/tuopandingyi/TuopanQuery.h"

/**
 * ���̷���ʵ��
 */
class TuopanService
{
public:
	// ��ҳ��ѯ������������
	TuopanPageDTO::Wrapper listAll(const TuopanQuery::Wrapper& query);
	//// ͨ��ID��ѯ��������
	//SampleDTO::Wrapper getById(uint64_t id);
	//// ��������
	//uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const TuopanDTO::Wrapper& dto);
	// ����ɾ������
	bool removeData(oatpp::List<oatpp::String>& idlist);
};

#endif // !_TUOPAN_SERVICE_