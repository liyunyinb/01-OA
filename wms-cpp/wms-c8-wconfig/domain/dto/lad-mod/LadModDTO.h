#pragma once

#ifndef _LADMOD_DTO_
#define _LADMOD_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����ʽ�������ݴ������ֻ������������
 * ��Ϊ���������ʱֻ��Ҫ�������ݲ���Ҫid
 */
class LadModAddDTO : public oatpp::DTO
{
	DTO_INIT(LadModAddDTO, oatpp::DTO);
	// �����ʽ����
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("lad.field.code"));

	// �����ʽ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("lad.field.name"));
};
/**
 * �����ʽ�������,���������ݴ������Ļ��������Ψһid
 * �޸�������Ҫid
 */
class LadModDTO : public LadModAddDTO
{
	DTO_INIT(LadModDTO, LadModAddDTO);
	// ΨһID
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("lad.field.id"));
};

/**
 * �����ʽ��ҳ�������
 */
class LadModPageDTO : public PageDTO<LadModDTO::Wrapper>
{
	DTO_INIT(LadModPageDTO, PageDTO<LadModDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LADMOD_DTO_