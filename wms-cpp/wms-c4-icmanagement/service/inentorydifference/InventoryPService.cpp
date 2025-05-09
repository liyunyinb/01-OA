#include "stdafx.h"
#include "InventoryPService.h"
#include "../../dao/inentorydifference/InventoryPDAO.h"
#include "../../domain/dto/inentorydifference/InventoryPDTO.h"

InventoryPPageDTO::Wrapper InventoryPService::listAll(const InventoryPquery::Wrapper& query)
{
	// �������ض���
	auto pages = InventoryPPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	InventoryPDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<InventoryPDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (InventoryPDO sub : result)
	{
		auto dto = InventoryPDtailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, stt_name, Stt_name, stt_date, Stt_date, bin_id, Bin_id, tin_id, Tin_id, goods_id, Goods_id, goods_name, Goods_name, goods_qua, Goods_qua, goods_unit, Goods_unit, goods_pro_data, Goods_pro_data, stt_qua, Stt_qua, cus_code, Cus_code, cus_id, Cus_id, stt_sta, Stt_sta);
		pages->addData(dto);
	}
	return pages;
}

uint64_t InventoryPService::saveData(const InventoryPAddDTO::Wrapper& dto)
{
	// ��װDO����
	InventoryPDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Stt_name, stt_name, Stt_date, stt_date, Bin_id, bin_id, Tin_id, tin_id, Goods_id, goods_id, Goods_name, goods_name, Goods_qua, goods_qua, Goods_unit, goods_unit, Goods_pro_data, goods_pro_data, Stt_qua, stt_qua, Cus_code, cus_code, Cus_id, cus_id, Stt_sta, stt_sta);
	// ִ���������
	InventoryPDAO dao;
	return dao.insert(data);
}
