#include "stdafx.h"
#include"UnloadingFeeDAO.h"
#include"UnloadingFeeMapper.h"
#include <sstream>


//��ѯ����������
std::string UnloadingFeeDAO::queryConditionBuilder(const UnloadingFeeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->acceptor) {

		sqlCondition << " AND create_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acceptor.getValue(""));
	}
	if (query->acceptDate_begin) {

		sqlCondition << " AND create_date BETWEEN ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acceptDate_begin.getValue(""));
	}
	if (query->acceptDate_end) {

		sqlCondition << " AND ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acceptDate_end.getValue(""));
	}
	if (query->orderNo) {

		sqlCondition << " AND im_notice_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->orderNo.getValue(""));
	}
	if (query->goods) {
		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods.getValue(""));
	}
	return sqlCondition.str();
}

//ͳ����������
uint64_t UnloadingFeeDAO::count(const UnloadingFeeQuery::Wrapper& query)
{
	SqlParams params;
	//ʹ����ͼ��ѯ
	string sql = "SELECT COUNT(*) FROM vw_unloading_fee ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

//��ҳ��ѯ����
std::list<UnloadingFeeDO> UnloadingFeeDAO::selectWithPage(const UnloadingFeeQuery::Wrapper& query)
{
	SqlParams params;
	//ʹ����ͼ��ѯ
	string sql = "SELECT * FROM vw_unloading_fee ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// ִ�в�ѯ
	UnloadingFeeMapper mapper;
	return sqlSession->executeQuery<UnloadingFeeDO>(sql, mapper, params);
}