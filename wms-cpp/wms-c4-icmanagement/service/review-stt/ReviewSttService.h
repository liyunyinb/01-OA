#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _REVIEW_STT_SERVICE_
#define _REVIEW_STT_SERVICE_
#include <list>

#include "domain/query/review-stt/ReviewSttQuery.h"
#include "domain/dto/review-stt/ReviewSttDTO.h"
#include "domain/vo/review-stt/ReviewSttVO.h"


/**
 * �̵�������ʵ��
 */
class ReviewSttService
{
public:
	// ��ҳ��ѯ��������
	ReviewSttPageDTO::Wrapper listAll(const ReviewSttQuery::Wrapper& query);
	//����
	bool updateData(const ReviewSttDTO::Wrapper& dto, const PayloadDTO& payload);
	//��������
	std::string exportData(const ReviewSttQuery::Wrapper& query);
	// ͨ��������ѯ��������
	//GoodsDiffPostListDTO::Wrapper getByCondition(const GoodsDiffPostQuery::Wrapper& query);
	// ��������
	/*uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const SampleDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);*/
};

#endif // !_REVIEW_STT_SERVICE_
