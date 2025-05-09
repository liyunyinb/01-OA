#pragma once
/*
 ��Ҳ 2025 02 28
*/
#ifndef _WORKSTATE_SERVICE_
#define _WORKSTATE_SERVICE_
#include <list>
#include "domain/vo/workstate/WorkStateVO.h"
#include "domain/dto/workstate/WorkStateDTO.h"
#include "domain/do/workstate/WorkStateDO.h"
/**
 * ����״̬ɾ������ʵ�֣�����excel�ĵ��ĵ��뵼������ʵ��
 */
class WorkStateService
{
public:
	// ͨ��IDɾ������
	bool removeData(string id); //���������string�������Ͳ���

	bool uploadData(const std::vector<std::vector<std::string>>& data, const PayloadDTO& payload);
	std::vector<std::vector<std::string>> getVectorData();
};

#endif // !_WORKSTATE_SERVICE_

