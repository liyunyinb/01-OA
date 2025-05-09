#pragma once
#ifndef _ENTERPRISE_QUERY_
#define _ENTERPRISE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ��ҳ��ѯ����
 */
class CompanyQuery : public PageQuery
{
	DTO_INIT(CompanyQuery, PageQuery);
	// ��ҵ�û�����
	API_DTO_FIELD_DEFAULT(String, id, "com_type_code");
	//��ҵ�û�����
	API_DTO_FIELD_DEFAULT(String, name, "com_type_name");
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_ENTERPRISE_QUERY_