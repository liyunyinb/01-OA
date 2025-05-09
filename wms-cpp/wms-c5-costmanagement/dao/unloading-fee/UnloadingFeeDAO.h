#pragma once

#ifndef _UNLOADINGFEE_DAO_
#define _UNLOADINGFEE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/UnloadingFeeDO.h"
#include"../../domain/dto/unloading-fee/UnloadingFeeDTO.h"
#include"../../domain/query/unloading-fee/UnloadingFeeQuery.h"

/**
 * ���ж�������ݿ����ʵ��
 */
class UnloadingFeeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    UnloadingFeeDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const UnloadingFeeQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������UnloadingFeeQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const UnloadingFeeQuery::Wrapper& query, SqlParams& params);
public:
	//ͳ����������
	uint64_t count(const UnloadingFeeQuery::Wrapper& query);
	//��ҳ��ѯ���ж����
	std::list<UnloadingFeeDO> selectWithPage(const UnloadingFeeQuery::Wrapper& query);
};

#endif // !_UNLOADINGFEE_DAO_