#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: maomao
 @Date: 2025/2/24 10:25:27

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
#ifndef _DEFPLAT_CONTROLLER_
#define _DEFPLAT_CONTROLLER_
#include "oatpp-swagger/Types.hpp"
#include "domain/GlobalInclude.h"
#include "domain/vo/def-file/DefPlatVo.h"
#include "domain/dto/def-file/DefPlatDto.h"

//#include "domain/query/plc-file/PlcFileQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/**
 * ��̨����-��̨���� �ӿ�
 */
class DefPlatController : public oatpp::web::server::api::ApiController {

	API_ACCESS_DECLARE(DefPlatController);

public:

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(DelPlat) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("def.del.description"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("def.del.id"), "default", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/platmanag/def/{id}", DelPlat, PATH(String, id), execDelPlat(id));

	// ��̨�༭�ӿ�
	ENDPOINT_INFO(EditPlat) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("def.edit.description"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//// ����������ѯ��������

		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("def.edit.id"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "platform_code", ZH_WORDS_GETTER("def.edit.code"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "platform_name", ZH_WORDS_GETTER("def.edit.name"), "", true);
	}
	ENDPOINT(API_M_PUT, "/platmanag/def", EditPlat, QUERIES(QueryParams, qps), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(dto, DefEditDto, qps);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execEditPlat(dto, authObject->getPayload()));
	}
	// ��̨�����ӿ�
	ENDPOINT_INFO(PutPlat) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("def.put.description"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "id1", ZH_WORDS_GETTER("def.put.id"), "", false);
	}
	ENDPOINT(API_M_POST, "/platmanag/def/output", PutPlat, BODY_DTO(DefPutDto::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execPutPlat(authObject->getPayload()));
	}
private:
	Uint64JsonVO::Wrapper execDelPlat(const String& id);
	Uint64JsonVO::Wrapper execEditPlat(const DefEditDto::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execPutPlat(const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_DEFPLAT_CONTROLLER_