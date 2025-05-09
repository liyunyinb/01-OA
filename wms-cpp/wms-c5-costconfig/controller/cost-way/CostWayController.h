#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2023/05/17 11:37:57

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
#ifndef _COSTWAY_CONTROLLER_
#define _COSTWAY_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/cost-way/DeleteQuery.h"
#include "domain/dto/cost-way/DeleteDTO.h"
#include "domain/vo/cost-way/DeleteVO.h"
#include "domain/vo/cost-way/DownloadExcelVO.h"
#include "domain/vo/cost-way/UploadExcelVO.h"
#include<list>
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �ͻ��Ʒѷ�ʽ-ɾ���Ʒѷ�ʽ
 */
class DeleteController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteController);
	// 3 ����ӿ�
public:
	//// 3.1 ����ɾ���ӿ�����
	//ENDPOINT_INFO(waydelete) {
	//	// �������ͷ��������Լ���Ȩ֧��
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost-way.delete"), StringJsonVO::Wrapper);
	//	// ��������·������˵��
	//	API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("cost-way.id"), 1, true);
	//}
	//// 3.2 ����ɾ���ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL,"/delete/{id}", waydelete, PATH(String, id), execwaydelete(id));


	// ����ɾ���ͻ��Ʒ����Խӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("cost-way.deleteall"), deleteCostway, DeleteJsonVO::Wrapper);
	// ����ɾ���ͻ��Ʒ����Խӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-config/cost-way/delete-way", deleteCostway, BODY_DTO(oatpp::List<String>, ids), execDeleteCostway(ids));
	// 3.1 ���������ӿ�����
	
	// 3.2 ����ɾ���ӿڴ���
private:


	// 3.3 ɾ������
	//StringJsonVO::Wrapper execwaydelete(const String& id);
	StringJsonVO::Wrapper execDeleteCostway(const oatpp::List<String>&ids);

};

//����excel���ؽӿ�
class DownloadExcelController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DownloadExcelController);
public:
	// �Ʒѷ�ʽexcel���ؽӿ�
		// ��������
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("file.field.download"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.excel-filename"), "test.xlsx", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/cost-config/cost-way/excel-download", downloadFile, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		
		return execDownloadFile(filename);
	}
private:
	// ִ��excel�ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
};

//����excel�ϴ��ӿ�
class UploadExcelController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(UploadExcelController);
public:
	// ����һ�����ļ��ϴ��ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.field.upload"), uploadFile, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "/cost-config/cost-way/excel-upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));
private: // ����ӿ�ִ�к���
	// ִ�е��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 