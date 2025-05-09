#pragma once

#ifndef _BILLING_NAME_CONTROLLER_
#define _BILLING_NAME_CONTROLLER_


#include "../../domain/dto/billing-name/BillingNameDTO.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"

#include "../../domain/query/billing-name/BillingNameQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �������ƿ���������ʾ����������ؽӿڵ�ʹ��
 */
class BillingNameController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(BillingNameController);

public:
    //����ɾ��
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(batchdeleteBillingName) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("billing-name.delete.batchdelete"), StringJsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("billing-name.delete.id"), "123456", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/billing-name/batch-delete/{id}", batchdeleteBillingName, BODY_DTO(BillingNameBatchDTO::Wrapper, bathdto), execbatchdeleteBillingName(bathdto));
  
    
    
    //
    ///*������������--*/
    ENDPOINT_INFO(exportBillingName) {
    //    // ����ӿڱ���
       API_DEF_ADD_TITLE(ZH_WORDS_GETTER("billing-name.filedownload.excel"));
       API_DEF_ADD_AUTH();
    //    // ������Ӧ������ʽ
       API_DEF_ADD_QUERY_PARAMS(String, "cost_code", ZH_WORDS_GETTER("billing-name.field.cost_code"), "123456", false);
       API_DEF_ADD_QUERY_PARAMS(String, "cost_name", ZH_WORDS_GETTER("billing-name.field.cost_name"), "123456", false);
       API_DEF_ADD_QUERY_PARAMS(String, "cost_type_code", ZH_WORDS_GETTER("billing-name.field.cost_type_code"), "123456", false);
    }
    //// ����˵�
    ENDPOINT(API_M_GET, "/billing-name/download", exportBillingName, QUERIES(QueryParams, exportParams), API_HANDLER_AUTH_PARAME) {
    //    // ������ѯ����ΪExportGoodsDiffPostQuery����ģ��
       API_HANDLER_QUERY_PARAM(exportQuery, BillingNameQuery, exportParams);
    //    // ����ִ�к�����Ӧ���

       return execExportName(exportQuery);
    }
    //�����������
    ENDPOINT_INFO(uploadBillingName) {
        //    // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("billing-name.fileupload.excel"));
        API_DEF_ADD_AUTH();
    }
    
    API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/billing-name/upload", uploadBillingName, REQUEST(std::shared_ptr<IncomingRequest>, request), execuploadName(request));

 
private:
	StringJsonVO::Wrapper execbatchdeleteBillingName(const BillingNameBatchDTO::Wrapper& bathdto);
    std::shared_ptr<OutgoingResponse> execExportName(const BillingNameQuery::Wrapper& query);
    StringJsonVO::Wrapper execuploadName(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_COST_NAME_CONTROLLER_