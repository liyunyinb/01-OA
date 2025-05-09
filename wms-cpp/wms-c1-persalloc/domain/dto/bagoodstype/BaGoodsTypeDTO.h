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
	// ����������
	DTO_FIELD(String, create_name);
	DTO_FIELD_INFO(create_name) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.create_name");
	}
	//�����˵�¼��
	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.create_by");
	}
	// ��������
	DTO_FIELD(String, create_date);
	DTO_FIELD_INFO(create_date) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.create_date");
	}
	// ��������
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.sys_org_code");
	}
	// ������˾
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.sys_company_code");
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
	//id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.id");
	}
	//����������
	DTO_FIELD(String, update_name);
	DTO_FIELD_INFO(update_name) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.update_name");
	}
	//�����˵�¼����
	DTO_FIELD(String, update_by);
	DTO_FIELD_INFO(update_by) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.update_by");
	}
	//��������
	DTO_FIELD(String, update_date);
	DTO_FIELD_INFO(update_date) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.update_date");
	}

};

class BaGoodsTypeNameDTO : public oatpp::DTO
{
	DTO_INIT(BaGoodsTypeNameDTO, DTO);

	//��Ʒ��������
	DTO_FIELD(String, goods_type_name);
	DTO_FIELD_INFO(goods_type_name) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.goods_type_name");
	}

};

/**
 * ��Ʒ�������Ʒ�ҳ�������
 */
class BaGoodsTypeNamePageDTO : public PageDTO<BaGoodsTypeNameDTO::Wrapper>
{
	DTO_INIT(BaGoodsTypeNamePageDTO, PageDTO<BaGoodsTypeNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 