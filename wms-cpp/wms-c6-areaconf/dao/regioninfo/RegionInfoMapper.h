#pragma once
/*
 @Author: 002
 @Date: 2025.3.7
*/
#ifndef _REGION_INFO_MAPPER_
#define _REGION_INFO_MAPPER_

#include "Mapper.h"
#include "domain/do/regioninfo/RegionInfoDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class RegionInfoMapper : public Mapper<RegionInfoDO>
{
public:
	RegionInfoDO mapper(ResultSet* resultSet) const override
	{
		RegionInfoDO data;
		data.setRegion_code(resultSet->getString(1));
		data.setRegion_name(resultSet->getString(2));
		data.setRegion_rdata(resultSet->getDouble(3));
		return data;
	}
};
class RegionNameMapper : public Mapper<RegionNameDO>
{
public:
	RegionNameDO mapper(ResultSet* resultSet) const override
	{
		RegionNameDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

/**
 * �ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrRegionInfoMapper : public Mapper<PtrRegionInfoDO>
{
	PtrRegionInfoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RegionInfoDO>();
		data->setRegion_code(resultSet->getString(1));
		data->setRegion_name(resultSet->getString(2));
		data->setRegion_rdata(resultSet->getDouble(3));
		return data;
	}
};
class PtrRegionNameMapper : public Mapper<PtrRegionNameDO>
{
public:
	PtrRegionNameDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RegionNameDO>();
		data->setName(resultSet->getString(1));
		return data;
	}
};

#endif 