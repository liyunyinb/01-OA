#pragma once
#ifndef _INVENTORY_LIST_DAO_
#define _INVENTORY_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/overallInventory/InventorylistDo.h"
#include "../../domain/query/overallInventory/InventorylistQuery.h"
/**
 * �������ݿ����ʵ��
 */
class InventorylistDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const InventorylistQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const InventorylistQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<InventorylistDo> selectWithPage(const InventorylistQuery::Wrapper& query);
	// ��ѯ����---����ҳ
	std::list<InventorylistDo> selectWithConditions(const InventorylistQuery::Wrapper& query);
	// ͨ��������ѯ����
	//std::list<InventorylistDo> selectByName(const string& name);
	// ͨ��ID��ѯ����
	PtrInventorylistDo selectById(uint64_t id);
	// ��������
	uint64_t insert(const InventorylistDo& iObj);
	// �޸�����
	int update(const InventorylistDo& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_GOODS_MANAGE_DAO_
