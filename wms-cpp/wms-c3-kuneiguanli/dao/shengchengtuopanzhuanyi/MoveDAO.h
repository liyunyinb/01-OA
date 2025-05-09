#pragma once
#ifndef _MOVE_DAO_
#define _MOVE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/MoveDO.h"
#include "../../domain/query/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class MoveDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    BaseDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<MoveDO> selectWithPage(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query);
		
};
#endif // !_MOVE_DAO_