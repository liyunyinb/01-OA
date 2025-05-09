#pragma once
#ifndef _ENTERPRISE_VO_
#define _ENTERPRISE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CDMattr/CDMDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ��ҳ�б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class CDMPageJsonVO : public JsonVO<CDMListPageDTO::Wrapper> {
	DTO_INIT(CDMPageJsonVO, JsonVO<CDMListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ENTERPRISE_VO_