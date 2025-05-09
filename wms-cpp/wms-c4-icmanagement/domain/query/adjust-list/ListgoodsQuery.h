#pragma once
#ifndef _LISTGOODS_QUERY_
#define _LISTGOODS_QUERY_

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
 * �ϼܻ����ҳ��ѯ����
 */
class ListgoodsQuery1 : public PageQuery
{
	//��ʼ��
	DTO_INIT(ListgoodsQuery1, PageQuery);

	//Ψһid
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("lis.field.id"));
	
	//����������
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("lis.field.crename"));

	// �����˵�¼����
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("lis.field.creloginame"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("lis.field.credate"));

	// ����������
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("lis.field.updname"));

	// �����˵�¼����
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("lis.field.updloginame"));

	//��������
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("lis.field.upddate"));

	//��������
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("lis.field.sysorgcode"));

	//������˾
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("lis.field.syscompanycode"));
	
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("lis.field.goodscode"));

	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_qua, ZH_WORDS_GETTER("lis.field.goodsqua"));

	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("lis.field.goodsname"));

	// ԭʼ��������
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("lis.field.orgbilltype"));
	
	// ԭʼ���ݱ���
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("lis.field.orgbillcode"));

	// ԭʼ��������Ŀ
	API_DTO_FIELD_DEFAULT(String, order_id_i, ZH_WORDS_GETTER("lis.field.orgbillrow"));

	// �ϼ�id
	API_DTO_FIELD_DEFAULT(String, wm_to_up_id, ZH_WORDS_GETTER("lis.field.goodsupid"));
	
	// ��λ
	API_DTO_FIELD_DEFAULT(String, goods_unit, ZH_WORDS_GETTER("lis.field.goodsunit"));

	// ����
	API_DTO_FIELD_DEFAULT(String, goods_batch, ZH_WORDS_GETTER("lis.field.goodsbatch"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, goods_pro_data, ZH_WORDS_GETTER("lis.field.goodscredata"));

	// ��ҵ����
	API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("lis.field. acttypecode"));

	// ��λ����
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("lis.field.kuweicode"));

	// ������
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("lis.field.tuobancode"));

	// ����
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("lis.field.huozhu"));

	// ������λ
	API_DTO_FIELD_DEFAULT(String, base_unit, ZH_WORDS_GETTER("lis.field.baseunit"));

	// ������λ����
	API_DTO_FIELD_DEFAULT(String, base_goodscount, ZH_WORDS_GETTER("lis.field. basegoodscount"));
};




/**
 * �ϼܻ����ҳ��ѯ����(�̳���)
 */
class ListgoodsQuery : public PageQuery
{
	//��ʼ��
	DTO_INIT(ListgoodsQuery, PageQuery);

	//Ψһid
	API_DTO_FIELD_DEFAULT(Int32, id, ZH_WORDS_GETTER("lis.field.id"));



	// ��������
	API_DTO_FIELD_DEFAULT(String, credate, ZH_WORDS_GETTER("lis.field.credate"));



	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goodscode, ZH_WORDS_GETTER("lis.field.goodscode"));



	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goodsname, ZH_WORDS_GETTER("lis.field.goodsname"));

	

	// ԭʼ���ݱ���
	API_DTO_FIELD_DEFAULT(String, orgbillcode, ZH_WORDS_GETTER("lis.field.orgbillcode"));



	// ��λ
	API_DTO_FIELD_DEFAULT(String, goodsunit, ZH_WORDS_GETTER("lis.field.goodsunit"));


	// ����
	API_DTO_FIELD_DEFAULT(String, huozhu, ZH_WORDS_GETTER("lis.field.huozhu"));
};





/**
 * ���������ϼ�����---�в�ѯ����
 */
class ExportDataQuery : public ListgoodsQuery
{
	DTO_INIT(ExportDataQuery, ListgoodsQuery);
	//��������---��ʼ
	API_DTO_FIELD_DEFAULT(String, credate_start, ZH_WORDS_GETTER("lis.field.credate_start"));
	//��������---��ֹ
	API_DTO_FIELD_DEFAULT(String, credate_end, ZH_WORDS_GETTER("lis.field.credate_end"));
	// �����˵�¼����
	API_DTO_FIELD_DEFAULT(String, creloginame, ZH_WORDS_GETTER("lis.field.creloginame"));
	// ��λ����
	API_DTO_FIELD_DEFAULT(String, kuweicode, ZH_WORDS_GETTER("lis.field.kuweicode"));
	// ������
	API_DTO_FIELD_DEFAULT(String, tuobancode, ZH_WORDS_GETTER("lis.field.tuobancode"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTGOODS_QUERY_
