#include "Macros.h"
#include "enterpriseDAO.h"

//��ѯ����������
std::string enterpriseDAO::queryCondionBuilder(const enterprisePageQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << "WHERE 1=1";
	if (query->enterpriseClassificationCode.getValue({}) != "NULL") {
		sqlCondition << " AND `com_type_code`=?";
		SQLPARAMS_PUSH(params, " % s", std::string, query->enterpriseClassificationCode.getValue({}));
	}
	if (query->enterpriseClassificationName.getValue({}) != "NULL") {
		sqlCondition << " AND `com_type_name`=?";
		SQLPARAMS_PUSH(params, " % s", std::string, query->enterpriseClassificationName.getValue({}));
	}
	return sqlCondition.str();
}
//����
uint64_t enterpriseDAO::count(const enterprisePageQuery::Wrapper& query)
{
	string sql = "SELECT COUNT(*) FROM `ba_com_type`";
	SqlParams params;
	sql += queryCondionBuilder(query, params);
	return sqlSession->executeQueryNumerical(sql, params);
}
//������ҵ������Ϣ
uint64_t enterpriseDAO::insert(const EnterpriseDO& enterpriseInfo)
{
	uint64_t jvo;
	/*
	���redis
	����˫дһ����
	*/
	string sql = "INSERT INTO `ba_com_type` (`id`,`create_name`,`create_by`,`create_date`,`com_type_code` ,`com_type_name`, `com_type_del`) VALUES(?,?,?,?,?,?,?)";
	jvo = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", enterpriseInfo.getId(), enterpriseInfo.getCreateName(), enterpriseInfo.getCreateBy(), enterpriseInfo.getCreateDate(), enterpriseInfo.getComTypeCode(), enterpriseInfo.getComTypeName(), to_string(enterpriseInfo.getComTypeDel()));
	return jvo;
}
//��ҵ�������ݷ�ҳ��ѯ
std::list<EnterpriseDO> enterpriseDAO::selectWithPage(const enterprisePageQuery::Wrapper& query) {

	/*���redis*/
	string sql = "SELECT `com_type_code` , `com_type_name`,`com_type_del` FROM `ba_com_type`";
	SqlParams params;
	EnterpriseDoMapper1 mapper;
	sql += queryCondionBuilder(query, params);
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	auto res = sqlSession->executeQuery<EnterpriseDO>(sql, mapper, params);
	return res;

}

//��ȡ��ҵ������������
std::list<EnterpriseDO> enterpriseDAO::getEnterpriseName()
{
	EnterpriseDoMapper map;
	/*���redis*/
	string sql = "SELECT DISTINCT `com_type_name` FROM `ba_com_type`";
	return sqlSession->executeQuery<EnterpriseDO>(sql, map);
}
