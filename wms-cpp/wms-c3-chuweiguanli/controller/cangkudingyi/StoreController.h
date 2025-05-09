#pragma once
#ifndef _STORECONTROLLER_
#define _STORECONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/cangkudingyi/StoreDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

#define ADD_AUTH // �����Ҫ��Ȩ��ȡ��ע��

class StoreController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(StoreController);
public:
	// [���Ӳֿ�]�ӿ�
	ENDPOINT_INFO(addStore) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("store.add.summary"));
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_POST, "/chuweiguanli/cangkudingyi/add-store", addStore, BODY_DTO(StoreAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddStore(dto, authObject->getPayload()));
	}

	// [�޸Ĳֿ�]�ӿ�
	ENDPOINT_INFO(modifyStore) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("store.modify.summary"));
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_PUT, "/chuweiguanli/cangkudingyi/modify-store", modifyStore, BODY_DTO(StoreModifyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyStore(dto, authObject->getPayload()));
	}

private:
	// ִ�������ֿ����
	StringJsonVO::Wrapper execAddStore(const StoreAddDTO::Wrapper dto, const PayloadDTO& payload);
	// ִ���޸Ĳֿ����
	StringJsonVO::Wrapper execModifyStore(const StoreModifyDTO::Wrapper dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_STORECONTROLLER_

