#include "stdafx.h"
#include "PisService.h"
#include "../../dao/ba_qm_sta/PisDAO.h"

PisPageDTO::Wrapper PisService::listAll(const PisQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PisPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PisDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PisDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PisDO sub : result)
	{
		auto dto = PisDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, code, Code, name, Name);
		pages->addData(dto);
	}
	return pages;
}

std::string PisService::saveData(const PisAddDTO::Wrapper& dto,const PayloadDTO& payload)
{
	// ��װDO����
	PisDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name);
	data.setCreate_Name(payload.getUsername());
	data.setCreate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	// ִ���������
	PisDAO dao;
	return dao.insert(data);
}

bool PisService::updateData(const PisDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	PisDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, Code, code);
	data.setCreate_Name(payload.getUsername());
	data.setCreate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	// ִ�������޸�
	PisDAO dao;
	return dao.update(data) >= 0;
}

//PisDTO::Wrapper PisService::getByCode(const string& code)
//{
//	// ��ѯ����
//	PisDAO dao;
//	auto res = dao.selectByCode(code);
//
//	// û�в�ѯ������
//	 if (!res)
//		return nullptr;
//
//	// ��ѯ������ת����DTO
//	auto dto = PisDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, code, Code, sta, Sta);
//	return dto;
//}
//
//
//PisDTO::Wrapper PisService::getBySta(const string& sta)
//{
//	// ��ѯ����
//	PisDAO dao;
//	auto res = dao.selectBySta(sta);
//
//	// û�в�ѯ������
//	if (!res)
//		return nullptr;
//
//	// ��ѯ������ת����DTO
//	auto dto = PisDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, code, Code, sta, Sta);
//	return dto;
//}

