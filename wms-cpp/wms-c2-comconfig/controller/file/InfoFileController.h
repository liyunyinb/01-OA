#pragma once
#pragma once
#ifndef _INFO_FILE_CONTROLLER_
#define _INFO_FILE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/info-file/InfoFileVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* �ļ�����ʾ���ӿ�
*/
class InfoFileController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(InfoFileController);
public:
	// 3. ������ҵ���� -- ���ļ��ϴ�
	ENDPOINT_INFO(UploadCompanyGrade) {
		info->summary = ZH_WORDS_GETTER("file.upload.summary");
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("file.upload.summary"), StringJsonVO::Wrapper);
	}
	// ����˵�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/entleve/upload-file", UploadCompanyGrade, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadGrade(request, authObject->getPayload()));
	//// ����һ�����ļ��ϴ��ӿ�
	//// ��������
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	//// ����˵�
	//API_HANDLER_ENDPOINT(API_M_POST, "/entleve/upload-file", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));
private: // ����ӿ�ִ�к���
	// ִ�е��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadGrade(std::shared_ptr<IncomingRequest> request, const PayloadDTO& dto);
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_COMPANY_INFO_FILE_CONTROLLER_