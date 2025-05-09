#include "stdafx.h"
#include "SttTaskController.h"
#include "../../service/stt-task/SttTaskService.h"

StringJsonVO::Wrapper SttTaskController::execDelTask(const String& id, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();

	SttTaskService service;
	// ִ������ɾ��
	if (service.delData(id, payload))
	{
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}

	return jvo;
}
