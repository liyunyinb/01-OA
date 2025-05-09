#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_CONTROLLER_
#define _HUO_QU_CANG_WEI_SHU_JU_CONTROLLER_
#include "domain/GlobalInclude.h"
#include "domain/vo/cangweitu/HuoQuCangWeiShuJuVO.h"
#include "domain/query/cangweitu/HuoQuCangWeiShuJuQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class HuoQuCangWeiShuJuController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(HuoQuCangWeiShuJuController);
public:
    // 3.1 �����ѯ�ӿ�����
    ENDPOINT_INFO(querystore) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("store.query-forward.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(HuoQuCangWeiShuJuJsonVO);
        // ����������ѯ��������
        API_DEF_ADD_QUERY_PARAMS(String, "bin_store", ZH_WORDS_GETTER("store.field.bin_store"), "1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("store.field.ku_wei_bian_ma"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "znode", ZH_WORDS_GETTER("store.field.znode"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "xnode", ZH_WORDS_GETTER("store.field.xnode"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "ynode", ZH_WORDS_GETTER("store.field.ynode"), "123", false);
    }

    ENDPOINT(API_M_GET, "/chuweiguanli/cangweitu/query-store", querystore, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(storeQuery, HuoQuCangWeiShuJuQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryStore(storeQuery));
    }

    //ENDPOINT_INFO(test) {
    //    info->summary = ZH_WORDS_GETTER("api.summary");
    //    //���������������Ϣ
    //    API_DEF_ADD_PAGE_PARAMS();
    //    //��Ӧ��ʽ����
    //    API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    //}
    //ENDPOINT("GET", "/test", test, QUERIES(QueryParams, params)) {
    //    //������ѯ����
    //    API_HANDLER_QUERY_PARAM(query, PageQuery, params);
    //    //��Ӧ������
    //    API_HANDLER_RESP_VO(excuteTest(query));
    //}
private:
    HuoQuCangWeiShuJuJsonVO::Wrapper execQueryStore(const HuoQuCangWeiShuJuQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif// !_HUO_QU_CANG_WEI_SHU_JU_CONTROLLER_