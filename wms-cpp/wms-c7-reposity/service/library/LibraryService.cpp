/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "LibraryService.h"
#include "../../dao/library/LibraryDAO.h"

bool LibraryService::updateData(const ModifyLibraryDTO::Wrapper& dto)
{
	// ��װDO����
	LibraryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Code, bin_type_code, Name, bin_type_name);
	// ִ�������޸�
	LibraryDAO dao;
	return dao.update(data) == 1;
}

bool LibraryService::removeData(string id)
{
	LibraryDAO dao;
	return dao.deleteById(id) == 1;
}
