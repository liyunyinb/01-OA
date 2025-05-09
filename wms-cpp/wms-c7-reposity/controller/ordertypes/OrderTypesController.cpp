/*
 @Author: nanbowan
*/
#include"stdafx.h"
#include"OrderTypesController.h"
#include "../../service/ordertypes/OrderTypesService.h"

Uint64JsonVO::Wrapper OrderTypesController::execModifyOrd(const ModifyOrderTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	string stdId = dto->id->c_str();
	uint64_t idValue = std::stoull(stdId);
	if (!dto->id || idValue < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	OrderTypesService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(idValue);
	}
	else
	{
		jvo->fail(idValue);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper OrderTypesController::execDeleteOrd(const oatpp::String& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��

	if (!id || id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	OrderTypesService service;
	string stdId = id->c_str();
	uint64_t idValue = std::stoull(stdId);
	if (service.removeData(id)){
		jvo->success(idValue);
	}
	else
	{
		jvo->fail(idValue);
	}
	// ��Ӧ���
	return jvo;
}


