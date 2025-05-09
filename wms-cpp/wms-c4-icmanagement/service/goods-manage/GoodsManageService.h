#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _GOODS_MANAGE_SERVICE_
#define _GOODS_MANAGE_SERVICE_
#include <list>

#include "domain/vo/goods-manage/GoodsDiffPostVO.h"
#include "domain/dto/goods-manage/GoodsDiffPostDTO.h"
#include "domain/query/goods-manage/GoodsDiffPostQuery.h"


/**
 * �̵�������ʵ��
 */
class GoodsManageService
{
public:
	// ��ҳ��ѯ��������
	GoodsDiffPostPageDTO::Wrapper listAll(const GoodsDiffPostQuery::Wrapper& query);
	//�������
	bool updateData(const GoodsDiffPostDTO::Wrapper& dto, const PayloadDTO& payload);
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
