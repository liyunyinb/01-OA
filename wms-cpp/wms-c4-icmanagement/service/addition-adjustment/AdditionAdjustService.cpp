#include "stdafx.h"
//#include "RemovalAdjustService.h"
#include "AdditionAdjustService.h"
//#include "../../dao/sample/SampleDAO.h"
//#include "../../dao/removal-adjustment/RemovalAdjustDAO.h"
#include "../../dao/addition-adjustment/AdditionAdjustDAO.h"
#include "../../domain/do/addition-adjustment/AdditionDO.h"
#include <list>


bool AdditionService::updateData(const AdditionBatchDTO::Wrapper& batchdto)
{
	// ��װDO����
	//AdditionDO data;
	//int cnt = 0;
	std::vector<bool> flags;
	flags.reserve(batchdto->dtoList->size()); // Ԥ����ռ�
	for (const auto& sub : *batchdto->dtoList)
	{
		if (!sub) continue; // ���������
		AdditionDO data;
		ZO_STAR_DOMAIN_DTO_TO_DO(data, sub, Id, id, Order_id, order_id, Goods_id, goods_id, Goods_name, goods_name);
		AdditionDAO dao;
		flags.push_back(dao.update(data));
	}
	return std::all_of(flags.begin(), flags.end(), [](bool success) { return success; });
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Order_id, order_id, Goods_id, goods_id, Goods_name, goods_name);
	// ִ�������޸�
	
}