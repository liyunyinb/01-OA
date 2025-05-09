#pragma once
#ifndef _INVENTORY_LIST_MAPER_
#define _INVENTORY_LIST_MAPER_
#include "Mapper.h"
#include "../../domain/do/overallInventory/InventorylistDo.h"
/**
 * �����ֶ�ƥ��ӳ��
 */
class InventorylistMapper : public Mapper<InventorylistDo>
{
public:
	InventorylistDo mapper(ResultSet* resultSet) const override
	{
		InventorylistDo data;
		data.setId(resultSet->getString(1));                   // ���  
		data.setCreateName(resultSet->getString(2));            // ����������  
		data.setCreateBy(resultSet->getString(3));             // �����˵�¼����  
		data.setCreateDate(resultSet->getString(4));          // ��������  
		data.setUpdateName(resultSet->getString(5));           // ����������  
		data.setUpdateBy(resultSet->getString(6));            // �����˵�¼����  
		data.setUpdateDate(resultSet->getString(7));          // ��������  
		data.setSysOrgCode(resultSet->getString(8));          // ��������  
		data.setSysCompanyCode(resultSet->getString(9));      // ������˾  
		data.setBinId(resultSet->getString(10));               // ��λ����  
		data.setTinId(resultSet->getString(11));               // ���̱���  
		data.setGoodsId(resultSet->getString(12));            // ��Ʒ����  
		data.setGoodsName(resultSet->getString(13));           // ��Ʒ����  
		data.setGoodsQua(resultSet->getString(14));           // ����  
		data.setGoodsUnit(resultSet->getString(15));           // ��λ  
		data.setGoodsProDate(resultSet->getString(16));        // ��������  
		data.setGoodsBatch(resultSet->getString(17));         // ����  
		data.setSttQua(resultSet->getString(18));             // �̵�����  
		data.setCusName(resultSet->getString(19));            // �ͻ�����  
		data.setCusCode(resultSet->getString(20));            // �ͻ�  
		data.setSttSta(resultSet->getString(21));             // �̵�״̬  
		data.setBaseUnit(resultSet->getString(22));            // ������λ  
		data.setBaseGoodscount(resultSet->getString(23));      // ������λ����  
		data.setSttId(resultSet->getString(24));             // stt_id  
		data.setGoodsCode(resultSet->getString(25));          // ��Ʒͳһ����  
		data.setSttType(resultSet->getString(26));            // �̵�����  
		data.setDongXian(resultSet->getString(27));           // ����
		return data;
	}
};
/**
 * �����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrSampleMapper : public Mapper<PtrInventorylistDo>
{
public:
	PtrInventorylistDo mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<InventorylistDo>();
		data->setId(resultSet->getString(1));                   // ���  
		data->setCreateName(resultSet->getString(2));            // ����������  
		data->setCreateBy(resultSet->getString(3));             // �����˵�¼����  
		data->setCreateDate(resultSet->getString(4));          // ��������  
		data->setUpdateName(resultSet->getString(5));           // ����������  
		data->setUpdateBy(resultSet->getString(6));            // �����˵�¼����  
		data->setUpdateDate(resultSet->getString(7));          // ��������  
		data->setSysOrgCode(resultSet->getString(8));          // ��������  
		data->setSysCompanyCode(resultSet->getString(9));      // ������˾  
		data->setBinId(resultSet->getString(10));               // ��λ����  
		data->setTinId(resultSet->getString(11));               // ���̱���  
		data->setGoodsId(resultSet->getString(12));            // ��Ʒ����  
		data->setGoodsName(resultSet->getString(13));           // ��Ʒ����  
		data->setGoodsQua(resultSet->getString(14));           // ����  
		data->setGoodsUnit(resultSet->getString(15));           // ��λ  
		data->setGoodsProDate(resultSet->getString(16));        // ��������  
		data->setGoodsBatch(resultSet->getString(17));         // ����  
		data->setSttQua(resultSet->getString(18));             // �̵�����  
		data->setCusName(resultSet->getString(19));            // �ͻ�����  
		data->setCusCode(resultSet->getString(20));            // �ͻ�  
		data->setSttSta(resultSet->getString(21));             // �̵�״̬  
		data->setBaseUnit(resultSet->getString(22));            // ������λ  
		data->setBaseGoodscount(resultSet->getString(23));      // ������λ����  
		data->setSttId(resultSet->getString(24));             // stt_id  
		data->setGoodsCode(resultSet->getString(25));          // ��Ʒͳһ����  
		data->setSttType(resultSet->getString(26));            // �̵�����  
		data->setDongXian(resultSet->getString(27));           // ����
		return data;
	}
};
#endif // !_GOODS_MANAGE_MAPPER_