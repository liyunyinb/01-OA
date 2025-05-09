#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _LIST_GOODS_MAPPER_
#define _LIST_GOODS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/adjust-list/wm_to_up_goodsDO.h"

/**
 * �����ֶ�ƥ��ӳ��
 */
class ListGoodsMapper : public Mapper<Wm_To_Up_GoodsDO>
{
public:
	Wm_To_Up_GoodsDO mapper(ResultSet* resultSet) const override
	{
		Wm_To_Up_GoodsDO data;
		data.setId(resultSet->getString(1));                   // ���  
		data.setCreateName(resultSet->getString(2));           // ����������  
		data.setCreateBy(resultSet->getString(3));            // �����˵�¼����  
		data.setCreateDate(resultSet->getString(4));           // ��������  // �޸������ȱʧ��create_date�ֶ�  
		data.setUpdateName(resultSet->getString(5));            // ����������  
		data.setUpdateBy(resultSet->getString(6));             // �����˵�¼����  
		data.setUpdateDate(resultSet->getString(7));           // ��������  
		data.setSysOrgCode(resultSet->getString(8));           // ��������  
		data.setSysCompanyCode(resultSet->getString(9));       // ������˾  
		data.setGoodsId(resultSet->getString(10));             // ��Ʒ����  
		data.setGoodsQua(resultSet->getString(11));           // ����  
		data.setOrderTypeCode(resultSet->getString(12));       // ԭʼ��������  
		data.setOrderId(resultSet->getString(13));             // ԭʼ���ݱ���  
		data.setOrderIdI(resultSet->getString(14));            // ԭʼ��������Ŀ  
		data.setWmToUpId(resultSet->getString(15));           // �ϼ�ID  
		data.setGoodsUnit(resultSet->getString(16));          // ��λ  
		data.setGoodsBatch(resultSet->getString(17));         // ����  
		data.setGoodsProData(resultSet->getString(18));       // ��������  
		data.setActTypeCode(resultSet->getString(19));         // ��ҵ����  
		data.setKuWeiBianMa(resultSet->getString(20));        // ��λ����  
		data.setBinId(resultSet->getString(21));             // ������  
		data.setCusCode(resultSet->getString(22));            // ����  
		data.setBaseUnit(resultSet->getString(23));            // ������λ  
		data.setBaseGoodscount(resultSet->getString(24));      // ������λ����  
		data.setGoodsName(resultSet->getString(25));           // ��Ʒ����  // �޸�����Ʒ�����ֶ���������Ϊ25  
		return data;
	}
};

/**
 * �����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrSampleMapper : public Mapper<PtrWm_To_Up_GoodsDO>
{
public:
	PtrWm_To_Up_GoodsDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<Wm_To_Up_GoodsDO>();
		data->setId(resultSet->getString(1));                   // ���  
		data->setCreateName(resultSet->getString(2));           // ����������  
		data->setCreateBy(resultSet->getString(3));            // �����˵�¼����  
		data->setCreateDate(resultSet->getString(4));           // ��������  // �޸������ȱʧ��create_date�ֶ�  
		data->setUpdateName(resultSet->getString(5));            // ����������  
		data->setUpdateBy(resultSet->getString(6));             // �����˵�¼����  
		data->setUpdateDate(resultSet->getString(7));           // ��������  
		data->setSysOrgCode(resultSet->getString(8));           // ��������  
		data->setSysCompanyCode(resultSet->getString(9));       // ������˾  
		data->setGoodsId(resultSet->getString(10));             // ��Ʒ����  
		data->setGoodsQua(resultSet->getString(11));           // ����  
		data->setOrderTypeCode(resultSet->getString(12));       // ԭʼ��������  
		data->setOrderId(resultSet->getString(13));             // ԭʼ���ݱ���  
		data->setOrderIdI(resultSet->getString(14));            // ԭʼ��������Ŀ  
		data->setWmToUpId(resultSet->getString(15));           // �ϼ�ID  
		data->setGoodsUnit(resultSet->getString(16));          // ��λ  
		data->setGoodsBatch(resultSet->getString(17));         // ����  
		data->setGoodsProData(resultSet->getString(18));       // ��������  
		data->setActTypeCode(resultSet->getString(19));         // ��ҵ����  
		data->setKuWeiBianMa(resultSet->getString(20));        // ��λ����  
		data->setBinId(resultSet->getString(21));             // ������  
		data->setCusCode(resultSet->getString(22));            // ����  
		data->setBaseUnit(resultSet->getString(23));            // ������λ  
		data->setBaseGoodscount(resultSet->getString(24));      // ������λ����  
		data->setGoodsName(resultSet->getString(25));           // ��Ʒ����  // �޸�����Ʒ�����ֶ���������Ϊ25  
		return data;
	}
};

#endif // !_LIST_GOODS_MAPPER_