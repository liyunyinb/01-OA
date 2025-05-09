#pragma once
#include "stdafx.h"
#include "ChuWeiService.h"
#include "../../dao/chuweidingyi/ChuWeiDao.h"
#include <oatpp/core/Types.hpp> 

// ��λ�б��ҳ���ݶ���
ChuWeiPageDTO::Wrapper ChuWeiService::listAll(const ChuWeiQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ChuWeiPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ChuWeiDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<BinDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (BinDO sub : result)
	{
		auto dto = ChuWeiDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, 
			id, Id, 
			bin_store, BinStore, 
			ku_wei_bian_ma, KuWeiBianMa, 
			ku_wei_tiao_ma, KuWeiTiaoMa, 
			ku_wei_lei_xing, KuWeiLeiXing,
			ku_wei_shu_xing, KuWeiShuXing,
			CHP_SHU_XING, CHPShuXing,
			suo_shu_ke_hu, SuoShuKeHu,
			ting_yong, TingYong,
			ming_xi, MingXi);
		pages->addData(dto);
	}
	return pages;
}

//�޸Ĵ�λ
bool ChuWeiService::updateData(const ChuWeiDTO::Wrapper& dto)
{
	// ��װDO����
	BinDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Id, id,
		BinStore, bin_store,
		SuoShuKeHu, suo_shu_ke_hu,
		KuWeiLeiXing, ku_wei_lei_xing,
		KuWeiShuXing, ku_wei_shu_xing,
		CHPShuXing, CHP_SHU_XING,
		ShangJiaCiXu, shang_jia_ci_xu,
		QuHuoCiXu, qu_huo_ci_xu,
		ZuiDaZhongLiang, zui_da_zhong_liang,
		ZuiDaTuoPan, zui_da_tuo_pan,
		Chang, chang,
		Kuan,kuan,
		Gao,gao,
		ZuiDaTiJi, zui_da_ti_ji,
		TingYong, ting_yong,
		MingXi, ming_xi,
		MingXi1, ming_xi1,
		MingXi2, ming_xi2, 
		MingXi3, ming_xi3,
		LORABqid, LORA_bqid,
		XNode, xnode,
		YNode, ynode,
		ZNode, znode);
	
	// ִ�������޸�
	ChuWeiDAO dao;
	return dao.update(data) == 1;
}

// ����idɾ����λ
bool ChuWeiService::removeData(string id)
{
	ChuWeiDAO dao;
	return dao.deleteById(id) == 1;
}

// ʵ������ɾ��
bool ChuWeiService::batchRemoveData(const oatpp::List<oatpp::String>& ids) {
	ChuWeiDAO dao;
	bool allSuccess = true;
	for (const auto& id : *ids) {
		if (dao.deleteById(id) != 1) {
			allSuccess = false;
		}
	}
	return allSuccess;
}