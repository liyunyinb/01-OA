#include "stdafx.h"
#include"dao/loading-fee/LoadingFeeDAO.h"
#include"LoadingFeeMapper.h"

//��ѯ����������
std::string LoadingFeeDAO::queryConditionBuilder(const LoadingFeeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->Operator) {

		sqlCondition << " AND create_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->Operator.getValue(""));
	}
	if (query->operateDate_begin) {

		sqlCondition << " AND create_date BETWEEN ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->operateDate_begin.getValue(""));
	}
	if (query->operateDate_end) {

		sqlCondition << " AND ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->operateDate_end.getValue(""));
	}
	if (query->orderNo) {

		sqlCondition << " AND order_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->orderNo.getValue(""));
	}
	if (query->goods) {
		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods.getValue(""));
	}
	return sqlCondition.str();
}

//ͳ����������
uint64_t LoadingFeeDAO::count(const LoadingFeeQuery::Wrapper& query)
{
	SqlParams params;
	//ʹ����ͼ��ѯ
	string sql = "SELECT COUNT(*) FROM vw_loading_fee ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

//��ҳ��ѯ���װ����
std::list<LoadingFeeDO> LoadingFeeDAO::selectWithPage(const LoadingFeeQuery::Wrapper& query)
{
	SqlParams params;
	//ʹ����ͼ��ѯ
	string sql = "SELECT * FROM vw_loading_fee ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// ִ�в�ѯ
	LoadingFeeMapper mapper;
	return sqlSession->executeQuery<LoadingFeeDO>(sql, mapper, params);
}