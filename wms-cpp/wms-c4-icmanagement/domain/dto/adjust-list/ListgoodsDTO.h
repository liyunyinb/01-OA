#pragma once
#ifndef _LISTGOODS_DTO_
#define _LISTGOODS_DTO_

/*****************************************************************************
	*  @COPYRIGHT NOTICE
	*  @Copyright (c) 2013, kato1
	*  @All rights reserved
	*  @file	 : ListgoodsController.cpp
	*  @version  : ver 1.0
	*  @author   : kato1
	*  @date     : 2025/2/26 17:04
	*  @brief    : brief
*****************************************************************************/

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)





/**
*�����ϼܻ������ݶ���
*/


class BaseListgoodsDTO : public oatpp::DTO
{
	//��ʼ��
	DTO_INIT(BaseListgoodsDTO, oatpp::DTO);

	//Ψһid
	API_DTO_FIELD(String, id, "id", true, "0");

};



/**
*�޸��ϼܻ������ݶ���
*/
class ListgoodsadjustDTO : public BaseListgoodsDTO
{
	//��ʼ��
	DTO_INIT(ListgoodsadjustDTO, BaseListgoodsDTO);
	
	// ��Ʒ����
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("lis.field.goodsqua"),false,"1");

	// ��������
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("lis.field.goodscredata"), false, "xxxx-xx-xx");

	// ������
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("lis.field.tuobancode"), false, "ATP002");

	// ��λ����
	API_DTO_FIELD(String, ku_wei_bian_ma, ZH_WORDS_GETTER("lis.field.kuweicode"), false, "X1-1-01");

	// ������λ
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("lis.field.baseunit"), false, ZH_WORDS_GETTER("lis.field.box"));

};


/**
 * �ϼܻ����б����ݶ���
 */
class ListgoodsDTO : public ListgoodsadjustDTO
{
	//��ʼ��
	DTO_INIT(ListgoodsDTO, ListgoodsadjustDTO);

	// ��������
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("lis.field.credate"), false, "xxxx-xx-xx");

	// ��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("lis.field.goodscode"),false, "RL001");

	// ��Ʒ����
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("lis.field.goodsname"),false, ZH_WORDS_GETTER("lis.field.meat"));

	// ��λ
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("lis.field.goodsunit"),false, ZH_WORDS_GETTER("lis.field.box"));


	// ԭʼ���ݱ���
	API_DTO_FIELD(String, order_id, ZH_WORDS_GETTER("lis.field.orgbillcode"),false, "RK20240320-0003");


	// ����
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("lis.field.huozhu"),false, "X00001-XXXX-KH" + (ZH_WORDS_GETTER("lis.field.company")));
};




/**
 * �ϼܻ����б������ҳ���ݶ���
 */
class ListgoodsBasePageDTO : public BaseListgoodsDTO
{
	//��ʼ��
	DTO_INIT(ListgoodsBasePageDTO, BaseListgoodsDTO);



	// ��������
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("lis.field.credate"), false, "xxxx-xx-xx");


	// ��Ʒ����
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("lis.field.goodsqua"), false, "1");


	// ��λ����
	API_DTO_FIELD(String, ku_wei_bian_ma, ZH_WORDS_GETTER("lis.field.kuweicode"), false, "X1-1-01");


	// ������
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("lis.field.tuobancode"), false, "ATP002");


	// ������λ
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("lis.field.baseunit"), false, ZH_WORDS_GETTER("lis.field.box"));

	// ��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("lis.field.goodscode"), false, "RL001");

	// ��Ʒ����
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("lis.field.goodsname"), false, ZH_WORDS_GETTER("lis.field.meat"));

	// ��λ
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("lis.field.goodsunit"), false, ZH_WORDS_GETTER("lis.field.box"));


	// ԭʼ���ݱ���
	API_DTO_FIELD(String, order_id, ZH_WORDS_GETTER("lis.field.orgbillcode"), false, "RK20240320-0003");


	// ����
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("lis.field.huozhu"), false, "X00001-XXXX-KH" + (ZH_WORDS_GETTER("lis.field.company")));

	// ������λ����
	API_DTO_FIELD(String, base_goodscount, ZH_WORDS_GETTER("lis.field.basegoodscount"), false, "3");
};



/**
 * �ϼܻ����б��ҳ���ݶ���
 */
class ListgoodsPageDTO : public PageDTO<ListgoodsBasePageDTO::Wrapper>
{
	//��ʼ��
	DTO_INIT(ListgoodsPageDTO, PageDTO<ListgoodsBasePageDTO::Wrapper>);


};





/**
 * �ϼܻ�����ϸ���ݶ���(������ϸ��Ϣһ�㶼�����б�����,��˿��Լ̳����б�����)
 */
class ListgoodsDetailDTO : public BaseListgoodsDTO
{
	//��ʼ��
	DTO_INIT(ListgoodsDetailDTO, ListgoodsDTO);

	// ��������
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("lis.field.credate"), false, "xxxx-xx-xx");


	// ��Ʒ����
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("lis.field.goodscode"), false, "RL001");


	// ԭʼ���ݱ���
	API_DTO_FIELD(String, order_id, ZH_WORDS_GETTER("lis.field.orgbillcode"), false, "RK20240320-0003");


	// ��λ
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("lis.field.goodsunit"), false, ZH_WORDS_GETTER("lis.field.box"));

	
	// ����
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("lis.field.huozhu"), false, "X00001-XXXX-KH" + (ZH_WORDS_GETTER("lis.field.company")));


	// ��Ʒ����
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("lis.field.goodsqua"), false, "1");

	// ��������
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("lis.field.goodscredata"), false, "xxxx-xx-xx");


	// ��λ����
	API_DTO_FIELD(String, ku_wei_bian_ma, ZH_WORDS_GETTER("lis.field.kuweicode"), false, "X1-1-01");

	// ������
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("lis.field.tuobancode"), false, "ATP002");


	// ������λ
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("lis.field.baseunit"), false, ZH_WORDS_GETTER("lis.field.box"));


	// ������λ����
	API_DTO_FIELD(String, base_goodscount, ZH_WORDS_GETTER("lis.field.basegoodscount"), false, "3");
};





#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTGOODS_DTO_