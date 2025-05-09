#include "stdafx.h"
#include"UnloadingFeeService.h"
#include"../../dao/unloading-fee/UnloadingFeeDAO.h"
#include"../../domain/dto/unloading-fee/UnloadingFeeDTO.h"
#include"../../domain/query/unloading-fee/UnloadingFeeQuery.h"

//��ҳ��ѯ���ж����
UnloadingFeePageDTO::Wrapper UnloadingFeeService::pageQueryUnloadingFee(const UnloadingFeeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = UnloadingFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	UnloadingFeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<UnloadingFeeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (UnloadingFeeDO sub : result)
	{
		auto dto = UnloadingFeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee, Fee, acceptor, Acceptor, acceptDate, AcceptDate, orderNo, OrderNo, goods, Goods, goodsName, GoodsName, unloadingNum, UnloadingNum, unloadingWeight, UnloadingWeight, feeRMB, FeeRMB, price, Price);
		pages->addData(dto);
	}
	return pages;
}

//�������ж����
list<UnloadingFeeDO> UnloadingFeeService::DownloadUnloadingFee(const UnloadingFeeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = UnloadingFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	UnloadingFeeDAO dao;
	uint64_t count = dao.count(query);
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	//����Ҫ����������
	list<UnloadingFeeDO> result = dao.selectWithPage(query);
	return result;
}