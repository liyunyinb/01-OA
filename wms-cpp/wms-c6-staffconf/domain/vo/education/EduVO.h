#pragma once

#ifndef _EDU_VO_
#define _EDU_VO_

#include "../../GlobalInclude.h"
#include "../../dto/education/EduDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ѧ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class EduJsonVO : public JsonVO<EduDTO::Wrapper> {
	DTO_INIT(EduJsonVO, JsonVO<EduDTO::Wrapper>);
};

/**
 * ѧ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class EduPageJsonVO : public JsonVO<EduPageDTO::Wrapper> {
	DTO_INIT(EduPageJsonVO, JsonVO<EduPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Edu_VO_