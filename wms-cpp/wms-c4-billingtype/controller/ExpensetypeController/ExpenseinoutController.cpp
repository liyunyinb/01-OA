/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : ExpenseinoutController.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/3/10 21:12
    *  @brief    : brief
*****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include "ExpenseinoutController.h"
#include "../../service/expensetype/ExpenseTypeService.h"
#include "../../domain/query/expensetype/ExpenseTypeQuery.h"
#include "../../service/CostTypeService/CostTypeService.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

//excel ����
#include "../../lib-common/include/ExcelComponent.h"


StringJsonVO::Wrapper ExpenseinoutController::execUploadExpenceType(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	//// 1 ��ʼ��

	auto jvo = StringJsonVO::createShared();
	API_MULTIPART_INIT(container, reader);
	////// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	////// 3 ��ȡ����
	request->transferBody(&reader);
	////// 4 ��������
	/////* todo: ���������ݾ����߼�����Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	/////* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	auto fileData = "";
	auto fileSize = 0;
	std::string filename = "";
	std::string sheetName = "Sheet1";// ʹ�ô���excel��Ĭ�ϵ�sheet����
	CostTypeService service;
	if (file)
	{
		ExcelComponent excel;
		//	// 5. ��ȡ�ļ�����
		fileData = file->data();  // ��ȡ����������
		fileSize = file->size();
		filename = partfile->getFilename().getValue(""); // ��ȡԭʼ�ļ���

		std::vector<std::vector<std::string>> result = excel.readIntoVector(fileData, fileSize, sheetName);
		for (int i = 1; i < result.size(); i++)
		{

			auto dto = GetCostDTO::createShared();  // ��������
			dto->cost_code = oatpp::String(result[i][0]);
			dto->cost_name = oatpp::String(result[i][1]);
			dto->cost_type = oatpp::String(result[i][2]);
			service.saveData(dto, payload);
		}
	}
	else
	{
		jvo->fail("No file uploaded");
		return jvo;
	}

	jvo->success("uploaded file success");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExpenseinoutController::execExportData(const ExpenseTypeQuery::Wrapper& query)
{
	ExpenseTypeService service;

	auto result = service.exportData(query);

	std::string fullPath = result;
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

	response->putHeader("Content-Disposition", "attachment; filename=test.xlsx");

	// Ӱ��ɹ����
	return response;
}