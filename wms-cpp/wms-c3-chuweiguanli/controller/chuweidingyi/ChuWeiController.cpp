#include "stdafx.h"
#include "ChuWeiController.h"
#include "../../service/chuweidingyi/ChuWeiService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include <oatpp/core/Types.hpp> 

//��ҳ��ѯ
ChuWeiPageJsonVO::Wrapper ChuWeiController::execQueryChuwei(const ChuWeiQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ChuWeiService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ChuWeiPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//�޸Ĵ�λ
StringJsonVO::Wrapper ChuWeiController::execModifyChuwei(const ChuWeiDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ����У�飺��� id �Ƿ�Ϊ��
	if (!dto->id) {
		jvo->init("", RS_PARAMS_INVALID); // ����ʱ���ؿ��ַ����ʹ�����
		return jvo;
	}
		ChuWeiService service;
		if (service.updateData(dto)) {
			// �ɹ���Ӧ��Я��ID��
			jvo->success(dto->id);
		}
		else {
			// ʧ����Ӧ,���ش�����ʾ��Ϣ
			jvo->fail(String{ "fail" });
		}
	return jvo;
}

//ͨ������idɾ����λ
StringJsonVO::Wrapper ChuWeiController::execRemoveChuwei(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!id || id->empty())
	{
		jvo->init("", RS_PARAMS_INVALID); // ����ʱ���ؿ��ַ����ʹ�����
		return jvo;
	}
	// ����һ��Service
	ChuWeiService service;
	// ִ��ɾ������
	if (service.removeData(id)) {
		jvo->success(id); // �ɹ�ʱ���� id
	}
	else {
		jvo->fail(String{ "fail" }); // ʧ��ʱ���� id �ʹ�����
	}
	// ��Ӧ���
	return jvo;
}

//����ɾ����λ
StringJsonVO::Wrapper ChuWeiController::execBatchRemoveChuwei(const BatchDeleteDTO::Wrapper& dto) {
	auto jvo = StringJsonVO::createShared();
	if (!dto || !dto->ids || dto->ids->empty()) {
		jvo->init("", RS_PARAMS_INVALID);
		return jvo;
	}

	ChuWeiService service;
	std::vector<String> successIds;

	// ��ʽ����������
	auto& idList = dto->ids;
	for (auto it = idList->begin(); it != idList->end(); ++it) {
		const auto& id = *it;
		if (service.removeData(id)) {
			successIds.push_back(id);
		}
	}

	// ��Ӧ�߼�
	if (successIds.empty()) {
		jvo->fail(ZH_WORDS_GETTER("Chuwei.delete.fail"));
	}
	else if (successIds.size() == idList->size()) {
		jvo->success(ZH_WORDS_GETTER("Chuwei.delete.success"));
	}
	else {
		jvo->success(ZH_WORDS_GETTER("Chuwei.delete.partly_success"));
	}

	return jvo;
}