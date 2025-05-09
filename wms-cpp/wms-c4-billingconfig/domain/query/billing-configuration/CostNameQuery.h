#pragma once

#ifndef _COST_NAME_QUERY_
#define _COST_NAME_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CostNameQuery : public PageQuery
{
    DTO_INIT(CostNameQuery, PageQuery);
    DTO_FIELD(String, id); // ����
    DTO_FIELD(String, cost_code);         // ���ô���
    DTO_FIELD(String, cost_name);         // ��������
    DTO_FIELD(String, cost_type_code);    // �������ʹ���
    DTO_FIELD(String, create_name);       // ����������
    DTO_FIELD(String, create_by);         // �����˵�¼����
    DTO_FIELD(String, create_date);     // ��������
    DTO_FIELD(String, update_name);       // ����������
    DTO_FIELD(String, update_by);         // �����˵�¼����
    DTO_FIELD(String, update_date);     // ��������
    DTO_FIELD(String, sys_org_code);      // ��������
    DTO_FIELD(String, sys_company_code);  // ������˾
    DTO_FIELD(Int32, page);               // ��ҳҳ��
    DTO_FIELD(Int32, size);               // ��ҳ��С
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_NAME_QUERY_