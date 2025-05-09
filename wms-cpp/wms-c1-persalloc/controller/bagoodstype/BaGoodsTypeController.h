#pragma once
#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/bagoodstype/BaGoodsTypeDTO.h"
#include "domain/query/bagoodstype/BaGoodsTypeQuery.h"
#include "domain/vo/bagoodstype/BaGoodsTypeVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class BaGoodsTypeController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(BaGoodsTypeController);
public:
    //��ѯ��Ʒ���Խӿ�����
    ENDPOINT_INFO(getBaGoodsType) {
        //��Ϣ
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ba_goods_type.get.summary"));
        //��Ȩ
        API_DEF_ADD_AUTH();

        //��ҳ��ѯ
        API_DEF_ADD_PAGE_PARAMS();

        API_DEF_ADD_RSP_JSON_WRAPPER(BaGoodsTypeNamePageJsonVO);
    }
    //��ѯ��Ʒ���Խӿڴ���
    ENDPOINT("GET", "/pa/list-pa", getBaGoodsType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(userQuery, BaGoodsTypeQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryBaGoodsType(userQuery, authObject->getPayload()));
    }

private:
    //��ҳ��ѯ��Ʒ����
    BaGoodsTypeNamePageJsonVO::Wrapper execQueryBaGoodsType(const BaGoodsTypeQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) ///< En