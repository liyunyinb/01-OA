#pragma once

#ifndef _BIN_TRANSFER_CONTROLLER_
#define _BIN_TRANSFER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/shengchengchuweizhuanyi/BinTransferQuery.h"
#include "domain/dto/shengchengchuweizhuanyi/BinTransferDTO.h"
#include "domain/vo/shengchengchuweizhuanyi/BinTransferVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 *
 */
class BinTransferController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(BinTransferController);

public:
	// [��ת���б�]�ӿ�
	ENDPOINT_INFO(queryBinTransfer) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("assignment.get.bin.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BinTransferJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

		//Ψһ��ʶ
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("assignment.field.id"), "", false);
		// �ƶ�����
		API_DEF_ADD_QUERY_PARAMS(String, "moveDate", ZH_WORDS_GETTER("assignment.field.move-date"), "", false);
		// ������ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "toMoveDate", ZH_WORDS_GETTER("assignment.field.to-move-date"), "", false);
		// �������
		API_DEF_ADD_QUERY_PARAMS(String, "inventoryType", ZH_WORDS_GETTER("assignment.field.inventory-type"), "", false);
		// ��λ
		API_DEF_ADD_QUERY_PARAMS(String, "bin", ZH_WORDS_GETTER("assignment.field.bin"), "", false);
		// ����
		API_DEF_ADD_QUERY_PARAMS(String, "tin", ZH_WORDS_GETTER("assignment.field.tin"), "", false);
		// ����
		API_DEF_ADD_QUERY_PARAMS(String, "cusCode", ZH_WORDS_GETTER("assignment.field.cus-code"), "", false);
		// ��������
		API_DEF_ADD_QUERY_PARAMS(String, "cusName", ZH_WORDS_GETTER("assignment.field.cus-name"), "", false);
		// ��Ʒ����
		API_DEF_ADD_QUERY_PARAMS(String, "goodsID", ZH_WORDS_GETTER("assignment.field.goods-id"), "", false);
		//��Ʒ����
		API_DEF_ADD_QUERY_PARAMS(String, "goodsName", ZH_WORDS_GETTER("assignment.field.goods-name"), "", false);
		//��������
		API_DEF_ADD_QUERY_PARAMS(String, "produceDate", ZH_WORDS_GETTER("assignment.field.produce-date"), "", false);
		// ����������
		API_DEF_ADD_QUERY_PARAMS(String, "toProduceDate", ZH_WORDS_GETTER("assignment.field.to-produce-date"), "", false);
	}

	ENDPOINT(API_M_GET, "/shengchengchuweizhuanyi/query-bin-transfer", queryBinTransfer, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(pageQuery, BinTransferQuery, queryParams);
		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryBinTransfer(pageQuery));
	}

	//[����ת������(֧������)]�ӿ�
	ENDPOINT_INFO(modifyBinTransfer) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("assignment.put.bin.modify.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ��Ӧ��ʽ����
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/shengchengchuweizhuanyi/modify-bin-transfer", modifyBinTransfer, BODY_DTO(BinTransferListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyBinTransfer(dto));
	}


private:
	// ִ�п�ת���б��ѯ
	BinTransferJsonVO::Wrapper execQueryBinTransfer(const BinTransferQuery::Wrapper& query);
	// ִ������ת������(֧������)
	StringJsonVO::Wrapper execModifyBinTransfer(const BinTransferListDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) 

#endif // _BIN_TRANSFER_CONTROLLER_