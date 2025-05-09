#pragma once

#ifndef _LOADINGFEE_VO_
#define _LOADINGFEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/loading-fee/LoadingFeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���װ�����б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LoadingFeeJsonVO : public JsonVO<LoadingFeeDTO::Wrapper> {
	DTO_INIT(LoadingFeeJsonVO, JsonVO<LoadingFeeDTO::Wrapper>);
};

/**
 * ���װ���ѷ�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class LoadingFeePageJsonVO : public JsonVO<LoadingFeePageDTO::Wrapper> {
	DTO_INIT(LoadingFeePageJsonVO, JsonVO<LoadingFeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _LOADINGFEE_VO_