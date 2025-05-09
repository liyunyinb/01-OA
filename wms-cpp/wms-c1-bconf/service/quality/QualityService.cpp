#include "stdafx.h"
#include "QualityService.h"
#include "dao/quality/QualityDAO.h"

QualityPageDTO::Wrapper QualityService::getData(const QualityQuery::Wrapper& query)
{
	// �������ض���
	auto pages = QualityPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	QualityDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<QualityDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (QualityDO sub : result)
	{
		auto dto = QualityListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, qm_qa_name, Name, qm_qa_code, Code);
		pages->addData(dto);
	}
	return pages;
}

bool QualityService::InsertData(const QualityAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	QualityDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, qm_qa_name, Code, qm_qa_code);
	// ��װ�޸�����
	data.setCreate_Name(payload.getUsername());
	data.setCreate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	// ִ�������޸�
	QualityDAO dao;
	return dao.insert(data);
}

QualityDetailDTO::Wrapper QualityService::getByCode(const string& code)
{
	QualityDAO dao;
	// ��ѯ���������ļ�¼
	list<QualityDO> result = dao.selectByCode(code);

	// ���û���ҵ���������ؿն���
	if (result.empty()) {
		return QualityDetailDTO::createShared(); // ����һ���յ�DTO
	}

	auto dto = QualityDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result.front(), qm_qa_name, Name, qm_qa_code, Code);

	return dto;
}

QualityDetailDTO::Wrapper QualityService::getByName(const string& name)
{
	QualityDAO dao;
	// ��ѯ���������ļ�¼
	list<QualityDO> result = dao.selectByName(name);

	// ���û���ҵ���������ؿն���
	if (result.empty()) {
		return QualityDetailDTO::createShared(); // ����һ���յ�DTO
	}

	auto dto = QualityDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result.front(), qm_qa_name, Name, qm_qa_code, Code);

	return dto;
}

bool QualityService::updateData(const QualityListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	QualityDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, qm_qa_name, Code, qm_qa_code, Id, id);
	// ��װ�޸�����
	data.setUpdate_Name(payload.getUsername());
	data.setUpdate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	// ִ�������޸�
	QualityDAO dao;
	return dao.update(data) == 1;
}
