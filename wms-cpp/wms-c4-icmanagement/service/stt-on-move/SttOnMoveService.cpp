#include "SttOnMoveService.h"
#include "../../dao/stt-on-move/SttOnMoveDAO.h"

SttOnMovePageDTO::Wrapper SttOnMoveService::listAll(const SttOnMoveQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SttOnMovePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SttOnMoveDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	// ��ѯ�õ�DO�б�
	list<SttOnMoveDO> result = dao.selectWithPage(query);
	// ��DOת��ΪDTO
	for (SttOnMoveDO res : result)
	{
		auto dto = SttOnMoveListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, res, last_move, LastMove, cktype, Kuctype, bin_id, KuWeiBianMa, tin_id, BinId, cus_code, CusCode, cus_name, ZhongWenQch, goods_id, GoodsId, goods_qua, GoodsQua, goods_name, ShpMingCheng, goods_pro_data, GoodsProData, goods_save_date, BzhiQi, base_unit, GoodsUnit, stt_sta, SttSta,id,Id);
		pages->addData(dto);
	}
	return pages;
}

SttOnMoveDetailDTO::Wrapper SttOnMoveService::getById(const string& id)
{
	// ��ѯ����
	SttOnMoveDAO dao;
	auto res = dao.selectWithId(id);
	if (!res)
		return nullptr;

	// ��ѯ���doת��dto
	auto dto = SttOnMoveDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, last_move, LastMove, cktype, Kuctype, bin_id, KuWeiBianMa, tin_id, BinId, cus_code, CusCode, cus_name, ZhongWenQch, goods_id, GoodsId, goods_qua, GoodsQua, goods_name, ShpMingCheng, goods_pro_data, GoodsProData, goods_save_date, BzhiQi, base_unit, GoodsUnit, stt_sta, SttSta, id, Id);
	return dto;
}
