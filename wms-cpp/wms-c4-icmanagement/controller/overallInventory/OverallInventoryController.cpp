#include "stdafx.h"
#include "OverallInventoryController.h"
#include "../../service/overallInventory/InventorylistService.h"
#include "FastDfsClient.h"


InventoryJsonPageVO::Wrapper OverallInventoryController::execQuerySample(const InventorylistQuery::Wrapper& query, const PayloadDTO& payload)
{   // ����һ��Service
	InventorylistService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = InventoryJsonPageVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper OverallInventoryController::execAddSample(const InventorylistDto::Wrapper& dto)
{// ���巵�����ݶ���
	//auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	/*if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// ��ЧֵУ��
	/*if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	//// ����һ��Service
	//InventorylistService service;
	//// ִ����������
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	////��Ӧ���
	//return jvo;
	return {};
}