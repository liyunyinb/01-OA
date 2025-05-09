#pragma once

#ifndef  _COST_TYPE_QUERY_
#define  _COST_TYPE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CostTypeQuery : public PageQuery
{
    DTO_INIT(CostTypeQuery, PageQuery);
    DTO_FIELD(UInt64, id); // ����
    DTO_FIELD(String, cost_code);         // ���ô���
    DTO_FIELD(String, cost_name);         // ��������
    DTO_FIELD(String, cost_type);    // ��������
    DTO_FIELD(String, create_name);       // ����������
    DTO_FIELD(String, create_date);       // ��������
    DTO_FIELD(String, update_name);       // ����������
    DTO_FIELD(String, update_date);       // ��������
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_TYPE_QUERY_