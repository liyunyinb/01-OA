#include "stdafx.h"
#include "BaGoodsTypeService.h"
#include "../../dao/bagoodstype/BaGoodsTypeDAO.h"


BaGoodsTypePageDTO::Wrapper BaGoodsTypeService::listAll(const BaGoodsTypeQuery::Wrapper& query) {
	//���ض���
	auto pages = BaGoodsTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	BaGoodsTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	//DO to DTO
	list<BaGoodsTypeDO> result = dao.selectWithPage(query);
	for (BaGoodsTypeDO sub : result) {
		auto dto = BaGoodsTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,id,Id,goods_type_code,GoodsTypeName,goods_type_name, GoodsTypeName);
		pages->addData(dto);
	}
	return pages;
}