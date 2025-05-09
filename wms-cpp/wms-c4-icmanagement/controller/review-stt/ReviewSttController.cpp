#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "ReviewSttController.h"
#include "../../service/review-stt/ReviewSttService.h"
#include "FastDfsClient.h"



ReviewSttPageJsonVO::Wrapper ReviewSttController::execQueryAll(const ReviewSttQuery::Wrapper& query)
{
	// ����һ��Service
	ReviewSttService service;
	// ��ѯ����
	auto result = service.listAll(query);

	// ��Ӧ���
	auto jvo = ReviewSttPageJsonVO::createShared();
	if (result)
	{
		jvo->success(result);
	}
	else
	{
		jvo->fail(result);
	}
	return jvo;
}

Uint64JsonVO::Wrapper ReviewSttController::execReviewStt(const ReviewSttDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ����һ��Service
	ReviewSttService service;
	// ��ѯ����

	auto result = service.updateData(dto,payload);
	// ��Ӧ���
	auto jvo = Uint64JsonVO::createShared();
	if (result)
	{
		jvo->success(result);
	}
	else
	{
		jvo->fail(result);
	}
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ReviewSttController::execExportReviewStt(const ExportReviewSttQuery::Wrapper& query)
{
	ReviewSttService service;

	auto result = service.exportData(query);
	//// ��Ӧ���
	//auto jvo = Uint64JsonVO::createShared();
	//if (result)
	//{
	//	jvo->success(result);
	//}
	//else
	//{
	//	jvo->fail(result);
	//}
	//return jvo;

	// �����ļ�ȫ·��
	//std::string fullPath = result + URIUtil::urlDecode(filename.getValue(""));
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


