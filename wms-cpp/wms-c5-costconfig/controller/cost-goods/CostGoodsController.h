//#pragma once
///*
// Copyright Zero One Star. All rights reserved.
//
// @Author: Jane
// @Date: 2025/02/26 11:19:05
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	  https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*/
//#ifndef _COSTGOODSCONTROLLER_H_
//#define _COSTGOODSCONTROLLER_H_
//
//#include "domain/vo/BaseJsonVO.h"
//#include "ApiHelper.h"
//#include "ServerInfo.h"
//#include "domain/query/cost-goods/BillingProductCategoryQuery.h"
//#include "domain/dto/cost-goods/CostGoodsDTO.h"
//#include "domain/vo/cost-goods/CostGoodsVO.h"
//#include <service/cost-goods/CostGoodsService.h>
//
//// 0 ����API������ʹ�ú�
//#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
//
///**
// * �ͻ��Ʒѷ�ʽ-ɾ���Ʒѷ�ʽ
// */
//class CostGoodsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
//{
//	// 2 ����������������
//	API_ACCESS_DECLARE(CostGoodsController);
//public:
//	// 3.1 ����ɾ���ӿ�����
//	ENDPOINT_INFO(waydelete) {
//		// �������ͷ��������Լ���Ȩ֧��
//		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("CostGoodsQuery.delete.query"), StringJsonVO::Wrapper);
//		// ��������·������˵��
//		API_DEF_ADD_PATH_PARAMS(String, "code", ZH_WORDS_GETTER("CostGoodsQuery.way.code"), "1", true);
//	}
//	// 3.2 ����ɾ���ӿڴ���
//	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-goods/delete/{code}", waydelete, PATH(String, code), execwaydelete(code));
//
//	// �Ʒѷ�ʽexcel���ؽӿ�
//	// ��������
//	ENDPOINT_INFO(downloadFile) {
//		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("CostGoodsQuery.file.download"), Void);
//		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.excel-filename"), "excel/test.xlsx", true);
//	}
//	// ����˵�
//	ENDPOINT(API_M_GET, "/cost-goods/file-download", downloadFile, QUERY(String, filename)) {
//		return execDownloadFile(filename);
//	}
//
//	// ����һ�����ļ��ϴ��ӿ�
//	// ��������
//	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("CostGoodsQuery.file.upload"), uploadFile, StringJsonVO::Wrapper);
//	// ����˵�
//	API_HANDLER_ENDPOINT(API_M_POST, "/cost-goods/file-upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));
//
//private:
//	// 3.3 ɾ������
//	StringJsonVO::Wrapper execwaydelete(const String& code);
//
//	// ִ��excel�ļ����ش���
//	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
//
//	// ִ�е��ļ��ϴ�����
//	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
//};
//
//// 0 ȡ��API������ʹ�ú�
//#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
//#endif 
