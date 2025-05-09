#pragma once

#ifndef _COST_QUERY_
#define _COST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ϸ��ҳ��ѯ����   query�����൱�ڲ�ѯ�����ֶ�
 */
class CostDetailQuery : public PageQuery
{
	DTO_INIT(CostDetailQuery, PageQuery);


	// �ͻ�����
	DTO_FIELD(String, cus_code);
	DTO_FIELD_INFO(cus_code) {
		info->description = ZH_WORDS_GETTER("cost.field.cus_code");
	}
	// �ͻ�����
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {
		info->description = ZH_WORDS_GETTER("cost.field.cus_name");
	}
	// ���ñ���
	DTO_FIELD(String, cost_code);
	DTO_FIELD_INFO(cost_code) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_code");
	}
	// ��������
	DTO_FIELD(String, cost_name);
	DTO_FIELD_INFO(cost_name) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_name");
	}
	// ��������
	DTO_FIELD(String, cost_data);
	DTO_FIELD_INFO(cost_data) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_data");
	}
	// ������Դ
	DTO_FIELD(String, cost_ori);
	DTO_FIELD_INFO(cost_ori) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_ori");
	}
	// ��ע
	DTO_FIELD(String, beizhu);
	DTO_FIELD_INFO(beizhu) {
		info->description = ZH_WORDS_GETTER("cost.field.beizhu");
	}
	// ״̬
	DTO_FIELD(String, cost_sta);
	DTO_FIELD_INFO(cost_sta) {
		info->description = ZH_WORDS_GETTER("cos.field.cost_sta");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_QUERY_

