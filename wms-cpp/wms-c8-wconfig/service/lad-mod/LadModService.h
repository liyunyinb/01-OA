#pragma once

#ifndef _LADMOD_SERVICE_
#define _LADMOD_SERVICE_
#include <list>
#include "domain/vo/lad-mod/LadModVO.h"
#include "domain/query/lad-mod/LadModQuery.h"
#include "domain/dto/lad-mod/LadModDTO.h"
#include "../../domain/dto/lad-mod/BatchDeleteRequestDto.h"

/**
 * ʾ�������ʽ����ʵ��
 */
class LadModService
{
public:
	// ��ҳ��ѯ��������
	LadModPageDTO::Wrapper listAll(const LadModQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const LadModAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const LadModDTO::Wrapper& dto);
	// ͨ��IDɾ�������ʽ
	bool deleteLad(oatpp::UInt64 id);
	// ����ɾ�������ʽ
	bool batchDeleteLad(const BatchDeleteRequestDto::Wrapper& dto);
	// ���������ʽ�������ļ���ַ��
	string exportLad();
	// ���������ʽ
	int importLad(string filePath);
};

#endif // !_SAMPLE_SERVICE_

