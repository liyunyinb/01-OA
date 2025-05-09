#pragma once
#ifndef _EXPORT_VO_H_
#define _EXPORT_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/export-industry-class/ExportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportJsonVO : public JsonVO<ExportDTO::Wrapper> {
	DTO_INIT(ExportJsonVO, JsonVO<ExportDTO::Wrapper>);
};

/**
 * ��ҵ�����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExportPageJsonVO : public JsonVO<ExportPageDTO::Wrapper> {
	DTO_INIT(ExportPageJsonVO, JsonVO<ExportPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORT_VO_H_