#include "stdafx.h"
#include "StoreService.h"
#include "../../dao/cangweitu/StoreDAO.h"

List<HuoQuCangWeiShuJuDTO::Wrapper> StoreService::listAll(const HuoQuCangWeiShuJuQuery::Wrapper& query)
{
	// �������ض���
	//auto pages = HuoQuCangWeiShuJuPageDTO::createShared();
	/*pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;*/

	//// ��ѯ����������
	//SampleDAO dao;
	//uint64_t count = dao.count(query);
	//if (count <= 0)
	//{
	//	return pages;
	//}

	//// ��ҳ��ѯ����
	//pages->total = count;
	//pages->calcPages();
	auto listdto = List<HuoQuCangWeiShuJuDTO::Wrapper>::createShared();
	
	StoreDAO dao;
	list<WvDO> result = dao.selectWithPage(query);
	for (auto sub : result) {
		auto dto = HuoQuCangWeiShuJuDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, bin_store, BinStore, bin_id, BinId, znode, Znode, xnode, Xnode, ynode, Ynode, colour, Colour, tincount, Tincount);
		//pages->addData(dto);
		listdto->push_back(dto);
	}
	return listdto;
	
	//return pages;
}