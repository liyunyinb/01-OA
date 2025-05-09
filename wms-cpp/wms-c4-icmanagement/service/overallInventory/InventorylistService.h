#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _REVIEW_STT_SERVICE_
#define _REVIEW_STT_SERVICE_
#include <list>

#include "domain/query/overallInventory/InventorylistQuery.h"
#include "domain/dto/overallInventory/InventorylistDto.h"
#include "domain/vo/overallInventory/InventorylistVo.h"


/**
 * �̵�������ʵ��
 */
class InventorylistService
{
public:
	// ��ҳ��ѯ��������
	InventorylistDto::Wrapper listAll(const InventorylistQuery::Wrapper& query);
	
	// ͨ��������ѯ��������
	//GoodsDiffPostListDTO::Wrapper getByCondition(const GoodsDiffPostQuery::Wrapper& query);
	// ��������
	//uint64_t saveData(const InventorylistDto::Wrapper& dto);
	 /*// �޸�����
	bool updateData(const SampleDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);*/
};

#endif // !_REVIEW_STT_SERVICE_
