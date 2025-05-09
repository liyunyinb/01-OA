#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_DTO_
#define _HUO_QU_CANG_WEI_SHU_JU_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ���ݲ�ѯ����
 */
class HuoQuCangWeiShuJuDTO : public oatpp::DTO
{
	DTO_INIT(HuoQuCangWeiShuJuDTO, DTO);
	// �ֿ�
	API_DTO_FIELD_DEFAULT(String, bin_store, ZH_WORDS_GETTER("store.field.bin_store"));
	//��λ
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("store.field.bin_id"));
	//����
	API_DTO_FIELD_DEFAULT(String, znode, ZH_WORDS_GETTER("store.field.znode"));
	//����
	API_DTO_FIELD_DEFAULT(String, xnode, ZH_WORDS_GETTER("store.field.xnode"));
	//����
	API_DTO_FIELD_DEFAULT(String, ynode, ZH_WORDS_GETTER("store.field.ynode"));
	//��ɫ
	API_DTO_FIELD_DEFAULT(String, colour, ZH_WORDS_GETTER("store.field.colour"));
	//tincount
	API_DTO_FIELD_DEFAULT(String, tincount, "tincount");
};

class HuoQuCangWeiShuJuPageDTO : public PageDTO<HuoQuCangWeiShuJuDTO::Wrapper>
{
	DTO_INIT(HuoQuCangWeiShuJuPageDTO, PageDTO<HuoQuCangWeiShuJuDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_HUO_QU_CANG_WEI_SHU_JU_DTO_