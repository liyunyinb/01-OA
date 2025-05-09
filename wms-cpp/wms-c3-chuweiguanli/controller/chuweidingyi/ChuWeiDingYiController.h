#pragma once

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/chuweidingyi/AddCWDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class ChuWeiDingYiController : public oatpp::web::server::api::ApiController
{
	//	����������������
	API_ACCESS_DECLARE(ChuWeiDingYiController);

	//  ����ӿ�
public:
	// ���� ¼�봢λ�ӿ� ����
	ENDPOINT_INFO(addCW)
	{
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("chuwei.add.summary"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ���� ¼�봢λ�ӿ� ����
	ENDPOINT(API_M_POST, "/chuweiguanli/chuweidingyi/add-CW", addCW, BODY_DTO(AddCWDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddCW(dto, authObject->getPayload()));
	}

private:
	StringJsonVO::Wrapper execAddCW(const AddCWDTO::Wrapper dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)