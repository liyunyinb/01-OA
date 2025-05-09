#pragma once
#ifndef _REMOVAL_SERVICE_
#define _REMOVAL_SERVICE_
#include <list>
//#include "domain/vo/sample/SampleVO.h"
#include "../../domain/vo/removal-adjustment/RemovalVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "../../domain/query/removal-adjustment/RemovalQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
#include "../../domain/dto/removal-adjustment/RemovalDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RemovalService
{
public:
	// ��ҳ��ѯ��������
	RemovalPageDTO::Wrapper listAll(const RemovalQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	RemovalDetailDTO::Wrapper getById(const oatpp::String& id);
	RemovalDetailPageDTO::Wrapper getdetail(const RemovalQuery::Wrapper& query);
	//ͨ���ַ�ID��ѯ��ϸ����
	//RemovalDetailDTO::Wrapper getbyorder_id(const RemovalQuery::Wrapper& query);
	// ��������
	//uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const RemovalListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_