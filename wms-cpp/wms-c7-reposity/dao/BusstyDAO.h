#pragma once
#include "BaseDAO.h"
#include "../lib-oatpp/include/oatpp/core/data/mapping/type/Vector.hpp"
#include "domain/GlobalInclude.h"
#include "../arch-demo/Macros.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../wms-c7-reposity/domain/do/ba_buss_typeDO.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class BusstyDAO : public BaseDAO
{
public:
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	int deleteByID(uint64_t ID);
	//ҵ�����͵���
	std::list<ba_buss_typeDO> leadout();
	//ҵ�����͵���
	int leadin(ba_buss_typeDO data);
	
};
