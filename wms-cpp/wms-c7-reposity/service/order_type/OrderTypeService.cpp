#include "stdafx.h"
#include "OrderTypeService.h"
#include "../../dao/order_type/OrderTypeDAO.h"

//#include "../../lib-common/include/id/SnowFlake.h"

#include "../../lib-common/include/id/UuidFacade.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"

// ��ѯ�������������б�
OrderTypeNamePageDTO::Wrapper OrderTypeService::listName(const PageQuery::Wrapper& query)
{
	auto pages = OrderTypeNamePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	OrderTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		 return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrderTypeNameDO> result = dao.selectNameList();
	for (OrderTypeNameDO sub : result)
	{
		auto dto = OrderTypeNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, order_type_name, OrderTypeName);
		pages->addData(dto);
	}
	return pages;
}

// ��ҳ��ѯ��������
OrderTypePageDTO::Wrapper OrderTypeService::listAll(const OrderTypeQuery::Wrapper& query)
{
	auto pages = OrderTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	OrderTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();

	list<OrderTypeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (OrderTypeDO sub : result)
	{
		auto dto = OrderTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, order_type_code, OrderTypeCode, order_type_name, OrderTypeName);
		pages->addData(dto);
	}
	return pages;
}
// ��������
uint64_t OrderTypeService::saveData(const OrderTypeAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	OrderTypeAddDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, OrderTypeCode, order_type_code, OrderTypeName, order_type_name);
	// ���id
	//SnowFlake sf(1, 1);
	//data.setId(std::to_string(sf.nextId()));
	//UuidFacade uuidGenerator {};
	//data.setId(uuidGenerator.genUuid());
	data.setId(UuidFacade().genUuid());

	data.setCreateDate(SimpleDateTimeFormat::format());

	// ����������/�����˵�¼����/��������/������˾
	data.setCreateName(payload.getUsername());
	data.setCreateBy(payload.getRealname());
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());

	OrderTypeDAO dao;
	return dao.insert(data);
}