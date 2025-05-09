#ifndef _TOTAL_REICEIVED_FEES_
#define _TOTAL_REICEIVED_FEES_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class TotalReiceivedFeesQuery : public PageQuery
{
	DTO_INIT(TotalReiceivedFeesQuery, PageQuery);
	// ����
	API_DTO_FIELD_DEFAULT(String, feestartdate, ZH_WORDS_GETTER("TRF.feestartdate"));
	API_DTO_FIELD_DEFAULT(String, feeenddate, ZH_WORDS_GETTER("TRF.feeenddate"));
	API_DTO_FIELD_DEFAULT(String, customers, ZH_WORDS_GETTER("TRF.customers"));
	API_DTO_FIELD_DEFAULT(String, customersname, ZH_WORDS_GETTER("TRF.customersname"));
	API_DTO_FIELD_DEFAULT(String, fees, ZH_WORDS_GETTER("TRF.fees"));
	API_DTO_FIELD_DEFAULT(String, feesname, ZH_WORDS_GETTER("TRF.feesname"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_TOTAL_REICEIVED_FEES_