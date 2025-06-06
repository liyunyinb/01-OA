#include "stdafx.h"
#include "OverallInventoryController.h"
#include "../../service/overallInventory/InventorylistService.h"
#include "FastDfsClient.h"


InventoryJsonPageVO::Wrapper OverallInventoryController::execQuerySample(const InventorylistQuery::Wrapper& query, const PayloadDTO& payload)
{   // 定义一个Service
	InventorylistService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = InventoryJsonPageVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper OverallInventoryController::execAddSample(const InventorylistDto::Wrapper& dto)
{// 定义返回数据对象
	//auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	/*if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// 有效值校验
	/*if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	//// 定义一个Service
	//InventorylistService service;
	//// 执行数据新增
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	////响应结果
	//return jvo;
	return {};
}