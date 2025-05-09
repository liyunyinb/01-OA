#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: BigTomato
 @Date: 2025/02/19 10:53:52

.
*/
#ifndef _GOODSCONTROLLER_H_
#define _GOODSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/goods/GoodsDTO.h"
#include "../../domain/vo/goods/GoodsVo.h"
#include "../../domain/query/goods/GoodsQuery.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GetGoodsController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(GetGoodsController);
public: // ����ӿ�
	// ��ѯ��Ʒ��Ŀ������
	ENDPOINT_INFO(queryGoods) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goods.get.summary"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GoodsJsonVO);
	}
	ENDPOINT(API_M_GET, "/gc/query-category-tree", queryGoods,API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGoods());
	}

	// 3.1 ����ID��ѯ�ӿ�����
	ENDPOINT_INFO(queryById) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("goods.getbyid.summary"), CombineGoodsJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("goods.id"), 1, false);		// ���Բ�������,����������ȡһ����Ŀ����
	}
	// 3.2 ����ID��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/gc/query-by-id", queryById, QUERY(Int64, id), execById(id));
	

	// 3.1 ����ID��ѯ�ӿ�����
	ENDPOINT_INFO(queryNoId) {
		// ����ͨ������
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goods.getnoid.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CombineGoodsJsonVO);
	}
	// 3.2 ����ID��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/gc/query-no-id", queryNoId, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execNoId());
	}


	// �ļ��ϴ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("goods.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/gc/export-categories", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne( request,authObject->getPayload() ) );

	//�ļ�����
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("goods.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("goods.download.summary2"), "goods_category.xlsx", true);
		API_DEF_ADD_AUTH();
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/gc/import-categories", downloadFile, QUERY(String, filename),API_HANDLER_AUTH_PARAME) {
		return execDownloadFile(filename);
	}

private: // ����ӿ�ִ�к���
	CombineGoodsJsonVO::Wrapper execQueryGoods();
	CombineGoodsJsonVO::Wrapper execById(const Int64& id);
	CombineGoodsJsonVO::Wrapper execNoId();
	
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GOODSCONTROLLER_H_