#pragma once
#ifndef _MOVE_SERVICE_
#define _MOVE_SERVICE_
#include <list>
#include "domain/vo/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoVO.h"
#include "domain/query/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoQuery.h"
#include "domain/dto/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class MoveService
{
public:
	// ��ҳ��ѯ��������
	HuoQuKeZhuanYiLieBiaoListPageDTO::Wrapper querylist(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query);
	
};

#endif // !_MOVE_SERVICE_