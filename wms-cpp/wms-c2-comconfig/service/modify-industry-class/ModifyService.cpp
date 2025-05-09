#include "stdafx.h"
#include "ModifyService.h"
#include "../../dao/modify-industry-class/ModifyDAO.h"

bool ModifyService::updateData(const ModifyDTO::Wrapper& dto)
{
	// ��װDO����
	ModifyDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Classfl_code, classfl_code, Classfl_name, classfl_name, Classfl_del, classfl_del, Id, id);
	// ִ�������޸�
	ModifyDAO dao;
	return dao.update(data) == 1;
}

