#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include"../wms-c7-reposity/domain/do/file/FileDO.h"
#include"../wms-c7-reposity/domain/do/ordertypes/OrderTypesDO.h"
#include"FileMapper.h"


/**
 * �����ݿ����ʵ��
 */
class FileDAO : public BaseDAO
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
	list< FileDO> selectAll();
	// ��������
	uint64_t insert(const OrderTypesDO& iObj);
};
#endif // !_SAMPLE_DAO_

