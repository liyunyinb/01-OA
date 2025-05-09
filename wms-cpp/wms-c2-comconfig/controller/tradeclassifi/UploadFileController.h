#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/02/24 11:19:05

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
#ifndef _UPLOADFILECONTROLLER_
#define _UPLOADFILECONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class UploadFileController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(UploadFileController);
public:
	// 3. ������ҵ���� -- ���ļ��ϴ�
	ENDPOINT_INFO(uploadTradeClassifi) {
		info->summary = ZH_WORDS_GETTER("file.upload-more.summary");
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("file.upload-more.summary"), StringJsonVO::Wrapper);
	}
	// ����˵�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/indclas/upload-file", uploadTradeClassifi, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadTrade(request, authObject->getPayload()));
	//// ����һ���ļ��ϴ��ӿ�
	//// ��������
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.upload-more.summary"), uploadFile, StringJsonVO::Wrapper);
	//// ����˵�
	//API_HANDLER_ENDPOINT(API_M_POST, "/indclas/upload-file", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadTrade(request));
private: // ����ӿ�ִ�к���
	// ִ�ж��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadTrade(std::shared_ptr<IncomingRequest> request, const PayloadDTO& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_
