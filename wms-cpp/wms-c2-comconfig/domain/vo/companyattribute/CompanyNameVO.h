#pragma once
#ifndef _ENTERPRISE_VO_
#define _ENTERPRISE_VO_

#include "../../dto/companyattribute/CompanyNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
��ҵ�����˵���״̬�б�
*/
class CompanyNameJsonVO : public JsonVO<CompanyNameDTO::Wrapper> {
	DTO_INIT(CompanyNameJsonVO, JsonVO<CompanyNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ENTERPRISE_VO_
