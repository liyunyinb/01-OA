#pragma once

#ifndef _PIS_CONTROLLER_
#define _PIS_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/ba_qm_sta/PisQuery.h"
#include "domain/dto/ba_qm_sta/PisDTO.h"
#include "domain/vo/ba_qm_sta/PisVO.h"
#include "oatpp/web/server/api/ApiController.hpp"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"

// 1. ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class PisController : public oatpp::web::server::api::ApiController {
    // 2 ����������������
    API_ACCESS_DECLARE(PisController);
    // 3 ����ӿ�
public:
    // 3.1 ����pis��ҳ��ѯ�ӿ�����
    ENDPOINT_INFO(queryPis) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pis.get.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(PisPageJsonVO);
        // �����ҳ��ѯ��������
        API_DEF_ADD_PAGE_PARAMS();
        // ����������ѯ��������
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("pis.field.qm_sta_code"), "QS001", false);
        API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("pis.field.qm_sta_name"), ZH_WORDS_GETTER("pis.field.qm_sta_name_ex"), false);
    }
    // 3.2 ����qis��ҳ��ѯ�ӿڴ���
    ENDPOINT(API_M_GET, "/pis/list-pis", queryPis, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(userquery, PisQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryPis(userquery, authObject->getPayload()));
    }

    // 3.1 ����pis�������ݽӿ�����
    ENDPOINT_INFO(addPis) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pis.post.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    // 3.2 ����pis�������ݽӿڴ���
    ENDPOINT(API_M_POST, "/pis/add-pis", addPis, BODY_DTO(PisAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execAddPis(dto,authObject->getPayload()));
    }

    // 3.1 ����pis�޸Ľӿ�����
    ENDPOINT_INFO(modifyPis) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pis.put.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME)
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    // 3.2 ����pis�޸Ľӿڴ���
    ENDPOINT(API_M_PUT, "/pis/modify-pis", modifyPis, BODY_DTO(PisDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execModifyPis(dto,authObject->getPayload()));
    }

private:
    // 3.3 ��ʾ��ҳ��ѯ
    PisPageJsonVO::Wrapper execQueryPis(const PisQuery::Wrapper& query, const PayloadDTO& payload);
    // 3.3 ��ʾ��������
    StringJsonVO::Wrapper execAddPis(const PisAddDTO::Wrapper& dto,const PayloadDTO& payload);
    // 3.3 ��ʾ�޸�����
    StringJsonVO::Wrapper execModifyPis(const PisDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End ApiController codegen section
#endif



    // 3.1 ����pis-code������ѯ�ӿ�����
    //ENDPOINT_INFO(queryPisByCode) {
    //    // ����ͨ������
    //    API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("pis.query-by-code.summary"), PisJsonVO::Wrapper);
    //    // �����������
    //    API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("pis.field.qm_sta_code"), "1", true);
    //}
    //// 3.2 ����pis-code������ѯ�ӿڴ���
    //API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/pis/query-by-code", queryPisByCode, QUERY(String, code), execQueryByCode(code));

    // 3.1 ����pis-sta������ѯ�ӿ�����
    //ENDPOINT_INFO(queryPisBySta) {
    //    // ����ͨ������
    //    API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("pis.query-by-sta.summary"), PisJsonVO::Wrapper);
    //    // �����������
    //    API_DEF_ADD_QUERY_PARAMS(String, "sta", ZH_WORDS_GETTER("pis.field.qm_sta_name"), "yes", true);
    //}
    // 3.2 ����pis-sta������ѯ�ӿڴ���
    //API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/pis/query-by-sta", queryPisBySta, QUERY(String, sta), execQueryBySta(sta));

    // 3.3 ��ʾcode��ѯ����
    //PisJsonVO::Wrapper execQueryByCode(const String& code);
    // 3.3 ��ʾsta��ѯ����
    //PisJsonVO::Wrapper execQueryBySta(const String& sta);
