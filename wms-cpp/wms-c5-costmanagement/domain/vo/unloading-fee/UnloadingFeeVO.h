#pragma once

#ifndef _UNLOADINGFEE_VO_
#define _UNLOADINGFEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/unloading-fee/UnloadingFeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ж������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UnloadingFeeJsonVO : public JsonVO<UnloadingFeeDTO::Wrapper> {
	DTO_INIT(UnloadingFeeJsonVO, JsonVO<UnloadingFeeDTO::Wrapper>);
};

/**
 * ���ж���ѷ�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UnloadingFeePageJsonVO : public JsonVO<UnloadingFeePageDTO::Wrapper> {
	DTO_INIT(UnloadingFeePageJsonVO, JsonVO<UnloadingFeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _UNLOADINGFEE_VO_