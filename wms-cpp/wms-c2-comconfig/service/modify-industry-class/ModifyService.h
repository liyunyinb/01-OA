#pragma once
#ifndef _MODIFY_SERVICE_
#define _MODIFY_SERVICE_

#include <list>
#include "domain/dto/modify-industry-class/ModifyDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ModifyService
{
public:
	// �޸�����
	bool updateData(const ModifyDTO::Wrapper& dto);
	
};

#endif // !_MODIFY_SERVICE_
