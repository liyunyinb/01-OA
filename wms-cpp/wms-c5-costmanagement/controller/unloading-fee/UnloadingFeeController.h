#pragma once

#ifndef _UNLOADINGFEE_CONTROLLER_
#define _UNLOADINGFEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/unloading-fee/UnloadingFeeVO.h"
#include"../../domain/do/UnloadingFeeDO.h"
#include"../../domain/dto/unloading-fee/UnloadingFeeDTO.h"
#include"../../domain/query/unloading-fee/UnloadingFeeQuery.h"

//����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���ж���ѿ�����
 */
class UnloadingFeeController : public oatpp::web::server::api::ApiController //�̳п�����
{
	//1.����������������
	API_ACCESS_DECLARE(UnloadingFeeController);
	//����ӿ�
public:
	//�����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(pageQueryUnloadingFee) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unloadingfee.get.page-query"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(UnloadingFeePageJsonVO);
		//�����ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "acceptor", ZH_WORDS_GETTER("unloadingfee.field.acceptor"), "zhangsan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acceptDate_begin", ZH_WORDS_GETTER("unloadingfee.field.acceptDate_begin"), "2024-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acceptDate_end", ZH_WORDS_GETTER("unloadingfee.field.acceptDate_end"), "2025-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orderNo", ZH_WORDS_GETTER("unloadingfee.field.orderNo"), "ORDER00", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods", ZH_WORDS_GETTER("unloadingfee.field.goods"), "food", false);
	}
	//�����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/cost-management/unloading-fee/page-query", pageQueryUnloadingFee, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userquery, UnloadingFeeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execPageQueryUnloadingFee(userquery, authObject->getPayload()));
	}

	// ����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadUnoadingFee) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.unloadingFee"), Void);
		//����ҳ���ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "acceptor", ZH_WORDS_GETTER("unloadingfee.field.operator"), "zhangsan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acceptDate_begin", ZH_WORDS_GETTER("uloadingfee.field.acceptDate_begin"), "2024-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acceptDate_end", ZH_WORDS_GETTER("unloadingfee.field.acceptDate_end"), "2025-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orderNo", ZH_WORDS_GETTER("unloadingfee.field.orderNo"), "ORDER001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods", ZH_WORDS_GETTER("unloadingfee.field.goods"), "food", false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/cost-management/unloading-fee/download", downloadUnoadingFee, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userquery, UnloadingFeeQuery, queryParams);
		return execDownloadUnLoadingFee(userquery);
	}

private:
	//��ҳ��ѯ���ж����
	UnloadingFeePageJsonVO::Wrapper execPageQueryUnloadingFee(const UnloadingFeeQuery::Wrapper& query, const PayloadDTO& payload);
	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadUnLoadingFee(const UnloadingFeeQuery::Wrapper& query);
};

#endif // _UNLOADINGFEE_CONTROLLER_