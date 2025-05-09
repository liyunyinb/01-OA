#pragma once

#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ba_act_type/BaActTypeDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class BaActTypeMapper : public Mapper<BaActTypeDO>
{
public:
	BaActTypeDO mapper(ResultSet* resultSet) const override
	{
		BaActTypeDO data;
		data.setId(resultSet->getString(1));
		data.setActTypeCode(resultSet->getString(2));
		data.setActTypeName(resultSet->getString(3));
		data.setOperStepCode(resultSet->getString(4));
		return data;
	}
};


class BaActTypeMapperAll : public Mapper<BaActTypeDO> {
public:
	BaActTypeDO mapper(ResultSet* resultSet) const override {
		BaActTypeDO data;
		data.setId(resultSet->getString(1));           // ����
		data.setCreateName(resultSet->getString(2));   // ����������
		data.setCreateBy(resultSet->getString(3));     // �����˵�¼����
		data.setCreateDate(resultSet->getString(4));   // ��������
		data.setUpdateName(resultSet->getString(5));   // ����������
		data.setUpdateBy(resultSet->getString(6));     // �����˵�¼����
		data.setUpdateDate(resultSet->getString(7));   // ��������
		data.setSysOrgCode(resultSet->getString(8));   // ��������
		data.setSysCompanyCode(resultSet->getString(9)); // ������˾
		data.setActTypeCode(resultSet->getString(10)); // ��ҵ���ʹ���
		data.setActTypeName(resultSet->getString(11)); // ��ҵ��������
		data.setOperStepCode(resultSet->getString(12)); // ҵ�񻷽ڴ���
		return data;
	}
};


/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrBaActTypeMapper : public Mapper<PtrBaActTypeDO>
{
public:
	PtrBaActTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BaActTypeDO>();
		data->setId(resultSet->getString(1));
		data->setActTypeCode(resultSet->getString(2));
		data->setActTypeName(resultSet->getString(3));
		data->setOperStepCode(resultSet->getString(4));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_