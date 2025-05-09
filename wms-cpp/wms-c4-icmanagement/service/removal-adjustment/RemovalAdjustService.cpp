#include "stdafx.h"
#include "RemovalAdjustService.h"
//#include "../../dao/sample/SampleDAO.h"
#include "../../dao/removal-adjustment/RemovalAdjustDAO.h"


RemovalPageDTO::Wrapper RemovalService::listAll(const RemovalQuery::Wrapper& query)
{
	//�������ʵ�ַ�ҳ��ѯ�ķ���
	// �������ض���
	auto pages = RemovalPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RemovalDAO dao;
	//���DAO�Ǻ����ݿ⽻���Ķ���
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;//��ѯ���ж���������
	pages->calcPages();//����ж���ҳ
	list<RemovalDO> result = dao.selectWithPage(query);
	// ��DOת����DTO ˵����һ��������Ӧ
	//��һ��������ҳ��ľ�����Ϣ����DO�Ž�ȥ
	for (RemovalDO sub : result)
	{
		auto dto = RemovalListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub, id, Id,order_id,Order_id,goods_id,Goods_id,goods_name,Goods_name);
		pages->addData(dto);
	
	}
	//��ҳ����Ϣ���ظ�Controller
	return pages;
}
RemovalDetailDTO::Wrapper RemovalService::getById(const oatpp::String& id)
{
	oatpp::String oatStr = id;
	std::string stdStr(oatStr->c_str());
	RemovalDAO dao;
	auto res = dao.selectById(stdStr);
	auto dto = RemovalDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto,res,id,Id,order_id,Order_id,goods_id,Goods_id,goods_name,Goods_name,goods_qua, Goods_qua);

	return dto;
}
RemovalDetailPageDTO::Wrapper RemovalService::getdetail(const RemovalQuery::Wrapper& query)
{
	auto pages = RemovalDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	RemovalDAO dao;
	//���DAO�Ǻ����ݿ⽻���Ķ���
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	pages->total = count;//��ѯ���ж���������
	pages->calcPages();//����ж���ҳ
	list<RemovalDO> result = dao.selectdetail(query);
	for (RemovalDO sub : result)
	{
		auto dto = RemovalDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, order_id, Order_id, goods_id, Goods_id, goods_name, Goods_name, goods_qua, Goods_qua);
		pages->addData(dto);

	}
	//��ҳ����Ϣ���ظ�Controller
	return pages;
}
bool RemovalService::updateData(const RemovalListDTO::Wrapper & dto)
{
	// ��װDO����
	RemovalDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,Id,id,Order_id,order_id,Goods_id,goods_id,Goods_name,goods_name);
	// ִ�������޸�
	RemovalDAO dao;
	return dao.update(data) == 1;
}