#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_VO_
#define _COMPANYATTR_VO_

#include "../../GlobalInclude.h"
#include "../../dto/companyattr/CompanyattrDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ��ҳ�б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class CompanyattrPageJsonVO : public JsonVO<CompanyattrListPageDTO::Wrapper> {
	DTO_INIT(CompanyattrPageJsonVO, JsonVO<CompanyattrListPageDTO::Wrapper>);
};
class CompanyattrJsonVO :public JsonVO<CompanyattrListDTO::Wrapper> {
	DTO_INIT(CompanyattrJsonVO, JsonVO<CompanyattrListDTO::Wrapper>);
};

class CompanyAttrJsonVO :public JsonVO<CompanyattrIdListDTO::Wrapper> {
	DTO_INIT(CompanyAttrJsonVO, JsonVO<CompanyattrIdListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_COMPANYATTR_VO_