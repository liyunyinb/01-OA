#pragma once


#ifndef _customer_QUERY_
#define _customer_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class CustomerBillQuery : public PageQuery
{
	DTO_INIT(CustomerBillQuery, PageQuery);

	


	// �ͻ�����;
	DTO_FIELD(String, customercode);
	DTO_FIELD_INFO(customercode) {
		info->description = ZH_WORDS_GETTER("field.customer-code");
	}
	// ����ȫ��
	DTO_FIELD(String, fullchinesename);;
	DTO_FIELD_INFO(fullchinesename) {
		info->description = ZH_WORDS_GETTER("field.full-chinese-name");
	}

};




/**
 * ����δ���˵�����
 */
	
class UnsettledQuery : public oatpp::DTO
{
	DTO_INIT(UnsettledQuery, PageQuery);



	// �ͻ�����;
	DTO_FIELD(String, customercode);
	DTO_FIELD_INFO(customercode) {
		info->description = ZH_WORDS_GETTER("field.customer-code");
	}
	// �ļ�����
	DTO_FIELD(String, filename);;
	DTO_FIELD_INFO(filename) {
		info->description = ZH_WORDS_GETTER("bill.filename");
	}

};

	

/**
 * �����ڼ��˵�����
 */ 
class PeriodQuery : public oatpp::DTO
{
		DTO_INIT(PeriodQuery, PageQuery);

		// �ͻ�����;
		DTO_FIELD(String, customercode);
		DTO_FIELD_INFO(customercode) {
			info->description = ZH_WORDS_GETTER("field.customer-code");
		}

		// ��ʼʱ��
		DTO_FIELD(String, startdate);
		DTO_FIELD_INFO(startdate) {
			info->description = ZH_WORDS_GETTER("field.begin");
		}
		// ����ʱ��
		DTO_FIELD(String, enddate);;
		DTO_FIELD_INFO(enddate) {
			info->description = ZH_WORDS_GETTER("bill.end");
		}


		// �ļ�����
		DTO_FIELD(String, filename);;
		DTO_FIELD_INFO(filename) {
			info->description = ZH_WORDS_GETTER("bill.filename");
		}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_