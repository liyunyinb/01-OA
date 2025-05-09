#pragma once
#ifndef _QUALITYCONTROLLER_H_
#define _QUALITYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/qcd/QualityDTO2.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QualityController2 : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(QualityController2);

public:
	// ******************************������Ҫ�ǵü�AUTHȨ��*****************************************************
	
	// ɾ��Ʒ�ʴ���
	ENDPOINT_INFO(removeQcd) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("qcd.delete.summary"), StringJsonVO::Wrapper);
	}
	// �ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qcd/delete-qcd", removeQcd, BODY_DTO(DeleteDTO::Wrapper, dto), execDeleteQuality(dto));


	// ���ļ��ϴ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("qcd.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/qcd/upload-qcd", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadFile(request, authObject->getPayload()));

	// �ļ�����
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("qcd.download.summary"), Void);

		// ������Ȩ����
		API_DEF_ADD_AUTH();

		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "quality_codes" , true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/qcd/download-qcd", downloadFile, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execDownloadFile(filename);
	}

private:

	// ɾ��Ʒ�ʴ���
	StringJsonVO::Wrapper execDeleteQuality(const DeleteDTO::Wrapper& dto);
	// ִ�е��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadFile(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUALITYCONTROLLER_H_