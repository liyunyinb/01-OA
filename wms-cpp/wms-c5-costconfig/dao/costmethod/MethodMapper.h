#pragma once
#ifndef _METHOD_MAPPER_
#define _METHOD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/cost-way/CostwayDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class MethodMapper : public Mapper<CostwayDO>
{
public:
	CostwayDO mapper(ResultSet* resultSet) const override
	{
		CostwayDO data;
		data.setId(resultSet->getString(1));
		data.setPronut_code(resultSet->getString(10));
		data.setPronut_name(resultSet->getString(11));
		return data;
	}
};

///**
// * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
// */
//class PtrSampleMapper : public Mapper<PtrSampleDO>
//{
//public:
//	PtrSampleDO mapper(ResultSet* resultSet) const override
//	{
//		auto data = std::make_shared<SampleDO>();
//		data->setId(resultSet->getUInt64(1));
//		data->setName(resultSet->getString(2));
//		data->setSex(resultSet->getString(3));
//		data->setAge(resultSet->getInt(4));
//		return data;
//	}
//};

#endif // !_SAMPLE_MAPPER_