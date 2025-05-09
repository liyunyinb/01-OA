#pragma once

#ifndef _CHECK_DTO_
#define _CHECK_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �̵�������ݣ�Ҫ���͵Ļ�������
 */
class CheckBaseDTO : public oatpp::DTO
{
	DTO_INIT(CheckBaseDTO, DTO);
	//ID
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("mql.rest.id"), false, "2c9efaca91697e98019227d531751cc2");

	//����������
	API_DTO_FIELD(String, create_name, ZH_WORDS_GETTER("mql.creat.create_name"), false, ZH_WORDS_GETTER("inv.manager"));

	//�����˵�¼����
	API_DTO_FIELD(String, create_by, ZH_WORDS_GETTER("mql.creat.create_by"), false, ZH_WORDS_GETTER("admin"));

	//��������
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("mql.creat.create_date"), false, "2099-12-31");

	//����������
	API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("mql.update.update_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//�����˵�¼����
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("mql.update.update_by"), false, "admin");
	//��������
	API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("mql.update.update_date"), false, "2099-12-31");
	//��������
	API_DTO_FIELD(String, sys_org_code, ZH_WORDS_GETTER("mql.sys.sys_org_code"), false, "A05");
	//������˾
    API_DTO_FIELD(String, sys_company_code, ZH_WORDS_GETTER("mql.sys.sys_company_code"), false, "A05");
	// ��λ
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");
	//����
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");
	//��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");
	//��Ʒ����
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));
	//����
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");
	// ��λ
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));
	//��������
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");
	// ����
	API_DTO_FIELD(String, goods_batch, ZH_WORDS_GETTER("mql.goods.goods_batch"), false, "2099-12-31");
	//�̵�����
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");
	//�ͻ�����
	API_DTO_FIELD(String, cus_name, ZH_WORDS_GETTER("mql.cus.cus_name"), false, "XXXX-KH���޹�˾");
	//�ͻ�
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "X00001");
	//�̵�״̬
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
	//������λ
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("mql.base.base_unit"), false, "0");
	//������λ����
	API_DTO_FIELD(String, base_goodscount, ZH_WORDS_GETTER("mql.base.base_goodscount"), false, "0");
	//stt_id
	API_DTO_FIELD(String, stt_id, "stt_id", false, "2024-10-15 20:38");
	//��Ʒͳһ����
	API_DTO_FIELD(String, goods_code, ZH_WORDS_GETTER("mql.goods.goods_code"), false, "0");
	//�̵�����
	API_DTO_FIELD(String, stt_type, ZH_WORDS_GETTER("mql.stt.stt_type"), false, "01");
	//����
	API_DTO_FIELD(String, dong_xian, ZH_WORDS_GETTER("mql.rest.dong_xian"), false, "0");


};
/**
 * �̵��б��������ݶ���
 */
class CheckAddDTO : public CheckBaseDTO
{
	DTO_INIT(CheckAddDTO, CheckBaseDTO);
	// ��λ
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");
	//����
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");
	//��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");
	//��Ʒ����
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));
	//����
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");
	// ��λ
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));
	//��������
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");
	// ����
	API_DTO_FIELD(String, goods_batch, ZH_WORDS_GETTER("mql.goods.goods_batch"), false, "2099-12-31");
	//�̵�����
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");
	//��������
	API_DTO_FIELD(String, cus_name, ZH_WORDS_GETTER("mql.cus.cus_name"), false, "JCGAMING");
	//����
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "LiHua");
	//�̵�״̬
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
	//����������
	API_DTO_FIELD(String, create_name, ZH_WORDS_GETTER("mql.creat.create_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//��������
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("mql.creat.create_date"), false, "2099-12-31");
	//����������
	API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("mql.update.update_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//�����˵�¼����
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("mql.update.update_by"), false, "admin");
	//��������
	API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("mql.update.update_date"), false, "2099-12-31");
};

/**
 * �̵�����ϸ�����б�
 */
class CheckDtailDTO : public CheckAddDTO
{
	DTO_INIT(CheckDtailDTO, CheckAddDTO);
	///ID
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("mql.rest.id"), false, "1");
	// ��λ
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");
	//����
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");
	//��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");
	//��Ʒ����
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));
	//����
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");
	// ��λ
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));
	//��������
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");
	// ����
	API_DTO_FIELD(String, goods_batch, ZH_WORDS_GETTER("mql.goods.goods_batch"), false, "2099-12-31");
	//�̵�����
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");
	//��������
	API_DTO_FIELD(String, cus_name, ZH_WORDS_GETTER("mql.cus.cus_name"), false, "JCGAMING");
	//����
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "LiHua");
	//�̵�״̬
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
	//����������
	API_DTO_FIELD(String, create_name, ZH_WORDS_GETTER("mql.creat.create_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//��������
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("mql.creat.create_date"), false, "2099-12-31");
	//����������
	API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("mql.update.update_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//�����˵�¼����
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("mql.update.update_by"), false, "admin");
	//��������
	API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("mql.update.update_date"), false, "2099-12-31");
};
///**
// * �̵��˵�Ψһ��ʶ
// */
//class CheckListDTO : public oatpp::DTO
//{
//	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("inv.inventorystatus"));
//}
/**
 * �̵����б��ҳ����
 */
class CheckPageDTO : public PageDTO<CheckBaseDTO::Wrapper>
{
	DTO_INIT(CheckPageDTO, PageDTO<CheckBaseDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECK_DTO_#pragma once
