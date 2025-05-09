#pragma once
#ifndef _ACTTYPEQUERY_H_
#define _ACTTYPEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ȡ��ҵ�����б�����ݴ���ģ��
 */
class ActTypeQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(ActTypeQuery, PageQuery);
	// ��ҵ���ʹ���
	API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("act_type.field.act_type_code"));
	// ��ҵ��������
	API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("act_type.field.act_type_name"));
	// ҵ�񻷽�
	API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("act_type.field.oper_step_code"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ACTTYPEQUERY_H_