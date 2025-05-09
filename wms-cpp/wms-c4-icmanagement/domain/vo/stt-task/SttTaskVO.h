#pragma once

#ifndef _STT_TASK_VO_
#define _STT_TASK_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/stt-task/SttTaskDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SttTaskPageJsonVO : public JsonVO<SttTaskListDTO::Wrapper> {
	DTO_INIT(SttTaskPageJsonVO, JsonVO<SttTaskListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_STT_TASK_VO_