#include "stdafx.h"
#include "controller/baworkst/BaWorkStController.h"
#include "../../service/baworkst/BaWorkStService.h"
#include "../ApiDeclarativeServicesHelper.h"


BaWorkStPageJsonVO::Wrapper BaWorkStController::execQueryBaWorkSt(const BaWorkStQuery::Wrapper& query, const PayloadDTO& payload) {
	BaWorkStService service;
	auto result = service.listAll(query);
	auto jvo = BaWorkStPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper BaWorkStController::execAddBaWorkSt(const BaWorkStAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	//�ǿ�У��
	if ( !dto->work_sta_code || !dto->work_sta_name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}


	// ����һ��Service
	BaWorkStService service;
	// ִ����������
	std::string id = service.saveData(dto,payload);
	if (id.size() !=  0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	//��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper BaWorkStController::execModifyBaWorkSt(const BaWorkStChangeDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if ( !dto->work_sta_code || !dto->work_sta_name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	BaWorkStService service;
	// ִ�������޸�
	std::string id = service.updateData(dto, payload);
	if (id.size() != 0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(-1));
	}

	// ��Ӧ���
	return jvo;
}