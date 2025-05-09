#include "stdafx.h"
#include "EduCodeController.h"
#include "../../service/EducationService.h"
#include "../ApiDeclarativeServicesHelper.h"

#include <filesystem>  // C++17 ���ļ�ϵͳ��
#include <fstream>     // �ļ�����
#include <string>      // �ַ�������
#include <iostream>    // �����־

#include "Macros.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

StringJsonVO::Wrapper EduCodeController::execDelEducate(const String& code)
{
	auto jvo = StringJsonVO::createShared();
	
	if (!code || code->empty())
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DelRoleService service;
	// ִ������ɾ��

	if (service.removeData(code)) {
		jvo->success(code);
	}
	else
	{
		jvo->fail(code);
	}
	// ��Ӧ���
	return jvo;
}

EduPageJsonVO::Wrapper EduCodeController::execQueryEdu(const EduQuery::Wrapper& query)
{
	EduService service;
	auto result = service.listAll(query);
	auto jvo = EduPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper EduCodeController::execAddEdu(const EduAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// ��ЧֵУ��
	if (dto->educode->empty() || dto->eduname->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	EduService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload);
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

StringJsonVO::Wrapper EduCodeController::execModifyEducode(const EducationalDTO::Wrapper& educationalDTO, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!educationalDTO->code || !educationalDTO->name)
	{
		jvo->fail(" ");
		return jvo;
	}
	// ����һ��Service
	DelRoleService service;
	// ִ�������޸�
	if (service.updateData(educationalDTO, payload)) {
		jvo->success(educationalDTO->code);
	}
	else
	{
		jvo->fail(educationalDTO->code);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper EduCodeController::importEduCode(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// ���ļ��ж�ȡ
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		// �����ļ�ȫ·��
		std::string fullPath = "./file/edu.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<string>> vec = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("education.educode"));
		EduService service;
		service.saveData(vec, payload);
	}

	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;

}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> EduCodeController::execexportEducode()
{
	EduService service;
	auto vec = service.listAll();

	// �����ļ�ȫ·��
	std::string fullPath = "./file/edu.xlsx";

	ExcelComponent excel;
	excel.loadFile(fullPath);
	excel.writeVectorToFile(fullPath, ZH_WORDS_GETTER("education.field.educode"), vec);

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
	response->putHeader("Content-Disposition", "attachment; filename=edu.xlsx");

	// Ӱ��ɹ����
	return response;
}