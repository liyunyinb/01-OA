#pragma once

#ifndef _COMDEG_VO_
#define _COMDEG_VO_

#include "../../GlobalInclude.h"
#include "../../dto/comdeg/ComdegDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��˾�ȼ���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ComdegJsonVO : public JsonVO<ComdegDetailDTO::Wrapper> {
	DTO_INIT(ComdegJsonVO, JsonVO<ComdegDetailDTO::Wrapper>);
};

/**
 * ��˾�ȼ���ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ComdegPageJsonVO : public JsonVO<ComdegPageDTO::Wrapper> {
	DTO_INIT(ComdegPageJsonVO, JsonVO<ComdegPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COMDEG_VO_