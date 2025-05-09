#include "stdafx.h"
#include "AdditionAdjustController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/addition-adjustment/AdditionAdjustService.h"
StringJsonVO::Wrapper AdditionController::execbatchAddition(const AdditionBatchDTO::Wrapper& batchdto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	string resultfail = string("fail");
	string resultsuccess = string("success");
	////// ����У��
	if (!batchdto || !batchdto->dtoList || batchdto->dtoList->empty()) {
		jvo->fail(resultfail);
		return jvo;
	}
	// ����һ��service
	AdditionService service;
	// ִ�������޸�
	if (service.updateData(batchdto)) {
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}

	
}