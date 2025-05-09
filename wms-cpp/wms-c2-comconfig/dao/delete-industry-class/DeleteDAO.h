#pragma once
#ifndef _DELETE_DAO_
#define _DELETE_DAO_
#include "BaseDAO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DeleteDAO : public BaseDAO
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

		// ͨ��ID����ɾ������
	int deleteById(vector<string>& ids);
};
#endif // !_DELETE_DAO_
