#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: JOHAN LIN
 @Date: 2025/02/21 19:29:00

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

#ifndef _COST_ATTRIBUTE_CONTROLLER_
#define _COST_ATTRIBUTE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/cost-attribute/CostAttributeDTO.h"
#include "domain/do/cost-attribute/CostAttributeDO.h"
#include "domain/query/cost-attribute/CostAttributeQuery.h"
#include "domain/vo/cost-attribute/CostAttributeVO.h"
#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class CostAttributeController : public oatpp::web::server::api::ApiController {
	// ����������������
	API_ACCESS_DECLARE(CostAttributeController);

public:
	// --------------------------------------------------------����ɾ���ӿ�����--------------------------------------------------------//
	ENDPOINT_INFO(deleteCostAttribute) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost.attribute.delete"), StringJsonVO::Wrapper);
		//// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(List<String>, "ids", ZH_WORDS_GETTER("cost.attribute.delete"), {"1"}, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-config/cost-attribute/delete-attribute", deleteCostAttribute, BODY_DTO(List<String>, ids), execDeleteCostAttribute(ids));

	
	// --------------------------------------------------------���嵼��ͻ����ԣ����ļ��ϴ����ӿ�---------------------------------------//
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("excel.import"), importFile, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "/cost-config/cost-attribute/import-attribute", importFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execImportCostAttribute(request));
	
	// --------------------------------------------------------���嵼���ͻ����ԣ��ļ����أ��ӿ�------------------------------------------//
	// ��������
	ENDPOINT_INFO(exportFile) {
		API_DEF_ADD_AUTH();
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("excel.export"), Void);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/cost-config/cost-attribute/export-attribute", exportFile, API_HANDLER_AUTH_PARAME) {
		return execExportCostAttribute();
	}

private:
	// ����ɾ���ͻ��Ʒ�����ִ�к���
	StringJsonVO::Wrapper execDeleteCostAttribute(const List<String>& ids);

	// ���嵼��ͻ��Ʒ�����ִ�к���
	StringJsonVO::Wrapper execImportCostAttribute(shared_ptr<IncomingRequest> request);

	// ���嵼���ͻ��Ʒ�����ִ�к���
	std::shared_ptr<OutgoingResponse> execExportCostAttribute();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_COST_ATTRIBUTE_CONTROLLER_