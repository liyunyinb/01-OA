#pragma once
#ifndef _CHUWEI_DAO_
#define _CHUWEI_DAO_
#include "BaseDAO.h"
#include "../../domain/do/BinDO.h"
#include "../../domain/query/chuweidingyi/ChuWeiQuery.h"

/**
 * �����ݿ����ʵ��
 */
class ChuWeiDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    ChuWeiDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const ChuWeiQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������ChuWeiQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ChuWeiQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ChuWeiQuery::Wrapper& query);
	// ***��ҳ��ѯ����
	std::list<BinDO> selectWithPage(const ChuWeiQuery::Wrapper& query);
	// �޸�����
	int update(const BinDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_CHUWEI_DAO_
