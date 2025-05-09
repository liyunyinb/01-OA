#pragma once
#ifndef _EDU_SERVICE_
#define _EDU_SERVICE_
#include <list>
#include "domain/vo/education/EduVO.h"
#include "domain/query/education/EduQuery.h"
#include "domain/dto/education/EduDTO.h"

/**
 * ѧ������ʵ��
 */
class EduService
{
public:
	// ��ҳ��ѯ��������
	EduPageDTO::Wrapper listAll(const EduQuery::Wrapper& query);
	std::vector<std::vector<std::string>> listAll();
	// ��������
	uint64_t saveData(const EduAddDTO::Wrapper& dto, const PayloadDTO& payload);
	void saveData(std::vector<std::vector<std::string>>& vec, const PayloadDTO& payload);
};

#endif // !_EDU_SERVICE_