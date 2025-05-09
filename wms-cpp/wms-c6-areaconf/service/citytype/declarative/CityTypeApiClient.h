#pragma once
/*
 @Author: 002
 @Date: 2025.3.4
*/
#ifndef _CITY_TYPE_APICLIENT_H_
#define _CITY_TYPE_APICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ��������ʽ����
 */
class CityTypeApiClient : public oatpp::web::client::ApiClient 
{
	// ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// ��ʼ������
	API_CLIENT_INIT(CityTypeApiClient);

	// ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�

	// ͨ��ID��ѯ
	API_CALL(API_M_DEL, "/city/type/del", delCitytype, QUERY(String, id));

#include OATPP_CODEGEN_END(ApiClient)
	// ȡ��ApiClient������ʹ�ú�---����
};

#endif // !_CITY_TYPE_APICLIENT_H_