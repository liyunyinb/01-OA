#pragma once

#ifndef _XIANGXIXINXISERVICE_
#define _XIANGXIXINXISERVICE_
#include <list>
#include "../../domain/dto/chuweidingyi/xiangxixinxiDTO.h"
#include "../../domain/query/chuweidingyi/xiangxixinxiQUERY.h"
 


class xiangxixinxiSERVICE
{
public:

	// ͨ��ID��ѯ��������
	xiangxixinxiDTO::Wrapper getById(const xiangxixinxiQUERY::Wrapper& id);

	//ͨ��ID���ز�������, �����ļ�·��
	string daochuchuweiCONTROLLER(oatpp::List<oatpp::String>&  chuwei);

	//���봢λ
	std::string addchuweiSERVICE(const  xiangxixinxiDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_XIANGXIXINXISERVICE_