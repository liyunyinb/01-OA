#include "stdafx.h"
#include "ComdegController.h"
#include "service/ba-com-deg/ComdegService.h"

ComdegPageJsonVO::Wrapper ComdegController::execcomdegAll(const ComdegQuery::Wrapper& query)
{
	// ����һ��Service
	ComdegService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ComdegPageJsonVO::createShared();
	jvo->success(result);
	return jvo;   
}

Uint64JsonVO::Wrapper ComdegController::execAddComdeg(const ComdegAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
		auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->degcode || !dto->degname || !dto->degdel)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->degcode->empty() || dto->degname->empty() || dto->degdel->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ComdegService service;
	// ִ����������
	uint64_t id = service.saveData(dto,payload);
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
