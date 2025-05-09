/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "OrderTypesService.h"
#include "../../dao/ordertypes/OrderTypesDAO.h"

bool OrderTypesService::updateData(const ModifyOrderTypeDTO::Wrapper& dto)
{
	// ��װDO����
	OrderTypesDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Code, order_type_code, Name, order_type_name);
	// ִ�������޸�
	OrderTypesDAO dao;
	return dao.update(data) == 1;
}

bool OrderTypesService::removeData(string id)
{
	OrderTypesDAO dao;
	return dao.deleteById(id) == 1;
}
