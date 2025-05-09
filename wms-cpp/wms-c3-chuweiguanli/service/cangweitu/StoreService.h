#pragma once
#ifndef _STORE_SERVICE_
#define _STORE_SERVICE_
#include <list>
#include "domain/vo/cangweitu/HuoQuCangWeiShuJuVO.h"
#include "domain/query/cangweitu/HuoQuCangWeiShuJuQuery.h"
#include "domain/dto/cangweitu/HuoQuCangWeiShuJuDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class StoreService
{
public:
	
	List<HuoQuCangWeiShuJuDTO::Wrapper> listAll(const HuoQuCangWeiShuJuQuery::Wrapper& query);
	
};

#endif // !_STORE_SERVICE_