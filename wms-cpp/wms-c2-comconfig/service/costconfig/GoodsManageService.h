#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _GOODS_MANAGE_SERVICE_
#define _GOODS_MANAGE_SERVICE_
#include <list>

#include "domain/vo/costconfig/GoodsDiffPostVO.h"
#include "domain/dto/costconfig/GoodsDiffPostDTO.h"
#include "domain/query/costconfig/GoodsDiffPostQuery.h"


/**
 * �̵�������ʵ��
 */
class GoodsManageService
{
public:
	// ��ҳ��ѯ��������
	GoodsDiffPostPageDTO::Wrapper listAll(const GoodsDiffPostQuery::Wrapper& query);
	//��ҵ�ȼ�
	bool updateData(const GoodsDiffPostDTO::Wrapper& dto);
	//��������
	std::string exportData(const GoodsDiffPostQuery::Wrapper& query);
	// ͨ��������ѯ��������
	//GoodsDiffPostListDTO::Wrapper getByCondition(const GoodsDiffPostQuery::Wrapper& query);
	// ��������
	/*uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const SampleDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);*/
};

#endif // !_GOODS_MANAGE_SERVICE_
