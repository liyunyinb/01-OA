#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/libraryfile/LibraryFileDO.h"

/**
 * ���ֶ�ƥ��ӳ��
 */
class LibraryFileMapper : public Mapper<LibraryFileDO>
{
public:
	LibraryFileDO mapper(ResultSet* resultSet) const override
	{
		LibraryFileDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

/**
 * ʾ�����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrLibraryFileMapper : public Mapper<PtrLibraryFileDO>
{
public:
	PtrLibraryFileDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<LibraryFileDO>();
		data->setCode(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		return data;
	}
};

#endif //