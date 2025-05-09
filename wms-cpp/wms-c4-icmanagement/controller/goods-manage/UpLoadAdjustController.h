#pragma once
/*

 @Author: qingbingwei
 @Date: 2025/2/22 14:22

*/
#ifndef _UP_LOAD_ADJUST_CONTROLLER_
#define _UP_LOAD_ADJUST_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/goods-manage/GoodsDiffPostVO.h"
#include "domain/dto/goods-manage/GoodsDiffPostDTO.h"
#include "domain/query/goods-manage/GoodsDiffPostQuery.h"
//#include "Macros.h"
#include "ExcelComponent.h"
#include "../../../arch-tests/Macros.h"



// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �̵����-�̵�������
 */
class UpLoadAdjustController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UpLoadAdjustController);
	// 3 ����ӿ�
public:
	//���������ϼܵ�������---�в�ѯ����
	ENDPOINT_INFO(exportUpLoad) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("diff-post.goods.export-up-load.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		/*API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("goods.field.bin_id"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("goods.field.tin_id"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("goods.field.goods_id"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("goods.field.goods_name"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("goods.field.goods_pro_data"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("goods.field.goods_batch"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("goods.field.cus_name"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus", ZH_WORDS_GETTER("goods.field.cus"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("goods.field.stt_sta"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date_start", ZH_WORDS_GETTER("goods.field.create_date_start"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date_end", ZH_WORDS_GETTER("goods.field.create_date_end"), "****", false);*/
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/goods/export-up-load", exportUpLoad, QUERIES(QueryParams, exportParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪExportGoodsDiffPostQuery����ģ��
		API_HANDLER_QUERY_PARAM(exportQuery, ExportGoodsDiffPostQuery, exportParams);
		// ����ִ�к�����Ӧ���
		//API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
		API_HANDLER_RESP_VO(execExportUpLoad(exportQuery));
	}

private:
	Uint64JsonVO::Wrapper execExportUpLoad(const ExportGoodsDiffPostQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_UP_LOAD_ADJUST_CONTROLLER_