#pragma once
#ifndef _DELETE_CONTROLLER_
#define _DELETE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/delete-industry-class/DeleteDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DeleteController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteController);
	// 3 ����ӿ�
public:
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(DeleteClass) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("chengfeng.delete"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("chengfeng.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/indclas/delete-indclas", DeleteClass, BODY_DTO(DeleteDTO::Wrapper, id), execDeleteClass(id));

	

private:	
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execDeleteClass(const DeleteDTO::Wrapper& id);

	
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DELETE_CONTROLLER_