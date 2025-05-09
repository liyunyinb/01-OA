#pragma once
// ��Ҳ 2025/2/24
#ifndef _WORKSTATE_CONTROLLER_
#define _WORKSTATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/GlobalInclude.h"
#include "ExcelComponent.h"
#include "domain/dto/workstate/WorkStateDTO.h"
#include "domain/vo/workstate/WorkStateVO.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class WorkStateController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(WorkStateController);
public: // ����ӿ�

	// 1.1 ���幤��״̬ɾ���ӿ�����
	ENDPOINT_INFO(workstate) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("ba_work_st.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("ba_work_st.field.id"), "1", true);
	}
	// 1.2 ���幤��״̬ɾ���ӿڴ���
	API_HANDLER_ENDPOINT(API_M_DEL, "ops/delete", workstate, QUERY(String, id), execRemoveWorkState(id));

	// ����һ�����ļ��ϴ��ӿ�
	//2.1 ����״̬�ļ��ϴ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("ba_work_st.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "ops/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request, authObject->getPayload()));



	

	//3.1 ����״̬�ļ�����
	ENDPOINT_INFO(downloadExcel) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("ba_work_st.download.summary"),Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("ba_work_st.download.filename"), "workState.xlsx", true);
		API_DEF_ADD_AUTH();
	}
	// ����˵�
	ENDPOINT(API_M_GET, "ops/download", downloadExcel, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execDownloadExcel(filename);
	}





private: 
	// �����ϴ�����״̬�ļ��ӿ�ִ�к���
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	
	// �������ع���״̬�ļ��ӿ�ִ�к���
	std::shared_ptr<OutgoingResponse> execDownloadExcel(const String& filename);
	// ����ɾ������״̬�ӿ�ִ�к���
	Uint64JsonVO::Wrapper execRemoveWorkState(const String& id);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WORKSTATE_CONTROLLER_