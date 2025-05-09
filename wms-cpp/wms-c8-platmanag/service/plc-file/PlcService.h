#pragma once
/*
 @Author: tutu
*/
#ifndef _PLC_SERVICE_
#define _PLC_SERVICE_
#include <list>
#include "domain/vo/plc-file/PlcFileVO.h"
#include "domain/query/plc-file/PlcFileQuery.h"
#include "domain/dto/plc-file/PlcFileDto.h"

class PlcService
{
public:
	// ��ҳ��ѯ��������
	PlcListPageDTO::Wrapper listAll(const PlcFileQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	PlcdetailDTO::Wrapper getById(string id);
	// ��������
	bool saveData(const PlcAddDTO::Wrapper& dto, string name, string realname, string orgcode, string companycode);
	// �޸�����
	bool updateData(const PlcdetailDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id);
};

#endif

