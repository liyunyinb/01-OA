#pragma once
#ifndef _COMPANY_INFORMATION_VO_
#define _COMPANY_INFORMATION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cominfo/ComInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��˾��Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ComInfoJsonVO : public JsonVO<ComInfoDTO::Wrapper> {
	DTO_INIT(ComInfoJsonVO, JsonVO<ComInfoDTO::Wrapper>);
};

/**
 * ��˾��Ϣ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ComInfoPageJsonVO : public JsonVO<ComInfoPageDTO::Wrapper> {
	DTO_INIT(ComInfoPageJsonVO, JsonVO<ComInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANY_INFORMATION_VO_

