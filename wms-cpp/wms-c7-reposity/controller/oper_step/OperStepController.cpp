/*
/*@File Name         : OperStepController.cpp                                                     
/*@Author            : ���̾־ֳ�
/*@Description       :
*/
#include "stdafx.h"
#include "ServerInfo.h"
#include "SimpleDateTimeFormat.h"
#include "OperStepController.h"
#include "ExcelComponent.h"
#include "service/oper_step/OperStepService.h"

StringJsonVO::Wrapper OperStepController::execModifyOperStep(const OperStepDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	OperStepService service;
	if (service.modifyData(dto, payload))
	{
		jvo->success("OK");
	}
	else {
		jvo->fail("NO");
	}
	return jvo;
}

StringJsonVO::Wrapper OperStepController::execDeleteOperStep(const OperStepDeleteDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	OperStepService service;
	if (service.deleteData(dto))
	{
		jvo->success("OK");
	}
	else
	{
		jvo->fail("NO");
	}
	return jvo;
}

StringJsonVO::Wrapper OperStepController::execUploadExcel(const std::shared_ptr<IncomingRequest>& request, const PayloadDTO& payload)
{
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		string fullPath = "./public/static/file/OperStep.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<std::string>> rfile = ExcelComponent::readIntoVector(fullPath, "OperStep");
		OperStepService service;
		service.importData(rfile, payload);
		std::vector<std::vector<std::string>> vec;
		vec = service.selectAll();
		ExcelComponent exc;
		exc.writeVectorToFile(fullPath, "OperStep", vec);
	}

	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> OperStepController::execExportExcel()
{
	// �����ļ�ȫ·��
	std::string fullPath = "./public/static/file/OperStep.xlsx";

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=OperStep.xlsx");

	// Ӱ��ɹ����
	return response;
}



