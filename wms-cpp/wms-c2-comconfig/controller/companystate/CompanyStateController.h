#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
 @Date: 2025/2/22 21:02:41

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
#ifndef _COMPANYSTATE_CONTROLLER_
#define _COMPANYSTATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/companystate/CompanyStateDTO.h"
#include "domain/vo/companystate/CompanyStateVO.h"
#include "service/companystate/CompanyStateService.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class CompanyStateController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CompanyStateController);
	// 3 ����ӿ�
public:
	// 3.1 ������ҵ��Ϣ¼��ӿ�����
	ENDPOINT_INFO(addCompanyState) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("companystate.add"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyStateJsonVO);
	}
	// 3.2 ������ҵ��Ϣ¼��ӿڴ���
	ENDPOINT(API_M_POST, "/comstate/add-state", addCompanyState, BODY_DTO(CompanyAddStateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddCompanyInfo(dto, authObject->getPayload()));
	}

	// 3.1 ������ҵ��Ϣ�޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("companystate.modify"), modifyCompanyState, CompanyStateJsonVO::Wrapper);
	// 3.2 ������ҵ��Ϣ�޸Ľӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cominfo/modify-info", modifyCompanyInfo, BODY_DTO(CompanyInfoDTO::Wrapper, dto), execModifyCompanyInfo(dto, authObject->getPayload()));
	ENDPOINT(API_M_PUT, "/comstate/modify-state", modifyCompanyState, BODY_DTO(CompanyUpdateStateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyCompanyInfo(dto, authObject->getPayload()));
	}

	// 3.1 ������ҵ��Ϣɾ���ӿ�����
	ENDPOINT_INFO(removeCompanyState) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("companystate.delete"), CompanyStateJsonVO::Wrapper);
		// ��������·������˵��
//		API_DEF_ADD_PATH_PARAMS(UInt64, "ids", ZH_WORDS_GETTER("companyinfo.companyId"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/comstate/remove-state/{id}", removeCompanyState, BODY_DTO(CompanyRemoveStateDTO::Wrapper, id), execRemoveCompanyInfo(id));
private:
	// 3.3 ��ʾ��ҵ��Ϣ¼������
	CompanyStateJsonVO::Wrapper execAddCompanyInfo(const CompanyAddStateDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 ��ʾ��ҵ��Ϣ¼�޸�����
	CompanyStateJsonVO::Wrapper execModifyCompanyInfo(const CompanyUpdateStateDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 ��ʾ��ҵ��Ϣ¼ɾ������
	CompanyStateJsonVO::Wrapper execRemoveCompanyInfo(const CompanyRemoveStateDTO::Wrapper& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COMPANYINFO_CONTROLLER_