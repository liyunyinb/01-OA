#pragma once

#ifndef _COST_DTO_
#define _COST_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ������ϸ¼����Ӧ����   dto�����൱����Ӧ�ֶ�
 */
/*
class CostDetailAddDTO : public oatpp::DTO
{

	DTO_INIT(CostDetailAddDTO, DTO);

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("cost.field.cus_code"));

	//����ķ������ƺͷ��ñ��벻̫ȷ������Ӧ����ƫ���ñ����
	// ��������
	API_DTO_FIELD_DEFAULT(String, cost_name, ZH_WORDS_GETTER("cost.field.cost_name"));

	// ���ñ���
	API_DTO_FIELD_DEFAULT(String, cost_code, ZH_WORDS_GETTER("cost.field.cost_code"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, cost_date, ZH_WORDS_GETTER("cost.field.cost_date"));

	// ԭ��
	API_DTO_FIELD_DEFAULT(String, cost_yj, ZH_WORDS_GETTER("cost.field.cost_yj"));

	// ����˰��
	API_DTO_FIELD_DEFAULT(String, cost_bhs, ZH_WORDS_GETTER("cost.field.cost_bhs"));

	// ˰��
	API_DTO_FIELD_DEFAULT(String, cost_se, ZH_WORDS_GETTER("cost.field.cost_se"));

	// ��˰��
	API_DTO_FIELD_DEFAULT(String, cost_hsj, ZH_WORDS_GETTER("cost.field.cost_hsj"));

	// ������Դ
	API_DTO_FIELD_DEFAULT(String, cost_ori, ZH_WORDS_GETTER("cost.field.cost_ori"));

	// ��ע
	API_DTO_FIELD_DEFAULT(String, beizhu, ZH_WORDS_GETTER("cost.field.beizhu"));

	// ״̬
	API_DTO_FIELD_DEFAULT(String, cost_sta, ZH_WORDS_GETTER("cost.field.cost_sta"));

	// �Ʒ�����
	API_DTO_FIELD_DEFAULT(String, cost_sl, ZH_WORDS_GETTER("cost.field.cost_sl"));

	// ������λ
	API_DTO_FIELD_DEFAULT(String, cost_unit, ZH_WORDS_GETTER("cost.field.cost_unit"));

};
*/

/**
 * ������ϸ��Ӧ����   dto�����൱����Ӧ�ֶ�
 */
class CostDetailBaseDTO : public oatpp::DTO
{
	DTO_INIT(CostDetailBaseDTO, DTO);

	// ΨһID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("cost.field.id"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("cost.field.create_name"));

	// �����˵�¼����
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("cost.field.create_by"));

	//��������
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("cost.field.create_date"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("cost.field.update_name"));

	//�����˵�¼����  
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("cost.field.update_by"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("cost.field.update_date"));

	// ��������  
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("cost.field.sys_org_code"));

	// ������˾ 
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("cost.field.sys_company_code"));

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("cost.field.cus_code"));

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("cost.field.cus_name"));

	// ���ñ���
	API_DTO_FIELD_DEFAULT(String, cost_code, ZH_WORDS_GETTER("cost.field.cost_code"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, cost_name, ZH_WORDS_GETTER("cost.field.cost_name"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, cost_date, ZH_WORDS_GETTER("cost.field.cost_date"));

	// ԭ��
	API_DTO_FIELD_DEFAULT(String, day_cost_yj, ZH_WORDS_GETTER("cost.field.cost_yj"));

	// ����˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_bhs, ZH_WORDS_GETTER("cost.field.cost_bhs"));

	// ˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_se, ZH_WORDS_GETTER("cost.field.cost_se"));

	// ��˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_hsj, ZH_WORDS_GETTER("cost.field.cost_hsj"));

	// ������Դ
	API_DTO_FIELD_DEFAULT(String, cost_ori, ZH_WORDS_GETTER("cost.field.cost_ori"));

	// ��ע
	API_DTO_FIELD_DEFAULT(String, beizhu, ZH_WORDS_GETTER("cost.field.beizhu"));

	// ״̬
	API_DTO_FIELD_DEFAULT(String, cost_sta, ZH_WORDS_GETTER("cost.field.cost_sta"));

	// �Ʒ�����
	API_DTO_FIELD_DEFAULT(String, cost_sl, ZH_WORDS_GETTER("cost.field.cost_sl"));

	// ������λ
	API_DTO_FIELD_DEFAULT(String, cost_unit, ZH_WORDS_GETTER("cost.field.cost_unit"));

	// �Ƿ����
	API_DTO_FIELD_DEFAULT(String, cost_js, ZH_WORDS_GETTER("cost.field.cost_js"));

	// ����id
	API_DTO_FIELD_DEFAULT(List<String>, ids, ZH_WORDS_GETTER("cost.field.ids"));

};



//����¼������ʱ�����DTO
class CostDetailAddDTO : public oatpp::DTO
{
	DTO_INIT(CostDetailAddDTO, DTO);

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("cost.field.cus_code"));

	// ���ñ���
	API_DTO_FIELD_DEFAULT(String, cost_code, ZH_WORDS_GETTER("cost.field.cost_code"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, cost_date, ZH_WORDS_GETTER("cost.field.cost_date"));

	// ԭ��
	API_DTO_FIELD_DEFAULT(String, day_cost_yj, ZH_WORDS_GETTER("cost.field.cost_yj"));

	// ����˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_bhs, ZH_WORDS_GETTER("cost.field.cost_bhs"));

	// ˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_se, ZH_WORDS_GETTER("cost.field.cost_se"));

	// ��˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_hsj, ZH_WORDS_GETTER("cost.field.cost_hsj"));

	// ������Դ
	API_DTO_FIELD_DEFAULT(String, cost_ori, ZH_WORDS_GETTER("cost.field.cost_ori"));

	// ��ע
	API_DTO_FIELD_DEFAULT(String, beizhu, ZH_WORDS_GETTER("cost.field.beizhu"));

	// ״̬
	API_DTO_FIELD_DEFAULT(String, cost_sta, ZH_WORDS_GETTER("cost.field.cost_sta"));

	// �Ʒ�����
	API_DTO_FIELD_DEFAULT(String, cost_sl, ZH_WORDS_GETTER("cost.field.cost_sl"));

	// ������λ
	API_DTO_FIELD_DEFAULT(String, cost_unit, ZH_WORDS_GETTER("cost.field.cost_unit"));

};

//�����޸�����ʱ�����DTO
class CostDetailEditDTO : public oatpp::DTO
{
	DTO_INIT(CostDetailEditDTO, DTO);

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("cost.field.cus_code"));

	// ���ñ���
	API_DTO_FIELD_DEFAULT(String, cost_code, ZH_WORDS_GETTER("cost.field.cost_code"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, cost_date, ZH_WORDS_GETTER("cost.field.cost_date"));

	// ԭ��
	API_DTO_FIELD_DEFAULT(String, day_cost_yj, ZH_WORDS_GETTER("cost.field.cost_yj"));

	// ����˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_bhs, ZH_WORDS_GETTER("cost.field.cost_bhs"));

	// ˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_se, ZH_WORDS_GETTER("cost.field.cost_se"));

	// ��˰��
	API_DTO_FIELD_DEFAULT(String, day_cost_hsj, ZH_WORDS_GETTER("cost.field.cost_hsj"));

	// ������Դ
	API_DTO_FIELD_DEFAULT(String, cost_ori, ZH_WORDS_GETTER("cost.field.cost_ori"));

	// ��ע
	API_DTO_FIELD_DEFAULT(String, beizhu, ZH_WORDS_GETTER("cost.field.beizhu"));

	// ״̬
	API_DTO_FIELD_DEFAULT(String, cost_sta, ZH_WORDS_GETTER("cost.field.cost_sta"));

	// �Ʒ�����
	API_DTO_FIELD_DEFAULT(String, cost_sl, ZH_WORDS_GETTER("cost.field.cost_sl"));

	// ������λ
	API_DTO_FIELD_DEFAULT(String, cost_unit, ZH_WORDS_GETTER("cost.field.cost_unit"));

	// ΨһID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("cost.field.id"));

};



/**
 * ������ϸ�б��ҳ�������
 */
class CostDetailListPageDTO : public PageDTO<CostDetailBaseDTO::Wrapper>
{
	DTO_INIT(CostDetailListPageDTO, PageDTO<CostDetailBaseDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_DTO_

