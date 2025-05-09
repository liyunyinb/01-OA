#include "stdafx.h"
#include "HuoQuKeZhuanYiLieBiaoController.h"
#include "service/shengchengtuopanzhuanyi/MoveService.h"

HuoQuKeZhuanYiLieBiaoPageJsonVO::Wrapper HuoQuKeZhuanYiLieBiaoController:: execQueryAll(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query)
{
	// ����һ��Service
	MoveService service;
	// ��ѯ����
	auto result = service.querylist(query);
	// ��Ӧ���
	auto jvo = HuoQuKeZhuanYiLieBiaoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}