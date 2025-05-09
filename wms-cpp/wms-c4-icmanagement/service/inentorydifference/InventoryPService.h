#pragma once
#ifndef _INVENTORYP_SERVICE_
#define _INVENTORYP_SERVICE_
#include <list>
#include "domain/vo/inentorydifference/InventoryPVO.h"
#include "domain/query/inentorydifference/InventoryPquery.h"
#include "domain/dto/inentorydifference/InventoryPDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class InventoryPService
{
public:
	// ��ҳ��ѯ��������
	InventoryPPageDTO::Wrapper listAll(const InventoryPquery::Wrapper& query);
	// ��������
	uint64_t saveData(const InventoryPAddDTO::Wrapper& dto);
};

#endif // !_INVENTORYP_SERVICE_

