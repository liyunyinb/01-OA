 #include "stdafx.h"
#include "ComdegService.h"
#include "../lib-common/include/id/UuidFacade.h"
#include "dao/comdegfig/ComdegfigDAO.h"
#include <SimpleDateTimeFormat.h>

ComdegPageDTO::Wrapper ComdegService::listAll(const ComdegQuery::Wrapper& query) {
	// �������ض���
	auto pages = ComdegPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ComdegfigDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ComdegfigDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ComdegfigDO sub : result)
	{
		auto dto = ComdegListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, degname, DegName, degcode, DegCode, degdel, DegDel,id,Id);
		pages->addData(dto);
	}
	return pages;
}

uint64_t ComdegService::saveData(const ComdegAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ����������
	UuidFacade uf(1);
	std::string formattedTime = SimpleDateTimeFormat::format();;
	// ��װDO����
	ComdegfigDO data;
	data.setId(uf.genUuid());
	data.setCreateName(payload.getRealname());
	data.setCreateBy(payload.getUsername());
	data.setCreateDate(formattedTime);
	data.setCompanyCode(payload.getCompanycode());
	data.setOrgCode(payload.getOrgcode());
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,DegName, degname, DegCode, degcode, DegDel, degdel);
	// ִ���������
	ComdegfigDAO dao;
	return dao.insert(data);
}