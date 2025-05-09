#include "stdafx.h"
#include "CostDetailController.h"
#include "../../service/cost-detail-ahead/CostDetailService.h"

CostDetailListPageJsonVO::Wrapper CostDetialController::execQueryPageAll(const CostDetailQuery::Wrapper& query) {
	
	// ����һ��Service
	CostDetailService service;

	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CostDetailListPageJsonVO::createShared();
	jvo->success(result);

	return jvo;
}


Uint64JsonVO::Wrapper CostDetialController::execAddCost(const CostDetailAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ����һ��Service
	CostDetailService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload);
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


// 3.3 ��ʾ�޸�����
StringJsonVO::Wrapper CostDetialController::execeditCost(const CostDetailEditDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ����һ��Service
	CostDetailService service;
	// ִ�������޸�
	if (service.updateData(dto, payload)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}

// 3.3 ��ʾɾ������
StringJsonVO::Wrapper CostDetialController::execRemoveCost(const String& id) {

	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// �����Լ�飺���ַ�����Ƿ��ַ�
	if (!id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CostDetailService service;
	// ִ������ɾ��
	if (service.removeData(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}


StringJsonVO::Wrapper CostDetialController::execRemoveAllCost(const List<String>& ids) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// �����Լ�飺���ַ�����Ƿ��ַ�
	if (!ids) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CostDetailService service;
	int count = 0;
	// ִ������ɾ��
	for (int i = 0; i < ids->size(); i++) {
		if (service.removeData(ids[i])) {
			count++;
		}
		else
		{
			jvo->fail(ids[i]);
			break;
		}
	}
	if(count == ids->size())
		jvo->success("delete batch success");
	// ��Ӧ���
	return jvo;
	/*

	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	if (!ids) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	vector<string> stringIds;
	for (int i=0; i < ids->size(); i++) {
		stringIds.push_back(ids[i]);
	}

	CostDetailService service;
	if (service.removeBatchData(stringIds)) {
		jvo->success("Batch delete success");
	}
	else {
		jvo->fail("Batch delete failed");
	}

	return jvo;
	*/
}