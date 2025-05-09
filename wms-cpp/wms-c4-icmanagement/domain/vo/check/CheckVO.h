#pragma once

#ifndef _CHECK_VO_
#define _CHECK_VO_

#include "../../GlobalInclude.h"
#include "../../dto/check/CheckDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �̵�������JsonVO��������Ӧ���ͻ��˵�Json����
 */
class CheckJsonVO : public JsonVO<CheckDtailDTO::Wrapper> {
	DTO_INIT(CheckJsonVO, JsonVO<CheckDtailDTO::Wrapper>);
};

/**
 * �̵��������б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class CheckPageJsonVO : public JsonVO<CheckPageDTO::Wrapper> {
	DTO_INIT(CheckPageJsonVO, JsonVO<CheckPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECK_VO_#pragma once
