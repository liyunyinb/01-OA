#pragma once

#ifndef _COST_VO_
#define _COST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cost-detail/CostDetialDTO.h"

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
class CostDetailListPageJsonVO : public JsonVO<CostDetailBaseDTO::Wrapper> {
	DTO_INIT(CostDetailListPageJsonVO, JsonVO<CostDetailBaseDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_VO_