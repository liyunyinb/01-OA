#include "stdafx.h"
#include "TuopanController.h"
#include "../../service/tuopandingyi/TuopanService.h"
#include "../../domain/vo/tuopandingyi/TuopanVO.h"




TuopanPageJsonVO::Wrapper TuopanController::execQueryTuopan(const TuopanQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	TuopanService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = TuopanPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper TuopanController::execModifyTuopan(const TuopanDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id )
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TuopanService service;
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

StringJsonVO::Wrapper TuopanController::execRemoveTuopan(const DeleteTuopanDTO::Wrapper& idlist)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!idlist)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TuopanService service;

	// ִ������ɾ��
	bool res = service.removeData(idlist->id);
	if (res) {
		jvo->init("success", RS_SUCCESS);
	}
	else
	{
		jvo->init("fail", RS_FAIL);
	}
	
	// ��Ӧ���
	return jvo;
}
