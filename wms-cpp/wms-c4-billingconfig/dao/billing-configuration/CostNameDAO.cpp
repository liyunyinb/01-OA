#include "stdafx.h"
#include "CostNameDAO.h"
#include "CostNameMapper.h"
#include <sstream>
#include <chrono>
#include <ctime>
#include <string>
#include <algorithm>
#include "id/UuidFacade.h"

std::string removeDashes(const std::string& input) {
    std::string result;
    std::remove_copy(input.begin(), input.end(), std::back_inserter(result), '-');
    return result;
}

std::string getCurrentTimeAsString() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
    return std::string(buffer);
}

// ��ѯ����������
std::string CostNameDAO::queryConditionBuilder(const CostNameQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    if (query->id) {
        sqlCondition << " AND id = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
    }
    if (query->cost_code) {
        sqlCondition << " AND cost_code = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cost_code.getValue(""));
    }
    if (query->cost_name) {
        sqlCondition << " AND cost_name = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cost_name.getValue(""));
    }
    if (query->cost_type_code) {
        sqlCondition << " AND cost_type_code = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cost_type_code.getValue(""));
    }
    if (query->create_name) {
        sqlCondition << " AND create_name = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->create_name.getValue(""));
    }
    if (query->create_by) {
        sqlCondition << " AND create_by = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->create_by.getValue(""));
    }
    if (query->create_date) {
        sqlCondition << " AND create_date = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->create_date.getValue(""));
    }
    if (query->update_name) {
        sqlCondition << " AND update_name = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->update_name.getValue(""));
    }
    if (query->update_by) {
        sqlCondition << " AND update_by = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->update_by.getValue(""));
    }
    if (query->update_date) {
        sqlCondition << " AND update_date = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->update_date.getValue(""));
    }
    if (query->sys_org_code) {
        sqlCondition << " AND sys_org_code = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->sys_org_code.getValue(""));
    }
    if (query->sys_company_code) {
        sqlCondition << " AND sys_company_code = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->sys_company_code.getValue(""));
    }

    return sqlCondition.str();
}

uint64_t CostNameDAO::count(const CostNameQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM `ba_cost` ";
    // ������ѯ����
    sql += queryConditionBuilder(query, params);
    // ִ�в�ѯ
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CostNameDO> CostNameDAO::selectAll(const CostNameQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT `id`, `cost_code`, `cost_name`, `cost_type_code`, `create_name`, `create_by`, `create_date`, `update_name`, `update_by`, `update_date`, `sys_org_code`, `sys_company_code` FROM `ba_cost`";

    sql += queryConditionBuilder(query, params);
    

    CostNameMapper mapper;

    return sqlSession->executeQuery<CostNameDO>(sql, mapper, params);
}

// ��ҳ��ѯ����
std::list<CostNameDO> CostNameDAO::selectWithPage(const CostNameQuery::Wrapper& query)
{
    
    SqlParams params;
    std::string sql = "SELECT `id`, `cost_code`, `cost_name`, `cost_type_code`, `create_name`, `create_by`, `create_date`, `update_name`, `update_by`, `update_date`, `sys_org_code`, `sys_company_code` FROM `ba_cost`";

    sql += queryConditionBuilder(query, params);
    
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    
    CostNameMapper mapper;
    
    return sqlSession->executeQuery<CostNameDO>(sql, mapper, params);
}





// ��������
int CostNameDAO::insert(const CostNameDO& iObj, const PayloadDTO& payload)
{

    UuidFacade uf(0);
    std::string id = removeDashes(uf.genUuid());


    std::string date = getCurrentTimeAsString();
    std::string sql = "INSERT INTO `ba_cost` (`id`,`cost_code`, `cost_name`, `cost_type_code`, `create_name`, `create_by`, `create_date`,  `sys_org_code`, `sys_company_code`) VALUES (?,?, ?, ?, ?, ?, ?, ?, ?)";
    // ִ�в���������������²����ID
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s", id,
        iObj.getCostCode(), iObj.getCostName(), iObj.getCostTypeCode(),
        payload.getUsername(), payload.getRealname(), date,
        payload.getOrgcode(), payload.getCompanycode());
}

// �޸�����
int CostNameDAO::update(const CostNameDO& uObj, const PayloadDTO& payload)
{
    std::string date = getCurrentTimeAsString();
    std::string sql = "UPDATE `ba_cost` SET `cost_code` = ?, `cost_name` = ?, `cost_type_code` = ?,  `update_name` = ?, `update_by` = ?, `update_date` = ?, `sys_org_code` = ?, `sys_company_code` = ? WHERE `id` = ?";
    //UPDATE `ba_cost` SET `cost_code` = "2001" , `cost_name` = "�����̼Ʒ�11" , `cost_type_code` = "01" ,  `update_name` = "111" , `update_by` = "000" , `update_date` ="2017-10-18 06:49:27" , `sys_org_code` = "10" , `sys_company_code` = "A9" WHERE `id` = "4028804072df34cc0174a95c083d0016";
    // ִ�и��²�������������Ӱ�������
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s",
        uObj.getCostCode(), uObj.getCostName(), uObj.getCostTypeCode(),
        payload.getUsername(), payload.getRealname(), date,
        payload.getOrgcode(), payload.getCompanycode(), uObj.getId());
}


