#pragma once
#ifndef _HUOQUKEZHUANYILIEBIAOVO_
#define _HUOQUKEZHUANYILIEBIAOVO_

#include "../../GlobalInclude.h"
#include "../../dto/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ת���б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class HuoQuKeZhuanYiLieBiaoJsonVO : public JsonVO<HuoQuKeZhuanYiLieBiaoDTO::Wrapper> {
	DTO_INIT(HuoQuKeZhuanYiLieBiaoJsonVO, JsonVO<HuoQuKeZhuanYiLieBiaoDTO::Wrapper>);
};

/**
 * ��ת���б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class HuoQuKeZhuanYiLieBiaoPageJsonVO : public JsonVO<HuoQuKeZhuanYiLieBiaoListPageDTO::Wrapper> {
	DTO_INIT(HuoQuKeZhuanYiLieBiaoPageJsonVO, JsonVO<HuoQuKeZhuanYiLieBiaoListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_HUOQUKEZHUANYILIEBIAOVO_