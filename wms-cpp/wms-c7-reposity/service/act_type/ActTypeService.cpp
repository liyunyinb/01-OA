#include "stdafx.h"
#include "ActTypeService.h"
#include "../../dao/act_type/ActTypeDAO.h"
//#include "../../lib-common/include/id/SnowFlake.h"
#include "../../lib-common/include/id/UuidFacade.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"

ActTypePageDTO::Wrapper ActTypeService::listAll(const ActTypeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ActTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	ActTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ActTypeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ActTypeDO sub : result)
    {
       auto dto = ActTypeDTO::createShared();
	   ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, act_type_code, ActTypeCode, act_type_name, ActTypeName, oper_step_code, OperStepCode);
	   //ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, act_type_code, ActTypeCode, act_type_name, ActTypeName, oper_step_code, OperStepCode);
	   pages->addData(dto);
    }
	return pages;
}

uint64_t ActTypeService::saveData(const ActTypeBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	ActTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ActTypeCode, act_type_code, ActTypeName, act_type_name, OperStepCode, oper_step_code);
	// ���id
	//SnowFlake sf(1, 1);
	//data.setId(std::to_string(sf.nextId()));
	UuidFacade uuidGenerator {};
	data.setId(uuidGenerator.genUuid());

	data.setCreateDate(SimpleDateTimeFormat::format());

	// ����������/�����˵�¼����/��������/������˾
	data.setCreateName(payload.getUsername());
	data.setCreateBy(payload.getRealname());
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());

	// ִ���������
	ActTypeDAO dao;
	return dao.insert(data);
}

