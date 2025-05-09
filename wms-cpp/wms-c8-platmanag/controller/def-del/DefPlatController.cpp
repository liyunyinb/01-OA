#include "stdafx.h"
#include "DefPlatController.h"
#include "../../service/def-plat/DefPlatService.h"
#include "../ApiDeclarativeServicesHelper.h"
Uint64JsonVO::Wrapper DefPlatController::execDelPlat(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (id == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DefPlatService service;
	// ִ������ɾ��
	if (service.DefDelData(id)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(3);
	}
	// ��Ӧ���
	return jvo;
}
StringJsonVO::Wrapper DefPlatController::execPutPlat(const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	// ����һ��Service
	DefPlatService service;
	// ִ�����ݵ���
	string result = service.DefPutData(payload);
	if (!result.empty()) {
		jvo->success(result);
	}
	else {
		jvo->fail(result);
	}
	return jvo;
}
Uint64JsonVO::Wrapper DefPlatController::execEditPlat(const DefEditDto::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (dto->id == "")
	{
		//std::cout << dto->id << dto->id_ << std::endl;
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DefPlatService service;
	// ִ�������޸�
	if (service.DefEditData(dto, payload)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(3);
	}
	// ��Ӧ���
	return jvo;
}
