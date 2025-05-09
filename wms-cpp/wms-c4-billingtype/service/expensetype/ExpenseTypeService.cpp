#define _CRT_SECURE_NO_WARNINGS

#pragma once


#include "stdafx.h"
#include "../../dao/expensetype/ExpenseTypeDAO.h"
#include "ExpenseTypeService.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"


//#define TEST_EXCEL_FN "./" + ZH_WORDS_GETTER("diff-post.excel.path.good-diff-post") + ".xlsx"
#define TEST_EXCEL_SN ZH_WORDS_GETTER("expense.excel.s1")


std::string ExpenseTypeService::exportData(const ExpenseTypeQuery::Wrapper& query)
{
	ExpenseTypeDAO dao;
	list<ExpenseTypeDO> result = dao.selectWithConditions(query);

	std::vector<ExpenseTypeDO> datas(result.begin(), result.end());


	// ������ͷ����
	std::vector<std::string> headers = {
		ZH_WORDS_GETTER("expense.field.cost_code"),
		ZH_WORDS_GETTER("expense.field.cost_type_name"),
		//ZH_WORDS_GETTER("expense.field.cost_type_del"),
	};
	std::vector<std::vector<std::string>> data;
	data.push_back(headers);

	for (int i = 0; i < datas.size(); ++i)
	{
		std::vector<std::string> row;
		row.push_back(datas[i].getCost_type_code());
		row.push_back(datas[i].getCost_type_name());
		//row.push_back(datas[i].getCost_type_del());
		data.push_back(row);
	}

	// ���屣������λ�ú�ҳǩ����
	// ע�⣺�ļ������ƺ��ļ�·�����ܳ�������
	//std::string fileName = TEST_EXCEL_FN;
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫ�������ļ��л�ȡ
	//std::string sheetName = TEST_EXCEL_SN;

	// ���浽�ļ�
	ExcelComponent excel;
	//excel.writeVectorToFile("6666.xlsx", sheetName, data);
	auto buff = excel.writeVectorToBuff(TEST_EXCEL_SN, data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	FastDfsClient dfs("121.43.101.169");
	std::string upResult = dfs.uploadFile(tsData, buff.size(),"xlsx");
	if (upResult != "")
	{
		std::cout << "http://121.43.101.169:8888/" << upResult << std::endl;
		//����
		std::string dir = "file";
		std::string fullPath = dfs.downloadFile(upResult, &dir);
		std::cout << fullPath << std::endl;
		return fullPath;
	}
	return "";
}
