#pragma once
#ifndef _QUALITY_DTO_
#define _QUALITY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Ʒ�ʴ���������ݶ��� 
 */
class QualityBaseDTO : public oatpp::DTO
{
	DTO_INIT(QualityBaseDTO, DTO);
	// Ʒ�ʴ��� 
	API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("quality.qm_qa_code"));

	// Ʒ�ʴ�������
	API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("quality.qm_qa_name"));
};

/**
 * ����Ʒ�ʴ������ݶ���
 */
class QualityAddDTO : public QualityBaseDTO
{
	DTO_INIT(QualityAddDTO, QualityBaseDTO);

	//// Ʒ�ʴ��� 
	//API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("quality.qm_qa_code"));

	//// Ʒ�ʴ�������
	//API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("quality.qm_qa_name"));
}; 

/**
 * Ʒ�ʴ�����ϸ���ݶ���
 */
class QualityDetailDTO : public QualityAddDTO
{
	DTO_INIT(QualityDetailDTO, QualityAddDTO);
	//// Ʒ�ʴ��� 
	//API_DTO_FIELD_DEFAULT(String, qacode, ZH_WORDS_GETTER("quality.qm_qa_code"));

	//// Ʒ�ʴ�������
	//API_DTO_FIELD_DEFAULT(String, qacodename, ZH_WORDS_GETTER("quality.qm_qa_name"));
};

/**
 * Ʒ�ʴ����б����ݶ���
 */
class QualityListDTO : public QualityBaseDTO
{
	DTO_INIT(QualityListDTO, QualityBaseDTO);

	// Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("quality.qm_qa_id"));
};

/**
 * Ʒ�ʴ����ҳ�������
 */
class QualityPageDTO : public PageDTO<QualityListDTO::Wrapper>
{
	DTO_INIT(QualityPageDTO, PageDTO<QualityListDTO::Wrapper>);
};




#include OATPP_CODEGEN_END(DTO)
#endif // !QUALITY_DTO