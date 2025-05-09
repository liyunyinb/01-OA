/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/02/24 11:37:57

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
#include <iostream>
#include "UploadFileController.h"
#include "ExcelComponent.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "service/tradeclassifi/UploadFileService.h"
#include <filesystem> //ɾ�������ļ�
#include <regex> // ������ʽ
#include "domain/dto/tradeclassifi/UploadFileDTO.h"
#include <fstream>

// ��̬��ȡ�ϴ�����Execl�ı���
vector<std::string> GetSheetTitle(const string& ExcelPath) {
	xlnt::workbook wb;
	wb.load(ExcelPath);
	vector<std::string> sheetTitle = wb.sheet_titles();
	return sheetTitle;
}

bool CheckExeclDataIsVaild(const std::string& ExcelPath) {
	try {
		// 1. ����ļ��Ƿ����
		std::ifstream file(ExcelPath);
		if (!file.good()) {
			std::cerr << "����: �ļ������ڻ򲻿ɶ� - " << ExcelPath << std::endl;
			return false;
		}

		// 2. ����ļ���ʽ
		if (ExcelPath.find(".xlsx") == std::string::npos) {
			std::cerr << "����: ��֧�� .xlsx ��ʽ�ļ�" << std::endl;
			return false;
		}

		// 3. ���ع�����
		xlnt::workbook wb;
		wb.load(ExcelPath);

		// 4. ��ȡ���й�������
		const auto wsList = wb.sheet_titles();

		// 5. �����������
		const int maxRows = 100000;
		int rowCount = 0;
		for (const auto& sheetName : wsList) {
			auto ws = wb.sheet_by_title(sheetName);
			for (const auto& row : ws.rows()) {
				if (++rowCount > maxRows) {
					std::cerr << "����: �������������� (" << maxRows << " ��)" << std::endl;
					return false;
				}
			}
		}
		return true;
	}
	catch (const xlnt::exception& e) {
		std::cerr << "xlnt �쳣: " << e.what() << std::endl;
		return false;
	}
	catch (const std::exception& e) {
		std::cerr << "��׼�쳣: " << e.what() << std::endl;
		return false;
	}
}

// ������У��
bool RegexCheck(const string& typecodes, const string& typenames) {

	// ������ʽ��У�� typecodes��ֻ�������֣�
	std::regex codeRegex(R"(^\d+$)"); // ֻ��������

	// ������ʽ��У�� typenames��������ĸ�����֡������ַ����»��ߣ���ֹ�ո��������ţ�
	std::regex nameRegex(R"(^[a-zA-Z0-9_\p{Han}]+$)"); // \p{Han} ƥ�������ַ���_ ƥ���»���

	// У�� typecodes
	if (!std::regex_match(typecodes, codeRegex)) {
		std::cout << "typecodes check error" << std::endl;
		return false;
	}

	// У�� typenames
	if (!std::regex_match(typenames, nameRegex)) {
		std::cout << "typenames check error" << std::endl;
		return false;
	}

	return true; // ��������ֶζ�У��ͨ��
}

// ɾ��������ʱ�ļ�
void DeleteTempExecl(const string& ExecPath) {
	if (std::filesystem::exists(ExecPath)) {
		if (std::filesystem::remove(ExecPath)) {
			std::cout << "The file was deleted successfully" << endl;
		}
		else {
			std::cout << "File deletion failed!" << std::endl;
		}
	}
	else {
		std::cout << "the path does not exist!" << std::endl;
	}
}

/*��ȡ���ݣ���װ��vector<AttriInfoJsonDTO::Wrapper>*/
vector<UploadFileDTO::Wrapper> getDataFromExcelUploadFile(const string& ExcelPath, const PayloadDTO& pdto) {
	int colNum = 2;//�����ֶ�
	vector<UploadFileDTO::Wrapper> dtoList;
	ExcelComponent excel;

	//Ψһֵ�������ظ� typecode typename ��ͬ�Ĳ��ܳ������Σ��������������Ҫ����ȥ��
	std::unordered_map<std::string, std::string> uniqueValues;  //�����ȡ����ʱ�������ظ������ݲ������������

	// ��̬��ȡ��ǰexeclӵ�е�ҳǩ
	auto sheet = GetSheetTitle(ExcelPath);
	// �ж���ҳǩ�����������ҳǩ������
	for (auto sheetTitle : sheet) {
		vector<vector<string>> dataList = excel.readIntoVector(ExcelPath, sheetTitle);//��ȡҳǩ
		for (auto index : dataList) {
			auto dto = UploadFileDTO::createShared();
			// �ֶ���У��
			if (index.size() != colNum) {//��������,������ҵ����ֻ������������ ���Դ���typecodes & ��������typenames
				return dtoList;
			}
			else {
				// Ψһ��У��
				if (uniqueValues.find(index[0]) != uniqueValues.end()) {
					// �������ظ�
					continue; // ȥ����һ�е�����
				}
				// ������У��
				else if (!RegexCheck(index[0], index[1])) {
					// ������������
					continue; // ȥ����һ�е�����
				}
				// ��ȡ�ֶ�����
				else {
					dto->sysorgcode = pdto.getOrgcode();
					dto->syscompanycode = pdto.getCompanycode();
					dto->creadename = pdto.getRealname();
					dto->createby = pdto.getUsername();
					dto->typecodes = index[0];
					dto->typenames = index[1];
					uniqueValues[index[0]] = index[1]; //����Ψһֵ
				}
			}
			dtoList.push_back(dto);
		}
	}
	return dtoList;
}

StringJsonVO::Wrapper UploadFileController::execUploadTrade(std::shared_ptr<IncomingRequest> request, const PayloadDTO& dto)
{
	/*�����߼�*/
// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 ��ȡ����
	request->transferBody(&reader);

	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 ��������
	/* ��ȡ������ */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "typecode", typecode);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "typenames", typenames);

	/* ��ӡ������ */
	if (typecode) OATPP_LOGD("Multipart", "age=%d", typecode.getValue({}).c_str());
	if (typenames) OATPP_LOGD("Multipart", "nickname='%s'", typenames.getValue({}).c_str());

	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	auto jvo = StringJsonVO::createShared();
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());

		//���ļ����浽����
		string fullPath = "public/static/file/" + filename;
		//string fullPath = "E:\\temp\\" + filename;
		file.saveToFile(fullPath.c_str());
		std::cout << "The fullPath is : " << fullPath << std::endl;

		///* �����ϴ���FastDFS */
		//ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		//// ��ȡ�ļ���׺��
		//string suffix = "";
		//size_t pos = filename.rfind(".");
		//if (pos != string::npos)
		//{
		//	suffix = filename.substr(pos + 1);
		//}
		// �ϴ��ļ�
		//string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		//downloadUrl = urlPrefix + downloadUrl;
		//OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		//std::cout << downloadUrl << std::endl;


		// �������ļ�������У�飬�����һ���̲�ͨ�����ᱻֱ�ӷ��� 
		// ��ע����Execl����һ���̲��ᱻ��Ϊ��Ч��
		//  ����������ᱻ������Ч -- ������������

		if (!CheckExeclDataIsVaild(fullPath)) {
			std::cerr << "file data invaild!!!" << std::endl;
			jvo->fail("file data invaild");
			//ɾ��������ʱ�ļ�
			DeleteTempExecl(fullPath);
			//ɾ��Զ���ļ�
			//dfs.deleteFile(downloadUrl);
			return jvo;
		}

		// �������ݿ�
		UploadFileService service;

		vector<UploadFileDTO::Wrapper> object_data = getDataFromExcelUploadFile(fullPath, dto);

		if (object_data.size() == 0) {// �������Ϊ��
			jvo->fail("empty");
		}
		for (auto dto : object_data) {
			if (!service.saveData(dto)) { //serviceִ�в���
				jvo->fail("false");
			}
		}

		//ɾ��������ʱ�ļ�
		DeleteTempExecl(fullPath);
		//ɾ��Զ���ļ�
		//dfs.deleteFile(downloadUrl);

		//���й������ɹ� ����ok
		jvo->success("ok");
	}

	return jvo;
}
