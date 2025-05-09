#pragma once

#ifndef _COST_VO_
#define _COST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cost-detail-ahead/CostDetialDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ϸ����JsonVO��������Ӧ���ͻ��˵�Json����
 */
class CostDetailJsonVO : public JsonVO<CostDetailBaseDTO::Wrapper> {
	DTO_INIT(CostDetailJsonVO, JsonVO<CostDetailBaseDTO::Wrapper>);
};

/**
 * ������ϸ��ҳ�б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class CostDetailListPageJsonVO : public JsonVO<CostDetailListPageDTO::Wrapper> {
	DTO_INIT(CostDetailListPageJsonVO, JsonVO<CostDetailListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_VO_