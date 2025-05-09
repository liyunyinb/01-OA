#include "stdafx.h"
#include "CangKuDingYiService.h"
#include "../../dao/cangkudingyi/CangkuDAO.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include "../../../lib-common/include/FastDfsClient.h"
#include "../../../lib-common/include/NacosClient.h"
#include "../../../nacos-register/Macros.h"

//	��ȡ�ֿ������б�(�޲�)
oatpp::List<CangkuNameListDTO::Wrapper> CangKuDingYiService::getCangkuNameList() {
	//	�������ض���
	auto result = oatpp::List<CangkuNameListDTO::Wrapper>::createShared();

	//	��ѯ�ֿ������б�
	CangkuDAO dao;
	list<StoreDO> sum = dao.getCangkuNameList();

	for (StoreDO item : sum) {
		auto dto = CangkuNameListDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, item, id, Id, store_code, StoreCode, store_name, StoreName);

		result->emplace_back(dto);
	}

	return result;
}
//	ͨ���ֿ�IDɾ���ֿ�(֧������)
bool CangKuDingYiService::deleteCangkuById_List(oatpp::List<oatpp::String>& id_list) {
	//	�������ض���
	bool flag = true;

	//	��id_list��ȡ������idִ��ɾ������
	CangkuDAO dao;
	for (auto id : *id_list) {
		flag &= dao.deleteCangkuById(id);
	}


	return flag;	
}
//	ͨ���ֿ�����б����ֿ���Ϣ,������������
string CangKuDingYiService::getpath_exportCangkuByCodeList(oatpp::List<oatpp::String>& code_list) {
	
	ExcelComponent excel;
	CangkuDAO dao;

	//	���ݲֿ�ID��ȡ��������
	std::vector<std::vector<std::string>> data;
	if (code_list->empty()) {
		data = dao.getAllExcelData();
	}
	else {
		data.push_back({ ZH_WORDS_GETTER("Cangku.info.store_code"), ZH_WORDS_GETTER("Cangku.info.store_name"), ZH_WORDS_GETTER("Cangku.info.store_text") });
		for (auto code : *code_list) {
			data.emplace_back(dao.getExcelData(code));
		}
	}

	//	�������ϴ����ļ���������
	auto buff = excel.writeVectorToBuff("sheet1", data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());

#ifdef LINUX
	ZO_CREATE_DFS_CLIENT_URL(dfs_client, pre_url);
    std::string url = dfs_client.uploadFile(tsData, buff.size(), "xlsx");
	return pre_url + url;
#else
	ZO_CREATE_DFS_CLIENT_URL(dfs,pre_url);
	std::string res = dfs.uploadFile(tsData, buff.size(), "xlsx");
	return  pre_url + res;
#endif

	
}