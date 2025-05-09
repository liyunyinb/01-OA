#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/3/10 14:33

*/
#ifndef _REVIEW_STT_VO_H_
#define _REVIEW_STT_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/review-stt/ReviewSttDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��������ʾJsonVO����������Ӧ���ͻ���
 */
class ReviewSttJsonVO : public JsonVO<ReviewSttDetailDTO::Wrapper>
{
	DTO_INIT(ReviewSttDetailDTO, JsonVO<ReviewSttDetailDTO::Wrapper>);
};

/**
 * ����һ�����̷�ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class ReviewSttPageJsonVO : public JsonVO<ReviewSttPageDTO::Wrapper>
{
	DTO_INIT(ReviewSttPageJsonVO, JsonVO<ReviewSttPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _REVIEW_STT_VO_H_