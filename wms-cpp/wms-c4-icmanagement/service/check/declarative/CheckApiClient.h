#pragma once

#ifndef _CHECKAPICLIENT_H_
#define _CHECKAPICLIENT_H_

// 1 �������ͷ�ļ�
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ��дʾ��ApiClient����ʾ��������ʽ����
 */
class CheckApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(CheckApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
	// ��������ѯ
	API_CALL(API_M_GET, "/inv/check", queryCheck, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, name));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

#endif // !_CHECKAPICLIENT_H_