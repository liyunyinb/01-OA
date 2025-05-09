#pragma once

#ifndef _COST_DTO_
#define _COST_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ������ϸ������Ӧ����   dto�����൱����Ӧ�ֶ�
 */
class CostDetailBaseDTO : public oatpp::DTO
{
	DTO_INIT(CostDetailListPageDTO, DTO);

	// ΨһID
	API_DTO_FIELD_DEFAULT(String, id , ZH_WORDS_GETTER("cost.field.id"));

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("cost.field.cus_code"));

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("cost.field.cus_name"));

	// ���ñ���
	API_DTO_FIELD_DEFAULT(String, cost_code, ZH_WORDS_GETTER("cost.field.cost_code"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, cost_name, ZH_WORDS_GETTER("cost.field.cost_name"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, cost_data, ZH_WORDS_GETTER("cost.field.cost_data"));

	// ������Դ
	API_DTO_FIELD_DEFAULT(String, cost_ori, ZH_WORDS_GETTER("cost.field.cost_ori"));

	// ��ע
	API_DTO_FIELD_DEFAULT(String, beizhu, ZH_WORDS_GETTER("cost.field.beizhu"));

	// ״̬
	API_DTO_FIELD_DEFAULT(String, cost_sta, ZH_WORDS_GETTER("cost.field.cost_sta"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("cost.field.create_name"));

	//��������
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("cost.field.create_date"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("cost.field.update_name"));

	// ԭ��
	API_DTO_FIELD_DEFAULT(String, cost_yj, ZH_WORDS_GETTER("cost.field.cost_yj"));

	// ����˰��
	API_DTO_FIELD_DEFAULT(String, cost_bhs, ZH_WORDS_GETTER("cost.field.cost_bhs"));

	// ˰��
	API_DTO_FIELD_DEFAULT(String, cost_se, ZH_WORDS_GETTER("cost.field.cost_se"));

	// ��˰��
	API_DTO_FIELD_DEFAULT(String, cost_hsj, ZH_WORDS_GETTER("cost.field.cost_hsj"));

	// �Ʒ�����
	API_DTO_FIELD_DEFAULT(String, cost_sl, ZH_WORDS_GETTER("cost.field.cost_sl"));

	// ������λ
	API_DTO_FIELD_DEFAULT(String, cost_unit, ZH_WORDS_GETTER("cost.field.cost_unit"));

	// �Ƿ����
	API_DTO_FIELD_DEFAULT(String, cost_js, ZH_WORDS_GETTER("cost.field.cost_js"));


};


/**
 * ������ϸ¼����Ӧ����   dto�����൱����Ӧ�ֶ�
 */
class CostDetailAddDTO : public CostDetailBaseDTO
{
	DTO_INIT(CostDetailAddDTO, CostDetailBaseDTO);

	// ..............

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

