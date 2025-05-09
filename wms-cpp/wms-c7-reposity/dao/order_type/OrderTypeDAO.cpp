#include "stdafx.h"
#include "OrderTypeDAO.h"
#include "OrderTypeMapper.h"
#include <sstream>

std::string OrderTypeDAO::queryConditionBuilder(const OrderTypeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->order_type_code)
	{
        sqlCondition << " AND order_type_code = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->order_type_code.getValue(""));
	}
	if (query->order_type_name)
	{
        sqlCondition << " AND order_type_name = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->order_type_name.getValue(""));
	}
	return sqlCondition.str();
}


// ��ѯ����
uint64_t OrderTypeDAO::count(const PageQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(id) FROM ba_order_type ";
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

uint64_t OrderTypeDAO::count(const OrderTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(id) FROM ba_order_type ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}
// ��ѯ�������������б�
std::list<OrderTypeNameDO> OrderTypeDAO::selectNameList()
{
	SqlParams params;
	string sql = "SELECT id,order_type_name FROM ba_order_type ";
	OrderTypeNameMapper mapper;
    return sqlSession->executeQuery<OrderTypeNameDO>(sql, mapper, params);
}
// ��ҳ��ѯ����
std::list<OrderTypeDO> OrderTypeDAO::selectWithPage(const OrderTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,order_type_code,order_type_name FROM ba_order_type ";
	sql += queryConditionBuilder(query, params);
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	OrderTypeMapper mapper;
	return sqlSession->executeQuery<OrderTypeDO>(sql, mapper, params);
}
// ��������
uint64_t OrderTypeDAO::insert(const OrderTypeAddDO& iObj)
{
	string sql = "INSERT INTO `ba_order_type` (`id`,`create_date` ,`order_type_code`, `order_type_name`, `create_name`, `create_by`, `sys_org_code`, `sys_company_code`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreateDate(), iObj.getOrderTypeCode(), iObj.getOrderTypeName(), iObj.getCreateName(), iObj.getCreateBy(), iObj.getSysOrgCode(), iObj.getSysCompanyCode());

}