#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/dto/ordertypes/OrderTypesDTO.h" 

/**
 * ����ʵ��
 */
class OrderTypesService
{
public:
	// �޸�����
	bool updateData(const ModifyOrderTypeDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id);;
};

#endif // !_SAMPLE_SERVICE_

