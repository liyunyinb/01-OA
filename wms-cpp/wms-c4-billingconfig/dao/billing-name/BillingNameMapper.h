#pragma once
#ifndef _BILLING_MAPPER_
#define _BILLING_MAPPER_

#include "Mapper.h"
#include "../../domain/do/billing-name/BillingNameDO.h"
/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class BillingNameMapper : public Mapper<BillingNameDO>
{
public:
	//ResultSetͨ����������ȡ���ݿ��ÿ���ֶ�
    BillingNameDO mapper(ResultSet* resultSet) const override
	{
		BillingNameDO data;
		//��data����ཫ���ݿ��ÿһ���ֶθ���������
		//data.setId(resultSet->getString(1));// ���
		data.setCost_code(resultSet->getString(1));
		data.setCost_name(resultSet->getString(2));
		data.setCost_type_code(resultSet->getString(3));
		return data;
	}
};

/**
 * �����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrBillingNameMapper : public Mapper<PtrBillingNameDO>
{
public:
	PtrBillingNameDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BillingNameDO>();
		//data->setId(resultSet->getString(1));// ���
		data->setCost_code(resultSet->getString(1));
		data->setCost_name(resultSet->getString(2));
		data->setCost_type_code(resultSet->getString(3));
		return data;
	}
};


#endif // !_DOWNGOODS_MAPPER_#pragma once
