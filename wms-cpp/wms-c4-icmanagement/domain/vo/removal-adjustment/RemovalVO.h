#pragma once
#ifndef _REMOVAL_VO_
#define _REMOVAL_VO_

#include "../../GlobalInclude.h"
#include "../../dto/removal-adjustment/RemovalDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RemovalListJsonVO : public JsonVO<RemovalListDTO::Wrapper> {
	DTO_INIT(RemovalListJsonVO, JsonVO<RemovalListDTO::Wrapper>);
};
class RemovalDetailJsonVO :public JsonVO<RemovalDetailDTO::Wrapper>
{
	DTO_INIT(RemovalDetailJsonVO, JsonVO<RemovalDetailDTO::Wrapper>);
};
class RemovalDetailPageJsonVO :public JsonVO<RemovalDetailPageDTO::Wrapper> {
	DTO_INIT(RemovalDetailPageJsonVO, JsonVO<RemovalDetailPageDTO::Wrapper>);
};
/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RemovalPageJsonVO : public JsonVO<RemovalPageDTO::Wrapper> {
	DTO_INIT(RemovalPageJsonVO, JsonVO<RemovalPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // 