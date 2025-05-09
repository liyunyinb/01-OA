#pragma once
#ifndef _QUALITYQUERY_H_
#define _QUALITYQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class QualityQuery : public PageQuery
{
	DTO_INIT(QualityQuery, PageQuery);
	// ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("goodsstate.id"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("goodsstate.create_name"));
	// ������
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("goodsstate.create_by"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("goodsstate.create_date"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("goodsstate.update_name"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("goodsstate.update_by"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("goodsstate.update_date"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("goodsstate.sys_org_code"));
	// ������˾
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("goodsstate.sys_company_code"));
	// Ʒ�ʴ���
	API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("goodsstate.qm_qa_code"));
	// Ʒ�ʴ�������
	API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("goodsstate.qm_qa_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUALITYQUERY_H_