#ifndef _PRODUCTCONTROLLER_
#define _PRODUCTCONTROLLER_
#include"domain/vo/BaseJsonVO.h"
#include "oatpp/web/server/api/ApiController.hpp"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"
#include "domain/GlobalInclude.h"
#include"../../domain/dto/goodcategory/ProductDTO.h"
#include"../../domain/vo/goodcategory/ProductVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class ProductController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(ProductController);
public:
    //1.����¼����Ʒ��Ŀ�ӿ�
    ENDPOINT_INFO(addproduct) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.add.summary"));
        // ����Ĭ����Ȩ����
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    ENDPOINT(API_M_POST, "/gc/add-gc", addproduct, BODY_DTO(ProductListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execAddProduct(dto));
    }
    //2.�����޸���Ʒ��Ŀ�ӿ�
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("product.modify.summary"), modifyProduct, StringJsonVO::Wrapper);
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/gc/modify-gc", modifyProduct, BODY_DTO(ProductListDTO::Wrapper, dto), execModifyProduct(dto));
    //3.����ɾ����Ʒ��Ŀ�ӿ�
    ENDPOINT_INFO(removeProduct) {
        // �������ͷ��������Լ���Ȩ֧��
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("product.delete.summary"), StringJsonVO::Wrapper);
        // ��������·������˵��
        API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("product.field.categorynum"), 1, true);
    }
    // 3.2 ����ɾ���ӿڴ���
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/gc/delete-gc", removeProduct, PATH(String, id), execRemoveProduct(id));
private:
    StringJsonVO::Wrapper execAddProduct(const ProductListDTO::Wrapper& dto);
    StringJsonVO::Wrapper execModifyProduct(const ProductListDTO::Wrapper& dto);
    StringJsonVO::Wrapper execRemoveProduct(const String& id);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif // !_PRODUCTCONTROLLER_