

#include <iostream>
#include "stdafx.h"
#include "CustomerBillService.h"
#include "dao/custormer-bill/CustormerBillDAO.h"
#include "ExcelComponent.h"






//��ҳ��ѯ
CustomerBillPageDTO::Wrapper CustomerBillPageService::listAll(const CustomerBillQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CustomerBillPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	CustomerBillDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CustomerBillDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (CustomerBillDO sub : result)
	{


		auto dto = CustomerBillDTO::createShared();
		dto->customercode = "d";
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, customercode, Id, fullchinesename, Name);
		pages->addData(dto);
	}
	return pages;
}



//id��ѯ�õ�excel�ļ�
oatpp::String ExportService::getById(oatpp::String id)
{
	// ��ѯ����
	CustomerBillDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (res.empty())
		return "";



	std::vector<std::vector<std::string>> data;
	stringstream ss;
	data.push_back(std::vector<std::string>());
	//�����ֶ���������
		data[0].push_back("id");
		data[0].push_back("create_name");
		data[0].push_back("create_by");
		data[0].push_back("create_date");
		data[0].push_back("update_name");
		data[0].push_back("update_by");
		data[0].push_back("update_date");
		data[0].push_back("sys_org_code");
		data[0].push_back("sys_company_code");
		data[0].push_back("cus_code");
		data[0].push_back("cus_name");
		data[0].push_back("cost_code");
		data[0].push_back("cost_name");
		data[0].push_back("cost_date");
		data[0].push_back("day_cost_yj");
		data[0].push_back("day_cost_bhs");
		data[0].push_back("day_cost_se");
		data[0].push_back("day_cost_hsj");
		data[0].push_back("cost_ori");
		data[0].push_back("beizhu");
		data[0].push_back("cost_sta");
		data[0].push_back("cost_sl");
		data[0].push_back("cost_unit");
		data[0].push_back("cost_js");

		for (auto it = res.begin(); it!= res.end(); it++) {
			std::vector<std::string> row;
			row = convertDayCostDOToVector(*it);//��doת��Ϊvector
			data.push_back(row);
		}
		

		// ��Excel���ݵ�����String��
		ExcelComponent excel;
		auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("bill.exported"), data);
		const char* tsData = reinterpret_cast<const char*>(buff.data());
		auto fstring = String(tsData, buff.size());

		return fstring;

}





//date��ѯ�õ�excel�ļ�
oatpp::String periodService::getBydate(const PeriodQuery::Wrapper& file)
{
	// ��ѯ����
	CustomerBillDAO dao;
	auto res = dao.selectBydate(file);

	// û�в�ѯ������   
	if (res.empty())
		return "";



	std::vector<std::vector<std::string>> data;
	//std::string info = ZH_WORDS_GETTER("bill.exported");
	stringstream ss;
	data.push_back(std::vector<std::string>());
	//�����ֶ���������
	data[0].push_back("id");
	data[0].push_back("create_name");
	data[0].push_back("create_by");
	data[0].push_back("create_date");
	data[0].push_back("update_name");
	data[0].push_back("update_by");
	data[0].push_back("update_date");
	data[0].push_back("sys_org_code");
	data[0].push_back("sys_company_code");
	data[0].push_back("cus_code");
	data[0].push_back("cus_name");
	data[0].push_back("cost_code");
	data[0].push_back("cost_name");
	data[0].push_back("cost_date");
	data[0].push_back("day_cost_yj");
	data[0].push_back("day_cost_bhs");
	data[0].push_back("day_cost_se");
	data[0].push_back("day_cost_hsj");
	data[0].push_back("cost_ori");
	data[0].push_back("beizhu");
	data[0].push_back("cost_sta");
	data[0].push_back("cost_sl");
	data[0].push_back("cost_unit");
	data[0].push_back("cost_js");

	for (auto it = res.begin(); it != res.end(); it++) {
		std::vector<std::string> row;
		row=convertDayCostDOToVector(*it);//��doת��Ϊvector
		data.push_back(row);
	}


	// ��Excel���ݵ�����String��
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("bill.period"), data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());

	return fstring;

}
