#include "stdafx.h"
#include "GoodsStateService.h"
#include "../../dao/goodsstate/GoodsStateDAO.h"
#include "domain/do/GoodsStateControllerDO/GoodsStateControllerDO.h"
#include "domain/vo/goodsstate/GoodsStateVO.h"
#include "domain/query/goodsstate/GoodStateQuery.h"
#include "domain/dto/goodsstate/GoodStateDTO.h"
#include "Macros.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
// ����ɾ��
bool GoodsStateService::removeDates(const std::vector<std::string>& ids) {
    if (ids.empty()) {
        OATPP_LOGE("GoodsStateService", "No IDs provided for batch deletion");
        return false;
    }

    GoodsStateDAO dao;
    int deletedCount = dao.deleteByIds(ids);

    if (deletedCount > 0) {
        OATPP_LOGI("GoodsStateService", "Successfully deleted %d records", deletedCount);
        return true;
    }
    else {
        OATPP_LOGE("GoodsStateService", "Failed to delete any records");
        return false;
    }
}
// ��������
bool GoodsStateService::importData(const std::vector<std::vector<std::string>>& data) {
    // 1. ��������Ƿ�Ϊ��
    if (data.empty()) {
        return false;
    }
    // 2. ���� Excel ����
    for (size_t i = 1; i < data.size(); i++) { // ������ͷ
        const auto& row = data[i];
        // 3. ������ݸ�ʽ
        if (row.size() < 11) { // ȷ��ÿ����  11 ������
            continue;
        }
        GoodsStateControllerDO doo;
        try {
            // 4. �� Excel ����ת��Ϊ DO ����
            UuidFacade uid(1);
    
            doo.setId(uid.genUuid()); // ID
            doo.setCreate_name(row[1]); // ��������
            doo.setCreate_by(row[2]); // ������
            doo.setCreate_date(row[3]); // ��������
            doo.setUpdate_name(row[4]); // ��������
            doo.setUpdate_by(row[5]); // ������
            doo.setUpdate_date(row[6]); // ��������
            doo.setSys_org_code(row[7]); // ��������
            doo.setSys_company_code(row[8]); // ������˾
            doo.setQm_sta_code(row[9]); // Ʒ�ʴ���
            doo.setQm_sta_name(row[10]); // Ʒ�ʴ�������
        }
        catch (const std::exception& e) {
            OATPP_LOGE("goodsstates", "Failed to parse data in row %zu: %s", i, e.what());
            continue;
        }
        // 5. ���� DAO ���������
        GoodsStateDAO dao;
        uint64_t res = dao.insert(doo);
        if (res == 0) {
            OATPP_LOGE("GoodsStateService", "Failed to insert data in row %zu", i);
            return false; // ���Ϊʧ��
        }
    }
    return true; // �����Ƿ��������ݶ�����ɹ�
}
//��ѯ���ݱ������е�����--->��������
std::list<GoodStateDTO::Wrapper> GoodsStateService::QueryAll(const GoodStateQuery::Wrapper& query)
{
	GoodsStateDAO dao;
	//ȷ���ܵ����������� list��Ϊ����ֵ
	auto result = dao.QueryWithPage(query);

	// ����ѯ����Ƿ�Ϊ�� ,  ����Ҫ***
	if (result.empty()) {
		OATPP_LOGE("GoodsStateService", "No data found in ba_qm_sta table");
		return {}; // ���ؿ��б�
	}
	// 2. �� DO �б�ת��Ϊ DTO �б�
	std::list<GoodStateDTO::Wrapper> dtoList;
	for (const auto& doo : result) {
		auto dto = GoodStateDTO::createShared();
		dto->id = doo.getId();
		dto->create_name = doo.getCreate_name();
		dto->create_by = doo.getCreate_by();
		dto->create_date = doo.getCreate_date();
		dto->update_name = doo.getUpdate_name();
		dto->update_by = doo.getUpdate_by();
		dto->update_date = doo.getUpdate_date();
		dto->sys_org_code = doo.getSys_org_code();
		dto->sys_company_code = doo.getSys_company_code();
		dto->qm_sta_code = doo.getQm_sta_code();
		dto->qm_sta_name = doo.getQm_sta_name();
		dtoList.push_back(dto); // �� DTO ��ӵ��б���
	}
	return dtoList;
}