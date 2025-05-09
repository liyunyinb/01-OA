#pragma once

#ifndef _CHUWEI_CONTROLLER_
#define _CHUWEI_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/chuweidingyi/ChuWeiVO.h"
#include "domain/query/chuweidingyi/ChuWeiQuery.h"
#include "domain/dto/chuweidingyi/ChuWeiDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class ChuWeiController : public oatpp::web::server::api::ApiController {//�̳п�����
	// ����������������
	API_ACCESS_DECLARE(ChuWeiController);
	// ����ӿ�
public:
	//[��ȡ��λ�б�����+��ҳ��]�ӿ�����
	ENDPOINT_INFO(queryChuwei) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Chuwei.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ChuWeiPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "bin_store", ZH_WORDS_GETTER("Chuwei.field.bin_store"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("Chuwei.field.ku_wei_bian_ma"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_tiao_ma", ZH_WORDS_GETTER("Chuwei.field.ku_wei_tiao_ma"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_lei_xing", ZH_WORDS_GETTER("Chuwei.field.ku_wei_lei_xing"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xnode", ZH_WORDS_GETTER("Chuwei.field.xnode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ynode", ZH_WORDS_GETTER("Chuwei.field.ynode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "znode", ZH_WORDS_GETTER("Chuwei.field.znode"), "", false);
	}

	// [��λ��ҳ��ѯ]�ӿڴ���
	ENDPOINT(API_M_GET, "/chuweiguanli/chuweidingyi/query-chuwei", queryChuwei, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(chuweiQuery, ChuWeiQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryChuwei(chuweiQuery, authObject->getPayload()));
	}


	// [��λ�޸�]�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Chuwei.modify.summary"), modifyChuwei, StringJsonVO::Wrapper);
	// [��λ�޸�]�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/chuweiguanli/chuweidingyi/modify-chuwei", modifyChuwei, BODY_DTO(ChuWeiDTO::Wrapper, dto), execModifyChuwei(dto));

	//[ɾ����λ]�ӿ�����
	ENDPOINT_INFO(removeChuwei) {	
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Chuwei.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	}
	// [ɾ����λ]�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/chuweiguanli/chuweidingyi/delect-chuwei/{id}", removeChuwei, PATH(String, id), execRemoveChuwei(id));

	// [����ɾ����λ]�ӿ�����
	ENDPOINT_INFO(batchRemoveChuwei) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Chuwei.delete.batch_summary"), StringJsonVO::Wrapper);
		info->addConsumes<Object<BatchDeleteDTO>>("application/json"); // ��ʽ����������
	}
	// [����ɾ����λ]�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/chuweiguanli/chuweidingyi/batch-delete-chuwei", batchRemoveChuwei,
		BODY_DTO(BatchDeleteDTO::Wrapper, dto), execBatchRemoveChuwei(dto));


private:
	//��ҳ��ѯ��λ����
	ChuWeiPageJsonVO::Wrapper execQueryChuwei(const ChuWeiQuery::Wrapper& query, const PayloadDTO& payload);
	//��λ�޸�����
	StringJsonVO::Wrapper execModifyChuwei(const ChuWeiDTO::Wrapper& dto);
	//��λɾ������
	StringJsonVO::Wrapper execRemoveChuwei(const String& id);
	StringJsonVO::Wrapper execBatchRemoveChuwei(const BatchDeleteDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif // _CHUWEI_CONTROLLER_