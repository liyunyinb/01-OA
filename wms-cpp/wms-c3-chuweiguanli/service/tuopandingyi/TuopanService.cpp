#include "stdafx.h"
#include "TuopanService.h"
#include "../../dao/tuopandingyi/TuopanDAO.h"
#include "../../Macros.h"


TuopanPageDTO::Wrapper TuopanService::listAll(const TuopanQuery::Wrapper& query)
{
	//�������ض���
	auto pages = TuopanPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	TuopanDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) 
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<TuopanDO> result = dao.selectWithPage(query);

	//��DOת����DTO
	for (TuopanDO sub : result)
	{
		auto dto = TuopanDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, tin_id, TinId,tin_sort, TinSort, bin_id, BinId, tin_status, TinStatus, bpm_status, BpmStatus, sys_org_code, SysOrgCode, sys_company_code, SysCompanyCode);
		pages->addData(dto);
	}
	return pages;
}

bool TuopanService::updateData(const TuopanDTO::Wrapper& dto)
{
	// ��װDO����
	TuopanDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Id,id,TinId,tin_id,TinSort,tin_sort,BinId,bin_id,TinStatus,tin_status,BpmStatus,bpm_status, SysOrgCode,sys_org_code, SysCompanyCode,sys_company_code );
	// ִ�������޸�
	TuopanDAO dao;
	return dao.update(data) == 1;
}

bool TuopanService::removeData(oatpp::List<oatpp::String>& idlist)
{
	TuopanDAO dao;
	bool flag = true;

	//����idlistִ������ɾ������
	for (auto id : *idlist) 
	{
		flag &= dao.deleteById(id);
	}
	return  flag;
}
