#ifndef _BAGOODSTYPE_MAPPER_
#define _BAGOODSTYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/bagoodstype/BaGoodsTypeDO.h"

/**
 * ����״̬���ֶ�ƥ��ӳ��
 */
class BaGoodsTypeMapper : public Mapper<BaGoodsTypeDO>
{
public:
	BaGoodsTypeDO mapper(ResultSet* resultSet) const override
	{
		BaGoodsTypeDO data;
		//��������������ѯ
		data.setId(resultSet->getString(1));
		data.setCreateName(resultSet->getString(2));
		data.setCreateBy(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setUpdateName(resultSet->getString(5));
		data.setUpdateBy(resultSet->getString(6));
		data.setUpdateDate(resultSet->getString(7));
		data.setSysOrgCode(resultSet->getString(8));
		data.setSysCompanyCode(resultSet->getString(9));
		data.setGoodsTypeCode(resultSet->getString(10));
		data.setGoodsTypeName(resultSet->getString(11));
		return data;
	}
};

/**
 * ����״̬���ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrBaGoodsTypeMapper : public Mapper<PtrBaGoodsTypeDO>
{
public:
	PtrBaGoodsTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BaGoodsTypeDO>();
		data->setId(resultSet->getString(1));
		data->setCreateName(resultSet->getString(2));
		data->setCreateBy(resultSet->getString(3));
		data->setCreateBy(resultSet->getString(4));
		data->setUpdateName(resultSet->getString(5));
		data->setUpdateBy(resultSet->getString(6));
		data->setUpdateDate(resultSet->getString(7));
		data->setSysOrgCode(resultSet->getString(8));
		data->setSysCompanyCode(resultSet->getString(9));
		data->setGoodsTypeCode(resultSet->getString(10));
		data->setGoodsTypeName(resultSet->getString(11));
		return data;
	}
};

#endif // !_BAGOODSTYPE_MAPPER_