/*
 Copyright Zero One Star. All rights reserved.

 @Author: JOHAN LIN
 @Date: 2025/02/22 19:11:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#define _IP_ "192.168.110.141"

#include "stdafx.h"
#include "CostAttributeController.h"
#include "./service/cost-attribute/CostAttributeService.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"
#include "../ApiDeclarativeServicesHelper.h"
#include <iostream>
#include <string>
#include "SimpleDateTimeFormat.h"
/*
	ɾ���ͻ��Ʒ�����
*/
StringJsonVO::Wrapper CostAttributeController::execDeleteCostAttribute(const List<String>& ids) {
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ����У��
	if (!ids) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service    
	// ɾ������
	CostAttributeService service;
	int count = 0;
	for (int i = 0; i < ids->size(); i++) {
		if (service.DeleteCostAttribute(ids[i])) {
			count++;
		}
		else
		{
			jvo->fail(ids[i]);
			break;
		}
	}
	if (count == ids->size()) {
		jvo->success("delete success");
	}


	// ��Ӧ���
	return jvo;

}

/*
	����ͻ��Ʒ�����
*/
//StringJsonVO::Wrapper CostAttributeController::execImportCostAttribute(shared_ptr<IncomingRequest> request) {
//	// 1 ��ʼ��
//	API_MULTIPART_INIT(container, reader);
//
//	// 2 ���ö�ȡ��
//	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
//
//	// 3 ��ȡ����
//	request->transferBody(&reader);	// 1 ��ʼ��
//	/*OATPP_LOGD("Multipart", "parts_count=%d", container->count());
//	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "pronut_code", pronut_code);
//	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "pronut_name", pronut_name);*/
//	// 4 ��������
//	/* ��ȡ�ļ����� */
//	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
//	if (file)
//	{
//		/* ��ӡ�ļ����� */
//		string filename = partfile->getFilename().getValue("");
//		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
//		// ���Խ��ļ����浽������
//		string fullPath = "public/static/file/" + filename;
//		file.saveToFile(fullPath.c_str());
//		/* �����ϴ���FastDFS */
//		string url = _IP_;
//		FastDfsClient dfs(url);
//		// ��ȡ�ļ���׺��
//		string suffix = "";
//		size_t pos = filename.rfind(".");
//		if (pos != string::npos)
//		{
//			suffix = filename.substr(pos + 1);
//		}
//
//		// �ϴ��ļ�
//		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
//		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
//
//		// ��ʼ��xInt
//		xlnt::workbook wb;
//		std::string fullp = string("public/static/file/");
//		dfs.downloadFile(downloadUrl, &fullp);
//		wb.load(fullPath);
//		xlnt::worksheet ws = wb.active_sheet();
//		int j = 0;
//
//		// ��ʼ��һ��vector�����洢�ļ���dto����
//		vector<CostAttributeDTO::Wrapper> dataDTOs;
//		for (const auto& row : ws.rows()) {
//			if (j == 0)
//			{
//				j++;
//				continue;
//			}
//			vector<string> rowData;
//			for (const auto& cell : row)
//			{
//				rowData.push_back(cell.to_string());
//			}
//			auto dto = CostAttributeDTO::createShared();
//			dto->addExcel(rowData);
//			dataDTOs.push_back(dto);
//		}
//		// �����ݴ���service�������ݿ�
//		CostAttributeService service;
//		CostAttributesDTO::Wrapper id = service.ImportCostAttribute(dataDTOs);
//	}
//	// 5 ��Ӧ���
//	auto jvo = StringJsonVO::createShared();
//	jvo->success("OK");
//	return jvo;
//
//}
//
/*
	����ͻ��Ʒ�����
*/
StringJsonVO::Wrapper CostAttributeController::execImportCostAttribute(shared_ptr<IncomingRequest> request) {
	// 1 ��ʼ�������Ͷ�ȡ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);//���ϴ��������,���Ǻ���ֻ����"file"����

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 ��������
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* ���Խ��ļ����浽�������� */
		/*string fullpath = "public/static/file/" + filename;
		file.saveToFile(fullpath.c_str());*/

		if (false)//�Ƿ��ϴ���FastDFS,��ѡ
		{
			/* �����ϴ���FastDFS */
			ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
			// ��ȡ�ļ���׺��
			string suffix = "";
			size_t pos = filename.rfind(".");
			if (pos != string::npos)
			{
				suffix = filename.substr(pos + 1);
			}
			// �ϴ��ļ�
			string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
			downloadUrl = urlPrefix + downloadUrl;
			OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		}
	}
	// 5 ��Ӧ���:�ļ��ϴ���String��file,Ҫ��file�������������ݿ�
	auto jvo = StringJsonVO::createShared();
	ExcelComponent excel;
	const char* data = file->data();
	vector<vector<string>> matrix = excel.readIntoVector(data, file->size(), ZH_WORDS_GETTER("excel.name.import"));
	//��ÿ��������װ��DTO�����service�����
	int lines = matrix.size();
	for (int i = 1; i < lines; ++i)
	{
		auto dto = ImportCostAttributeDTO::createShared();
		dto->addExcel(matrix[i][0], matrix[i][1]);
		//�Ӹ��ض�ȡ��Ϣ
		CostAttributeService service;
		uint64_t id = service.ImportCostAttribute(dto);
		if (id <= 0)
		{
			jvo->fail("fail");
			return jvo;
		}
	}
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CostAttributeController::execExportCostAttribute()
{
	ExportCostAttributeQuery::Wrapper query;
	CostAttributeService service;
	list<CostAttributeDO> result = service.ExportCostAttribute();
	std::vector<std::vector<std::string>> data;
	stringstream ss;
	std::vector<std::string> r1;
	ss.clear();
	std::string info = ZH_WORDS_GETTER("cost.attribute.code");
	ss << info;
	r1.push_back(ss.str());
	ss.str("");
	ss.clear();
	info = ZH_WORDS_GETTER("cost.attribute.name");
	ss << info;
	r1.push_back(ss.str());
	ss.str("");
	data.push_back(r1);
	for (auto r : result)
	{
		std::vector<std::string> row;
		string n = r.getKeHuShuXingCode();
		string m = r.getKeHuShuXingName();
		ss.clear();
		ss << n;
		row.push_back(ss.str());
		ss.str("");
		ss.clear();
		ss << m;
		row.push_back(ss.str());
		ss.str("");
		data.push_back(row);
	}
	std::string fileName = "./public/excel/1.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.name.export");


	// ��Excel���ݵ�����String��
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(sheetName, data);
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
	response->putHeader("Content-Disposition", "attachment; filename=" + fileName);

	// Ӱ��ɹ����
	return response;
}

///*
//	�����ͻ��Ʒ�����
//*/
//shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CostAttributeController::execExportCostAttribute() {
//	// ����һ��service
//	// ��������
//	CostAttributeService service;
//	auto res = CostPageDTO::createShared();
//	res = service.ExportCostAttribute();
//
//	// �жϷ��ط�������Ƿ�Ϊ��
//	if (res->pages){
//		return createResponse(Status::CODE_500, "Failed to retrieve data");
//	}
//	// ��ʼ����ά���� �洢���ݿͻ��������� ��������excel�ļ�
//	std::vector<std::vector<std::string>> data;
//	std::vector<std::string> header;
//	// ������Ӧͷ
//	header.push_back(ZH_WORDS_GETTER("excel.code"));
//	header.push_back(ZH_WORDS_GETTER("excel.Name"));
//	// ������Ӧͷ
//	data.push_back(header);
//	// �������ݵ���ά����
//	for (auto it : *res->rows) {
//		std::vector<std::string> row;
//		row.push_back(it->id);
//		row.push_back(it->create_name);
//		row.push_back(it->create_by);
//		row.push_back(it->create_date);
//		row.push_back(it->update_name);
//		row.push_back(it->update_by);
//		row.push_back(it->update_date);
//		row.push_back(it->sys_org_code);
//		row.push_back(it->sys_company_code);
//		row.push_back(it->kehushuxing_code);
//		row.push_back(it->kehushuxing_name);
//		data.push_back(row);
//	}
//
//	// excel�ļ���
//	std::string sheetName = ZH_WORDS_GETTER("excel.name.export");
//	// ����excel�ļ��������
//	ExcelComponent excel;
//	// ����excel buffer 
//	auto buff = excel.writeVectorToBuff(sheetName, data);
//	if (buff.empty()) {
//		return createResponse(Status::CODE_500, "Failed to generate Excel file");
//	}
//
//	auto fstring = String(reinterpret_cast<const char*>(buff.data()), buff.size());
//	const String& filename = "ExportedCostAttribute";
//	auto response = createResponse(Status::CODE_200, fstring);
//	response->putHeader("Content-Disposition", "attachment; filename=" + (filename ? filename : "default.xlsx"));
//	response->putHeader("Content-Type", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
//
//	return response;
//}

