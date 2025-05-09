/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : ListgoodsController.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/26 17:04
    *  @brief    : brief
*****************************************************************************/
#include "stdafx.h"
#include "ListgoodsController.h"
#include "../../service/adjust-list/AdjustlistService.h"
#include "../../service/adjust-list/ListgoodsService.h"
ListgoodsPageJsonVO::Wrapper ListgoodsController::execQueryPage(const ListgoodsQuery1::Wrapper& query, const PayloadDTO& payload) {
	// ����һ��Service
	AdjustlistService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ListgoodsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}




ListgoodsdetailJsonVO::Wrapper ListgoodsController::execQuerydetail(const String&id) {

	// ���巵�����ݶ���
	auto jvo = ListgoodsdetailJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (id.getValue({}) == "")
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AdjustlistService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;

}


StringJsonVO::Wrapper ListgoodsController::execModifyListgoods(const ListgoodsadjustDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id || dto->id == "")
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	AdjustlistService service;
	// ִ�������޸�
	String resultfail = String("fail");
	String resultsuccess = String("success");
	if (service.updateData(dto,payload)) {
		jvo->success(resultsuccess);
	}
	else
	{
		jvo->fail(resultfail);
	}
	// ��Ӧ���
	return jvo;

}	

/************************************************/

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ListgoodsController::execExportData(const ExportDataQuery::Wrapper& query)
{
	ListGoodsService service;

	auto result = service.exportData(query);

	std::string fullPath = result/* + URIUtil::urlDecode("test.xlsx")*/;
	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	//response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));
	response->putHeader("Content-Disposition", "attachment; filename=test.xlsx" /*ZH_WORDS_GETTER("diff-post.excel.name")*/);

	// Ӱ��ɹ����
	return response;
}