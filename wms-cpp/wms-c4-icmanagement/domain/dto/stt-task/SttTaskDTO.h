#pragma once

#ifndef _STT_TASKDTO_
#define _STT_TASKDTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*	�̵�����������ݶ���
*/
class SttTaskBaseDTO : public oatpp::DTO
{
	DTO_INIT(SttTaskBaseDTO, oatpp::DTO);
	// ��ȡ�̵������б�����ݣ����ɸ����ȡ�б��ͬѧ����
};

class SttTaskDetailDTO : public SttTaskBaseDTO
{
	DTO_INIT(SttTaskDetailDTO, SttTaskBaseDTO);
};

class SttTaskListDTO : public SttTaskDetailDTO
{
	DTO_INIT(SttTaskListDTO, SttTaskDetailDTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sttTask.field.id"));
};

class SttTaskPageDTO : public PageDTO<SttTaskListDTO::Wrapper>
{
	DTO_INIT(SttTaskPageDTO, PageDTO<SttTaskListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif