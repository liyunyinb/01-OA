//#include "stdafx.h"
//#include <iostream>
//
//// FastDFS��Ҫ�����ͷ
//#include "ServerInfo.h"
//#include "NacosClient.h"
//#include "FastDfsClient.h"
//#include "SimpleDateTimeFormat.h"
//#include "CostGoodsController.h"
//#include <ExcelComponent.h>
//
//StringJsonVO::Wrapper CostGoodsController::execwaydelete(const String& code)
//{
//	// ���巵�����ݶ���
//	auto jvo = StringJsonVO::createShared();
//	if (code == "")
//	{
//		jvo->init(String(""), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	CostGoodsService service;
//	// ִ������ɾ��
//	if (service.removeData(code.getValue(""))) {
//		jvo->success(code);
//	}
//	else
//	{
//		jvo->fail(code);
//	}
//	// ��Ӧ���
//	return jvo;
//}
//
//std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CostGoodsController::execDownloadFile(const String& filename)
//{
//	BillingProductCategoryQuery::Wrapper query;
//	CostGoodsService service;
//	list<GoodsClassDO> result = service.listAll();
//	std::vector<std::vector<std::string>> data;
//	stringstream ss;
//	std::vector<std::string> r1;
//	ss.clear();
//	std::string info = ZH_WORDS_GETTER("CostGoodsQuery.way.code");
//	ss << info;
//	r1.push_back(ss.str());
//	ss.str("");
//	ss.clear();
//	info = ZH_WORDS_GETTER("CostGoodsQuery.way.name");
//	ss << info;
//	r1.push_back(ss.str());
//	ss.str("");
//	data.push_back(r1);
//	for (auto r : result)
//	{
//		std::vector<std::string> row;
//		string n = r.getGoodsClassCode();
//		string m = r.getGoodsClassName();
//		ss.clear();
//		ss << n;
//		row.push_back(ss.str());
//		ss.str("");
//		ss.clear();
//		ss << m;
//		row.push_back(ss.str());
//		ss.str("");
//		data.push_back(row);
//	}
//	std::string fileName = "./public/excel/1.xlsx";
//	std::string sheetName = ZH_WORDS_GETTER("CostGoodsQuery.file.sheetname");
//	
//	
//	// ��Excel���ݵ�����String��
//	ExcelComponent excel;
//	auto buff = excel.writeVectorToBuff(sheetName, data);
//	const char* tsData = reinterpret_cast<const char*>(buff.data());
//	auto fstring = String(tsData, buff.size());
//	 
//	 
//	// �ж��Ƿ��ȡ�ɹ�
//	if (!fstring)
//	{
//		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
//		return createResponse(Status::CODE_404, "File Not Found");
//	}
//
//	// ������Ӧͷ
//	auto response = createResponse(Status::CODE_200, fstring);
//
//	// ������Ӧͷ��Ϣ
//	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));
//
//	// Ӱ��ɹ����
//	return response;
//}
//
//StringJsonVO::Wrapper CostGoodsController::execUploadOne(std::shared_ptr<IncomingRequest> request)
//{
//	// 1 ��ʼ�������Ͷ�ȡ��
//	API_MULTIPART_INIT(container, reader);
//
//	// 2 ���ö�ȡ��
//	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);//���ϴ��������,���Ǻ���ֻ����"file"����
//
//	// 3 ��ȡ����
//	request->transferBody(&reader);
//	/* ��ӡ�ϴ��ܲ����� */
//	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
//
//	// 4 ��������
//	/* ��ȡ�ļ����� */
//	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
//	if (file)
//	{
//		/* ��ӡ�ļ����� */
//		string filename = partfile->getFilename().getValue("");
//		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
//		/* ���Խ��ļ����浽�������� */
//		//string fullPath = "public/static/file/" + filename;
//		//file.saveToFile(fullPath.c_str());
//
//		if (false)//�Ƿ��ϴ���FastDFS,��ѡ
//		{
//			/* �����ϴ���FastDFS */
//			ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
//			// ��ȡ�ļ���׺��
//			string suffix = "";
//			size_t pos = filename.rfind(".");
//			if (pos != string::npos)
//			{
//				suffix = filename.substr(pos + 1);
//			}
//			// �ϴ��ļ�
//			string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
//			downloadUrl = urlPrefix + downloadUrl;
//			OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
//		}
//	}
//	// 5 ��Ӧ���:�ļ��ϴ���String��file,Ҫ��file�������������ݿ�
//	auto jvo = StringJsonVO::createShared();
//	ExcelComponent excel;
//	const char* data = file->data();
//	vector<vector<string>> matrix = excel.readIntoVector(data, file->size(), ZH_WORDS_GETTER("CostGoodsQuery.file.sheetname"));
//	//��ÿ��������װ��DTO�����service�����
//	int lines = matrix.size();
//	for (int i = 1; i < lines; ++i)
//	{
//		auto dto = BPCExcelUploadDTO::createShared();
//		dto->addExcel(matrix[i][0], matrix[i][1]);
//		//�Ӹ��ض�ȡ��Ϣ
//		CostGoodsService service;
//		uint64_t id = service.saveData(dto);
//		if (id <= 0)
//		{
//			jvo->fail("fail");
//			return jvo;
//		}
//	}
//	jvo->success("OK");
//	return jvo;
//}