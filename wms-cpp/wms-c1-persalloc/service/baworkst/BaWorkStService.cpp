#include "stdafx.h"
#include "BaWorkStService.h"
#include "../../dao/baworkst/BaWorkStDAO.h"
#include "../include/id/UuidFacade.h"


BaWorkStPageDTO::Wrapper BaWorkStService::listAll(const BaWorkStQuery::Wrapper& query) {
	//���ض���
	auto pages = BaWorkStPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	BaWorkStDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	//DO to DTO
	list<BaWorkStDO> result = dao.selectWithPage(query);
	for (BaWorkStDO sub : result) {
		auto dto = BaWorkStDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub,id,Id);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub,create_name,CreateName,create_by,CreateBy,create_date,CreateDate);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub,update_name,UpdateName,update_by,UpdateBy, update_date, UpdateDate);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub,sys_org_code, SysOrgCode,sys_company_code, SysCompanyCode);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub,work_sta_code, WorkStaCode,work_sta_name,WorkStaName);
		pages->addData(dto);
	}
	return pages;
}
// ��������
string BaWorkStService::saveData(const BaWorkStAddDTO::Wrapper& dto,  const PayloadDTO& payload) {
	BaWorkStDO data;
	UuidFacade uuid;
	data.setId(uuid.genUuid());
	data.setCreateName(payload.getUsername());
	data.setCreateBy(payload.getUsername());
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CreateName, create_name, CreateBy, create_by/*, CreateDate, create_date*/);
	/*ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, SysOrgCode, sys_org_code, SysCompanyCode, sys_company_code);*/
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, WorkStaCode, work_sta_code, WorkStaName, work_sta_name);
	BaWorkStDAO dao;
	if (dao.insert(data) != 0) {
		return data.getId();
	}
	else {
		return "";
	}
}

// �޸�����
string BaWorkStService::updateData(const BaWorkStChangeDTO::Wrapper& dto, const PayloadDTO& payload) {
	BaWorkStDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id);
	std::string id = dto->id.getValue({});
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, UpdateName, update_name, UpdateBy, update_by/*, UpdateDate, update_date*/);
	data.setUpdateName(payload.getUsername());
	data.setUpdateBy(payload.getUsername());
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, SysOrgCode, sys_org_code, SysCompanyCode, sys_company_code);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, WorkStaCode, work_sta_code, WorkStaName, work_sta_name);
	BaWorkStDAO dao;
	if (dao.update(data) == 1) {
		return data.getId();
	}
	else {
		return "";
	}
}