#include "stdafx.h"
#include "QualityController2.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/qcd/QualityService2.h"
#include "../../domain/do/qcd/QualityDO2.h"
#include "../../domain/dto/qcd/QualityDTO2.h"
#include "ExcelComponent.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

// ɾ��Ʒ�ʴ���
StringJsonVO::Wrapper QualityController2::execDeleteQuality(const DeleteDTO::Wrapper& dto) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto || dto->ids->empty()) {
		jvo->code = 10001;
		jvo->message = "params is invalid";
		jvo->data = "0";
		return jvo;
	}

	std::vector<std::int32_t> ids;
	for (const auto& id : *dto->ids) {
		ids.push_back(id);
	}

	// ����һ��Service
	QualityService service;
	// ִ������ɾ��
	int count = service.removeData(ids);
	if (count > 0) {
		jvo->code = 10000;
		jvo->message = "operation is successful";
		jvo->data = std::to_string(count);
	}
	else
	{
		jvo->code = 10001;
		jvo->message = "operation failed";
		jvo->data = "0";
	}
	// ��Ӧ���
	return jvo;
}

// ���ļ��ϴ�
StringJsonVO::Wrapper QualityController2::execUploadFile(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO(reader, "file", -1);

	// ��ȡ����
	request->transferBody(&reader);

	// �����ļ�
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (!file) {
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Not Found File");
		return jvo;
	}

	// ��ȡ�ļ�����
	ExcelComponent excel;
	auto data = excel.readIntoVector(file->data(), file->size(), ZH_WORDS_GETTER("qcd.name"));


	// �������ݿ�
	QualityService service;
	bool result = service.importData(data, payload);

	// ���ؽ��
	auto jvo = StringJsonVO::createShared();
	if (result) {
		jvo->code = 10000;
		jvo->message = "operation is successful";
		jvo->data = "1";
	}
	else {
		jvo->code = 10001;
		jvo->message = "operation failed";
		jvo->data = "0";
	}
	return jvo;
}

// �ļ�����
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> QualityController2::execDownloadFile(const String& filename)
{
	// ����Service
	QualityService service;
	auto query = QualityQuery::createShared();
	auto dtoList = service.QueryAll(query);

	// ���DTO�Ƿ�Ϊ��
	if (dtoList.empty()) {
		return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	}
	// ת��Ϊ��ά����
	std::vector<std::vector<std::string>> data;
	std::vector<std::string> header = {
		ZH_WORDS_GETTER("qcd.id"),
		ZH_WORDS_GETTER("qcd.create_name"),
		ZH_WORDS_GETTER("qcd.create_by"),
		ZH_WORDS_GETTER("qcd.create_date"),
		ZH_WORDS_GETTER("qcd.update_name"),
		ZH_WORDS_GETTER("qcd.update_by"),
		ZH_WORDS_GETTER("qcd.update_date"),
		ZH_WORDS_GETTER("qcd.sys_org_code"),
		ZH_WORDS_GETTER("qcd.sys_company_code"),
		ZH_WORDS_GETTER("qcd.qm_qa_code"),
		ZH_WORDS_GETTER("qcd.qm_qa_name")
	};

	data.push_back(header);

	// ��DTO������䵽��ά������
	for (const auto& dto : dtoList) {
		std::vector<std::string> row;
		row.push_back(dto->id);
		row.push_back(dto->create_name);
		row.push_back(dto->create_by);
		row.push_back(dto->create_date);
		row.push_back(dto->update_name);
		row.push_back(dto->update_by);
		row.push_back(dto->update_date);
		row.push_back(dto->sys_org_code);
		row.push_back(dto->sys_company_code);
		row.push_back(dto->qm_qa_code);
		row.push_back(dto->qm_qa_name);

		data.push_back(row);
	}

	// д��Excel�ļ�
	ExcelComponent excle;
	auto buff = excle.writeVectorToBuff(ZH_WORDS_GETTER("qcd.name"), data);
	// ����Excel�ļ�
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());
	// �ж��Ƿ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);
	std::time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);

	// �ֶ���ʽ��������
	char buffer[9];  // �洢��ʽ������ַ���
	std::strftime(buffer, sizeof(buffer), "%Y%m%d", localTime);

	response->putHeader("Content-Type", "application/vnd.ms-excel");
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue("") + "_" + buffer + ".xlsx");

	// Ӱ��ɹ����
	return response;
}