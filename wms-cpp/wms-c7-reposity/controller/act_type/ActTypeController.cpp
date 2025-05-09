#include "stdafx.h"
#include "ActTypeController.h"
#include "../../service/act_type/ActTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"


ActTypePageJsonVO::Wrapper ActTypeController::execQueryActType(const ActTypeQuery::Wrapper& query)
{
	// ����һ��Service
	ActTypeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ActTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper ActTypeController::execAddActType(const ActTypeBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->act_type_code || !dto->act_type_name || !dto->oper_step_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->act_type_code->empty() || dto->act_type_name->empty() || dto->oper_step_code->empty())
	{
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ActTypeService service;
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