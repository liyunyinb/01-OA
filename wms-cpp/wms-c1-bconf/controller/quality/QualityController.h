#pragma once
#ifndef _QUALITY_CONTROLLER_
#define _QUALITY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/quality/QualityQuery.h"
#include "domain/dto/quality/QualityDTO.h"
#include "domain/vo/quality/QualityVO.h"

/*
 @Author: S4turday
 @Date: 2025��3��8��19:27:47

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Ʒ�ʴ��������
 */
class QualityController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(QualityController);
	// 3 ����ӿ�
public:
	// ��ȡƷ�ʴ����б�
	ENDPOINT_INFO(quality_query)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("quality.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(QualityPageJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "qm_qa_code", ZH_WORDS_GETTER("quality.qm_qa_code"), "CDE001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "qm_qa_name", ZH_WORDS_GETTER("quality.qm_qa_name"), "name", false);
	}
	ENDPOINT(API_M_GET, "/qcd/query", quality_query, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		queryParams.getAll();
		API_HANDLER_QUERY_PARAM(quaQuery, QualityQuery, queryParams);
		API_HANDLER_RESP_VO(execquery(quaQuery));
	}

	// 3.1 ����Code��ѯ�ӿ�����
	ENDPOINT_INFO(queryQualityByCode) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("quality.query.bycode"), QualityJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "qm_code", ZH_WORDS_GETTER("quality.qm_qa_code"), 1, true);
	}
	// 3.2 ����Code��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/qcd/query-by-code", queryQualityByCode, QUERY(String, code), execQueryByCode(code));

	// 3.1 ����Ʒ�ʴ������Ʋ�ѯ�ӿ�����
	ENDPOINT_INFO(queryQualityByName) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("quality.query.byname"), QualityJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("quality.qm_qa_name"), 1, true);
	}
	// 3.2 ����Ʒ�ʴ������Ʋ�ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/qcd/query-by-name", queryQualityByName, QUERY(String, name), execQueryByName(name));


	// ���Ʒ�ʴ���
	ENDPOINT_INFO(quality_add)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("quality.add.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
 	ENDPOINT(API_M_POST, "/qcd/add", quality_add, BODY_DTO(QualityAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execAdd(dto, authObject->getPayload()));
	}

	// �޸�Ʒ�ʴ�����Ϣ
	ENDPOINT_INFO(quality_update)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("quality.update.summary"));
		API_DEF_ADD_AUTH();

	}
	ENDPOINT(API_M_PUT, "/qcd/update", quality_update, BODY_DTO(QualityListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execUpdate(dto, authObject->getPayload()));
	}
private:
	Uint64JsonVO::Wrapper execUpdate(const QualityListDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAdd(const QualityAddDTO::Wrapper& dto, const PayloadDTO& payload);
	QualityPageJsonVO::Wrapper execquery(const QualityQuery::Wrapper& query);
	QualityJsonVO::Wrapper execQueryByCode(const String& code);
	QualityJsonVO::Wrapper execQueryByName(const String& name);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _QUALITY_CONTROLLER_