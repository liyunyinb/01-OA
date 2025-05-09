// wangye 2025/2/24
#include "stdafx.h"
#include <iostream>
#include "WorkStateController.h"
#include "../../service/workstate/WorkStateService.h"
#include "../ApiDeclarativeServicesHelper.h"

#define WORKSTATE_EXCEL_FN "./public/excel/ba-work-state.xlsx"
#define WORKSTATE_EXCEL_SN ZH_WORDS_GETTER("excel.sheet.s1")

// ʵ���ϴ�һ������״̬�ļ��ӿ�ִ�к���
StringJsonVO::Wrapper WorkStateController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// ��ʼ����ȡ��
	API_MULTIPART_INIT(container, reader);
	// ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	// ��ȡ����
	request->transferBody(&reader);
	// ��������
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	// �ǿ�У��
	if (!file)
	{
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Not Found File");
		return jvo;
	}
	
	ExcelComponent excel;
	auto data = excel.readIntoVector(file->data(), file->size(), ZH_WORDS_GETTER("wsf.excel.summary"));

	WorkStateService service;
	bool res = service.uploadData(data,payload);
	auto jvo = StringJsonVO::createShared();
	if (res) {
		jvo->success("OK");
		return jvo;
	}
	else {
		jvo->fail("error");
		return jvo;
	}
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> WorkStateController::execDownloadExcel(const String& filename)
{
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));
	WorkStateService service;

	std::vector<std::vector<std::string>> data;
	std::vector<std::vector<std::string>> DB;
	DB = service.getVectorData();
	std::string info1 = ZH_WORDS_GETTER("goods.download.info1");
	std::string info2 = ZH_WORDS_GETTER("goods.download.info2");

	std::vector<std::string> infoVec{ info1,info2};
	stringstream ss;
	// ����
	data.push_back(infoVec);
	for (int i = 0; i < DB.size(); i++)
	{
		std::vector<std::string> row;
		for (int j = 0; j < 2; j++)
		{
			ss.clear();
			ss << DB[i][j];
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}


	std::string fileName = WORKSTATE_EXCEL_FN;
	std::string sheetName = WORKSTATE_EXCEL_SN;


	// ��Excel���ݵ�����String��
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("file.field.filename"), data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());


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






// ɾ������״̬�ӿ�ִ�к���
Uint64JsonVO::Wrapper WorkStateController::execRemoveWorkState(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (atoi(id->c_str()) <= 0) //����������stringת����int���ͣ��ú���в���У��
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	WorkStateService service;
	auto ans = service.removeData(string(id->c_str()));
	// ִ������ɾ��
	if (ans) {
		jvo->success(ans);
	}
	else
	{
		jvo->fail(ans);
	}
	// ��Ӧ���
	return jvo;
}