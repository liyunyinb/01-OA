#pragma once
#ifndef _MODIFY_CONTROLLER_
#define _MODIFY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/modify-industry-class/ModifyDTO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifyController);
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("chengfeng.modify"), modifyClass, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/indclas/modify-indclas", modifyClass, BODY_DTO(ModifyDTO::Wrapper, dto), execModifyClass(dto));

private:
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyClass(const ModifyDTO::Wrapper& dto);


};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_