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
	DTO_FIELD(String, cusCode);
	DTO_FIELD_INFO(cusCode) {
		info->description = ZH_WORDS_GETTER("cost.field.cus_code");
	}
	// �ͻ�����
	DTO_FIELD(String, cusName);
	DTO_FIELD_INFO(cusName) {
		info->description = ZH_WORDS_GETTER("cost.field.cus_name");
	}
	// ���ñ���
	DTO_FIELD(String, costCode);
	DTO_FIELD_INFO(costCode) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_code");
	}
	// ��������
	DTO_FIELD(String, costName);
	DTO_FIELD_INFO(costName) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_name");
	}
	// �������ڿ�ʼ
	DTO_FIELD(String, costDateBegin);
	DTO_FIELD_INFO(costDateBegin) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_date_begin");
	}
	// �������ڽ���
	DTO_FIELD(String, costDateEnd);
	DTO_FIELD_INFO(costDateEnd) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_date_end");
	}
	DTO_FIELD(String, costOrigin);
	DTO_FIELD_INFO(costOrigin) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_ori");
	}
	// ��ע
	DTO_FIELD(String, note);
	DTO_FIELD_INFO(note) {
		info->description = ZH_WORDS_GETTER("cost.field.beizhu");
	}
	// ״̬
	DTO_FIELD(String, costState);
	DTO_FIELD_INFO(costState) {
		info->description = ZH_WORDS_GETTER("cos.field.cost_sta");
	}
	

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_QUERY_

