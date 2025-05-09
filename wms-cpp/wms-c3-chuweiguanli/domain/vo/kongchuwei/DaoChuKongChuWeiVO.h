#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_VO_
#define _DAO_CHU_KONG_CHU_WEI_VO_

#include "../../GlobalInclude.h"
#include "../../dto/kongchuwei/DaoChuKongChuWeiDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �մ�λ�ļ��ϴ��������
 */
class DaoChuKongChuWeiVO : public JsonVO<DaoChuKongChuWeiDTO::Wrapper>
{
	DTO_INIT(DaoChuKongChuWeiVO, JsonVO<DaoChuKongChuWeiDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DAO_CHU_KONG_CHU_WEI_VO_