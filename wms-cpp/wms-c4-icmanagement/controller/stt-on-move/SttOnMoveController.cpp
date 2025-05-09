/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/03 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "SttOnMoveController.h"
#include "../../service/stt-on-move/SttOnMoveService.h"
#include "../../service/stt-task/SttTaskService.h"

SttOnMovePageJsonVO::Wrapper SttOnMoveController::execQueryAll(const SttOnMoveQuery::Wrapper& query)
{
	// ����ҵ���߼���service
	SttOnMoveService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ���õ�������ת��ΪjsonVO��ʽ����Ӧ���
	auto jvo = SttOnMovePageJsonVO::Wrapper::createShared();
	// �����ɹ���Ϣ
	jvo->success(result);
	// ������Ӧ
	return jvo;
}

// ����id��ѯ������������
SttOnMoveDetailJsonVO::Wrapper SttOnMoveController::execQueryOne(const String& id)
{
	//���巵�����ݶ���
	auto jvo = SttOnMoveDetailJsonVO::createShared();
	// ����һ��Service
	SttOnMoveService service;
	// ִ�����ݲ�ѯservice�㷵��DTO����
	auto res = service.getById(id);
	// ������Ϣ
	if (res)
		jvo->success(res);
	else
		jvo->fail(res);
	return jvo;
}

// �����̵����񣬷���id
//StringJsonVO::Wrapper SttOnMoveController::execInsertSttTask(const String& id, const PayloadDTO& payload)
//{
//	//���巵�����ݶ���
//	auto jvo = StringJsonVO::createShared();
//	// ����һ��Service
//	SttOnMoveService sttOnMoveService;
//	auto sttOnMoveListDTO = sttOnMoveService.getById(id);
//	if (!sttOnMoveListDTO)
//	{
//		// ��ѯ����������ʧ��
//		jvo->fail(id);
//	}
//
//	SttTaskService sttTaskService;
//	auto res = sttTaskService.insert(sttOnMoveListDTO,payload);
//
//	jvo->success(id);
//
//	return jvo;
//}

SttOnMoveInsertTaskJsonVO::Wrapper SttOnMoveController::execInsertSttTaskMulti(const SttOnMoveInsertTaskDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// �����������ص�id����DTO
	auto returnDto = SttOnMoveInsertTaskDTO::createShared();
	returnDto->ids = Vector<String>::createShared();
	// ���巵�����ݶ���
	auto jvo = SttOnMoveInsertTaskJsonVO::createShared();

	// ����У��
	if (!dto->ids || dto->ids->empty())
	{
		jvo->init(nullptr,RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��servie
	SttTaskService sttTaskservice;
	SttOnMoveService sttOnMoveService;
	// ɾ������
	for (int i = 0 ; i < dto->ids->size();i++)
	{
		// ��ȡ�������б�����
		auto sttOnMoveListDTO = sttOnMoveService.getById(dto->ids->at(i));

		// �����ݲ����̵������б�
		auto res = sttTaskservice.insert(sttOnMoveListDTO,payload);

		returnDto->ids->push_back(dto->ids->at(i));
	}
	jvo->success(returnDto);
	return jvo;
}