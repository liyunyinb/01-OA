#pragma once

#ifndef _PIS_VO_
#define _PIS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ba_qm_sta/PisDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PisJsonVO : public JsonVO<PisDTO::Wrapper> {
	DTO_INIT(PisJsonVO, JsonVO<PisDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PisPageJsonVO : public JsonVO<PisPageDTO::Wrapper> {
	DTO_INIT(PisPageJsonVO, JsonVO<PisPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
