#include "stdafx.h"
#include "CostNameController.h"
#include "../../service/billing-configuration/CostNameService.h"
#include "../ApiDeclarativeServicesHelper.h"

CostNameJsonVO::Wrapper CostNameController::execQueryCostNameListAll(const CostNameQuery::Wrapper& costPageQuery)
{
	
	CostNameService service;
	// ��ѯ����
	auto result = service.listAll(costPageQuery);
	// ��Ӧ���
	auto jvo = CostNameJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

CostNamePageJsonVO::Wrapper CostNameController::execQueryCostNameListWithCondition(const CostNameQuery::Wrapper& costPageQuery)
{
	CostNameService service;
	// ��ѯ����
	auto result = service.listAllByPage(costPageQuery);
	// ��Ӧ���
	auto jvo = CostNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper CostNameController::execAddCostName(const CostAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	if (!dto->cost_code || !dto->cost_name || !dto->cost_type_code)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->cost_code->empty() || dto->cost_name->empty() || dto->cost_type_code->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CostNameService service;
	// ִ����������
	String resultfail = String("fail");
	String resultsuccess = String("success");
	if (service.saveData(dto,payload)) {
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}
	return jvo;
}

StringJsonVO::Wrapper CostNameController::execModifyCostName(const CostModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	if (!dto->id)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CostNameService service;
	// ִ�������޸�
	String resultfail = String("fail");
	String resultsuccess = String("success");
	if (service.updateData(dto,payload)) {
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}
	return jvo;
}