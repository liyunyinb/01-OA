#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _GOODS_MANAGE_DAO_
#define _GOODS_MANAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/review-stt/wm_stt_in_goodsDO.h"
#include "../../domain/query/review-stt/ReviewSttQuery.h"

/**
 * �������ݿ����ʵ��
 */
class ReviewSttDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    GoodsManageDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const GoodsDiffPostQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������GoodsDiffPostQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ReviewSttQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ReviewSttQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<Wm_Stt_In_GoodsDO> selectWithPage(const ReviewSttQuery::Wrapper& query);
	// ��ѯ����---����ҳ
	std::list<Wm_Stt_In_GoodsDO> selectWithConditions(const ReviewSttQuery::Wrapper& query);
	// ͨ��������ѯ����
	//std::list<Wm_Stt_In_GoodsDO> selectByName(const string& name);
	// ͨ��ID��ѯ����
	PtrWm_Stt_In_GoodsDO selectById(uint64_t id);
	// ��������
	uint64_t insert(const Wm_Stt_In_GoodsDO& iObj);
	// �޸�����
	int update(const Wm_Stt_In_GoodsDO& uObj, const PayloadDTO& payload);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_GOODS_MANAGE_DAO_
