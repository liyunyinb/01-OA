#pragma once
#ifndef _CHECK_SERVICE_
#define _CHECK_SERVICE_
#include <list>
#include "domain/vo/check/CheckVO.h"
#include "domain/query/check/CheckQuery.h"
#include "domain/dto/check/CheckDTO.h"
#include "domain/do/check/CheckDO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CheckService
{
public:
    // ��ҳ��ѯ��������
    CheckPageDTO::Wrapper listAll(const CheckQuery::Wrapper &query);

    // ���ɵ�������
    list<CheckDO> exportData(const CheckQuery::Wrapper &query);
};

#endif // !_CHECK_SERVICE_
