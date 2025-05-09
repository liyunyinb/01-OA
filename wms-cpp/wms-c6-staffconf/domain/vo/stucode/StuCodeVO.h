#pragma once
#ifndef _StuCode_VO_
#define _StuCode_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/stucode/StuCodeDTO.h"
//#include "JsonVO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class StuCodeJsonVO : public JsonVO<StuCodeDTO::Wrapper> {
	DTO_INIT(StuCodeJsonVO, JsonVO<StuCodeDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class StuCodePageJsonVO : public JsonVO<StuCodePageDTO::Wrapper> {
	DTO_INIT(StuCodePageJsonVO, JsonVO<StuCodePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_StuCode_VO_