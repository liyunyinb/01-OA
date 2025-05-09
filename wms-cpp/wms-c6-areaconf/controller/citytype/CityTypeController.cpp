#include "stdafx.h"
#include "CityTypeController.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "service/citytype/CityTypeService.h"
#ifdef _WIN32
#include <direct.h>  // Windows �� _mkdir
#define mkdir(path, mode) _mkdir(path)  // ���� Windows
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

StringJsonVO::Wrapper CityTypeController::execModifyCityTypeCode(const CityTypeDTO::Wrapper& dto, const PayloadDTO& payload) {
	CityTypeService service;
	auto jvo = StringJsonVO::createShared();
	if (service.Udp(dto, payload))
	{
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail("-1");
	}
    return jvo;
}

CityTypeNameListJsonVO::Wrapper CityTypeController::execGetCityTypeNamesList() {
	CityTypeService service;
	auto ans = service.nameList();
	auto jvo = CityTypeNameListJsonVO::createShared();
	jvo->success(ans);
	return jvo;
}

CityTypePageJsonVO::Wrapper CityTypeController::execGetCityTypeList(const CityTypeQuery::Wrapper& query) {
	CityTypeService service;
	auto ans = service.listAll(query);
	auto jvo = CityTypePageJsonVO::createShared();
	jvo->success(ans);
    return jvo;
}

StringJsonVO::Wrapper CityTypeController::execCreateCityType(const CitytypeBaseDTO::Wrapper& dto, const PayloadDTO& payload) {
	CityTypeService service;
	auto jvo = StringJsonVO::createShared();
	std::string id = service.Add(dto, payload);
	if (id != "")
	{
		jvo->success(id);
	}
	else
	{
		jvo->fail("-1");
	}
    return jvo;
}

StringJsonVO::Wrapper CityTypeController::execCitytypeDel(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!id || id->empty())
	{
		jvo->init("-1", RS_PARAMS_INVALID);  
		return jvo;
	}
	// ����һ��Service
	CityTypeService service;
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

StringJsonVO::Wrapper CityTypeController::execCitytypeUpload(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		// �����ļ�ȫ·��
		std::string fullPath = "./file/citytype.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<string>> vec = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("citytype.type"));
		CityTypeService service;
		service.import(vec, payload);
	}
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CityTypeController::execCitytypeDownload()
{
	CityTypeService service;
	auto vec = service.listAll();

	// �����ļ�ȫ·��
	std::string fullPath = "./file/citytype.xlsx";

	ExcelComponent excel;
	excel.loadFile(fullPath);
	excel.writeVectorToFile(fullPath, ZH_WORDS_GETTER("citytype.type"), vec);

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
	response->putHeader("Content-Disposition", "attachment; filename=citytype.xlsx");

	// Ӱ��ɹ����
	return response;
}