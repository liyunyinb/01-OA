#ifndef _EXPIRATION_DATE_EARLY_WARNING_QUERY_
#define _EXPIRATION_DATE_EARLY_WARNING_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ExpirationDateEarlyWarningQuery : public PageQuery
{
	DTO_INIT(ExpirationDateEarlyWarningQuery, PageQuery);
	// ����
	API_DTO_FIELD_DEFAULT(String, productcode, ZH_WORDS_GETTER("EWM.productcode"));
	API_DTO_FIELD_DEFAULT(String, customerproductcode, ZH_WORDS_GETTER("EWM.customerproductcode"));
	API_DTO_FIELD_DEFAULT(String, productname, ZH_WORDS_GETTER("EWM.productname"));
	API_DTO_FIELD_DEFAULT(String, customercode, ZH_WORDS_GETTER("EWM.customercode"));
	API_DTO_FIELD_DEFAULT(String, customername, ZH_WORDS_GETTER("EWM.customername"));
	API_DTO_FIELD_DEFAULT(String, productiondate, ZH_WORDS_GETTER("EWM.productiondate"));
	API_DTO_FIELD_DEFAULT(String, expirationdate, ZH_WORDS_GETTER("EWM.expirationdate"));
	API_DTO_FIELD_DEFAULT(String, Thelowervalueoftheremainingratio, ZH_WORDS_GETTER("EWM.The lower value of the remaining ratio"));
	API_DTO_FIELD_DEFAULT(String, Theuppervalueoftheremainingratio, ZH_WORDS_GETTER("EWM.The upper value of the remaining ratio"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPIRATION_DATE_EARLY_WARNING_QUERY_