//#pragma once
///*
// @Author: 002
// @Date: 2025.3.4
//*/
//#ifndef _REGION_INFO_APICLIENT_H_
//#define _REGION_INFO_APICLIENT_H_
//
//#include "oatpp/web/client/ApiClient.hpp"
//#include "ApiHelper.h"
//
///**
// * ��������ʽ����
// */
//class RegionInfoApiClient : public oatpp::web::client::ApiClient
//{
//	// ����ApiClient������ʹ�ú�---��ʼ
//#include OATPP_CODEGEN_BEGIN(ApiClient)
//
//	// ��ʼ������
//	API_CLIENT_INIT(RegionInfoApiClient);
//
//	// ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
//
//	// ͨ��ID��ѯ
//	API_CALL(API_M_GET, "/regioninfo/namelist", queryRegionByName, QUERY(String, area_name));
//
//#include OATPP_CODEGEN_END(ApiClient)
//	// ȡ��ApiClient������ʹ�ú�---����
//};
//
//#endif