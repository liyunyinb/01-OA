#pragma once
#ifndef _EXPENSETYPEQUERY_
#define _EXPENSETYPEQUERY_

/*****************************************************************************
	*  @COPYRIGHT NOTICE
	*  @Copyright (c) 2013, kato1
	*  @All rights reserved
	*  @file	 : ListgoodsController.cpp
	*  @version  : ver 1.0
	*  @author   : kato1
	*  @date     : 2025/2/26 17:04
	*  @brief    : brief
*****************************************************************************/

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ������������---�в�ѯ����
 */
class ExpenseTypeQuery : public PageQuery
{
	DTO_INIT(ExpenseTypeQuery, PageQuery);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("lis.field.id"));

	//��������---��ʼ
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("expense.field.create_name"));
	//��������---��ֹ
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("expense.field.create_by"));
	// �����˵�¼����
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("expense.field.create_date"));
	// ��λ����
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("expense.field.update_name"));
	// ������
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("expense.field.update_by"));

	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("expense.field.update_date"));

	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("expense.field.sys_org_code"));

	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("expense.field.sys_company_code"));

	API_DTO_FIELD_DEFAULT(String, cost_type_code, ZH_WORDS_GETTER("expense.field.cost_code"));

	API_DTO_FIELD_DEFAULT(String, cost_type_name, ZH_WORDS_GETTER("expense.field.cost_type_name"));

	API_DTO_FIELD_DEFAULT(String, cost_type_del, ZH_WORDS_GETTER("expense.field.cost_type_del"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPENSETYPEQUERY_
