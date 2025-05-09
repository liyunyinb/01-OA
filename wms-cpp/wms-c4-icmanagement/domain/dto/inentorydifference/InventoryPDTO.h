#pragma once

#ifndef _INVENTORY_PDTO_
#define _INVENTORY_PDTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �̵��˻������ݶ���Ҫ���͵Ļ�������
 */
class InventoryPBaseDTO : public oatpp::DTO
{
	DTO_INIT(InventoryPBaseDTO, DTO);

	// �̵���
	API_DTO_FIELD(String, stt_name, ZH_WORDS_GETTER("mql.stt.stt_name"), false, "LiHua");

	// ��λ
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");

	//����
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");

	//��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");

	//��Ʒ����
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));

	//����
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "LiHua");

	//��������
	API_DTO_FIELD(String, cus_id, ZH_WORDS_GETTER("mql.cus.cus_id"), false, "X00001");

};
/**
 * �̵����б��������ݶ���
 */
class InventoryPAddDTO : public InventoryPBaseDTO
{
	DTO_INIT(InventoryPAddDTO, InventoryPBaseDTO);

	// �̵���
	API_DTO_FIELD(String, stt_name, ZH_WORDS_GETTER("mql.stt.stt_name"), false, "LiHua");

	//�̵�����
	API_DTO_FIELD(String, stt_date, ZH_WORDS_GETTER("mql.stt.stt_date"), false, "2099-12-31");

	// ��λ
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");

	//����
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");

	//��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");

	//��Ʒ����
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));

	//�˵�����
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");

	//��λ
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));

	//��������
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");

	//�̵�����
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");

	//����
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "LiHua");

	//��������
	API_DTO_FIELD(String, cus_id, ZH_WORDS_GETTER("mql.cus.cus_id"), false, "X00001");

	//�̵�״̬
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
};

/**
 * �̵�����ϸ�����б�
 */
class InventoryPDtailDTO : public InventoryPAddDTO
{
	DTO_INIT(InventoryPDtailDTO, InventoryPAddDTO);
	//Ψһ��ʶ
	//ID
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("mql.rest.id"), false, "1");

	// �̵���
	API_DTO_FIELD(String, stt_name, ZH_WORDS_GETTER("mql.stt.stt_name"), false, "LiHua");

	//�̵�����
	API_DTO_FIELD(String, stt_date, ZH_WORDS_GETTER("mql.stt.stt_date"), false, "2099-12-31");

	// ��λ
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");

	//����
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");

	//��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");

	//��Ʒ����
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));

	//�˵�����
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");

	//��λ
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));

	//��������
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");

	//�̵�����
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");

	//����
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "LiHua");

	//��������
	API_DTO_FIELD(String, cus_id, ZH_WORDS_GETTER("mql.cus.cus_id"), false, "X00001");

	//�̵�״̬
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
};
///**
// * �̵��˵�Ψһ��ʶ
// */
//class InventoryPListDTO : public oatpp::DTO
//{
//	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("inv.inventorystatus"));
//}
/**
 * �̵����б��ҳ����
 */
class InventoryPPageDTO : public PageDTO<InventoryPBaseDTO::Wrapper>
{
	DTO_INIT(InventoryPPageDTO, PageDTO<InventoryPBaseDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_INVENTORY_PDTO_