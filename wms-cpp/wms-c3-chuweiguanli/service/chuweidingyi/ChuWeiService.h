#pragma once
#ifndef _CHUWEI_SERVICE_
#define _CHUWEI_SERVICE_
#include <list>
#include "domain/vo/chuweidingyi/ChuWeiVO.h"
#include "domain/query/chuweidingyi/ChuWeiQuery.h"
#include "domain/dto/chuweidingyi/ChuWeiDTO.h"
#include <oatpp/core/Types.hpp>

/**
 * ��λ����ʵ��
 */
class ChuWeiService
{
public:
	// ��ҳ��ѯ��������
	ChuWeiPageDTO::Wrapper listAll(const ChuWeiQuery::Wrapper& query);
	// �޸�����
	bool updateData(const ChuWeiDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id);
	// ����ɾ������
	bool batchRemoveData(const oatpp::List<oatpp::String>& ids);
};

#endif // !_CHUWEI_SERVICE_

