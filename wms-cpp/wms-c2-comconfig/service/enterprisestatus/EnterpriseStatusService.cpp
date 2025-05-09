#include "stdafx.h"
#include "EnterpriseStatusService.h"
#include "../../dao/enterprisestatus/EnterpriseStatusDAO.h"
#include "domain/do/enterprisestatus/EnterpriseStatusDO.h"
#include "domain/dto/md-cus-other/EnterpriseDTO.h"
//#include "..\..\..\work\Macros.h"
#include "./Macros.h"

//��ҵ״̬�İ�������ѯ��ҳ
EnterpriseListPageDTO::Wrapper EnterpriseStatusService::queryAll(const EnterpriseQuery::Wrapper& query)
{
	// �������ض���
	auto pages = EnterpriseListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	EnterpriseStatusDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<EnterpriseStatusDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (EnterpriseStatusDO sub : result)
	{
		auto dto = EnterpriseListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, enterpriseid, kehuzhuangtai_code, enterprisename, kehuzhuangtai_name,status, cus_sta_del);
		

		pages->addData(dto);
	}
	return pages;
}


//��ҵ״̬�����˵���ֻ�����ú�ͣ������״̬
EnterpriseStatusListDTO::Wrapper EnterpriseStatusService::queryForList()
{
	EnterpriseStatusDAO dao;
	auto result= EnterpriseStatusListDTO::createShared();
	result->items = oatpp::List<EnterpriseStatusDTO::Wrapper>::createShared();
	list<EnterpriseStatusListDO> dolist = dao.selectForList();
	uint64_t count = dao.count1();
	
	if (count <= 0)
	{
		return result;
	}
	for (EnterpriseStatusListDO sub : dolist)
	{
		auto dto = EnterpriseStatusListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, statusonlyid, id, enterpriseid, kehuzhuangtai_code, enterprisename, kehuzhuangtai_name);
		result->items->push_back(dto);
	}

	return result;
}