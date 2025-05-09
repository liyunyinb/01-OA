#include "stdafx.h"
#include "BaGoodsTypeService.h"
#include "../../dao/bagoodstype/BaGoodsTypeDAO.h"


BaGoodsTypeNamePageDTO::Wrapper BaGoodsTypeService::listAll(const BaGoodsTypeQuery::Wrapper& query) {
	//���ض���
	auto pages = BaGoodsTypeNamePageDTO::createShared();
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
		auto dto = BaGoodsTypeNameDTO::createShared();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id);
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, create_name, CreateName, create_by, CreateBy, create_date, CreateDate);
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, update_name, UpdateName, update_by, UpdateBy, update_date, UpdateDate);
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, sys_org_code, SysOrgCode, sys_company_code, SysCompanyCode);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,/* goods_type_code, GoodsTypeCode,*/ goods_type_name, GoodsTypeName);
		pages->addData(dto);
	}
	return pages;
}