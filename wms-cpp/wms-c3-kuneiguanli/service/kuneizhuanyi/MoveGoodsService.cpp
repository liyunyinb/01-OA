

#include "stdafx.h"
#include "MoveGoodsService.h"
#include "../../dao/kuneizhuanyi/MoveGoodsDAO.h"

MoveGoodsDetailedDTO::Wrapper MoveGoodsService::getDetailedById(const oatpp::String queryID)
{
	// ��ѯ����
	MoveGoodsDAO dao;
	auto res = dao.selectDetailedById(queryID);
	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = MoveGoodsDetailedDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res,
		goodsID, GoodsId, goodsName, GoodsName, nowNum, GoodsQua,
		moveNum, BaseGoodscount, produceDate, GoodsProData, toProduceDate, ToGoodsProData,
		goodsUnit, GoodsUnit, cusCode, CusCode, cusName, CusName,
		toCusCode, ToCusCode, toCusName, ToCusName,
		tinFrom, TinFrom, tinTo, TinId, binFrom, BinFrom,
		binTo, BinTo, moveStatus, MoveSta
	);
	return dto;
}

bool  MoveGoodsService::removeMoveGoods(const vector<string> id,const string usrName)
{
	MoveGoodsDAO dao;
	return dao.deleteById(id,usrName) == 1;
}

vector<vector<string>> MoveGoodsService::getDownLoadById(const vector<string>& ids)
{
	MoveGoodsDAO dao;
	return dao.selectDownLoadById(ids);
}














































































