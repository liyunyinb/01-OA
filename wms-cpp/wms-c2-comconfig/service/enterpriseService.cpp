#include "Macros.h"
#include "enterpriseService.h"
#include "./domain//do/enterpriseDO.h"
#include "domain/do/enterpriseDO.h"
#include "dao/enterprisedao/enterpriseDAO.h"
//��������
uint64_t enterpriseService::saveData(const addEnterpriseDTO::Wrapper& enterpriseInfo, const PayloadDTO& payload) {
	uint64_t jvo;
	//����DAO�������
	EnterpriseDO data;

	enterpriseDAO dao;

	//��ȡ��ǰʱ��
	auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);

	char tem_time_str[20];
	std::strftime(tem_time_str, sizeof tem_time_str, "%Y-%m-%d %H:%M:%S", std::localtime(&now_time));
	std::string currentTime(tem_time_str);
	//ֵ��������
	ZO_STAR_DOMAIN_DTO_TO_DO(data, enterpriseInfo, ComTypeCode, enterpriseClassificationCode, ComTypeName, enterpriseClassificationName, ComTypeDel, stopInfo);
	data.setId(payload.getId());
	data.setCreateName(payload.getUsername());
	//data.setCreateDate(currentTime);
	data.setCreateDate(SimpleDateTimeFormat().format());
	data.setCreateBy(payload.getUsername());
	data.setCreateName(payload.getRealname());

	jvo = dao.insert(data);
	return jvo;
}

//��ҳ��ѯ
enterprisePageDTO::Wrapper  enterpriseService::listAll(const enterprisePageQuery::Wrapper& query) {
	auto jvo = enterprisePageDTO::createShared();
	jvo->pageIndex = query->pageIndex;
	jvo->pageSize = query->pageSize;

	enterpriseDAO dao;
	jvo->total = dao.count(query);
	if (jvo->total <= 0)  return jvo;
	jvo->calcPages();

	auto res = dao.selectWithPage(query);

	//ƴ������
	for (const auto& i : res)
	{
		auto data = addEnterpriseDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(data, i, enterpriseClassificationCode, ComTypeCode, enterpriseClassificationName, ComTypeName, stopInfo, ComTypeDel);
		jvo->addData(data);
	}

	return jvo;
}
//��ȡ��ҵ����
enterpriseNameDTO::Wrapper enterpriseService::getEnterpriseName()//const PageQuery::Wrapper& query
{
	auto res = enterpriseNameDTO::createShared();
	enterpriseDAO dao;
	auto ans = dao.getEnterpriseName();
	for (const auto& i : ans) {
		auto data = i.getComTypeName();
		res->addData(data);
	}
	return res;
}