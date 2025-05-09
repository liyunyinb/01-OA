#pragma once
#pragma once
#include"domain/vo/BaseJsonVO.h"
#include"domain/GlobalInclude.h" 
#include"domain/query/PageQuery.h"
#include "domain/query/kongchuwei/GetKongChuWeiListMycontrollerQuery.h"
#include "domain/dto/kongchuwei/GetKongChuWeiListMycontrollerDTO.h"
#include "domain/vo/kongchuwei/GetKongChuWeiListMycontrollervo.h"
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class GetKongChuWeiListMycontroller : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(GetKongChuWeiListMycontroller);
public:
    /*
    * �մ�λ-��ÿմ�λ�б�
    */
    ENDPOINT_INFO(quaryGetKongChuWeiListMycontroller) {
        // ����Ĭ����Ȩ����
        API_DEF_ADD_AUTH();
        // ��ýӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("kongchuwei.get"));
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(GetKongChuWeiListMycontrollerJsonVO);
        // �����ҳ��ѯ��������
        
        API_DEF_ADD_PAGE_PARAMS();
        //Ψһ��ʶ
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("kongchuwei.quary.id"), "", false);
        //�ֿ�
        //API_DEF_ADD_QUERY_PARAMS(string, "bin_store", ZH_WORDS_GETTER("kongchuwei.quary.bin_store"), "", false);
        // ��λ����
        API_DEF_ADD_QUERY_PARAMS(String, "chuweishuxing", ZH_WORDS_GETTER("kongchuwei.quary.chuweishuxing"), "", false);
        // ��Ʒ����
        API_DEF_ADD_QUERY_PARAMS(String, "chp_shu_xing", ZH_WORDS_GETTER("kongchuwei.quary.chp_shu_xing"), "", false);
        // ��λ����
        API_DEF_ADD_QUERY_PARAMS(String, "chuweibaima", ZH_WORDS_GETTER("kongchuwei.quary.chuweibianma"), "", false);
        // �����ͻ�
        API_DEF_ADD_QUERY_PARAMS(String, "suo_shu_ke_hu", ZH_WORDS_GETTER("kongchuwei.quary.suo_shu_ke_hu"), "", false);
        // ������
        API_DEF_ADD_QUERY_PARAMS(String, "zui_da_ti_ji", ZH_WORDS_GETTER("kongchuwei.quary.zui_da_ti_ji"), "", false);
        // �ϼܴ���
        API_DEF_ADD_QUERY_PARAMS(String, "shang_jia_ci_XU", ZH_WORDS_GETTER("kongchuwei.quary.shang_jia_ci_XU"), "", false);
        // ����
        API_DEF_ADD_QUERY_PARAMS(String, "chang", ZH_WORDS_GETTER("kongchuwei.quary.chang"), "", false);
        // ���
        API_DEF_ADD_QUERY_PARAMS(String, "kuan", ZH_WORDS_GETTER("kongchuwei.quary.kuan"), "", false);
        // �߶�
        API_DEF_ADD_QUERY_PARAMS(String, "gao", ZH_WORDS_GETTER("kongchuwei.quary.gao"), "", false);
        // �������
        API_DEF_ADD_QUERY_PARAMS(String, "zui_da_tuo_pan", ZH_WORDS_GETTER("kongchuwei.quary.zui_da_tuo_pan"), "", false);
        //�Ƿ�ͣ��
        API_DEF_ADD_QUERY_PARAMS(String, "zhuang_tai", ZH_WORDS_GETTER("kongchuwei.quary.zhuang_tai"), "", false);
        //��λ����
        API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_lei_xing", ZH_WORDS_GETTER("kongchuwei.quary.ku_wei_lei_xing"), "", false);
    }
        //
        ENDPOINT(API_M_GET, "/chuweiguanli/kongchuwei/get-kongchuwei-list", quaryGetKongChuWeiListMycontroller, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
            //������ѯ����
            API_HANDLER_QUERY_PARAM(pageQuery, GetKongChuWeiListMycontrollerQuery, queryParams);
            //��Ӧ������
            API_HANDLER_RESP_VO(GetKongChuWeiListMycontrollerTest(pageQuery));

        }
private:
    GetKongChuWeiListMycontrollerJsonVO::Wrapper GetKongChuWeiListMycontrollerTest(const GetKongChuWeiListMycontrollerQuery::Wrapper & query);
 };

#include OATPP_CODEGEN_END(ApiController)
