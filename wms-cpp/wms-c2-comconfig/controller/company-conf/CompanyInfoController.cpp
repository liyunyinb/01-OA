#include "stdafx.h"
#include "CompanyController.h"
#include "service/company-conf/CompanyInfoService.h"


CompanyPageJsonVO::Wrapper CompanyController::execQueryALL(const CompanyInfoQuery::Wrapper& query)
{
	// ����һ��Service
	CompanyInfooService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CompanyPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


CompanyInfoVOJsonVO::Wrapper CompanyController::execQueryDETAIL(const Int64& id)
{
	// ���巵�����ݶ���
	auto jvo = CompanyInfoVOJsonVO::createShared();
	// ����һ��Service
	CompanyInfooService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	// ��Ӧ���
	return jvo;
}

