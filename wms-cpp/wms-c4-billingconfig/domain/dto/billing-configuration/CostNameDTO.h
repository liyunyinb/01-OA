#pragma once

#ifndef _COST_NAME_DTO_
#define _COST_NAME_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CostBaseDto : public oatpp::DTO
{
    DTO_INIT(CostBaseDto, DTO);
    DTO_FIELD(String, id)="4028804072df34cc0174a95c083d0016"; // ����

    
};

class CostNameDTO : public CostBaseDto
{
    DTO_INIT(CostNameDTO, CostBaseDto);
    DTO_FIELD(String, cost_code)="2001";         // ���ô���
    
    DTO_FIELD(String, cost_name) = ZH_WORDS_GETTER("cost.cost_name.Billed_per_pallet");    // ��������
    DTO_FIELD(String, cost_type_code)="01";    // �������ʹ���
    DTO_FIELD(String, create_name)="admin";       // ����������
    DTO_FIELD(String, create_by)="admin";         // �����˵�¼����
    DTO_FIELD(String, create_date)="2017-10-18 06:49:08";     // ��������
    DTO_FIELD(String, update_name)="admin";       // ����������
    DTO_FIELD(String, update_by)="admin";         // �����˵�¼����
    DTO_FIELD(String, update_date)="2017-10-18 06:49:27";     // ��������
    DTO_FIELD(String, sys_org_code)="A04";      // ��������
    DTO_FIELD(String, sys_company_code)="A04";  // ������˾
};



class CostListDTO : public oatpp::DTO
{
    DTO_INIT(CostListDTO, DTO);
    DTO_FIELD(List<CostNameDTO::Wrapper>, rows) = {};
public:
    void addData(CostNameDTO::Wrapper one)
    {
        this->rows->push_back(one);
    }

};




class CostListPageDTO : public PageDTO<CostNameDTO::Wrapper>
{
    DTO_INIT(CostListPageDTO, PageDTO<CostNameDTO::Wrapper>);
};

class CostAddDTO : public oatpp::DTO
{
    DTO_INIT(CostAddDTO, DTO);
    DTO_FIELD(String, cost_code) = "2001";           // ���ô���
    DTO_FIELD(String, cost_name) = ZH_WORDS_GETTER("cost.cost_name.Billed_per_pallet");       // ��������
    DTO_FIELD(String, cost_type_code) = "01";    // �������ʹ���
    //DTO_FIELD(String, create_name) = "admin";       // ����������
    //DTO_FIELD(String, create_by) = "admin";         // �����˵�¼����
    //DTO_FIELD(String, create_date) = "2017-10-18 06:49:08";     // ��������
    //DTO_FIELD(String, sys_org_code) = "A04";      // ��������
    //DTO_FIELD(String, sys_company_code) = "A04";  // ������˾
};

class CostModifyDTO : public CostBaseDto
{
    DTO_INIT(CostModifyDTO, CostBaseDto);
    DTO_FIELD(String, cost_code) = "2001";           // ���ô���
    DTO_FIELD(String, cost_name) = ZH_WORDS_GETTER("cost.cost_name.Billed_per_pallet");;         // ��������
    DTO_FIELD(String, cost_type_code) = "01";    // �������ʹ���
    //DTO_FIELD(String, update_name) = "admin";       // ����������
    //DTO_FIELD(String, update_by) = "admin";         // �����˵�¼����
    //DTO_FIELD(String, update_date) = "2017-10-18 06:49:27";     // ��������
    //DTO_FIELD(String, sys_org_code) = "A04";      // ��������
    //DTO_FIELD(String, sys_company_code) = "A04";  // ������˾
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_NAME_DTO_