#pragma once
#ifndef _MOVEGOODS_DAO_
#define _MOVEGOODS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/MoveGoodsDO.h"
#include "../../domain/query/kuneizhuanyi/MoveGoodsQuery.h"


class MoveGoodsDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params);
public:
	// ͨ��ID��ѯת��������ϸ����
	PtrMoveGoodsDO selectDetailedById(const oatpp::String  queryID);
	// ͨ��ID��ѯת�����񵼳�����
	std::vector<std::vector<string>> selectDownLoadById(const vector<string>& ids);
	// ͨ��IDɾ������
	int deleteById(const vector<string> id,const string usrName);
};
#endif // !_MOVEGOODS_DAO_