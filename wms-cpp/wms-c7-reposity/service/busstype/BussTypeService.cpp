#include "stdafx.h"
#include "BussTypeService.h"
#include "../../dao/busstype/BussTypeDAO.h"
#include "../../../lib-common/include/id/SnowFlake.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"


// ��ҳ��ѯ��������
BussTypeListPageDTO::Wrapper BussTypeService::listAll(const BussTypeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = BussTypeListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	BussTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<BussTypeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (BussTypeDO sub : result)
	{
		auto dto = BussTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,buss_type_code, BussTypeCode, buss_type_name, BussTypeName, buss_type_text, BussTypeText);
		pages->addData(dto);
	}
	return pages;
}
// ͨ��ҵ������Name��ѯ����
BussTypeListPageDTO::Wrapper BussTypeService::getByName(string name)
{
	auto pages = BussTypeListPageDTO::createShared();
	// ��ѯ����
	BussTypeDAO dao;
	auto res = dao.selectByName(name);
	// û�в�ѯ������
	if (res.empty())
		return nullptr;
	// ��DOת����DTO
	for (BussTypeDO sub : res)
	{
		auto dto = BussTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buss_type_code, BussTypeCode, buss_type_name, BussTypeName, buss_type_text, BussTypeText);
		pages->addData(dto);
	}
	return pages;
}
// ͨ��ҵ������Code��ѯ����
BussTypeListPageDTO::Wrapper BussTypeService::getByCode(string code)
{
	auto pages = BussTypeListPageDTO::createShared();
	// ��ѯ����
	BussTypeDAO dao;
	auto res = dao.selectByCode(code);
	// û�в�ѯ������
	if (res.empty())
		return nullptr;
	// ��DOת����DTO
	for (BussTypeDO sub : res)
	{
		auto dto = BussTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buss_type_code, BussTypeCode, buss_type_name, BussTypeName, buss_type_text, BussTypeText);
		pages->addData(dto);
	}
	return pages;
}
// ͨ��ҵ������Text��ѯ����
BussTypeListPageDTO::Wrapper BussTypeService::getByText(string text)
{
	auto pages = BussTypeListPageDTO::createShared();
	// ��ѯ����
	BussTypeDAO dao;
	auto res = dao.selectByText(text);
	// û�в�ѯ������
	if (res.empty())
		return nullptr;
	// ��DOת����DTO
	for (BussTypeDO sub : res)
	{
		auto dto = BussTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buss_type_code, BussTypeCode, buss_type_name, BussTypeName, buss_type_text, BussTypeText);
		pages->addData(dto);
	}
	return pages;
}
// ��������
uint64_t BussTypeService::saveData(const BussTypeAddDTO::Wrapper& dto)
{
	// ��װDO����
	BussTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,BussTypeCode,buss_type_code,BussTypeName,buss_type_name,BussTypeText ,buss_type_text);
	//���id
	SnowFlake sf(1, 1);
	data.setId(std::to_string(sf.nextId()));
	//��Ӵ�������
	data.setCreateDate(SimpleDateTimeFormat::format());
	// ִ���������
	BussTypeDAO dao;
	return dao.insert(data);
}
// �޸�����
bool BussTypeService::updateData(const BussTypeAddDTO::Wrapper& dto)
{
	// ��װDO����
	BussTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id,id,BussTypeCode, buss_type_code, BussTypeName, buss_type_name, BussTypeText, buss_type_text);
	// ִ�������޸�
	BussTypeDAO dao;
	return dao.update(data) == 1;
}