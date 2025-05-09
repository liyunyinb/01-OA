/*
 Copyright Zero One Star. All rights reserved.

 @Author: èͷ����
 @Date: 2025/03/10 16:09:12

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
#ifndef _Recv_G_Way_CONTROLLER_
#define _Recv_G_Way_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/recv-g-way/Recv-G-Way-FileVo.h"
#include "domain/dto/recv-g-way/Recv-G-WayFileDto.h"
#include "domain/query/recv-g-way/Recv-G-Way-FileQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/**
 * �ӻ���ʽɾ��
 */
class Recv_G_WayController : public oatpp::web::server::api::ApiController {

	API_ACCESS_DECLARE(Recv_G_WayController);

public:
	// �ӻ���ʽɾ���ӿ�
	ENDPOINT_INFO(DelRecv_G_Way) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("recv-g-way.delete.description"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("recv-g-way.file.id"), "1", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/wconfig/recv-g-way/{id}", DelRecv_G_Way, PATH(String, id), execDelRecv_G_Way(id));


	// �ӻ���ʽ���ӽӿ�
	ENDPOINT_INFO(AddRecv_G_Way) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("recv-g-way.post.description"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/wconfig/recv-g-way", AddRecv_G_Way, BODY_DTO(Recv_G_WayAddDto::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddRecv_G_Way(dto, authObject->getPayload()));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("recv-g-way.put.description"), EditRecv_G_Way, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/wconfig/recv-g-way", EditRecv_G_Way, BODY_DTO(Recv_G_WayEditDto::Wrapper, dto), execEditRecv_G_Way(dto));





	//��ѯ�ӻ���ʽ
	ENDPOINT_INFO(AllRecv_G_Way) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("recv-g-way.query-all.description"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Recv_G_WayAllJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "del_mode_name", ZH_WORDS_GETTER("recv-g-way.file.del_mode_name"), "li ming", false);
		

	}
	ENDPOINT(API_M_GET, "/wconfig/recv-g-way", AllRecv_G_Way, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��  
		API_HANDLER_QUERY_PARAM(Recv_G_WayQuery, Recv_G_WayQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAllRecv_G_Way(Recv_G_WayQuery, authObject->getPayload()));
	}

	// ����һ�����ļ��ϴ��ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("recv-g-way-file.upload_f.description"), uploadRecv_G_WayFile, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "/wconfig/recv-g-way-file/upload_f", uploadRecv_G_WayFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadRecv_G_Way(request));

	// ����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadRecv_G_WayFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("recv-g-way-file.download_f.description"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("recv-g-way-file.field_f.filename"), "file/test.jpg", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/wconfig/recv-g-way-file/download_f", downloadRecv_G_WayFile, QUERY(String, filename)) {
		return execDownloadRecv_G_WayFile(filename);
	}


private:
	//ɾ��
	Uint64JsonVO::Wrapper execDelRecv_G_Way(const String& id);
	//�޸�
	Uint64JsonVO::Wrapper execEditRecv_G_Way(const Recv_G_WayEditDto::Wrapper& dto);
	//����
	Uint64JsonVO::Wrapper execAddRecv_G_Way(const Recv_G_WayAddDto::Wrapper& dto, const PayloadDTO& payload);
	//��ѯ
	Recv_G_WayAllJsonVO::Wrapper execAllRecv_G_Way(const Recv_G_WayQuery::Wrapper& query, const PayloadDTO& payload);
	
	// ִ�е��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadRecv_G_Way(std::shared_ptr<IncomingRequest> request);

	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadRecv_G_WayFile(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_Recv_G_Way_CONTR