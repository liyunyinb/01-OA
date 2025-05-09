#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/2/27 22:17

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
#ifndef _COST_DETAIL_CONTROLLER_
#define _COST_DETAIL_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/cost-detail/CostDetailDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class CostDetailController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CostDetailController);
	// 3 ����ӿ�
public:
	//1.1�����տ�ӿ�����
	ENDPOINT_INFO(chargeCost) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost-detail.charge.summary"), StringJsonVO::Wrapper);
	}
	//1.2�����տ�ӿ�(֧�ֶ������)
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cost-management/cost-detail/charge-by-ids", chargeCost, BODY_DTO(List<String>, ids), execChargeCost(ids));

	//2.1����ȡ���տ�ӿ�����
	ENDPOINT_INFO(dischargeCost) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost-detail.discharge.summary"), StringJsonVO::Wrapper);
	}
	//2.2�����տ�ӿ�(֧�ֶ������)
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cost-management/cost-detail/discharge-by-ids", dischargeCost, BODY_DTO(List<String>, ids), execDischargeCost(ids));

	//3.1����������ϸ�ӿ�����(�ļ�����������)
	ENDPOINT_INFO(downloadCostDetail) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("cost-detail.download.summary"), Void);
	}
	//3.2����������ϸ�ӿ�(�ļ�����������)
	ENDPOINT(API_M_POST, "/cost-management/cost-detail/download", downloadCostDetail,BODY_DTO(List<String>,ids)) {
		return execDownloadCostDetail(ids);
	}

	//4.1���������ϸ�ӿ�����(�ļ��������ϴ�)
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("cost-detail.upload.summary"), uploadCostDetail, StringJsonVO::Wrapper);
	//4.2���������ϸ�ӿ�����(�ļ��������ϴ�,Ŀǰ�ǵ����ļ�)
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/cost-management/cost-detail/upload", uploadCostDetail, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadCostDetail(request, authObject->getPayload()));

private:
	//1.3�����տ�ʵ��
	StringJsonVO::Wrapper execChargeCost(List<String> ids);
	//2.3����ȡ���տ�ʵ��
	StringJsonVO::Wrapper execDischargeCost(List<String> ids);
	//3.3����������ϸʵ��
	std::shared_ptr<OutgoingResponse> execDownloadCostDetail(const List<String>& ids);
	//4.3���������ϸʵ��
	StringJsonVO::Wrapper execUploadCostDetail(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COST_DETAIL_CONTROLLER_!