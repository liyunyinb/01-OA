#pragma once
#ifndef _ADDITION_CONTROLLER_
#define _ADDITION_CONTROLLER_

#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"

#include "../../domain/vo/addition-adjustment/AdditionVO.h"
//#include "../../domain/query/removal-adjustment/RemovalQuery.h"
#include "../../domain/dto/addition-adjustment/AdditionDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class AdditionController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AdditionController);
	// 3 ����ӿ�
public:
	
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("addition-adjustment.post.batchmodify_goods"), batchmodifyAddition, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/addition-adjustment/batchmodify",batchmodifyAddition,BODY_DTO(AdditionBatchDTO::Wrapper,bathdto),execbatchAddition(bathdto));
private:
	StringJsonVO::Wrapper execbatchAddition(const AdditionBatchDTO::Wrapper& batchdto);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 