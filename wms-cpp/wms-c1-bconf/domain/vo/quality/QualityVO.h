#pragma once
#ifndef _QUALITY_VO_
#define _QUALITY_VO_

#include "../../GlobalInclude.h"
#include "../../dto/quality/QualityDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Ʒ�ʴ�������JsonVO��������Ӧ���ͻ��˵�Json����
 */
class QualityJsonVO : public JsonVO<QualityDetailDTO::Wrapper> {
	DTO_INIT(QualityJsonVO, JsonVO<QualityDetailDTO::Wrapper>);
};

/**
 * Ʒ�ʴ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class QualityPageJsonVO : public JsonVO<QualityPageDTO::Wrapper> {
	DTO_INIT(QualityPageJsonVO, JsonVO<QualityPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO__