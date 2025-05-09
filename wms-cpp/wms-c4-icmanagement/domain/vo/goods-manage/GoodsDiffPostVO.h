#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/2/22 14:33

*/
#ifndef _GOODS_DIFF_POST_VO_H_
#define _GOODS_DIFF_POST_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/goods-manage/GoodsDiffPostDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���̵���������ʾJsonVO����������Ӧ���ͻ���
 */
class GoodsDiffPostJsonVO : public JsonVO<GoodsDiffPostDetailDTO::Wrapper>
{
	DTO_INIT(GoodsDiffPostJsonVO, JsonVO<GoodsDiffPostDetailDTO::Wrapper>);
};

/**
 * ����һ���̵������˷�ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class GoodsDiffPostPageJsonVO : public JsonVO<GoodsDiffPostPageDTO::Wrapper>
{
	DTO_INIT(GoodsDiffPostPageJsonVO, JsonVO<GoodsDiffPostPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_