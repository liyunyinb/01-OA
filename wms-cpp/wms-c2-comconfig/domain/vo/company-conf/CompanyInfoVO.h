#pragma once
#ifndef _COMPANY_VO_
#define _COMPANY_VO_

#include "../../GlobalInclude.h"
#include "../../dto/company-conf/CompanyInfoDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��˾��ϸ��Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CompanyInfoVOJsonVO : public JsonVO<CompanyBaseeDTO::Wrapper> {
	DTO_INIT(CompanyInfoVOJsonVO, JsonVO<CompanyBaseeDTO::Wrapper>);
};

/**
 * ��˾��Ϣ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CompanyPageJsonVO : public JsonVO<CompanyListPageDTO::Wrapper> {
	DTO_INIT(CompanyPageJsonVO, JsonVO<CompanyListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COMPANY_VO_