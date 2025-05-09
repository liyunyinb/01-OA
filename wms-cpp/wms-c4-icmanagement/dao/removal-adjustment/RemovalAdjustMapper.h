#pragma once
#ifndef _REMOVAL_MAPPER_
#define _REMOVAL_MAPPER_

#include "Mapper.h"
//#include "../../domain/do/sample/SampleDO.h"
#include "../../domain/do/removal-adjustment/RemovalDO.h"
/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class RemovalMapper : public Mapper<RemovalDO>
{
public:
	//ResultSetͨ����������ȡ���ݿ��ÿ���ֶ�
	RemovalDO mapper(ResultSet* resultSet) const override
	{
		RemovalDO data;
		//��data����ཫ���ݿ��ÿһ���ֶθ���������
		data.setId(resultSet->getString(1));
		data.setOrder_id(resultSet->getString(2));
		data.setGoods_id(resultSet->getString(3));
		data.setGoods_name(resultSet->getString(4));
		//data.setGoods_qua(resultSet->getString(5));
		return data;
	}
};
class RemovalDetailMapper : public Mapper<RemovalDO>
{
public:
	RemovalDO mapper(ResultSet* resultSet) const override
	{
		RemovalDO data;
		//��data����ཫ���ݿ��ÿһ���ֶθ���������
		data.setId(resultSet->getString(1));
		data.setOrder_id(resultSet->getString(2));
		data.setGoods_id(resultSet->getString(3));
		data.setGoods_name(resultSet->getString(4));
		data.setGoods_qua(resultSet->getString(5));
		return data;
	}
};

/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrRemovalMapper : public Mapper<PtrRemovalDO>
{
public:
	PtrRemovalDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RemovalDO>();
		data->setId(resultSet->getString(1));
		data->setOrder_id(resultSet->getString(2));
		data->setGoods_id(resultSet->getString(3));
		data->setGoods_name(resultSet->getString(4));
		//data->setGoods_qua(resultSet->getString(5));
		return data;
	}
};
class PtrRemovalDetailMapper : public Mapper<PtrRemovalDO>
{
public:
	PtrRemovalDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RemovalDO>();
		data->setId(resultSet->getString(1));
		data->setOrder_id(resultSet->getString(2));
		data->setGoods_id(resultSet->getString(3));
		data->setGoods_name(resultSet->getString(4));
		data->setGoods_qua(resultSet->getString(5));
		return data;
	}
};


#endif // !_SAMPLE_MAPPER_