#include "stdafx.h"
#include "LadModService.h"
#include "../../dao/lad-mod/LadModDao.h"
#include "ExcelComponent.h"
#include <FastDfsClient.h>
#include "NacosClient.h"

LadModPageDTO::Wrapper LadModService::listAll(const LadModQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LadModPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	LadModDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<LadModDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (LadModDO sub : result)
	{
		auto dto = LadModDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, code, Code, name,Name);
		pages->addData(dto);
	}
	return pages;
}

uint64_t LadModService::saveData(const LadModAddDTO::Wrapper& dto)
{
	// ��װDO����
	LadModDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name);
	// ִ���������
	LadModDAO dao;
	return dao.insert(data);
}

bool LadModService::updateData(const LadModDTO::Wrapper& dto)
{
	// ��װDO����
	LadModDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name, Id, id);
	// ִ�������޸�
	LadModDAO dao;
	return dao.update(data) == 1;
}

bool LadModService::deleteLad(oatpp::UInt64 id)
{
	LadModDAO dao;
	return dao.deleteById(id) == 1;
}

bool LadModService::batchDeleteLad(const BatchDeleteRequestDto::Wrapper& dto)
{
	LadModDAO dao;
	return dao.batchDelete(dto) > 0;
}

string LadModService::exportLad() {
	LadModDAO dao;
	list<LadModDO> result = dao.selectAll();
	std::vector<std::vector<std::string>> data;
	std::vector<std::string> first;
	first.push_back(ZH_WORDS_GETTER("lad.excel.col.first"));
	first.push_back(ZH_WORDS_GETTER("lad.excel.col.second"));
	data.push_back(first);
	for (auto it = result.begin(); it != result.end(); ++it)
	{
		std::vector<std::string> row;
		for (int j = 1; j <= 2; j++)
		{
			if (j == 1)
			{
				row.push_back(it->getCode());
			}
			else
			{
				row.push_back(it->getName());
			}
			
		}
		data.push_back(row);
	}
	// ���屣������λ�ú�ҳǩ����
	// ע�⣺�ļ������ƺ��ļ�·�����ܳ�������
	std::string fileName = "./public/lad/export/lad.xlsx";
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫ�������ļ��л�ȡ
	std::string sheetName = ZH_WORDS_GETTER("lad.excel.name");

	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
#ifdef LINUX
	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	// ��ȡ�������ݽڵ�
	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
	std::string config = ns.getConfigText("client.conf");
	// ����ͻ��˶���
	FastDfsClient dfs(config, false);
#else
	// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
	NacosClient ns("192.168.220.128:8848", "4833404f-4b82-462e-889a-3c508160c6b4");
	// ��ȡ�������ݽڵ�
	auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
	// +FastDFS�ͻ�����������
	std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
	std::string ip = ipPort.substr(0, ipPort.find(":"));
	int port = stoi(ipPort.substr(ipPort.find(":") + 1));
	// ���ÿͻ��˶���
	FastDfsClient dfs(ip, port);
#endif
	// ����urlǰ׺
	string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	// �ϴ��ļ�
	string tmpField = dfs.uploadFile(fileName);
	// ���ص�ַ
	std::string downloadUrl = urlPrefix + tmpField;
	return downloadUrl;
}

int LadModService::importLad(string filePath)
{
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫ�������ļ��л�ȡ
	std::string sheetName = ZH_WORDS_GETTER("lad.excel.name");
	// ���ļ��ж�ȡ
	auto readData = ExcelComponent::readIntoVector("./" + filePath, sheetName);
	list<LadModDO> data;
	int i = 1;
	int result = -1;
	for (auto row : readData)
	{
		if (i == 1)
		{
			if (row.size() != 2 || row[0] != ZH_WORDS_GETTER("lad.excel.col.first") || row[1] != ZH_WORDS_GETTER("lad.excel.col.second"))
			{
				return -1;
			}
			result = 0;
			++i;
			continue;
		}
		LadModDO temp;
		int j = 1;
		for (auto value : row)
		{
			if (j == 1)
			{
				temp.setCode(value);
			}
			else if(j == 2)
			{
				temp.setName(value);
			}
			++j;
		}
		data.push_back(temp);
	}
	LadModDAO dao;
	dao.insert(data);
	return result;
}