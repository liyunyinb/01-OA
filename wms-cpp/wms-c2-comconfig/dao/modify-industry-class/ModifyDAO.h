#pragma once
#ifndef _MODIFY_DAO_
#define _MODIFY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/modify-industry-class/ModifyDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class ModifyDAO : public BaseDAO
{

public:	
	// �޸�����
	int update(const ModifyDO& uObj);
};
#endif // !_MODIFY_DAO_
