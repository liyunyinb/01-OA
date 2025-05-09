#pragma once
#ifndef _Comdeg_Controller_
#define _Comdeg_Controller_

#include "domain/GlobalInclude.h"
#include "domain/dto/comdeg/ComdegDTO.h"
#include "domain/vo/comdeg/ComdegVO.h"
#include "domain/query/comdeg/ComdegQuery.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/**
 * ��˾�ȼ���Ϣ����
 */
class ComdegController : public oatpp::web::server::api::ApiController {

    API_ACCESS_DECLARE(ComdegController)

public:
	ENDPOINT_INFO(querycomdegAll) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("com.query-all.summary"));
		
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ComdegPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "degname", ZH_WORDS_GETTER("com.field.degname"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "degcode", ZH_WORDS_GETTER("com.field.degcode"), "A", false);
		
	}


	// ���幫˾�ȼ���Ϣ��ѯ�ӿڴ���
    ENDPOINT(API_M_GET, "/entlevel/get-entlevellist", querycomdegAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {

		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(comdegQuery, ComdegQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execcomdegAll(comdegQuery));
    }

	//���幫˾�ȼ���Ϣ�����ӿ�����
	ENDPOINT_INFO(addcomdeg) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("com.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/entattr/add-entlevel", addcomdeg, BODY_DTO(ComdegAddDTO::Wrapper, dto)
										, execAddComdeg(dto, authObject->getPayload()));
	
	//���幫˾�ȼ���Ϣ�����ӿڴ���
	/*ENDPOINT(API_M_POST, "/entattr/add-entlevel", addcomdeg, BODY_DTO(ComdegDetailDTO::Wrapper, dto)) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddComdeg(dto, authObject->getPayload()));
	}*/

private:
	//��˾�ȼ���Ϣ��ҳ��ѯ����
	ComdegPageJsonVO::Wrapper execcomdegAll(const ComdegQuery::Wrapper& query);
	//��˾�ȼ���Ϣ��������
	Uint64JsonVO::Wrapper execAddComdeg(const ComdegAddDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_Comdeg_Controller_