

#ifndef _CUSTOMER_DO_
#define _CUSTOMER_DO_
#include "../DoInclude.h"


/**
 * ʾ�����ݿ�ʵ����
 */
class CustomerBillDO
{
	// �ͻ�����
	CC_SYNTHESIZE(string, cus_code, Id);
	// ����ȫ��
	CC_SYNTHESIZE(string, cus_name, Name);

public:
	CustomerBillDO() {
		cus_code = "";
		cus_code = "";

	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CustomerBillDO> PtrCustomerBillDO;
#endif // !_SAMPLE_DO_
