#pragma once
#ifndef _MODIFY_MAPPER_
#define _MODIFY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/modify-industry-class/ModifyDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class ModifyMapper : public Mapper<ModifyDO>
{
public:
	ModifyDO mapper(ResultSet* resultSet) const override
	{
		ModifyDO data;
		
		data.setId(resultSet->getString(1));
		data.setClassfl_code(resultSet->getString(2));
		data.setClassfl_name(resultSet->getString(3));
		data.setClassfl_del(resultSet->getString(4));

		return data;
	}
};

/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrModifyMapper : public Mapper<PtrModifyDO>
{
public:
	PtrModifyDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ModifyDO>();
		data->setId(resultSet->getString(1));
		data->setClassfl_code(resultSet->getString(2));
		data->setClassfl_name(resultSet->getString(3));
		data->setClassfl_del(resultSet->getString(4));
		return data;
	}
};


#endif // !_MODIFY_MAPPER_
