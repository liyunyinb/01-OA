


#ifndef _CUSTOMER_DAO_
#define _CUSTOMER_DAO_
#include "BaseDAO.h"
#include "domain/do/customer-bill/CustomerBillDO.h"
#include "domain/do/public-do/DayCostDO.h"
#include "domain/query/customer-bill/CustomerBillQuery.h"


// ��DayCostDO����ָ���趨һ����������ʹ��
//typedef std::shared_ptr<DayCostDO> PtrDayCostDO;


/**
 * ��ҳ��ѯ���ݿ����ʵ��
 */
class CustomerBillDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const CustomerBillQuery::Wrapper& query, SqlParams& params);
	inline std::string idConditionBuilder( oatpp::String& id, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const CustomerBillQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<CustomerBillDO> selectWithPage(const CustomerBillQuery::Wrapper& query);
	// ͨ��ID��ѯ����
	std::list<DayCostDO> selectById(oatpp::String id);
	//ͨ��date��ѯ����
	std::list<DayCostDO> selectBydate(const PeriodQuery::Wrapper& file);

};

#endif // !_SAMPLE_DAO_
