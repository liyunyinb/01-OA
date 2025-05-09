#ifndef _BAGOODSTYPE_QUERY_
#define _BAGOODSTYPE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯ��Ʒ����
 */
class BaGoodsTypeQuery : public PageQuery
{
	DTO_INIT(BaGoodsTypeQuery, PageQuery);
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

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_