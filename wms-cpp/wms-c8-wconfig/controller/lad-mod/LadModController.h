#pragma once


#ifndef _LADMOD_CONTROLLER_
#define _LADMOD_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"

#include "domain/query/lad-mod/LadModQuery.h"
#include "domain/dto/lad-mod/LadModDTO.h"
#include "domain/vo/lad-mod/LadModVO.h"
#include "domain/dto/lad-mod/BatchDeleteRequestDto.h"
#include "oatpp/core/data/stream/FileStream.hpp"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
*�����ʽ-��Ϣ����
*/
class LadModController : public oatpp::web::server::api::ApiController {
	//ע�����
	API_ACCESS_DECLARE(LadModController);
public:
	
	// ��ѯ�ӿ�������Ϣ
	ENDPOINT_INFO(queryAll) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("lad.query-all.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LadModPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("lad.field.code"), "SELF", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("lad.field.name"), "test", false);
	}
	//��ѯ�ӿ�
	ENDPOINT(API_M_GET, "/wconfig/ladmod", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ�� ����ΪLadModQuery��ʽ������,��������query�ﶨ��Ĳ�ѯģ��,���浽ladQuery���������
		API_HANDLER_QUERY_PARAM(ladQuery, LadModQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(ladQuery));
		
	}
	// ������ݽӿ�������Ϣ
	ENDPOINT_INFO(addLad) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("lad.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	
	//������ݽӿ� ��ӵ����ݸ�ʽΪAddDTO����������DTO�ﶨ������ݸ�ʽ,�ӿڵ����ֽ�addLad
	ENDPOINT(API_M_POST, "/wconfig/ladmod", addLad, BODY_DTO(LadModAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddLad(dto));
	}

	//�޸����ݽӿ�������Ϣ
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("lad.modify.summary"), modifyLadMod, Uint64JsonVO::Wrapper);
	//�����޸����ݽӿ�
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/wconfig/ladmod", modifyLadMod, BODY_DTO(LadModDTO::Wrapper, dto), execModifyLadMod(dto));

	// ɾ�������ӿ�������Ϣ
	ENDPOINT_INFO(deleteLad) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("lad.delete.summary"), Uint64JsonVO::Wrapper);
		// �������˵��
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("lad.field.id"), 1, true);
	}
	// ����ɾ�������ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/wconfig/ladmod/delete", deleteLad, QUERY(UInt64, id), execDeleteLad(id));

	// ����ɾ���ӿ�������Ϣ
	ENDPOINT_INFO(batchDelete) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("lad.batchDelete.summary"), Uint64JsonVO::Wrapper);
	}
	// ��������ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/wconfig/ladmod/batch-delete", batchDelete, BODY_DTO(BatchDeleteRequestDto::Wrapper, dto), execBatchDeleteLad(dto));

	// ���������ʽ�ӿ�������Ϣ
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("lad.import.summary"), importLad, StringJsonVO::Wrapper);
	// ���������ʽ�˵㶨��
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/wconfig/ladmod/import", importLad, REQUEST(std::shared_ptr<IncomingRequest>, request), execImportLad(request));

	// ���������ʽ�ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("lad.export.summary"), exportLad, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/wconfig/ladmod/export", exportLad, execExportLad());
private:
	//��ѯ���ΪVO�������Ƕ����PageJsonVo,����ҳ����,�������Ϊquery���е�LadModQuery
	LadModPageJsonVO::Wrapper execQueryAll(const LadModQuery::Wrapper& query);
	//��ӽ��ΪVO���е���ͨJsonVo,����ͨ��ʾ����,�������ΪDTO���е�AddDTO
	Uint64JsonVO::Wrapper execAddLad(const LadModAddDTO::Wrapper& dto);
	//�޸Ľ��ΪVO���е���ͨJsonVo,����ͨ��ʾ����,�������ΪDTO���е�AddDTO(�޸ĺ���Ӷ��õ���AddDTO)
	Uint64JsonVO::Wrapper execModifyLadMod(const LadModDTO::Wrapper& dto);
	//ɾ�����������ʽ
	Uint64JsonVO::Wrapper execDeleteLad(const oatpp::UInt64& id);
	//����ɾ��
	Uint64JsonVO::Wrapper execBatchDeleteLad(const BatchDeleteRequestDto::Wrapper& dto);
	//���������ʽ
	StringJsonVO::Wrapper execImportLad(std::shared_ptr<IncomingRequest> request);
	//���������ʽ
	StringJsonVO::Wrapper execExportLad();
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _LadMod_CONTROLLER_