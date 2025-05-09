#pragma once

#ifndef _CANGKUDINGYICONTROLLER_H_
#define _CANGKUDINGYICONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/cangkudingyi/CangkuNameListDTO.h"
#include "domain/dto/cangkudingyi/CangkuListDTO.h"
#include "domain/query/cangkudingyi/CangkuListQuery.h"
#include "domain/dto/cangkudingyi/deleteCangkuDTO.h"
#include "domain/vo/cangkudingyi/CangkuVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CangKuDingYiController : public oatpp::web::server::api::ApiController
{
	//	����������������
	API_ACCESS_DECLARE(CangKuDingYiController);

	//  ����ӿ�
public:

	//	�����ȡ�ֿ������б�ӿ�����
	ENDPOINT_INFO(listCangkuName) {
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.get_cangku_name_list"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CangkuNameListJsonVO);
	}
	//	���� ��ȡ�ֿ������б�ӿ� ����
	ENDPOINT(API_M_GET, "/chuweiguanli/cangkudingyi/query-cangku-name-list", listCangkuName, API_HANDLER_AUTH_PARAME) {
		//	����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execListCangkuName(authObject->getPayload()));
	}

	//	���� ɾ���ֿ� �ӿ�����
	ENDPOINT_INFO(deleteCangku) {
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.delete_cangku.summary"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		////	����������ֿ�ID�б�
		//API_DEF_ADD_PATH_PARAMS(oatpp::List<UInt64>, "id_list", ZH_WORDS_GETTER("Cangku.EndPoint.delete_cangku.params.ids"), 10086, false);

	}
	//	���� ɾ���ֿ� �ӿ� ����
	ENDPOINT(API_M_DEL, "/chuweiguanli/cangkudingyi/delete-cangku-by-id", deleteCangku, BODY_DTO(DeleteCangkuDTO::Wrapper, id_list), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDeleteCangku(id_list, authObject->getPayload()));
	}

	//	���� �����ֿ�ӿ� ����
	ENDPOINT_INFO(downLoadCangkuExcel) {
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.down_load_cangku_excel.summary"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//	����������ֿ����

		//API_DEF_ADD_QUERY_PARAMS(oatpp::String, "store_code", ZH_WORDS_GETTER("Cangku.EndPoint.down_load_cangku_excel.params.store_code"), "001-FKD", false);
	}
	//	���� �����ֿ�ӿ� ����

	ENDPOINT(API_M_GET, "/chuweiguanli/cangkudingyi/down-load-cangku-excel", downLoadCangkuExcel, BODY_DTO(ExportCangkuDTO::Wrapper, store_code_list), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDownLoadCangkuExcel(store_code_list, authObject->getPayload()));
	}

	//	���� ��ȡ�ֿ��б�ӿ� ����
	ENDPOINT_INFO(listCangku)
	{
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.get_cangku_list"));

		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ

		API_DEF_ADD_RSP_JSON_WRAPPER(CangkuListPageJsonVO);
		//	�����������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "store_code", ZH_WORDS_GETTER("store.store_code"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_name", ZH_WORDS_GETTER("store.store_name"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_text", ZH_WORDS_GETTER("store.store_text"), "xxx", false);
	}

	//	���� ��ȡ�ֿ��б�ӿ� ����

	ENDPOINT(API_M_GET, "/chuweiguanli/query-cangku-list", listCangku, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(cangkulistQuery, CangkuListQuery, queryParams);
		//	����ִ�к�����Ӧ���

		API_HANDLER_RESP_VO(execListCangku(cangkulistQuery, authObject->getPayload()));
	}


	// ���� ����ֿ� ����
	ENDPOINT_INFO(upload)
	{
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.up_load_cangku_excel.summary"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ���� ����ֿ� �˵�
	ENDPOINT(API_M_POST, "/chuweiguanli/cangkudingyi/upload", upload, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execUpload(request));
	}
private:
	//	��ȡ�ֿ������б�ִ�к���
	CangkuNameListJsonVO::Wrapper execListCangkuName(const PayloadDTO& payload);
	//	ɾ���ֿ�ִ�к���
	StringJsonVO::Wrapper execDeleteCangku(const DeleteCangkuDTO::Wrapper& id_list, const PayloadDTO& payload);
	//	�����ֿ�ִ�к���

	StringJsonVO::Wrapper execDownLoadCangkuExcel(const ExportCangkuDTO::Wrapper& store_code_list, const PayloadDTO& payload);
	//	��ȡ�ֿ��б�ִ�к���

	CangkuListPageJsonVO::Wrapper execListCangku(const CangkuListQuery::Wrapper& query, const PayloadDTO& payload);
	// ����ֿ�ִ�к���
	StringJsonVO::Wrapper execUpload(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)



#endif // _CANGKUDINGYICONTROLLER_H_
