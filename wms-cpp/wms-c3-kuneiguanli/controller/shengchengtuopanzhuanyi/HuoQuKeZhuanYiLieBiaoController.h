#pragma once
#ifndef _HUO_QU_KE_ZHUAN_YI_LIE_BIAO_CONTROLLER_
#define _HUO_QU_KE_ZHUAN_YI_LIE_BIAO_CONTROLLER_
#include "domain/GlobalInclude.h"
#include "domain/vo/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoVO.h"
#include "domain/query/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
 ��ת���б�
*/
class HuoQuKeZhuanYiLieBiaoController : public oatpp::web::server::api::ApiController {

    API_ACCESS_DECLARE(HuoQuKeZhuanYiLieBiaoController);

public:
    ENDPOINT_INFO(queryALL) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tuopanzhuanyi.query-all.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(HuoQuKeZhuanYiLieBiaoPageJsonVO);
        // �����ҳ��ѯ��������
        API_DEF_ADD_PAGE_PARAMS();
        // ����������ѯ��������
        //API_DEF_ADD_QUERY_PARAMS(String, "move_date", ZH_WORDS_GETTER("tuopanzhuanyi.field.move_date"), "2022/2/22", false);
        API_DEF_ADD_QUERY_PARAMS(String, "kuctype", ZH_WORDS_GETTER("tuopanzhuanyi.field.kuctype"), "1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("tuopanzhuanyi.field.ku_wei_bian_ma"), "1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("tuopanzhuanyi.field.bin_id"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cus_code", ZH_WORDS_GETTER("tuopanzhuanyi.field.cus_code"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "zhong_wen_qch", ZH_WORDS_GETTER("tuopanzhuanyi.field.zhong_wen_qch"), "zhang san", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_id"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "shp_ming_cheng", ZH_WORDS_GETTER("tuopanzhuanyi.field.shp_ming_cheng"), "kele", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_date", ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_pro_date"), "2022/2/2", false);
    }

    ENDPOINT(API_M_GET, "/kuneiguanli/shengchengtuopanzhuanyi/query-move-list", queryALL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(kezhuanyiQuery, HuoQuKeZhuanYiLieBiaoQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryAll(kezhuanyiQuery));
    }

private:
    HuoQuKeZhuanYiLieBiaoPageJsonVO::Wrapper execQueryAll(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif // !_HUO_QU_KE_ZHUAN_YI_LIE_BIAO_CONTROLLER_