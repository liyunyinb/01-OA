#include "stdafx.h"
#include "AreaInfoController.h"
#include "service/areainfo/AreaInfoService.h"
#include "ExcelComponent.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> AreaInfoController::execDownloadExcel()
{

	AreaInfoService service;
	auto vec = service.selectAll();

	// �����ļ�ȫ·��
	std::string fullPath = "./file/areainfo.xlsx";

	ExcelComponent excel;
	excel.loadFile(fullPath);
	excel.writeVectorToFile(fullPath, ZH_WORDS_GETTER("AreaInfo.info"), vec);

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
	response->putHeader("Content-Disposition", "attachment; filename=areainfo.xlsx");
	
	// Ӱ��ɹ����
	return response;
}

StringJsonVO::Wrapper AreaInfoController::execUploadExcel(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		// �����ļ�ȫ·��
		std::string fullPath = "./file/areainfo.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<string>> vec = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("AreaInfo.info"));
		AreaInfoService service;
		service.upload(vec, payload);
	}
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

StringJsonVO::Wrapper AreaInfoController::execModify(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id)
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	AreaInfoService service;
	if (service.modifyData(dto, payload))
	{
		jvo->success(dto->id);
	}
	else {
		jvo->fail(dto->id);
	}
	return jvo;
}

StringJsonVO::Wrapper AreaInfoController::execDelete(const String& dto)
{
	auto jvo = StringJsonVO::createShared();
	AreaInfoService service;
	if (service.deleteData(dto->data()))
	{
		jvo->success(dto);
	}
	else
	{
		jvo->fail(dto);
	}
	return jvo;
}

AreaNameTreeJsonVO::Wrapper AreaInfoController::execNameTreeAreaInfo()
{
	auto jvo = AreaNameTreeJsonVO::createShared();

	AreaInfoService service;
	for (auto node : service.nameTree())
	{
		jvo->data->push_back(AreaNameTreeDTO::Wrapper(dynamic_pointer_cast<AreaNameTreeDTO>(node), AreaNameTreeDTO::Wrapper::Class::getType()));
	}

	return jvo;
}

AreaInfoPageJsonVO::Wrapper AreaInfoController::execAreaInfoList(const AreaInfoQuery::Wrapper& query)
{
	auto jvo = AreaInfoPageJsonVO::createShared();
	AreaInfoService service;
	auto list = service.List(query);
	jvo->success(list);
	return jvo;
}

StringJsonVO::Wrapper AreaInfoController::execAddAreaInfo(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	AreaInfoService service;
	if (service.addData(dto, payload))
	{
		jvo->success("OK");
	}
	else {
		jvo->fail("NO");
	}
	return jvo;
}