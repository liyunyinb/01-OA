#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include"../wms-c7-reposity/domain/do/libraryfile/LibraryFileDO.h"
#include"../wms-c7-reposity/domain/do/library/LibraryDO.h"
#include"LibraryFileMapper.h"


/**
 * �����ݿ����ʵ��
 */
class LibraryFileDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
public:
	// ��ѯ������������
	uint64_t count();
	// ��ѯ��������
	list< LibraryFileDO> selectAll();
	// ��������
	uint64_t insert(const LibraryDO& iObj);
};
#endif // !_SAMPLE_DAO_

