#pragma once
#ifndef _CHUWEI_VO_
#define _CHUWEI_VO_

#include "../../GlobalInclude.h"
#include "../../dto/chuweidingyi/ChuWeiDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ChuWeiPageJsonVO : public JsonVO<ChuWeiPageDTO::Wrapper> {
	DTO_INIT(ChuWeiPageJsonVO, JsonVO<ChuWeiPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHUWEI_VO_