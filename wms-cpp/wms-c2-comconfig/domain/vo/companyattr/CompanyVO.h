#pragma once
#ifndef _ENTERPRISE_VO_
#define _ENTERPRISE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/companyattr/CompanyDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ��ҳ�б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class CompanyPageJsonVO : public JsonVO<CompanyListPageDTO::Wrapper> {
	DTO_INIT(CompanyPageJsonVO, JsonVO<CompanyListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ENTERPRISE_VO_