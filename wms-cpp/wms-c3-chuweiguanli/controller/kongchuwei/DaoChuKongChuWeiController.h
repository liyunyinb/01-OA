#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_CONTROLLER_
#define _DAO_CHU_KONG_CHU_WEI_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/kongchuwei/DaoChuKongChuWeiVO.h"
#include "domain/query/kongchuwei/DaoChuKongChuWeiQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class DaoChuKongChuWeiController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DaoChuKongChuWeiController);
public:
	// ����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "bin_store", ZH_WORDS_GETTER("store.field.bin_store"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_shu_xing", ZH_WORDS_GETTER("store.field.ku_wei_shu_xing"), "tiao wen", false);
		API_DEF_ADD_QUERY_PARAMS(String, "chp_shu_xing", ZH_WORDS_GETTER("store.field.chp_shu_xing"), "ri yong", false);
		API_DEF_ADD_QUERY_PARAMS(String, "binid", ZH_WORDS_GETTER("store.field.binid"), "123", false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/chuweiguanli/kongchuwei/export-excel", downloadFile, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(storeQuery, DaoChuKongChuWeiQuery, queryParams);
		return execDownloadFile(storeQuery);
	}

private: // ����ӿ�ִ�к���

	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile(const DaoChuKongChuWeiQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DAO_CHU_KONG_CHU_WEI_CONTROLLER_