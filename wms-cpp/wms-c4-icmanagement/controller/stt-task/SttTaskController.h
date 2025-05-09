#pragma once

#ifndef _STT_TASK_CONTROLLER_
#define _STT_TASK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/stt-task/SttTaskVO.h"
//#include "domain/dto/stt-task/SttTaskDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �̵����-��������Ϣ����
 */
class SttTaskController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	API_ACCESS_DECLARE(SttTaskController);

public:
	// ����ɾ���̵�����ӿ�����
	ENDPOINT_INFO(delTask)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sttTask.summary.del"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ѯ��������
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("sttTask.field.id"), "0000", true);
	}

	// ����ɾ���̵�����ӿڴ���
	ENDPOINT(API_M_DEL, "/stt/stt-task/{id}", delTask,PATH(String, id), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execDelTask((id),authObject->getPayload()));
	}

private:
	
	StringJsonVO::Wrapper execDelTask(const String& id,const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_STT_TASK_CONTROLLER_