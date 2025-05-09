#pragma once
#include "../../GlobalInclude.h"
#include "../../dto/lihuorenwu/GettasklistControllerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GettasklistControllerJsonVO : public JsonVO<GettasklistControllerDTO::Wrapper> {
	DTO_INIT(GettasklistControllerJsonVO, JsonVO<GettasklistControllerDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GettasklistControllerPageJsonVO : public JsonVO<GettasklistControllerPageDTO::Wrapper> {
	DTO_INIT(GettasklistControllerPageJsonVO, JsonVO<GettasklistControllerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

// !_BIN_TRANSFER_VO_