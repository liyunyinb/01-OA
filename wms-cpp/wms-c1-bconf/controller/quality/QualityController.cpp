/*
 @Author: S4turday
 @Date: 2025��3��8��16:15:26

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
#include "QualityController.h"
#include "../../service/quality/QualityService.h"
#include "../ApiDeclarativeServicesHelper.h"




Uint64JsonVO::Wrapper QualityController::execUpdate(const QualityListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id || !dto->qm_qa_name || !dto->qm_qa_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	QualityService service;
	// ִ�������޸�
	uint64_t id = service.updateData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper QualityController::execAdd(const QualityAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->qm_qa_name || !dto->qm_qa_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��

	// ����һ��Service
	QualityService service;
	// ִ����������
	uint64_t id = service.InsertData(dto, payload);
	// ִ�������޸�
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

QualityPageJsonVO::Wrapper QualityController::execquery(const QualityQuery::Wrapper& query)
{
	// ����һ��Service
	QualityService service;
	// ��ѯ����
	auto result = service.getData(query);
	// ��Ӧ���
	auto jvo = QualityPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

QualityJsonVO::Wrapper QualityController::execQueryByCode(const String& code)
{
	// ���巵�����ݶ���
	auto jvo = QualityJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (code == "")
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��


	// ����һ��Service
	QualityService service;
	// ִ�����ݲ�ѯ
	auto res = service.getByCode(code);
	jvo->success(res);

	//��Ӧ���
	return jvo;
}

QualityJsonVO::Wrapper QualityController::execQueryByName(const String& name)
{
	// ���巵�����ݶ���
	auto jvo = QualityJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (name == "")
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��


	// ����һ��Service
	QualityService service;
	// ִ�����ݲ�ѯ
	auto res = service.getByName(name);
	jvo->success(res);

	//��Ӧ���
	return jvo;
}



