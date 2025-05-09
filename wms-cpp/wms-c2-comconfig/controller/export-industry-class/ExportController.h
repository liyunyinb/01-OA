#pragma once
#ifndef _EXPORT_CONTROLLER_H_
#define _EXPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ������ҵ����ӿ�
 */
class ExportController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ExportController);
public:
	// ����һ��������ҵ����ӿ�
		// ��������
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("chengfeng.export"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("chengfeng.excel"), "file.xlsx", true);
	//������ҳ��ѯ����
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("chengfeng.id"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "classfl_code", ZH_WORDS_GETTER("chengfeng.code"), "007", false);
		API_DEF_ADD_QUERY_PARAMS(String, "classfl_name", ZH_WORDS_GETTER("chengfeng.name"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "classfl_del", ZH_WORDS_GETTER("chengfeng.del"), "yes", false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/indclas/download-indclas", downloadFile, QUERY(String, filename)) {
		return execExportExcel(filename);
	}

private: // ����ӿ�ִ�к���
	
	// ������ҵ����
	std::shared_ptr<OutgoingResponse> execExportExcel(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORT_CONTROLLER_H_