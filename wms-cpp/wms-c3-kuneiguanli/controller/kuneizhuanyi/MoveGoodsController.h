#pragma once

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"
#include "domain/vo/kuneizhuanyi/MoveGoodsVO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MoveGoodsController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(MoveGoodsController);

public:
	// [��ҳ��ѯת�������б�]�ӿ�
	ENDPOINT_INFO(queryMoveGoodsList) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("move-goods.get.summary"), MoveGoodsPageJsonVO::Wrapper);
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("move-goods.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods-id", ZH_WORDS_GETTER("move-goods.field.goods-id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods-name", ZH_WORDS_GETTER("move-goods.field.goods-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus-code", ZH_WORDS_GETTER("move-goods.field.cus-code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus-name", ZH_WORDS_GETTER("move-goods.field.cus-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "to-cus-code", ZH_WORDS_GETTER("move-goods.field.to-cus-code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "to-cus-name", ZH_WORDS_GETTER("move-goods.field.to-cus-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin-from", ZH_WORDS_GETTER("move-goods.field.tin-from"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin-id", ZH_WORDS_GETTER("move-goods.field.tin-id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin-from", ZH_WORDS_GETTER("move-goods.field.bin-from"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin-to", ZH_WORDS_GETTER("move-goods.field.bin-to"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "move-sta", ZH_WORDS_GETTER("move-goods.field.move-sta"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "run-sta", ZH_WORDS_GETTER("move-goods.field.run-sta"), "", false);
	}
	ENDPOINT(API_M_GET, "/kuneizhuanyi/query-move-goods-list", queryMoveGoodsList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(moveGoodsQueryy, MoveGoodsQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryMoveGoodsList(moveGoodsQueryy, authObject->getPayload()));
	}


	// [�޸�ת������]�ӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("move-goods.put.modify.summary"), modifyMoveGoods, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneizhuanyi/modify-move-goods", modifyMoveGoods, BODY_DTO(MoveGoodsModifyDTO::Wrapper, dto), execModifyMoveGoods(dto));

	// [����ת������]�ӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("move-goods.put.batch.summary"), batchMoveGoods, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneiguanli/kuneizhuanyi/batch-move-goods", batchMoveGoods, BODY_DTO(MoveGoodsBatchDTO::Wrapper, dto), execBatchMoveGoods(dto));

	//  ����[ɾ��ת������֧��������]�ӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("move-goods.delete.batch.summary"), batchRemoveMoveGoods, Uint64JsonVO::Wrapper)
		ENDPOINT(API_M_DEL, "/kuneiguanli/kuneizhuanyi/batch-remove-move-goods", batchRemoveMoveGoods, BODY_DTO(String, id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execBatchRemoveMoveGoods(id,authObject->getPayload()));
	}

	// ����[��ȡת��������ϸ��Ϣ]�ӿ�
	ENDPOINT_INFO(queryDetailedMoveGoods) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("move-goods.getdetailed.summary"), MoveGoodsDetailedJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("move-goods.field.id"), "", false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/kuneiguanli/kuneizhuanyi/query-detailed-move-goods", queryDetailedMoveGoods, 
		QUERY(String, id), execQueryDetailedMoveGoods(id));


	//	����[����ת��-��������]�ӿ�
	ENDPOINT_INFO(downLoadMoveGoodsExcel) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("move-goods.getdownload.summary"), Void);
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "file_path", ZH_WORDS_GETTER("move-goods.field.file_path"), "C:\\", true);
		API_DEF_ADD_QUERY_PARAMS(String, "ids", ZH_WORDS_GETTER("move-goods.field.id"), String{ "4028ab1b95559083019555a4182a001c" }, true);
	}
	ENDPOINT(API_M_GET, "/kuneiguanli/kuneizhuanyi/down-load-move-goods", downLoadMoveGoodsExcel, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(ids, MoveGoodsExcelQuery, queryParams);
		return execDownLoadMoveGoods(ids);
	}

private:
	// ִ�з�ҳ��ѯת�������б�
	MoveGoodsPageJsonVO::Wrapper execQueryMoveGoodsList(const MoveGoodsQuery::Wrapper& moveGoodsQuery, const PayloadDTO& payload);
	// ִ���޸�ת������
	Uint64JsonVO::Wrapper execModifyMoveGoods(const MoveGoodsModifyDTO::Wrapper& moveGoodsModifyDTO);
	// ִ������ת������
	Uint64JsonVO::Wrapper execBatchMoveGoods(const MoveGoodsBatchDTO::Wrapper& moveGoodsBatchDTO);
	// ִ��ɾ��ת������֧��������
	StringJsonVO::Wrapper execBatchRemoveMoveGoods(const String& id, const PayloadDTO& payload);
	// ִ�л�ȡת��������ϸ��Ϣ
	MoveGoodsDetailedJsonVO::Wrapper execQueryDetailedMoveGoods(const String& id);
	// ִ�е���ת������
	std::shared_ptr<OutgoingResponse> execDownLoadMoveGoods(const MoveGoodsExcelQuery::Wrapper& ids);
};