#pragma once


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������ҳ��ѯ����
 */
class GettasklistControllerQuery : public PageQuery
{

	DTO_INIT(GettasklistControllerQuery, PageQuery);

	//Ψһ��ʶ
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("assignment.field.id");
	}

	// �������
	DTO_FIELD(String, inventoryType);
	DTO_FIELD_INFO(inventoryType) {
		info->description = ZH_WORDS_GETTER("output.con.inventoryType");
	}
	// ����
	DTO_FIELD(String, goods_qua);
	DTO_FIELD_INFO(goods_qua) {
		info->description = ZH_WORDS_GETTER("output.con.goods_qua");
	}
	// ��λ
	DTO_FIELD(String, shl_dan_wei);
	DTO_FIELD_INFO(shl_dan_wei) {
		info->description = ZH_WORDS_GETTER("output.con.shl_dan_wei");
	}
	// ������λ����
	DTO_FIELD(String,base_goodscount);
	DTO_FIELD_INFO(base_goodscount) {
		info->description = ZH_WORDS_GETTER("output.con.base_goodscount");
	}
	// ������λ
	DTO_FIELD(String,base_unit);
	DTO_FIELD_INFO(base_unit) {
		info->description = ZH_WORDS_GETTER("output.con.base_unit");
	}
	// ��λ
	DTO_FIELD(String, bin);
	DTO_FIELD_INFO(bin) {
		info->description = ZH_WORDS_GETTER("output.con.bin");
	}
	// ����
	DTO_FIELD(String, tin);
	DTO_FIELD_INFO(tin) {
		info->description = ZH_WORDS_GETTER("output.con.tin");
	}
	// ����
	DTO_FIELD(String, cusCode);
	DTO_FIELD_INFO(cusCode) {
		info->description = ZH_WORDS_GETTER("output.con.cusCode");
	}
	// ��������
	DTO_FIELD(String, cusName);
	DTO_FIELD_INFO(cusName) {
		info->description = ZH_WORDS_GETTER("output.con.cusName");
	}
	// ��Ʒ
	DTO_FIELD(String, commodity);
	DTO_FIELD_INFO(commodity) {
		info->description = ZH_WORDS_GETTER("output.con.commodity");
	}
	// ��Ʒ����
	DTO_FIELD(String,shp_ming_cheng);
	DTO_FIELD_INFO(shp_ming_cheng) {
		info->description = ZH_WORDS_GETTER("output.con.shp_ming_cheng");
	}
	//��������
	DTO_FIELD(String, goods_pro_data);
	DTO_FIELD_INFO(goods_pro_data) {
		info->description = ZH_WORDS_GETTER("output.con.goods_pro_data");
	}
	//������
	DTO_FIELD(String, bzhi_qi);
	DTO_FIELD_INFO(bzhi_qi) {
		info->description = ZH_WORDS_GETTER("output.con.bzhi_qi");
	}
	//������
	  DTO_FIELD(String, to_goods_pro_data);
	DTO_FIELD_INFO(to_goods_pro_data) {
		info->description = ZH_WORDS_GETTER("output.con.to_goods_pro_data");
	}
	//�ֿ�
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("output.con.bin_store");
	}

};

#include OATPP_CODEGEN_END(DTO)

