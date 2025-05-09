#include "stdafx.h"
#include <iostream>
#include "ExportController.h"
//#include "domain/vo/cominfo/ComInfoVO.h"
#include <regex>

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExportController::execExportExcel(const String& filename)
{
	// �����ļ�ȫ·��
	std::string fullPath = "Public/DownloadIndcla/" + URIUtil::urlDecode(filename.getValue(""));
	//��`ba_classfl`��Ӧ�ṹ
	std::vector<std::string> ba_classfl = {
	ZH_WORDS_GETTER("chengfeng.id"),
	ZH_WORDS_GETTER("chengfeng.code"),
	ZH_WORDS_GETTER("chengfeng.name"),
	ZH_WORDS_GETTER("chengfeng.del")
	};
	std::vector<std::string> ba_classfl_en = {
		"id","code","name","del"
	};
	//�������ݵ��ͻ���
	/*
	int total_size;//�ɲ�ѯ��ҵ��Ϣ�õ�������
	int PageSize;//ÿҳ����

	//����һ��excel���
	ExcelComponent excel;
	std::string sheetName = "Page";

	for (int PageIndex = 0; PageIndex  < (total_size - 1) / PageSize; PageIndex++) //������ҳ��
	{
		//����ÿһ������
		std::vector<std::vector<std::string>> data;
		data.push_back(ba_comp);
		data.push_back(ba_comp_en);

		// ���ɵ�ǰҳ������
		for (int i = 0; i < PageSize; i++)
		{
			int recordIndex = PageIndex * PageSize + i;
			if (recordIndex >= total_size) break; // ����Խ��

			// ʵ��Ӧ�����ݿ��ѯ
			std::vector<std::string> row = {

			};
			data.push_back(row);
		}
		// ���ɵ�ǰ��ҳ�����ݵ��ļ�
		std::string currentSheetName = sheetNamePrefix + std::to_string(PageIndex + 1);
		excel.writeVectorToFile(fullPath, currentSheetName, data);
	}
	//����ÿһ������
	std::vector<std::vector<std::string>> data;
	data.push_back(ba_comp);
	data.push_back(ba_comp_en);
	for(int i=PageIndex*PageSize;i<total_size;++i)
	{
		int recordIndex = PageIndex * PageSize + i;

		// ʵ��Ӧ�����ݿ��ѯ
		std::vector<std::string> row = {

		};
		data.push_back(row);
	}
	// ��ȡ�ļ����ݵ� buffer ����
	auto buff = excel.writeVectorToBuff(sheetName + std::to_string(++PageIndex), data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	*/


	// �������� �����ݽ�������
	// ����zo_wms��������Ҫ����ѯ��ҵ��Ϣ�ӿ����
	// ���� total_size �� PageSize �ɲ�ѯ��ҵ��Ϣ�ӿ���ɻ�ȡ
	int total_size = 200;  // ������������
	int PageSize = 100;      // ÿҳ100��
	int PageIndex;

	ExcelComponent excel;
	std::string sheetName = "Page";

	for (PageIndex = 0; PageIndex < (total_size - 1) / PageSize; PageIndex++)
	{
		std::vector<std::vector<std::string>> data;
		data.push_back(ba_classfl);
		data.push_back(ba_classfl_en);

		// ���ɵ�ǰҳ������
		for (int i = 0; i < PageSize; i++)
		{
			int recordIndex = PageIndex * PageSize + i;
			if (recordIndex >= total_size) break; // ����Խ��

			// ������ģ�����ݣ�ʵ��Ӧ�����ݿ��ѯ
			std::vector<std::string> row = {
				std::to_string(recordIndex + 1), "user" + std::to_string(recordIndex),
				"creator" + std::to_string(recordIndex), "2024-03-01 10:00:00",
				"editor" + std::to_string(recordIndex), "editor_by" + std::to_string(recordIndex),
				"2024-03-02 11:00:00", "100" + std::to_string(recordIndex),
				"200" + std::to_string(recordIndex), "C00" + std::to_string(recordIndex),
				"Company" + std::to_string(recordIndex), "Alias" + std::to_string(recordIndex),
				"Address" + std::to_string(recordIndex), "Company_EN" + std::to_string(recordIndex),
				"Alias_EN" + std::to_string(recordIndex)
			};
			data.push_back(row);
		}

		// ���ɵ�ǰ��ҳ�����ݵ��ļ�
		std::string currentSheetName = sheetName + std::to_string(PageIndex + 1);
		excel.writeVectorToFile(fullPath, currentSheetName, data);
	}
	std::vector<std::vector<std::string>> data;
	data.push_back(ba_classfl);
	data.push_back(ba_classfl_en);
	// ���ɵ�ǰҳ������
	for (int i = PageIndex * PageSize; i < total_size; i++)
	{

		// ������ģ�����ݣ�ʵ��Ӧ�����ݿ��ѯ
		std::vector<std::string> row = {
			std::to_string(i + 1), "user" + std::to_string(i),
			"creator" + std::to_string(i), "2024-03-01 10:00:00",
			"editor" + std::to_string(i), "editor_by" + std::to_string(i),
			"2024-03-02 11:00:00", "100" + std::to_string(i),
			"200" + std::to_string(i), "C00" + std::to_string(i),
			"Company" + std::to_string(i), "Alias" + std::to_string(i),
			"Address" + std::to_string(i), "Company_EN" + std::to_string(i),
			"Alias_EN" + std::to_string(i)
		};
		data.push_back(row);
	}

	// ��ȡ�ļ����ݵ� buffer ����
	auto buff = excel.writeVectorToBuff(sheetName + std::to_string(++PageIndex), data);
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