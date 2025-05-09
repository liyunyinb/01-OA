#pragma once
#ifndef _COST_DTO_
#define _COST_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//��������
class CostBaseDto : public oatpp::DTO
{
	DTO_INIT(CostBaseDto, DTO);
	DTO_FIELD(UInt64, id)= 1;//����
};
class GetCostDTO : public CostBaseDto
{
	DTO_INIT(GetCostDTO, CostBaseDto);
	DTO_FIELD(String, cost_code);//���ô���
	DTO_FIELD(String, cost_name);//��������
	DTO_FIELD(String, cost_type);//��������
	DTO_FIELD(String, create_name);//����������
	DTO_FIELD(String, create_date);//����ʱ��
};
class CostListDTO : public CostBaseDto
{
	
	DTO_INIT(CostListDTO, CostBaseDto);
	DTO_FIELD(String, cost_code)= "12345";//���ô���
	DTO_FIELD(String, cost_name)= "other";//��������
	DTO_FIELD(String, cost_type) = "othercost";//��������
	DTO_FIELD(String, create_name) = "Li";//����������
	DTO_FIELD(String, create_date) = "2024-9-13-09-13-45";//����ʱ��
	DTO_FIELD(String, update_name) = "Li";//�޸�����
	DTO_FIELD(String, update_date) = "2024-9-14-09-13-45";//�޸�ʱ��
};
//¼ȡ��������

//�޸ķ�������
class ModifyCostDTO : public CostBaseDto
{
	
	DTO_INIT(ModifyCostDTO, CostBaseDto);
	DTO_FIELD(String, cost_code) = "12345";//���ô���
	DTO_FIELD(String, cost_name) = "other";//��������
	DTO_FIELD(String, cost_type) = "othercost";//��������
	DTO_FIELD(String, update_name) = "Li";//�޸�����
	DTO_FIELD(String, update_date) = "2024-9-13-09-13-45";//�޸�ʱ��
};

//��ҳ���ݶ���
class CostListPageDTO : public PageDTO<CostListDTO::Wrapper>
{
	DTO_INIT(CostListPageDTO, PageDTO<CostListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_DTO_