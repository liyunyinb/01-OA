#include "stdafx.h"
#include "OrderTypeController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/order_type/OrderTypeService.h"

OrderTypeNameVO::Wrapper OrderTypeController::execQueryNameOrderType(const PageQuery::Wrapper& query)
{
	// ����һ��Service
	OrderTypeService service;
	// ��ѯ����
	auto result = service.listName(query);
	// ��Ӧ���
	auto jvo = OrderTypeNameVO::createShared();
	jvo->success(result);
	return jvo;
}

OrderTypePageJsonVO::Wrapper OrderTypeController::execQueryOrderType(const OrderTypeQuery::Wrapper& query)
{
	// ����һ��Service
	OrderTypeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = OrderTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper OrderTypeController::addOrderType(const OrderTypeAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->order_type_code || !dto->order_type_name) 
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->order_type_code->empty() || dto->order_type_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	OrderTypeService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}