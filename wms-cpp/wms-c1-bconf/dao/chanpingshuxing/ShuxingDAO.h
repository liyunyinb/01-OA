#pragma once
 
#ifndef _SHUXINGDAO_
#define _SHUXINGDAO_
#include "BaseDAO.h"
#include"../../domain/do/chanpingshuxing/ShuxingDO.h"
#include "ShuxingMapper.h"

#include "id/SnowFlake.h"
#include "id/UuidFacade.h"
class ShuxingDAO : public BaseDAO
{
private:
	 
public:
	// �޸�����
	int update(const ShuxingDO& sdo);
	//ɾ������
	int delete_data(const vector<ShuxingDO>& sdos);
	//��������
	std::list<ShuxingDO> upload_data();
	 //��������
	int load_data(const ShuxingDO& sdos);
};
#endif  