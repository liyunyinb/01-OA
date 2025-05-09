#pragma once
#ifndef _QUALITYDTO_H_
#define _QUALITYDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QualityDTO : public oatpp::DTO
{
	DTO_INIT(QualityDTO, DTO);
	// ����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("qcd.id"));
	// ����������
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("qcd.create_name"));
	// �����˵�¼����
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("qcd.create_by"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("qcd.create_date"));
	// ����������
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("qcd.update_name"));
	// �����˵�¼����
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("qcd.update_by"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("qcd.update_date"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("qcd.sys_org_code"));
	// ������˾
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("qcd.sys_company_code"));
	// Ʒ�ʴ���
	API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("qcd.qm_qa_code"));
	// Ʒ�ʴ�������
	API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("qcd.qm_qa_name"));
};


/**
 * ʾ����ҳ�������
 */
class QualityPageDTO2 : public PageDTO<QualityDTO::Wrapper>
{
	DTO_INIT(QualityPageDTO2, PageDTO<QualityDTO::Wrapper>);
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ��������
	CC_SYNTHESIZE(string, create_name, Create_name);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ��������
	CC_SYNTHESIZE(string, create_date, Create_date);
	// ��������
	CC_SYNTHESIZE(string, update_name, Update_name);
	// ��������
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ��������
	CC_SYNTHESIZE(string, update_date, Update_date);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// ������˾
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	// Ʒ�ʴ���
	CC_SYNTHESIZE(string, qm_qa_code, Qm_qa_code);
	// Ʒ�ʴ�������
	CC_SYNTHESIZE(string, qm_qa_name, Qm_qa_name);
};

/**
 * ����ɾ��
 */
class DeleteDTO : public oatpp::DTO
{
	DTO_INIT(DeleteDTO, DTO);
	// ����ɾ���� ID �б�
	DTO_FIELD(Vector<Int32>, ids) = {};
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("qcd.ids");
		info->required = true;
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_QUALITYDTO_H_