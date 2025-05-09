#include "stdafx.h"
#include "HuoQuCangWeiShuJuController.h"
#include "service/cangweitu/StoreService.h"

HuoQuCangWeiShuJuJsonVO::Wrapper HuoQuCangWeiShuJuController::execQueryStore(const HuoQuCangWeiShuJuQuery::Wrapper& query)
{
	// ����һ��Service
	StoreService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = HuoQuCangWeiShuJuJsonVO::createShared();
	jvo->data=result;
	return jvo;
}