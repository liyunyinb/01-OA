#include "stdafx.h"
#include "CostTypeService.h"
#include "../../dao/CostType/CostTypeDAO.h"

CostListPageDTO::Wrapper CostTypeService::listAll(const CostTypeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CostListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	CostTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CostTypeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (CostTypeDO sub : result)
	{
		auto dto = CostListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, cost_code, Cost_code, cost_name, Cost_name, cost_type, Cost_type, create_name, Create_name, create_date, Create_date, update_name, Update_name, update_date, Update_date);
		pages->addData(dto);
	}
	return pages;
}

CostListDTO::Wrapper CostTypeService::getById(uint64_t id)
{
	// ��ѯ����
	CostTypeDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = CostListDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, cost_code, Cost_code, cost_name, Cost_name, cost_type, Cost_type, create_name, Create_name, create_date, Create_date, update_name, Update_name, update_date, Update_date);
	return dto;
}

uint64_t CostTypeService::saveData(const GetCostDTO::Wrapper& dto)
{
	// ��װDO����
	CostTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Cost_code, cost_code, Cost_name, cost_name, Cost_type, cost_type, Create_name, create_name, Create_date, create_date);
	// ִ���������
	CostTypeDAO dao;
	return dao.insert(data);
}

// ����payload��Ϣ��䣨fangtang����
uint64_t CostTypeService::saveData(const GetCostDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	CostTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Cost_code, cost_code, Cost_name, cost_name, Cost_type, cost_type);

	// ����create_date
	std::time_t now = std::time(nullptr);
	std::tm tm_now = *std::localtime(&now);
	std::stringstream ssCreateTime;
	ssCreateTime << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S ");
	//����ʱ��
	data.setCreate_date(ssCreateTime.str());

	// ����������
	data.setCreate_by(payload.getUsername());

	// �������ǳ�realname
	data.setCreate_name(payload.getRealname());

	// ������˾������
	data.setSysCompanyCode(payload.getCompanycode());
	data.setSysOrgCode(payload.getOrgcode());

	// ִ���������
	CostTypeDAO dao;


	return dao.insert(data);
}

bool CostTypeService::updateData(const ModifyCostDTO::Wrapper& dto)
{
	// ��װDO����
	CostTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Cost_code, cost_code, Cost_name, cost_name, Cost_type, cost_type, Update_name, update_name, Update_date, update_date);
	// ִ�������޸�
	CostTypeDAO dao;
	return dao.update(data) == 1;
}
bool CostTypeService::removeData(uint64_t id)
{
	CostTypeDAO dao;
	return dao.deleteById(id) == 1;
}

