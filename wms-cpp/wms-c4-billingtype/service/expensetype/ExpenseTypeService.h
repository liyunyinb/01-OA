#pragma once

#ifndef _EXPENSETYPESERVICE_
#define _EXPENSETYPESERVICE_
#include <list>



#include "domain/query/expensetype/ExpenseTypeQuery.h"


/**
 * �������ͷ���ʵ��
 */
class ExpenseTypeService
{
public:
	std::string exportData(const ExpenseTypeQuery::Wrapper& query);
};

#endif // !_EXPENSETYPESERVICE_
