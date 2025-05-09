#include "stdafx.h"
#include "ProductService.h"
#include "../../dao/goodcatgory/ProductDAO.h"
#include"../../domain/do/goodcategory/ProductDO.h"
#include"../../domain/dto/goodcategory/ProductDTO.h"

uint64_t ProductService::saveCategory(const ProductListDTO::Wrapper& dto)
{
	
	// ��װDO����
	ProductDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,PID,pid,Categoryname, categoryname, Categorylevel, categorylevel, Categorynum, categorynum,Topnode,topnode);
	// ִ��������Ʒ��Ŀ
	ProductDAO dao;
	return dao.save(data);
}

bool ProductService::updateCategory(const ProductListDTO::Wrapper& dto)
{
	// ��װDO����
	ProductDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PID, pid, Categoryname, categoryname, Categorylevel, categorylevel, Categorynum, categorynum, Topnode, topnode);
	// ִ���޸���Ʒ��Ŀ
	ProductDAO dao;
	return dao.update(data) == 1;
}

bool ProductService::removeCategory(const std::string& id)
{
	//ִ��ɾ����Ʒ��Ŀ
	ProductDAO dao;
	return dao.remove(id) == 1;
}
