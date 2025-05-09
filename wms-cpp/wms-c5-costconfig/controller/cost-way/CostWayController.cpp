/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2023/05/17 11:37:57

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
#include "stdafx.h"
#include "CostWayController.h"
#include "../../service/cost-way/CostwayService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include <iostream>
#include <string>
#include <filesystem>
#include "ExcelComponent.h"
// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
namespace fs = std::filesystem;

//StringJsonVO::Wrapper DeleteController::execwaydelete(const String& id)
//{
//	// ���巵�����ݶ���
//	auto jvo = StringJsonVO::createShared();
//	if (id =="")
//	{
//		jvo->init(String(""), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	CostwayService service;
//	// ִ������ɾ��
//	if (service.removeDataById(id.getValue(""))) {
//		jvo->success(id);
//	}
//	else
//	{
//		jvo->fail(id);
//	}
//	// ��Ӧ���
//	return jvo;
//}

StringJsonVO::Wrapper DeleteController::execDeleteCostway(const oatpp::List<String>& ids)
{
	auto jvo = StringJsonVO::createShared();
	//����У��
	for (const auto& id : *ids)
	{
		//�����Ƿ��д����ַ���Ϊ��
		if (*id == "")
		{
			jvo->init(String("error: parameter::id cannot be empty!"), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	CostwayService service;
	int success = 1;
	String wrong_ids = "";
	for (const auto& id : *ids)//�ɹ���״̬success,����������һ��id;ʧ����fail,��������ʧ�ܵ�id
	{
		if (service.removeDataById(id))//�ɹ��޸ĸ�id��Ӧ������
		{
			jvo->data = id;//�ڲ�ʵ��Ϊ����jvo->setStatus��jvo->data=id
		}
		else//����
		{
			success = 0;
			wrong_ids = wrong_ids + id + ",";
		}
	}
	if (success == 1)//û�г���
	{
		jvo->success(jvo->data);
	}
	else
	{
		jvo->fail(wrong_ids);
	}
	return jvo;
}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownloadExcelController::execDownloadFile(const String& filename)
{
	DeleteQuery::Wrapper query;
	CostwayService service;
	list<CostwayDO> result = service.listAll();
	std::vector<std::vector<std::string>> data;
	stringstream ss;
	std::vector<std::string> r1;
	ss.clear();
	std::string info = ZH_WORDS_GETTER("pronut_code");
	ss << info;
	r1.push_back(ss.str());
	ss.str("");
	ss.clear();
	info = ZH_WORDS_GETTER("pronut_name");
	cout << info << endl;
	ss << info;
	r1.push_back(ss.str());
	ss.str("");
	data.push_back(r1);
	for(auto r:result)
	{
		std::vector<std::string> row;
		string n = r.getPronut_code();
		string m = r.getPronut_name();
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
	cout << 1 << endl;
	std::string fileName = "./public/excel/1.xlsx";
	std::string sheetName= ZH_WORDS_GETTER("cost-way.excel");
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
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// Ӱ��ɹ����
	return response;
}

StringJsonVO::Wrapper UploadExcelController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 ��ȡ����
	request->transferBody(&reader);	// 1 ��ʼ��
	/*OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "pronut_code", pronut_code);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "pronut_name", pronut_name);*/
	// 4 ��������
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		// ���Խ��ļ����浽������
		string fullPath = "public/static/file/" + filename;
		file.saveToFile(fullPath.c_str());
		cout << fullPath << endl;;
		/* �����ϴ���FastDFS */
	    string urll = "121.43.101.169";
		cout << 1 << endl;
		FastDfsClient dfs(urll);
		cout << 2 << endl;
		// ��ȡ�ļ���׺��
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
	
		// �ϴ��ļ�
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		cout << downloadUrl << endl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		xlnt::workbook wb;
		std::string fullp = string("public/static/file/");
		dfs.downloadFile(downloadUrl, &fullp);
		wb.load(fullPath);
		xlnt::worksheet ws = wb.active_sheet();
		int j = 0;
		for (const auto& row : ws.rows()) {
			if (j == 0)
			{
				j++;
				continue;
			}
			int i = 0;
			string n;
			string m;
			for (const auto& cell : row) 
			{
			    std::cout << i << endl;
				if(i==0)
				{
					n = cell.to_string();
					i++;
				}
				else 
				{
					m = cell.to_string();
					i++;
				}
			}
			auto dto = UploadExcelDTO::createShared();
			dto->addExcel(n, m);
			CostwayService service;
			uint64_t id = service.saveData(dto);
		}
	}
	// 5 ��Ӧ���
	/* TODO: ������Ӧʲô�������Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

