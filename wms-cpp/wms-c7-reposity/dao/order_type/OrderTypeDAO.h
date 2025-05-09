#pragma once
#ifndef _ORDER_TYPE_DAO_H_
#define _ORDER_TYPE_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/order_type/OrderTypeDO.h"
#include "../../domain/query/order_type/OrderTypeQuery.h"

class OrderTypeDAO : public BaseDAO {
private:
    // ������ѯ����
    inline std::string queryConditionBuilder(const OrderTypeQuery::Wrapper& query, SqlParams& params);
public:
    // ��ѯ����
    uint64_t count(const OrderTypeQuery::Wrapper& query);
    uint64_t count(const PageQuery::Wrapper& query);

    // ��ѯ�������������б�
    std::list<OrderTypeNameDO> selectNameList();
    // ��ҳ��ѯ����
    std::list<OrderTypeDO> selectWithPage(const OrderTypeQuery::Wrapper& query);
    // ��������
    uint64_t insert(const OrderTypeAddDO& iObj);

};

#endif //! _ORDER_TYPE_DAO_H_