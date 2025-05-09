#include "stdafx.h"
#include "CangkuDAO.h"
#include "CangkuNameListMapper.h"
#include <sstream>

std::list<StoreDO> CangkuDAO::getCangkuNameList() {

	stringstream sql;
	//	����sql���
	sql << "SELECT id, store_code, store_name "
		<< "FROM `ba_store`";

	CangkuNameListMapper mapper;
	string sql_str = sql.str();
	
	return sqlSession->executeQuery<StoreDO, CangkuNameListMapper>(sql_str, mapper);
}

bool CangkuDAO::deleteCangkuById(string id) {
	bool flag = true;
	stringstream sql;
	//	��ɾ�����ڸòֿ�Ĵ�λ
	sql << "DELETE FROM md_bin "
		<< "WHERE bin_store IN ("
		<< "SELECT store_code FROM ba_store WHERE id = ?);";
	string sql_str = sql.str();
	flag &= (sqlSession->executeUpdate(sql_str, "%s", id) >= 0);
	//	��ɾ���òֿ�
	sql.str("");
	sql.clear();
	sql << "DELETE FROM ba_store WHERE id = ? ;";
	sql_str = sql.str();
    flag &= (sqlSession->executeUpdate(sql_str, "%s", id) >= 0);

	return flag;

}

std::vector<string> CangkuDAO::getExcelData(string store_code) {
    std::vector<string> result;
	stringstream sql;
    sql << "SELECT store_code, store_name, store_text "
		<< "FROM ba_store "
		<< "WHERE id = '" << store_code << "';";
	CangkuBaseInfoMapper mapper;
	string sql_str = sql.str();
	auto sql_result = sqlSession->executeQuery<StoreDO, CangkuBaseInfoMapper>(sql_str, mapper);
	result.push_back(sql_result.begin()->getStoreCode());
	result.push_back(sql_result.begin()->getStoreName());
    result.push_back(sql_result.begin()->getStoreText());

	return result;
}

std::vector<std::vector<std::string>> CangkuDAO::getAllExcelData() {
	std::vector<std::vector<std::string>> result;
	//result.push_back({ "�ֿ����", "�ֿ�����", "�ֿⱸע" });		//	���������Ժ����ʵ�
	result.push_back({ ZH_WORDS_GETTER("Cangku.info.store_code"), ZH_WORDS_GETTER("Cangku.info.store_name"), ZH_WORDS_GETTER("Cangku.info.store_text") });
    stringstream sql;
	sql << "SELECT store_code, store_name, store_text "
		<< "FROM ba_store ;";
	CangkuBaseInfoMapper mapper;
	string sql_str = sql.str();
	auto sql_result = sqlSession->executeQuery<StoreDO, CangkuBaseInfoMapper>(sql_str, mapper);
	
	for (auto& item : sql_result) {
		std::vector<std::string> row;
		row.push_back(item.getStoreCode());
        row.push_back(item.getStoreName());
        row.push_back(item.getStoreText());
		result.emplace_back(row);
	}

	return result;
}