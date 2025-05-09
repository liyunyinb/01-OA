#pragma once

#ifndef _SEX_VO_
#define _SEX_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/SampleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ա���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SexJsonVO : public JsonVO<SampleDTO::Wrapper> {
	DTO_INIT(SexJsonVO, JsonVO<SampleDTO::Wrapper>);
};

/**
 * �Ա��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SexPageJsonVO : public JsonVO<SamplePageDTO::Wrapper> {
	DTO_INIT(SexPageJsonVO, JsonVO<SamplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_