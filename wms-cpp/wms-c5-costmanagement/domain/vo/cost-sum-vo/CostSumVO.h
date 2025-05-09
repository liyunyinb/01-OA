#pragma once
#ifndef _CostSum_VO_
#define _CostSum_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cost-sum-dto/CostSumDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CostSumJsonVO : public JsonVO< CostSumBaseDTO::Wrapper> {
	DTO_INIT(CostSumJsonVO, JsonVO< CostSumBaseDTO::Wrapper>);
};

/**
 * ʾ����ҳl�б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class CostSumPageJsonVO : public JsonVO< CostSumPageDTO::Wrapper> {
	DTO_INIT(CostSumPageJsonVO, JsonVO< CostSumPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
