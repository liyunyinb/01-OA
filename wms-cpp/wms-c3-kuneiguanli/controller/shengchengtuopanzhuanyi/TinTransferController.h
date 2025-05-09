#pragma once

#ifndef _TIN_TRANSFER_CONTROLLER_
#define _TIN_TRANSFER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/shengchengtuopanzhuanyi/TinTransferQuery.h"
#include "domain/dto/shengchengtuopanzhuanyi/TinTransferDTO.h"
#include "domain/vo/shengchengtuopanzhuanyi/TinTransferVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 
 */
class TinTransferController	: public oatpp::web::server::api::ApiController 
{
	// ����������������
	API_ACCESS_DECLARE(TinTransferController);
	
public:
	// [��ת���б�]�ӿ�
	ENDPOINT_INFO(queryTinTransferList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("assignment.get.tin.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(TinTransferJsonVO);
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

	ENDPOINT(API_M_GET, "/shengchengtuopanzhuanyi/query-tin-transfer-list", queryTinTransferList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(pageQuery, TinTransferQuery, queryParams);
		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryTinTransferList(pageQuery));
	}

	//[����ת������(֧������)]�ӿ�
	ENDPOINT_INFO(modifyTinTransfer) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("assignment.put.tin.modify.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ��Ӧ��ʽ����
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/shengchengtuopanzhuanyi/modify-tin-transfer", modifyTinTransfer, BODY_DTO(TinTransferBaseDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyTinTransfer(dto));
	}

		
private:
	// ִ�п�ת���б��ѯ
	TinTransferJsonVO::Wrapper execQueryTinTransferList(const TinTransferQuery::Wrapper& query);
	// ִ������ת������(֧������)
	StringJsonVO::Wrapper execModifyTinTransfer(const TinTransferBaseDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) 

#endif // _TIN_TRANSFER_CONTROLLER_