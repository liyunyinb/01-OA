/*
 @Author: nanbowan
*/
#include"stdafx.h"
#include"LibraryController.h"
#include "../../service/library/LibraryService.h"

Uint64JsonVO::Wrapper LibraryController::execModifyLibrary(const ModifyLibraryDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	string stdId = dto->id->c_str();
	uint64_t idValue = std::stoull(stdId);
	if (!dto->id || idValue < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LibraryService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(idValue);
	}
	else
	{
		jvo->fail(idValue);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper LibraryController::execDeleteLibrary(const oatpp::String& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��

	if ( id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LibraryService service;
	string stdId = id->c_str();
	uint64_t idValue = std::stoull(stdId);
	if (service.removeData(id)){
		jvo->success(idValue);
	}
	else
	{
		jvo->fail(idValue);
	}
	// ��Ӧ���
	return jvo;
}


