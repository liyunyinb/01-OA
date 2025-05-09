#pragma once
#ifndef _TP_CONTROLLER_H_
#define _TP_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/tuopandingyi/QueryTPVO.h"
#include "domain/dto/tuopandingyi/AddTPDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TPController : public oatpp::web::server::api::ApiController {
    // ������������ʽӿ�
	API_ACCESS_DECLARE(TPController);
public:
	// ��ȡ���������б�
	ENDPOINT_INFO(QueryTP) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("TP.QueryTPSummary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(QueryTPListJsonVO);
	}
	ENDPOINT(API_M_GET, "/chuweiguanli/tuopandingyi/querytp", QueryTP, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryTP());
	}

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("TP.AddTPSummary"), addTP, Uint64JsonVO::Wrapper)
	ENDPOINT(API_M_POST, "/chuweiguanli/tuopandingyi/addtp", addTP, BODY_DTO(AddTPDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddTP(dto, authObject->getPayload()));
	}
private:
	// ��ȡ���������б�
	QueryTPListJsonVO::Wrapper execQueryTP();
	StringJsonVO::Wrapper execAddTP(const AddTPDTO::Wrapper &dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)
#endif