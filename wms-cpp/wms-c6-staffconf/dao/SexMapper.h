#pragma once
#ifndef _SEX_MAPPER_
#define _SEX_MAPPER_

#include "Mapper.h"
#include "../domain/do/sex/SexDO.h"

/**
 * �Ա���ֶ�ƥ��ӳ��
 */
class SexMapper : public Mapper<SexDO>
{
public:
	SexDO mapper(ResultSet* resultSet) const override
	{
		SexDO data;
		data.setId(resultSet->getString(1));
		data.setSexCode(resultSet->getString(2));
		data.setSexName(resultSet->getString(3));
		return data;
	}
};

/**
 * �Ա���ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrSexMapper : public Mapper<PtrSexDO>
{
public:
	PtrSexDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<SexDO>();
		data->setId(resultSet->getString(1));
		data->setSexCode(resultSet->getString(1));
		data->setSexName(resultSet->getString(2));
		return data;
	}
};

#endif // !_SEX_MAPPER_