#include "stdafx.h"
#include "PlcController.h"
#include "../../service/plc-file/PlcService.h"
#include "../ApiDeclarativeServicesHelper.h"

PlcPageJsonVO::Wrapper PlcController::execQueryAll(const PlcFileQuery::Wrapper& query)
{
	PlcService service;
	auto result = service.listAll(query);
	auto jvo = PlcPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
PlcJsonVO::Wrapper PlcController::execQueryById(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = PlcJsonVO::createShared();
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	//if (id.getValue({}) <= 0)
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// ����һ��Service
	PlcService service;
	// ִ����������
	auto res = service.getById(id);
	jvo->success(res);

	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper PlcController::execAddPlc(const PlcAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	/*if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// ��ЧֵУ��
	/*if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// ����һ��Service
	PlcService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload.getUsername(), payload.getRealname(), payload.getOrgcode(), payload.getCompanycode());
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
Uint64JsonVO::Wrapper PlcController::execModifyPlc(const PlcdetailDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����һ��Service
	PlcService service;
	// ִ�������޸�
	uint64_t id = service.updateData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	return jvo;
}
Uint64JsonVO::Wrapper PlcController::execRemovePlc(const String& id)
{
	auto jvo = Uint64JsonVO::createShared();
	PlcService service;
	uint64_t Idd = service.removeData(id);
	if (Idd > 0) {
		jvo->success(UInt64(Idd));
	}
	else
	{
		jvo->fail(UInt64(Idd));
	}
	return jvo;
}

StringJsonVO::Wrapper PlcController::execUploadFiles(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);
	// 2 ���ö�ȡ��
	//API_MULTIPART_CONFIG_FILE(reader, "file0", "public/static/file/test0.png");
	//API_MULTIPART_CONFIG_FILE(reader, "file1", "public/static/file/test1.png");
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	// 4 ��������
	/* TODO: ���������ݾ����߼�����Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file0", file0);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file1", file1);
	/* �����ļ��Ƿ��ȡ�� */
	OATPP_ASSERT_HTTP(partfile0, Status::CODE_400, "file0 is null");
	OATPP_ASSERT_HTTP(partfile1, Status::CODE_400, "file1 is null");
	/* ��ӡ�ļ�����·�� */
	OATPP_LOGD("Multipart", "file0 save path: %s", partfile0->getPayload()->getLocation()->c_str());
	OATPP_LOGD("Multipart", "file1 save path: %s", partfile1->getPayload()->getLocation()->c_str());
	// 5 ��Ӧ���
	/* TODO: ������Ӧʲô�������Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PlcController::execDownloadFile(const String& filename)
{
	// �����ļ�ȫ·��
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));
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
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// Ӱ��ɹ����
	return response;
}