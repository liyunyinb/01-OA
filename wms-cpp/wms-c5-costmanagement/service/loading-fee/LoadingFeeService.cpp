#include "stdafx.h"
#include"LoadingFeeService.h"
#include"../../dao/loading-fee/LoadingFeeDAO.h"


//��ҳ��ѯ���װ����
LoadingFeePageDTO::Wrapper LoadingFeeService::pageQueryLoadingFee(const LoadingFeeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LoadingFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	LoadingFeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<LoadingFeeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (LoadingFeeDO sub : result)
	{
		auto dto = LoadingFeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee, Fee, Operator, XOperator, operateDate, OperateDate, orderNo, OrderNo, goods, Goods, goodsName, GoodsName, goodsNum, GoodsNum, goodsWeight, GoodsWeight, feeRMB, FeeRMB, price, Price);
		pages->addData(dto);
	}
	return pages;
}


//�������װ����
list<LoadingFeeDO> LoadingFeeService::DownloadLoadingFee(const LoadingFeeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LoadingFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	LoadingFeeDAO dao;
	uint64_t count = dao.count(query);
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<LoadingFeeDO> result = dao.selectWithPage(query);
	return result;
}