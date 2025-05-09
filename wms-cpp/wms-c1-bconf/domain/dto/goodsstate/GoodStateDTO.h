#pragma once
#ifndef _GOODSTATEDTO_H_
#define _GOODSTATEDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GoodStateDTO : public oatpp::DTO
{
	DTO_INIT(GoodStateDTO, DTO);
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
	API_DTO_FIELD_DEFAULT(String, qm_sta_code, ZH_WORDS_GETTER("goodsstate.qm_qa_code"));
	// Ʒ�ʴ�������
	API_DTO_FIELD_DEFAULT(String, qm_sta_name, ZH_WORDS_GETTER("goodsstate.qm_qa_name"));
};
/**
 * ʾ����ҳ�������
 */
class  GoodStatePageDTO : public PageDTO<GoodStateDTO::Wrapper>
{
	DTO_INIT(GoodStatePageDTO, PageDTO<GoodStateDTO::Wrapper>);
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
	CC_SYNTHESIZE(string, qm_sta_code, Qm_sta_code);
	// Ʒ�ʴ�������
	CC_SYNTHESIZE(string, qm_sta_name, Qm_sta_name);
};

/**
 * ����ɾ������ DTO
 */
class BatchDeleteRequestDTO : public oatpp::DTO
{
	DTO_INIT(BatchDeleteRequestDTO, DTO);
	// ����ɾ���� ID �б�
	API_DTO_FIELD_DEFAULT(oatpp::List<oatpp::String>, ids, ZH_WORDS_GETTER("goodsstate.ids"));
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_GOODSTATEDTO_H_