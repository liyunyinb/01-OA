#pragma once
#ifndef _METHOD_SERVICE_
#define _METHOD_SERVICE_
#include <list>
#include "../../domain/do/cost-way/CostwayDO.h"
#include "../../dao/costmethod/MethodDAO.h"
#include "../../domain/vo/costmethod/MethodVO.h"
#include "../../domain/query/costmethod/BillMethodQuery.h"
#include "../../domain/dto/costmethod/MethodDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class MethodService
{
public:
	// ��ҳ��ѯ��������
	 MethodPageDTO::Wrapper listAll(const BillmethodQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	//SampleDTO::Wrapper getById(uint64_t id);
	// ��������
	string addData(const MethodAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const MethodDTO::Wrapper& dto);

	MethodPageDTO::Wrapper qall(const BillmethodQueryomit::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_

