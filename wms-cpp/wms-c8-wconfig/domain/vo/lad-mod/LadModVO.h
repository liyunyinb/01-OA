#pragma once
// ================================================================
// @FileName��    
// @Author��    cslr
// @Date��   2025-2-22
// Summary��  
//================================================================
#ifndef _LADMOD_VO_
#define _LADMOD_VO_

#include "../../GlobalInclude.h"
#include "../../dto/lad-mod/LadModDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����ʽ����JsonVO��������Ӧ���ͻ��˵�Json����
 */
class LadModJsonVO : public JsonVO<LadModDTO::Wrapper> {
	DTO_INIT(LadModJsonVO, JsonVO<LadModDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LadModPageJsonVO : public JsonVO<LadModPageDTO::Wrapper> {
	DTO_INIT(LadModPageJsonVO, JsonVO<LadModPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_