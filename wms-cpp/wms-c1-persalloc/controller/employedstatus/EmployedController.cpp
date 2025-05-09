#include "stdafx.h"
#include "EmployedController.h"
#include "../../service/employedstatus/EmployedService.h"
#include <iostream>

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include <filesystem> 
// ���ֶ�typedef�Ļ���ʶ�𣬲�֪��Ϊʲô
typedef oatpp::web::protocol::http::outgoing::Response OutgoingResponse;
//#include "SimpleDateTimeFormat.h"

Uint64JsonVO::Wrapper EmployedController::execRemoveByCode(const EmployedBatchRemoveDTO::Wrapper& dto_list)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	auto row = dto_list->rows;

	for (auto iter = row->begin(); iter != row->end(); iter++) {
		auto dto = *iter;

		// ����У��
		// �ǿ�У��
		if (!dto->code)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// ��ЧֵУ��
		if (dto->code->empty())
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}

		// ����һ��Service
		EmployedService service;
		// ִ������ɾ��
		auto res = service.removeData(dto);
		if (res) {
			jvo->success(res);
		}
		else {
			jvo->fail(res);
		}
	}
	// ��Ӧ���
	return jvo;
}

std::shared_ptr<OutgoingResponse> EmployedController::execDownloadFile()
{
	string filename = "ba_pos_sta.xlsx";
	EmployedService service;
	string loaclpath = "public/static/";
	bool success = service.exportAllData(loaclpath);

	// �����ļ�ȫ·��
	std::string fullPath = loaclpath + filename;

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring || !success)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);

	// Ӱ��ɹ����
	return response;
}

StringJsonVO::Wrapper EmployedController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	namespace fs = std::filesystem;
	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();

	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ȡ�ļ����� */
	string fullPath = "";
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (!file) {
		jvo->fail("fail");
		return jvo;
	}

	// �ļ�����
	string filename = partfile->getFilename().getValue("");

	// ���ļ����浽����
	fullPath = "public/static/file/" + filename;
	fs::path dir = fs::path("public/static/file/");
	if (!fs::exists(dir)) fs::create_directories(dir);				// �ݹ鴴��Ŀ¼
	file.saveToFile(fullPath.c_str());								// ���浽ָ��Ŀ¼

	ExcelComponent excel;
	xlnt::workbook wb;
	// ��ȡ���й���������
	const std::vector<std::string> sheetNames = wb.sheet_titles(); // �Զ���ȡҳǩ��,����Ҫ���������ļ�
	// auto res = excel.readIntoVector(fullPath, ZH_WORDS_GETTER("excel.sheet.s1"));

	auto res = excel.readIntoVector(fullPath, sheetNames[0]);
	if (res.size() < 1) {
		jvo->fail("fail");
		return jvo;
	}

	EmployedService service;
	bool success = service.importAllData(res, payload);

	if (success)
		jvo->success("success");
	else jvo->fail("fail");
	return jvo;
}
