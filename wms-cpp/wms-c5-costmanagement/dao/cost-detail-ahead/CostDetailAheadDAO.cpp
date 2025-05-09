#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: whx
 @Date: 2025/3/5 14:23:49

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
#include "CostDetailAheadDAO.h"
#include "CostDetailAheadMapper.h"
#include <sstream>


std::string CostDetailAheadDAO::queryConditionBuilder(const CostDetailQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	
	if (query->cusCode && !query->cusCode->empty()) {
		sqlCondition << " AND `cus_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cusCode.getValue(""));
	}
	if (query->cusName && !query->cusName->empty()) {

		sqlCondition << " AND `cus_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cusName.getValue(""));
	}
	if (query->costCode && !query->costCode->empty()) {

		sqlCondition << " AND `cost_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->costCode.getValue(""));
	}
	if (query->costName && !query->costName->empty()) {

		sqlCondition << " AND `cost_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->costName.getValue(""));
	}

	if (query->costDateBegin && !query->costDateBegin->empty()) {
		sqlCondition << " AND `cost_data` >= STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
		SQLPARAMS_PUSH(params, "dt_start", std::string, query->costDateBegin.getValue(""));
	}

	if (query->costDateEnd && !query->costDateEnd->empty()) {
		sqlCondition << " AND `cost_data` < STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s') + INTERVAL 1 DAY";
		SQLPARAMS_PUSH(params, "dt_end", std::string, query->costDateEnd.getValue(""));
	}
	
	if (query->note && !query->note->empty()) {

		sqlCondition << " AND `beizhu`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->note.getValue(""));
	}
	if (query->costState && !query->costState->empty()) {

		sqlCondition << " AND `cost_sta`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->costState.getValue(""));
	}
	
	return sqlCondition.str();
}


uint64_t CostDetailAheadDAO::count(const CostDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wm_day_cost ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DayCostDO> CostDetailAheadDAO::selectWithPage(const CostDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT `id`,`create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`,`cus_code`,`cus_name`,`cost_code`,`cost_name`,`cost_data`,`day_cost_yj`,`day_cost_bhs`,`day_cost_se`,`day_cost_hsj`,`cost_ori`,`beizhu`,`cost_sta`,`cost_sl`,`cost_unit`,`cost_js` FROM `wm_day_cost` ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	
	cout << "sql: " << sql << endl;
	
	// ִ�в�ѯ
	CostDetailMapper mapper;
	return sqlSession->executeQuery<DayCostDO>(sql, mapper, params);
}

//��������������ѯӦ�����������
std::list<DayCostDO> CostDetailAheadDAO::selectByName(const string& name)
{
	string sql = "SELECT id,name,sex,age FROM wm_day_cost WHERE `name` LIKE CONCAT('%',?,'%')";
	CostDetailMapper mapper;
	return sqlSession->executeQuery<DayCostDO>(sql, mapper, "%s", name);
}

PtrDayCostDO CostDetailAheadDAO::selectById(uint64_t id)
{
	string sql = "SELECT id,name,sex,age FROM wm_day_cost WHERE `id`=?";
	PtrCostDetailMapper mapper;
	return sqlSession->executeQueryOne<PtrDayCostDO>(sql, mapper, "%ull", id);
}

uint64_t CostDetailAheadDAO::insert(const DayCostDO& iObj)
{
	string sql = "INSERT INTO `wm_day_cost` (`id`, `create_name`, `create_by`,`create_date`,`sys_org_code`,`sys_company_code`,`cus_code`,`cost_code`,`cost_data`,`day_cost_yj`,`day_cost_bhs`,`day_cost_se`,`day_cost_hsj`,`cost_ori`,`beizhu`,`cost_sta`,`cost_sl`,`cost_unit`) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%dt%s%s%s%s%dt%s%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreateName(),  iObj.getCreateBy(), iObj.getCreateDate(), iObj.getSysOrgCode(), iObj.getSysCompanyCode(), iObj.getCusCode(),
		iObj.getCostCode(), iObj.getCostDate(), iObj.getDayCostYj(), iObj.getDayCostBhs(),iObj.getDayCostSe(), iObj.getDayCostHsj(), iObj.getCostOri(), iObj.getBeiZhu(), iObj.getCostSta(), iObj.getCostSl(), iObj.getCostUnit());
}

int CostDetailAheadDAO::update(const DayCostDO& uObj)
{
	 // ������� SQL��ע���ֶ����Ͷ��ţ�
	string sql = "UPDATE `wm_day_cost` SET "
		"`update_name`=?, `update_by`=?, `update_date`=?, "
		"`cus_code`=?, `cost_code`=?, `cost_data`=?, "  // �����ֶ����� cost_date
		"`day_cost_yj`=?, `day_cost_bhs`=?, `day_cost_se`=?, "
		"`day_cost_hsj`=?, `cost_ori`=?, `beizhu`=?, "
		"`cost_sta`=?, `cost_sl`=?, `cost_unit`=? "
		"WHERE `id`=?";

	// ������ĸ�ʽ���ַ�����16 ��������
	const char* format = "%s%s%dt%s%s%dt%s%s%s%s%s%s%s%s%s%s"; // ����ʵ�����͵���

	return sqlSession->executeUpdate(sql, format,
		uObj.getUpdateName(),    // �ַ��� (��������Ϊ string)
		uObj.getUpdateBy(),      // �ַ���
		uObj.getUpdateDate(),    // ����ʱ�䣨ת��Ϊ�ַ������� "YYYY-MM-DD HH:mm:ss"��
		uObj.getCusCode(),       // �ַ���
		uObj.getCostCode(),      // �ַ���
		uObj.getCostDate(),      // ����ʱ��
		uObj.getDayCostYj(),     // ��ֵ���ͣ�
		uObj.getDayCostBhs(),    // ��ֵ
		uObj.getDayCostSe(),     // ��ֵ
		uObj.getDayCostHsj(),    // ��ֵ
		uObj.getCostOri(),       // ��ֵ
		uObj.getBeiZhu(),        // �ַ���
		uObj.getCostSta(),       // �ַ���
		uObj.getCostSl(),        // ��ֵ
		uObj.getCostUnit(),      // �ַ���
		uObj.getId()             // ����
	);
}

int CostDetailAheadDAO::deleteById(const string& id)
{
	string sql = "DELETE FROM `wm_day_cost` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}


