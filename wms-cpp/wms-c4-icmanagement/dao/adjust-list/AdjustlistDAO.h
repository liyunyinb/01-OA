#pragma once
/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : AdjustlistDAO.h
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/27 14:44
    *  @brief    : brief
*****************************************************************************/

#ifndef _AdjustlistDAO_
#define _AdjustlistDAO_
#include "BaseDAO.h"
#include "../../domain/do/adjust-list/AdjustlistDO.h"
#include "../../domain/query/adjust-list/ListgoodsQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class AdjustlistDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const ListgoodsQuery1::Wrapper& query, SqlParams& params);
public:
	 //ͳ����������
	uint64_t count(const ListgoodsQuery1::Wrapper& query);

	 //ͨ��ID��ѯ����
	PtrAdjustlistDO selectById(const std::string id);

	 //��ҳ��ѯ����
	std::list<AdjustlistDO> selectWithPage(const ListgoodsQuery1::Wrapper& query);

	
	 //�޸�����
	int update(const AdjustlistDO& uObj, const PayloadDTO& payload);

};
#endif // !_AdjustlistDAO_
