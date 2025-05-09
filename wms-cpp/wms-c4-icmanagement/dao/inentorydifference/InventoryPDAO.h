#pragma once
#ifndef _INVENTORYP_DAO_
#define _INVENTORYP_DAO_
#include "BaseDAO.h"
#include "../../domain/do/inentorydifference/InventoryPDO.h"
#include "../../domain/query/inentorydifference/InventoryPquery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class InventoryPDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    InventoryPDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const InventoryPQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������InventoryPQuery����̬������ѯ�� ����ز���
	//************************************
	inline std::string queryConditionBuilder(const InventoryPquery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const InventoryPquery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<InventoryPDO> selectWithPage(const InventoryPquery::Wrapper& query);
	// ��������
	uint64_t insert(const InventoryPDO& iObj);
};
#endif // !_INVENTORYP_DAO_
