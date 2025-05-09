#pragma once

#ifndef _TUOPAN_CONTROLLER_
#define _TUOPAN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
//#include "domain/dto/sample/SampleDTO.h"
#include "domain/vo/tuopandingyi/TuopanVO.h"
#include "domain/query/tuopandingyi/TuopanQuery.h"
#include "domain/dto/tuopandingyi/DeleteTuopanDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���̿�����
 */
class TuopanController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(TuopanController);
	// 3 ����ӿ�
public:
	// ���̷�ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(querySample) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tuopan.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(TuopanPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("tuopan.field.id"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_sort", ZH_WORDS_GETTER("tuopan.field.order"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("tuopan.field.place"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_status", ZH_WORDS_GETTER("tuopan.field.status"), "xxx", false);
	}
	// ���̷�ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/chuweiguanli/tuopandingyi/fenyechaxun", querySample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, TuopanQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryTuopan(userQuery, authObject->getPayload()));
	}

	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("tuopan.put.summary"), modifySample, Uint64JsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/chuweiguanli/tuopandingyi/xiugaituopan", modifySample, BODY_DTO(TuopanDTO::Wrapper, dto), execModifyTuopan(dto));

	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeSample) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("tuopan.delete.summary"), Uint64JsonVO::Wrapper);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/chuweiguanli/tuopandingyi/shanchutuopan/{id}", removeSample,BODY_DTO(DeleteTuopanDTO::Wrapper,idlist), execRemoveTuopan(idlist));

	// 3.3 ���̷�ҳ��ѯ����
	TuopanPageJsonVO::Wrapper execQueryTuopan(const TuopanQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 �����޸�����
	StringJsonVO::Wrapper execModifyTuopan(const TuopanDTO::Wrapper& dto);
	// 3.3 ����ɾ������
	StringJsonVO::Wrapper execRemoveTuopan(const DeleteTuopanDTO::Wrapper& idlist);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _TUOPAN_CONTROLLER_