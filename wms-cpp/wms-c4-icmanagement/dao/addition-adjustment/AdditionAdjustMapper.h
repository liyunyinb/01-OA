#pragma once
#ifndef _ADDITION_MAPPER_
#define _ADDITION_MAPPER_

#include "Mapper.h"
//#include "../../domain/do/sample/SampleDO.h"
#include "../../domain/do/addition-adjustment/AdditionDO.h"
/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class AdditionMapper : public Mapper<AdditionDO>
{
public:
	//ResultSetͨ����������ȡ���ݿ��ÿ���ֶ�
	AdditionDO mapper(ResultSet* resultSet) const override
	{
		AdditionDO data;
		//��data����ཫ���ݿ��ÿһ���ֶθ���������
		data.setId(resultSet->getString(1));
		data.setOrder_id(resultSet->getString(2));
		data.setGoods_id(resultSet->getString(3));
		data.setGoods_name(resultSet->getString(4));
		//data.setGoods_qua(resultSet->getString(5));
		return data;
	}
};


/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrAdditionMapper : public Mapper<PtrAdditionDO>
{
public:
	PtrAdditionDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<AdditionDO>();
		data->setId(resultSet->getString(1));
		data->setOrder_id(resultSet->getString(2));
		data->setGoods_id(resultSet->getString(3));
		data->setGoods_name(resultSet->getString(4));
		//data->setGoods_qua(resultSet->getString(5));
		return data;
	}
};



#endif // !_SAMPLE_MAPPER_
