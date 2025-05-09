#pragma once
#include "SqlSession.h"
#include "domain/GlobalInclude.h"
#include "../lib-oatpp/include/oatpp/core/data/mapping/type/Vector.hpp"
#include "../wms-c7-reposity/dao/BusstyDAO.h"
#include "../arch-demo/Macros.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../wms-c7-reposity/domain/dto/BusstyDTO.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class BusstyService
{
public:
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	bool removedata(const uint64_t ID);
	// ҵ�����͵���
	std::list<ba_buss_typeDO> leadout();
	//ҵ�����͵���
	bool leadin(std::vector<std::string> v);
};
