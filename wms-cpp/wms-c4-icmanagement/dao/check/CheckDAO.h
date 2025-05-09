#pragma once
#ifndef _CHECK_DAO_
#define _CHECK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/check/CheckDO.h"
#include "../../domain/query/check/CheckQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CheckDAO : public BaseDAO
{
private:
    //************************************
    // Method:      queryConditionBuilder
    // FullName:    CheckDAO::queryConditionBuilder
    // Access:      private
    // Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
    // Parameter:   const CheckQuery::Wrapper& query ��ѯ���ݶ���
    // Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
    // Description: ��ѯ����������������CheckQuery����̬������ѯ�� ����ز���
    //************************************
    inline std::string queryConditionBuilder(const CheckQuery::Wrapper &query, SqlParams &params);

public:
    // ͳ����������
    uint64_t count(const CheckQuery::Wrapper &query);
    // ��ҳ��ѯ����
    std::list<CheckDO> selectWithPage(const CheckQuery::Wrapper &query);
    // ����ҳ��ѯ����
    std::list<CheckDO> selectWithConditions(const CheckQuery::Wrapper &query);
};
#endif // !_CHECK_DAO_
