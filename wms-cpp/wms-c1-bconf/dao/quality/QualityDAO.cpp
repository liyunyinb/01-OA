#include "stdafx.h"
#include "QualityDAO.h"
#include "QualityMapper.h"
#include <sstream>
#include <ctime>
#include <string>
#include <chrono>
#include <iomanip>

// C++11�����ϰ汾���ã��̰߳�ȫ�ҿ�ƽ̨
std::string getCurrentDateTimeString() {
	// ��ȡ��ǰʱ���
	auto now = std::chrono::system_clock::now();

	// ת��Ϊtime_t���ͣ�C���ʱ�䣩
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);

	// ת��Ϊ����ʱ��ṹ�壨�̰߳�ȫ�汾��
	std::tm tm_struct{};

	// ƽ̨�����Դ���
#if defined(_WIN32) || defined(_WIN64)
	localtime_s(&tm_struct, &now_time);    // Windows��ȫ�汾
#else
	localtime_r(&now_time, &tm_struct);     // Linux/macOS��ȫ�汾
#endif

	// ʹ��std::put_time��ʽ��ʱ��
	std::stringstream ss;
	ss << std::put_time(&tm_struct, "%Y-%m-%d %H:%M:%S");

	return ss.str();
}


inline std::string QualityDAO::queryConditionBuilder(const QualityQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->qm_qa_name) {

		sqlCondition << " AND `qm_qa_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->qm_qa_name.getValue(""));
	}
	if (query->qm_qa_code) {

		sqlCondition << " AND qm_qa_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->qm_qa_code.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t QualityDAO::count(const QualityQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_qm_qa";

	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<QualityDO> QualityDAO::selectWithPage(const QualityQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,qm_qa_code,qm_qa_name FROM ba_qm_qa ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// ִ�в�ѯ
	QualityMapper mapper;
	return sqlSession->executeQuery<QualityDO>(sql, mapper, params);
}

std::list<QualityDO> QualityDAO::selectByName(const string& name)
{
	string sql = "SELECT id,qm_qa_code,qm_qa_name FROM ba_qm_qa WHERE `qm_qa_name` LIKE CONCAT('%',?,'%')";
	QualityMapper mapper;
	return sqlSession->executeQuery<QualityDO>(sql, mapper, "%s", name);
}

std::list<QualityDO> QualityDAO::selectByCode(const string& code)
{
	string sql = "SELECT id,qm_qa_code,qm_qa_name FROM ba_qm_qa WHERE `qm_qa_code` LIKE CONCAT('%',?,'%')";
	QualityMapper mapper;
	return sqlSession->executeQuery<QualityDO>(sql, mapper, "%s", code);
}

uint64_t QualityDAO::insert(const QualityDO& iObj)
{
	string sql = "INSERT INTO `ba_qm_qa` (`id`, `qm_qa_code`, `qm_qa_name`,`create_name`,`create_by`,`create_date`,`sys_org_code`,`sys_company_code`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	UuidFacade uid(1);
	string _uid = uid.genUuid();
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", _uid, iObj.getCode(), iObj.getName(), iObj.getCreate_Name(), iObj.getCreate_By(), getCurrentDateTimeString(), iObj.getSys_Org_Code(), iObj.getSys_Company_Code());
}

int QualityDAO::update(const QualityDO& uObj)
{
	string sql = "UPDATE `ba_qm_qa` SET `qm_qa_name`=?, `qm_qa_code`=?, `update_name`=?,`update_by`=?,`update_date`=?,`sys_org_code`=?,`sys_company_code`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", uObj.getName(), uObj.getCode(), uObj.getUpdate_Name(), uObj.getUpdate_By(), getCurrentDateTimeString(), uObj.getSys_Org_Code(), uObj.getSys_Company_Code(), uObj.getId());
}
