#pragma once
#include "../../GlobalInclude.h"
#include "../../dto/kongchuwei/GetKongChuWeiListMycontrollerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetKongChuWeiListMycontrollerJsonVO : public JsonVO<GetKongChuWeiListMycontrollerDTO::Wrapper> {
	DTO_INIT(GetKongChuWeiListMycontrollerJsonVO, JsonVO<GetKongChuWeiListMycontrollerDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetKongChuWeiListMycontrollerPageJsonVO : public JsonVO<GetKongChuWeiListMycontrollerPageDTO::Wrapper> {
	DTO_INIT(GetKongChuWeiListMycontrollerPageJsonVO, JsonVO<GetKongChuWeiListMycontrollerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

// !_BIN_TRANSFER_VO_
