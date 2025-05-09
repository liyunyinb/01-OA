

#include "stdafx.h"
#include "CustormerBillController.h"
#include <iostream>
#include "service/customer-bill/CustomerBillService.h"


//�ͻ��˵���ѯ
CustomerBillPageJsonVO::Wrapper CustormerBillController::execQuerySample(const CustomerBillQuery::Wrapper& query, const PayloadDTO& payload)
{

	// ���巵�����ݶ���
	auto jvo = CustomerBillPageJsonVO::createShared();

	// ��ЧֵУ��
	if (query->pageIndex<0 || query->pageSize<0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CustomerBillPageService service;
	// ��ѯ����
	auto result = service.listAll(query);


	jvo->success(result);
	return jvo;
}







//����δ���˵�
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CustormerBillController::execExportFile(const UnsettledQuery::Wrapper& file)
{



	// ����һ��Service
	ExportService service;
	String fstring = service.getById(file->customercode);


	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + file->customercode.getValue("")+".xlsx");

	// Ӱ��ɹ����
	return response;
}









//�����ڼ��˵�
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CustormerBillController::execperiodFile(const PeriodQuery::Wrapper& file)
{



	// ����һ��Service
	periodService service;
	String fstring = service.getBydate(file);



	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + file->customercode.getValue("") + ".xlsx");

	// Ӱ��ɹ����
	return response;
}



