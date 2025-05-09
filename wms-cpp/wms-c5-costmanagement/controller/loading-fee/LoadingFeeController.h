#pragma once
 
#ifndef _LOADINGFEE_CONTROLLER_
#define _LOADINGFEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/loading-fee/LoadingFeeVO.h"
#include"../../domain/dto/loading-fee/LoadingFeeDTO.h"
#include"../../domain/query/loading-fee/LoadingFeeQuery.h"

//����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���ж���ѿ�����
 */
class LoadingFeeController : public oatpp::web::server::api::ApiController //�̳п�����
{
	//����������������
	API_ACCESS_DECLARE(LoadingFeeController);
	//����ӿ�
public:
	//1.�����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(pageQueryLoadingFee) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("loadingfee.get.page-query"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LoadingFeePageJsonVO);
		//����ҳ���ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "Operator", ZH_WORDS_GETTER("loadingfee.field.operator"), "zhangsan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "operateDate_begin", ZH_WORDS_GETTER("loadingfee.field.operateDate_begin"), "2024-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "operateDate_end", ZH_WORDS_GETTER("loadingfee.field.operateDate_end"), "2025-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orderNo", ZH_WORDS_GETTER("loadingfee.field.orderNo"), "ORDER001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods", ZH_WORDS_GETTER("loadingfee.field.goods"), "food", false);
	}
	//�����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/cost-management/loading-fee/page-query", pageQueryLoadingFee, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userquery, LoadingFeeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execPageQueryLoadingFee(userquery, authObject->getPayload()));
	}

	// 2.����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadLoadingFee) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.loadingFee"), Void);
		//����ҳ���ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "Operator", ZH_WORDS_GETTER("loadingfee.field.operator"), "zhangsan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "operateDate_begin", ZH_WORDS_GETTER("loadingfee.field.operateDate_begin"), "2024-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "operateDate_end", ZH_WORDS_GETTER("loadingfee.field.operateDate_end"), "2025-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orderNo", ZH_WORDS_GETTER("loadingfee.field.orderNo"), "ORDER001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods", ZH_WORDS_GETTER("loadingfee.field.goods"), "food", false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/cost-management/loading-fee/download", downloadLoadingFee, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userquery, LoadingFeeQuery, queryParams);
		return execDownloadLoadingFee(userquery);
	}
private:
	//��ҳ��ѯ���װ����
	LoadingFeePageJsonVO::Wrapper execPageQueryLoadingFee(const LoadingFeeQuery::Wrapper& query, const PayloadDTO& payload);
	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadLoadingFee(const LoadingFeeQuery::Wrapper& query);
};

#endif // _LOADINGFEE_CONTROLLER_