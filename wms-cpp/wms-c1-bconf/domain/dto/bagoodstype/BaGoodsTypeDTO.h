#ifndef _BAGOODSTYPE_DTO_
#define _BAGOODSTYPE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ʒ���Զ���
 */
class BaGoodsTypeDTO : public oatpp::DTO
{
	DTO_INIT(BaGoodsTypeDTO, DTO);
	//id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.id");
	}
	//��Ʒ���Ա���
	DTO_FIELD(String, goods_type_code);
	DTO_FIELD_INFO(goods_type_code) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.goods_type_code");
	}
	//��Ʒ��������
	DTO_FIELD(String, goods_type_name);
	DTO_FIELD_INFO(goods_type_name) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.goods_type_name");
	}
	
};

/**
 * ��Ʒ���Է�ҳ�������
 */
class BaGoodsTypePageDTO : public PageDTO<BaGoodsTypeDTO::Wrapper>
{
	DTO_INIT(BaGoodsTypePageDTO, PageDTO<BaGoodsTypeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 