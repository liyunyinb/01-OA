#pragma once

#ifndef _LOADINGFEE_DAO_
#define _LOADINGFEE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/LoadingFeeDO.h"
#include"../../domain/dto/loading-fee/LoadingFeeDTO.h"
#include"../../domain/query/loading-fee/LoadingFeeQuery.h"

/**
 * ���װ�������ݿ����ʵ��
 */
class LoadingFeeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    LoadingFeeDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const LoadingFeeQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������LoadingFeeQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const LoadingFeeQuery::Wrapper& query, SqlParams& params);
public:
	//ͳ����������
	uint64_t count(const LoadingFeeQuery::Wrapper& query);
	//��ҳ��ѯ���װ����
	std::list<LoadingFeeDO> selectWithPage(const LoadingFeeQuery::Wrapper& query);
};
#endif // !_LOADINGFEE_DAO_