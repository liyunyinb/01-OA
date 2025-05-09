#pragma once
// ��Ҳ 2025 02 28
#ifndef _WORKSTATE_DAO_
#define _WORKSTATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/workstate/WorkStateDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class WorkStateDAO : public BaseDAO
{
public:
	// ͨ��IDɾ������
	int deleteById(string id);

	std::list<WorkStateDO> selectAll();
	std::list<WorkStateDO> selectWork();
	int insert(WorkStateDO tmp);

};
#endif // !_WORKSTATE_DAO_
