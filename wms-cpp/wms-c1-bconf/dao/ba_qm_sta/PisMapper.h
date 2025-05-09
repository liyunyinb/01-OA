#pragma once

#ifndef _PIS_MAPPER_
#define _PIS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ba_qm_sta/PisDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class PisMapper : public Mapper<PisDO>
{
public:
	PisDO mapper(ResultSet* resultSet) const override
	{
		PisDO data;
		data.setId(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		return data;
	}
};

/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrPisMapper : public Mapper<PtrPisDO>
{
public:
	PtrPisDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<PisDO>();
		data->setId(resultSet->getString(1));
		data->setCode(resultSet->getString(2));
		data->setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_
