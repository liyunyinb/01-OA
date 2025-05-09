#include "stdafx.h"
#include "DareaInfoController.h"
#include "service/regioninfo/DareaInfoService.h"
#include "service/regioninfo/RegionInfoService.h"
#include "domain/do/regioninfo/RegionInfoDO.h"
#include <string>
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include <filesystem>
namespace fs = std::filesystem;

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DareaInfoController::execExport()
{
	DareaInfoService service;
	auto vec = service.Export();

	// �����ļ�ȫ·��
	std::string fullPath = "./file/dareainfo.xlsx";

	ExcelComponent excel;
	excel.loadFile(fullPath);
	excel.writeVectorToFile(fullPath, ZH_WORDS_GETTER("DareaInfo.info"), vec);

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
	response->putHeader("Content-Disposition", "attachment; filename=dareainfo.xlsx");

	// Ӱ��ɹ����
	return response;
}

StringJsonVO::Wrapper DareaInfoController::execImport(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		// �����ļ�ȫ·��
		std::string fullPath = "./file/dareainfo.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<string>> vec = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("DareaInfo.info"));
		DareaInfoService service;
		service.Import(vec, payload);
	}

	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

DareaInfoPageJsonVO::Wrapper DareaInfoController::executeQueryAll(const DareaInfoQuery::Wrapper& query)
{
	DareaInfoService service;
	auto result = service.listAll(query);
	auto jvo = DareaInfoPageJsonVO::createShared();

	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper DareaInfoController::execAddDareaInfo(const DareaInfoAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	DareaInfoService service;
	std::string id = service.AddOne(dto, payload);
	if (id != "")
	{
		jvo->init(String(id), RS_SUCCESS);
		return jvo;
	}
	else {
		jvo->init(String("-1"), RS_FAIL);
		return jvo;
	}
}

StringJsonVO::Wrapper DareaInfoController::execModifyDareaInfo(const DareaInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	DareaInfoService service;
	if (service.Update(dto, payload))
	{
		jvo->success("ok");
	}
	else {
		jvo->fail("no");
	}
	return jvo;
}

StringJsonVO::Wrapper DareaInfoController::execRemoveDareaInfo(const String& id)
{
	auto jvo = StringJsonVO::createShared();
	DareaInfoService service;
	std::cout << "remove dareainfo: id = " << id.getValue("") << std::endl;
	if (service.Delete(id.getValue("")))
	{
		jvo->success(id);
	}
	else {
		jvo->fail("-1");
	}
	return jvo;
}

RegionNameJsonVO::Wrapper DareaInfoController::execQueryName()
{
	// ���巵�����ݶ���
	auto jvo = RegionNameJsonVO::createShared();

	// ����һ��Service
	RegionInfoService service;
	// ִ����������
	auto res = service.getByName();
	jvo->success(res);

	//��Ӧ���
	return jvo;
}