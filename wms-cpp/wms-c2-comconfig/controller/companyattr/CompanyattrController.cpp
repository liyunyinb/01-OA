/*
* Author: laughter
*/
#include "stdafx.h"
#include "CompanyattrController.h"
#include "../../service/companyattr/CompanyattrService.h"

CompanyattrPageJsonVO::Wrapper CompanyattrController::execQueryAll(const CompanyattrQuery::Wrapper& query, const PayloadDTO& payload) {
	// ����һ��Service
	CompanyattrService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CompanyattrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
Uint64JsonVO::Wrapper CompanyattrController::execModify(const CompanyattrIdListDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id||!dto->com_type_code || !dto->com_type_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CompanyattrService service;
	// ִ�������޸�
	if (service.updateData(dto,payload)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(-1);
	}
	// ��Ӧ���
	return jvo;
}
Uint64JsonVO::Wrapper CompanyattrController::execAdd(const CompanyattrListDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->com_type_code || !dto->com_type_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// ��ЧֵУ��
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	// ����һ��Service
	CompanyattrService service;
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