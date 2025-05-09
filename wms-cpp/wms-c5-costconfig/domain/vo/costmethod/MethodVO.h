#pragma once
#ifndef _METHOD_VO_
#define _METHOD_VO_

#include "../../GlobalInclude.h"
#include "../../dto/costmethod/MethodDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MethodJsonVO : public JsonVO<MethodDTO::Wrapper> {
	DTO_INIT(MethodJsonVO, JsonVO<MethodDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MethodPageJsonVO : public JsonVO<MethodPageDTO::Wrapper> {
	DTO_INIT(MethodPageJsonVO, JsonVO<MethodPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _METHOD_VO_