#pragma once


#ifndef _STT_TASK_SERVICE_
#define _STT_TASK_SERVICE_

#include "domain/dto/stt-on-move/SttOnMoveDTO.h"

/**
 * �̵��������ʵ��
 */
class SttTaskService
{
public:
	// ������������ӵ��̵������У������̵�����
	uint64_t insert(const SttOnMoveDetailDTO::Wrapper& sttOnMoveDetailDTO,const PayloadDTO& payload);

	//bool insert(const SttOnMoveInsertTaskDTO::Wrapper& dto, const PayloadDTO& payload);
	
	// ɾ���̵������޸�stt_staΪ��ɾ��
	uint64_t delData(const string& id, const PayloadDTO& payload);
};


#endif