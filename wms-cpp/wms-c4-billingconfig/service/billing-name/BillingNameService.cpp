#include "stdafx.h"
//#include "RemovalAdjustService.h"
#include "BillingNameService.h"
//#include "../../dao/sample/SampleDAO.h"
//#include "../../dao/removal-adjustment/RemovalAdjustDAO.h"
#include "../../domain/do/billing-name/BillingNameDO.h"
#include "../../dao/billing-name/BillingNameDAO.h"
#include <list>


bool BillingNameService::batchdeleteData(const BillingNameBatchDTO::Wrapper& batchdto)
{
	// ��װDO����
	//AdditionDO data;
	//int cnt = 0;
	std::vector<bool> flags;
	flags.reserve(batchdto->dtoList->size()); // Ԥ����ռ�
	for (const auto& sub : *batchdto->dtoList)
	{
		if (!sub) continue; // ���������
		BillingNameDO data;
		ZO_STAR_DOMAIN_DTO_TO_DO(data, sub, Id, id);
		BillingNameDAO dao;
		flags.push_back(dao.batchdelete(data));
	}
	return std::all_of(flags.begin(), flags.end(), [](bool success) { return success; });
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Order_id, order_id, Goods_id, goods_id, Goods_name, goods_name);
	// ִ�������޸�

}
list<BillingNameDO> BillingNameService::exportData(const BillingNameQuery::Wrapper& query)
{
	BillingNameDAO dao;

	list<BillingNameDO> result = dao.selectWithConditions(query);

	return result;

}
bool BillingNameService::batchinsertData(const BillingNamefileDTO::Wrapper& dto)
{
	
		BillingNameDO data;
		ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id,Cost_code,cost_code,Cost_name,cost_name,Cost_type_code,cost_type_code);
		BillingNameDAO dao;
		if (dao.batchinsert(data))
		{
			return true;
		}
		else
		{
			return false;
		}
	//}
	//return std::all_of(flags.begin(), flags.end(), [](bool success) { return success; });
}