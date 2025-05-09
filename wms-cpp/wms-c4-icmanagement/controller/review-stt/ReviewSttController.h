#pragma once
/*

 @Author: qingbingwei
 @Date: 2025/3/10 14:22

*/
#ifndef _REVIEW_STT_CONTROLLER_
#define _REVIEW_STT_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "domain/query/review-stt/ReviewSttQuery.h"
#include "domain/dto/review-stt/ReviewSttDTO.h"
#include "domain/vo/review-stt/ReviewSttVO.h"
#include "Macros.h"
#include "ExcelComponent.h"



// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �̵����-����
 */
class ReviewSttController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ReviewSttController);
	// 3 ����ӿ�
public:

	//��ѯ�̵��б�����+��ҳ��
	ENDPOINT_INFO(queryAll) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("review-stt.goods.query-all.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewSttPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������---��ʱ���������������ϣ���Ϊ�е��
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("review-stt.goods.field.bin_id"), "X1-1-03", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("review-stt.goods.field.tin_id"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("review-stt.goods.field.goods_id"), "20222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("review-stt.goods.field.goods_name"), ZH_WORDS_GETTER("review-stt.goods.name.demo1"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("review-stt.goods.field.goods_pro_data"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("review-stt.goodsfield.goods_batch"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("review-stt.goods.field.cus_name"), ZH_WORDS_GETTER("review-stt.goods.name.demo2"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus", ZH_WORDS_GETTER("review-stt.goods.field.cus"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("review-stt.goods.field.stt_sta"), "null", false);
	}

	ENDPOINT(API_M_GET, "/review/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪReviewSttQuery����ģ��
		API_HANDLER_QUERY_PARAM(goodsQuery, ReviewSttQuery, queryParams);
		// ����ִ�к�����Ӧ���
		//API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
		API_HANDLER_RESP_VO(execQueryAll(goodsQuery));
	}

	//����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("review-stt.goods.review.summary"), reviewStt, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/review/review-stt", reviewStt, BODY_DTO(ReviewSttDTO::Wrapper, dto), execReviewStt(dto, authObject->getPayload()));

	//�������и�������---�в�ѯ����
	ENDPOINT_INFO(exportReviewStt) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("review-stt.goods.export-review-stt.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("review-stt.goods.field.bin_id"), "X1-1-03", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("review-stt.goods.field.tin_id"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("review-stt.goods.field.goods_id"), "20222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("review-stt.goods.field.goods_name"), ZH_WORDS_GETTER("review-stt.goods.name.demo1"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("review-stt.goods.field.goods_pro_data"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("review-stt.goods.field.goods_batch"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("review-stt.goods.field.cus_name"), ZH_WORDS_GETTER("review-stt.goods.name.demo2"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus", ZH_WORDS_GETTER("review-stt.goods.field.cus"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("review-stt.goods.field.stt_sta"), "null", false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/review/export-review-stt", exportReviewStt, QUERIES(QueryParams, exportParams)/*, API_HANDLER_AUTH_PARAME*/) {
		// ������ѯ����ΪExportGoodsDiffPostQuery����ģ��
		API_HANDLER_QUERY_PARAM(exportQuery, ExportReviewSttQuery, exportParams);
		// ����ִ�к�����Ӧ���
		//API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
		//API_HANDLER_RESP_VO(execExportDiffPost(exportQuery));
		return execExportReviewStt(exportQuery);
	}

private:
	ReviewSttPageJsonVO::Wrapper execQueryAll(const ReviewSttQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execReviewStt(const ReviewSttDTO::Wrapper& dto, const PayloadDTO& payload);
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportReviewStt(const ExportReviewSttQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_REVIEW_STT_CONTROLLER_
