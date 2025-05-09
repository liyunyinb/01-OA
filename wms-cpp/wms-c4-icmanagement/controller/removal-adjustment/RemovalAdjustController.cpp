#include "stdafx.h"
#include "RemovalAdjustController.h"
//#include "../../service/sample/SampleService.h"
#include "../../service/removal-adjustment/RemovalAdjustService.h"
#include "../ApiDeclarativeServicesHelper.h"


RemovalPageJsonVO::Wrapper RemovalController::execQueryRemoval(const RemovalQuery::Wrapper& query, const PayloadDTO& payload)
{
	//��ҳ��ѯ
	// ����һ��Service
	RemovalService service;
	// ʵ�ַ�ҳ��ѯ���ݵķ���
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RemovalPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return {};
}
RemovalDetailPageJsonVO::Wrapper RemovalController::execQueryRemovaldetail(const RemovalQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = RemovalDetailPageJsonVO::createShared();
	//jvo��һ��RemovalDetailJsonVO
	RemovalService service;
	auto result = service.getdetail(query);
	//�����result��һ��std::list<RemovalDetailDTO::Wrapper> ����
	jvo->success(result);

	//��Ӧ���
	return jvo;


	//return {};
}
StringJsonVO::Wrapper RemovalController::execModifyRemoval(const RemovalListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	
	// ����һ��Service
	RemovalService service;
	// ִ�������޸�
	
	String resultfail = String("fail");
	String resultsuccess = String("success");
	if (service.updateData(dto)) {
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}
	
}