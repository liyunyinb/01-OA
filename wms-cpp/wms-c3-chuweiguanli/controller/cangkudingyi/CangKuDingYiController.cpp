#include "stdafx.h"
#include "CangKuDingYiController.h"
#include "../../service/cangkudingyi/CangKuDingYiService.h"
#include "service/cangkudingyi/StoreService.h"

CangkuNameListJsonVO::Wrapper CangKuDingYiController::execListCangkuName(const PayloadDTO& payload) {
	//	������Ӧ���
	auto jvo = CangkuNameListJsonVO::createShared();

	//	���ݼ��飬��ʱ����У��
	if (payload.getCode() != PayloadCode::SUCCESS) {
		
	}
	else {
		//	Service��
		CangKuDingYiService service;
		//	��ѯ�ֿ������б�
		auto result = service.getCangkuNameList();
        //	�����
		jvo->success(result);
	}
	
	

	return jvo;
}

//	ɾ���ֿ⣨֧������ɾ����
StringJsonVO::Wrapper CangKuDingYiController::execDeleteCangku(const DeleteCangkuDTO::Wrapper& id_list, const PayloadDTO& payload) {
	//	������Ӧ���
	auto jvo = StringJsonVO::createShared();

	if (payload.getCode() != PayloadCode::SUCCESS) {
		return {};
	}
	else {
		//	��������
		if (id_list->id->empty()) {	//	����Ϊ��
			jvo->init("error", RS_PARAMS_INVALID);
			return jvo;
		}
		
		//	Service��
		CangKuDingYiService service;
		//	ִ������ɾ��
		bool res = service.deleteCangkuById_List(id_list->id);
        if (res) {
			jvo->init("success", RS_SUCCESS);
		}
		else {
			jvo->init("error", RS_FAIL);
		}

		return jvo;
	}
}


//	���ֿ������б���ΪExcel�ļ�����������·��
StringJsonVO::Wrapper CangKuDingYiController::execDownLoadCangkuExcel(const ExportCangkuDTO::Wrapper& store_code_list, const PayloadDTO& payload) {
	//	������Ӧ���
	auto jvo = StringJsonVO::createShared();
	
	if (payload.getCode() != PayloadCode::SUCCESS) {
		return {};
	}
	else {
		//	Service��
		CangKuDingYiService service;
		auto res = service.getpath_exportCangkuByCodeList(store_code_list->store_id);
		jvo->init("download_url: " + res, RS_SUCCESS);
	}

    return jvo;
}


CangkuListPageJsonVO::Wrapper CangKuDingYiController::execListCangku(const CangkuListQuery::Wrapper& query, const PayloadDTO& payload)
{
	StoreService service;

	//��ѯ
	auto result = service.listAll(query);
	auto jvo = CangkuListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper CangKuDingYiController::execUpload(std::shared_ptr<IncomingRequest> request)
{
	return {};
}


