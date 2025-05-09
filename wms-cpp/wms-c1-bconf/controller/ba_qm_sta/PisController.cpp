#include "stdafx.h"
#include "PisController.h"
#include "../../service/ba_qm_sta/PisService.h"
#include "../ApiDeclarativeServicesHelper.h"

PisPageJsonVO::Wrapper PisController::execQueryPis(const PisQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	PisService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = PisPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper PisController::execAddPis(const PisAddDTO::Wrapper& dto,const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->id || !dto->code || !dto->name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->code->empty() || dto->name->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	PisService service;
	// ִ����������
	std::string id = service.saveData(dto,payload);
	//std::cout << id << std::endl;
	if (id.size() != 0) { // �ɹ��������ݷ���״̬0
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String("no insert success"));
	}
	//��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper PisController::execModifyPis(const PisDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->code || !dto->name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->code->empty() || dto->name->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	PisService service;

	// ִ�������޸�
	if (service.updateData(dto,payload)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(String("update no success"));
	}
	// ��Ӧ���
	return jvo;
}



//PisJsonVO::Wrapper PisController::execQueryByCode(const String& code)
//{
//	// ���巵�����ݶ���
//	auto jvo = PisJsonVO::createShared();
//
//	// ����У��
//	// �ǿ�У��
//	if (code == "")
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	 //��ЧֵУ��
//	if (code.getValue({}) == 0)
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// ����һ��Service
//	PisService service;
//	// ִ����������
//	auto res = service.getByCode(code.getValue({}));
//	jvo->success(res);
//
//	//��Ӧ���
//	return jvo;
//}

//PisJsonVO::Wrapper PisController::execQueryBySta(const String& sta)
//{
//	// ���巵�����ݶ���
//	auto jvo = PisJsonVO::createShared();
//
//	// ����У��
//	// �ǿ�У��
//	if (sta == "")
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	//��ЧֵУ��
//	if (sta.getValue({}) == 0)
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// ����һ��Service
//	PisService service;
//	// ִ����������
//	auto res = service.getByCode(sta.getValue({}));
//	jvo->success(res);
//
//	//��Ӧ���
//	return jvo;
//}