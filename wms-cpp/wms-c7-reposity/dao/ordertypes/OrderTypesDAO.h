/*
 @Author: nanbowan
*/
#pragma once

#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "domain/do/ordertypes/OrderTypesDO.h"
#include "domain/dto/ordertypes/OrderTypesDTO.h"

/**
 * �����ݿ����ʵ��
 */
class OrderTypesDAO : public BaseDAO
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
	// �޸�����
	int update(const OrderTypesDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_SAMPLE_DAO_

