#pragma once


#ifndef _XIANGXIXINXIXIANSHIVO_
#define _XIANGXIXINXIXIANSHIVO_

#include "../../GlobalInclude.h"
#include "../../dto/chuweidingyi/xiangxixinxiDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ��������JsonVO��������Ӧ���ͻ��˵�Json����
 */
class xiangxixinxiJsonVO : public JsonVO<xiangxixinxiDTO::Wrapper> {
	DTO_INIT(xiangxixinxiJsonVO, JsonVO<xiangxixinxiDTO::Wrapper>);
};

/**
 * ������JsonVO��������Ӧ���ͻ��˵�Json����
 */
//class daochuJsonVO : public JsonVO<daochudto::Wrapper> {
//	DTO_INIT(daochuJsonVO, JsonVO<daochudto::Wrapper>);
//};


#include OATPP_CODEGEN_END(DTO)

#endif // !_XIANGXIXINXIXIANSHIVO_