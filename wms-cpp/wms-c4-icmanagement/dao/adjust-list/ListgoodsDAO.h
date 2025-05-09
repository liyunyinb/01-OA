#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/3/4 11:08

*/
#ifndef _LIST_GOODS_DAO_
#define _LIST_GOODS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/adjust-list/wm_to_up_goodsDO.h"
#include "../../domain/query/adjust-list/ListgoodsQuery.h"

/**
 * �������ݿ����ʵ��
 */
class ListGoodsDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    ListGoodsDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const ListgoodsQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������ListgoodsQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const ExportDataQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const ExportDataQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<Wm_To_Up_GoodsDO> selectWithPage(const ExportDataQuery::Wrapper& query);
	// ��ѯ����---����ҳ
	std::list<Wm_To_Up_GoodsDO> selectWithConditions(const ExportDataQuery::Wrapper& query);
};
#endif // !_LIST_GOODS_DAO_
