#pragma once
#ifndef _ORDER_TYPE_SERVICE_H_
#define _ORDER_TYPE_SERVICE_H_
#include <list>
#include "../../domain/vo/order_type/OrderTypeVo.h"
#include "../../domain/query/order_type/OrderTypeQuery.h"
#include "../../domain/dto/order_type/OrderTypeDTO.h"

class OrderTypeService
{
public:
	// ��ѯ�������������б�
	OrderTypeNamePageDTO::Wrapper listName(const PageQuery::Wrapper& query);
	// ��ҳ��ѯ��������
	OrderTypePageDTO::Wrapper listAll(const OrderTypeQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const OrderTypeAddDTO::Wrapper& dto, const PayloadDTO& payload);

};

#endif //! _ORDER_TYPE_SERVICE_H_