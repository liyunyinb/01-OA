#pragma once
#ifndef _COMDEG_DTO_
#define _COMDEG_DTO_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��˾�ȼ������б����
 */
class ComdegBaseDTO : public oatpp::DTO
{
	DTO_INIT(ComdegBaseDTO, DTO);

	//��ҵ�ȼ�����
	API_DTO_FIELD_DEFAULT(String, degname, ZH_WORDS_GETTER("com.field.degname"));

	//��ҵ�ȼ�����
	API_DTO_FIELD_DEFAULT(String, degcode, ZH_WORDS_GETTER("com.field.degcode"));

	//��ҵ�ȼ�ͣ��
	API_DTO_FIELD_DEFAULT(String, degdel, ZH_WORDS_GETTER("com.field.degdel"));
};

/**
 * ������˾�ȼ����ݶ���
 */
class ComdegAddDTO : public ComdegBaseDTO
{
	DTO_INIT(ComdegAddDTO, ComdegBaseDTO);

};

/**
 * ��˾�ȼ��������ݶ���
 */
class ComdegDetailDTO : public ComdegAddDTO
{
	DTO_INIT(ComdegDetailDTO, ComdegAddDTO);

	//Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("com.field.degid"));
};

/**
 * ��˾�ȼ��б����
 */
class ComdegListDTO : public ComdegBaseDTO
{
	DTO_INIT(ComdegListDTO, ComdegBaseDTO);

	//Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("com.field.degid"));
};

/**
 * ��˾�ȼ��б��ҳ���ݶ���
 */
class ComdegPageDTO : public PageDTO<ComdegListDTO::Wrapper>
{
	DTO_INIT(ComdegPageDTO, PageDTO<ComdegListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_COMDEG_DTO_