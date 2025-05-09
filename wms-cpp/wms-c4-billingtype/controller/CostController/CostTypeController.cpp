#include "stdafx.h"
#include "CostTypeController.h"
#include "../../service/CostTypeService/CostTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"

CostJsonVO::Wrapper CostTypeController::execQueryCostTypeListAll(const Int64& id)
{
    // ����ʵ�֣���ȡ���з�������
	// ���巵�����ݶ���
	auto jvo = CostJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (id.getValue({}) <= 0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CostTypeService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);
	return jvo;
}

CostPageJsonVO::Wrapper CostTypeController::execQueryCostTypeListWithCondition(const  CostTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
    // ����ʵ�֣���ȡ���������б��ҳ
	// ����һ��Service
	CostTypeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CostPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper CostTypeController::execGetCostType(const GetCostDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // ����ʵ�֣�¼���������
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// ��ЧֵУ��
	if ( dto->cost_code->empty() || dto->cost_name->empty()|| dto->cost_type->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CostTypeService service;
	// ִ����������
	uint64_t id = service.saveData(dto,payload);
	//std::cout << "controller id = " << id << "\n";
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

Uint64JsonVO::Wrapper CostTypeController::execModifyCostType(const ModifyCostDTO::Wrapper& dto)
{
    // ����ʵ�֣��޸ķ�������


	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CostTypeService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}