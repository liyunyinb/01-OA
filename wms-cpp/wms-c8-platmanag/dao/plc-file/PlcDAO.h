#pragma once
/*
 @Author: tutu
 @Date: 2025/03/05 14:23:49
*/
#ifndef _PLC_DAO_
#define _PLC_DAO_
#include "BaseDAO.h"
#include "../../domain/do/plc-file/PlcFileDO.h"
#include "../../domain/query/plc-file/PlcFileQuery.h"

class PlcDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    PlcDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const PlcFileQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������PlcFileQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const PlcFileQuery::Wrapper& query, SqlParams& params);
	std::string getCurrentDateTime();
public:
	// ͳ����������
	uint64_t count(const PlcFileQuery::Wrapper& query);
	//��ҳ��ѯ����
	std::list<PlcBaseDO> selectWithPage(const PlcFileQuery::Wrapper& query);
	// ͨ��������ѯ����
	//std::list<PlcDO> selectByName(const string& name);
	// ͨ��ID��ѯ����
	PtrPlcDO selectById(string id);
	// ��������
	int insert(const PlcDO& iObj, string name, string realname, string orgcode, string companycode);
	// �޸�����
	int update(const PlcDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif
