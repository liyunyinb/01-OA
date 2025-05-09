#include "stdafx.h"
#include "../../service/goods/GoodsService.h"
#include "GoodsController.h"

#include "../../../lib-common/include/ExcelComponent.h"
#include <iostream>


#define TEST_EXCEL_FN "./public/excel/1.xlsx"
#define TEST_EXCEL_SN ZH_WORDS_GETTER("excel.sheet.s1")


CombineGoodsJsonVO::Wrapper GetGoodsController::execQueryGoods()
{
	auto resjvo = CombineGoodsJsonVO::createShared();
	GoodsService service;
	// dto->jsonvo
	resjvo->success(service.getData());
	
	return resjvo;
}

CombineGoodsJsonVO::Wrapper GetGoodsController::execById(const Int64& id = -1) 
{
	auto resJvo = CombineGoodsJsonVO::createShared();
	GoodsService service;
	resJvo->success(service.getById(id));
	return resJvo;
}

CombineGoodsJsonVO::Wrapper GetGoodsController::execNoId()
{
	auto resJvo = CombineGoodsJsonVO::createShared();
	GoodsService service;
	resJvo->success(service.getTOP());
	return resJvo;
}

StringJsonVO::Wrapper GetGoodsController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO(reader,"file", -1);

	// 3 ��ȡ����
	request->transferBody(&reader);

	///* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (!file) {
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Not Found File");
		return jvo;
	}
	ExcelComponent excel;
	auto data = excel.readIntoVector(file->data(), file->size(), ZH_WORDS_GETTER("goods.excel.summary"));

	GoodsService service;
	bool res = service.uploadData(data,payload);

	// 5 ��Ӧ���
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

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> GetGoodsController::execDownloadFile(const String& filename)
{
	// �����ļ�ȫ·��
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));

	// ��ȡ�ļ�
	GoodsService service;


	std::vector<std::vector<std::string>> data;
	std::vector<std::vector<std::string>> DB;
	DB = service.getVectorData();
	std::string info1 = ZH_WORDS_GETTER("goods.download.info1");
	std::string info2 = ZH_WORDS_GETTER("goods.download.info2");
	std::string info3 = ZH_WORDS_GETTER("goods.download.info3");
	std::string info4 = ZH_WORDS_GETTER("goods.download.info4");
	std::string info5 = ZH_WORDS_GETTER("goods.download.info5");

	std::vector<std::string> infoVec{ info1,info2,info3,info4,info5 };
	stringstream ss;
	// ����
	data.push_back(infoVec);
	for (int i = 0; i < DB.size(); i++)
	{
		std::vector<std::string> row;
		for (int j = 0; j < 5; j++)
		{
			ss.clear();
			ss << DB[i][j];
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}


	std::string fileName = TEST_EXCEL_FN;
	std::string sheetName = TEST_EXCEL_SN;


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