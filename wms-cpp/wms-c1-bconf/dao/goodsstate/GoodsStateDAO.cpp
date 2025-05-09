#include "stdafx.h"
#include "GoodsStateDAO.h"
#include "GoodsStateMapper.h"
#include "domain/do/GoodsStateControllerDO/GoodsStateControllerDO.h"
#include <cstdarg> // ���ڿɱ����
// ����ɾ��
int GoodsStateDAO::deleteByIds(const std::vector<std::string>& ids) {
    if (ids.empty()) {
        OATPP_LOGE("GoodsStateDAO", "No IDs provided for batch deletion");
        return 0;
    }
    // ���� SQL ��䣬��̬����ռλ��
    std::string sql = "DELETE FROM `ba_qm_sta` WHERE `id` IN (";
    for (size_t i = 0; i < ids.size(); ++i) {
        sql += "?";
        if (i < ids.size() - 1) {
            sql += ",";
        }
    }
    sql += ")";

    // ��̬���������б�
    std::vector<std::string> params;
    for (const auto& id : ids) {
        if (id.empty()) {
            OATPP_LOGE("GoodsStateDAO", "Empty ID found in batch deletion");
            return 0;
        }
        params.push_back(id);
    }

    // ���� SqlSession �� executeUpdate ����
    try {
        return sqlSession->executeUpdate(sql, params);
    }
    catch (const std::exception& e) {
        OATPP_LOGE("GoodsStateDAO", "Failed to execute batch delete: %s", e.what());
        return 0;
    }
}
//��������
uint64_t GoodsStateDAO::insert(const GoodsStateControllerDO& iObj) {
	std::string sql = "INSERT INTO ba_qm_sta (id, create_name, create_by, create_date, update_name, update_by, update_date, sys_org_code, sys_company_code, qm_sta_code, qm_sta_name) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getId(), iObj.getCreate_name(), iObj.getCreate_by(), iObj.getCreate_date(),
		iObj.getUpdate_name(), iObj.getUpdate_by(), iObj.getUpdate_date(),
		iObj.getSys_org_code(), iObj.getSys_company_code(), iObj.getQm_sta_code(), iObj.getQm_sta_name());
}
// ��ҳ��ѯ���ݱ��е�����
std::list<GoodsStateControllerDO> GoodsStateDAO::QueryWithPage(const GoodStateQuery::Wrapper& query)
{
	std::list<GoodsStateControllerDO> res;
	std::string sql = "SELECT * FROM ba_qm_sta";
	// 1.ִ�в�ѯ
	GoodsStateMapper mapper;
    res = sqlSession->executeQuery<GoodsStateControllerDO>(sql, mapper);
	//1.2 ����ѯ����Ƿ�Ϊ�� �пմ������Ҫ*****
	if (res.empty()) {
		OATPP_LOGE("GoodsStateDAO", "Query returned no results");
	}
	return res;
}