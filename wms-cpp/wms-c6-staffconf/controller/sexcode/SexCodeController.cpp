#include "stdafx.h"
#include "SexCodeController.h"

#include <iostream>
#include "SqlSession.h"
#include "list"
#include "domain/do/sex/SexDO.h"
#include "dao/SexMapper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"


namespace fs = std::filesystem;

StuCodePageJsonVO::Wrapper SexCodeController::execQueryStucode(StuCodeQuery::Wrapper& stucodeQuery)
{
	StuCodeService service;
	auto result = service.listAll(stucodeQuery);
	auto jvo = StuCodePageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

StringJsonVO::Wrapper SexCodeController::execModifyStucode(const StuCodeDTO::Wrapper& stucodeDto, const PayloadDTO& payload)
{
	StuCodeService service;
	auto jvo = StringJsonVO::createShared();
	if (!stucodeDto->name || stucodeDto->name->empty() || !stucodeDto->code || stucodeDto->code->empty())
	{
		jvo->fail("");
		return jvo;
	}
	auto result = service.updateStuCode(stucodeDto, payload);

	if (result)
	{
		jvo->success("success");
	}
	else
	{
		jvo->fail("failed");
	}
	return jvo;
}

StringJsonVO::Wrapper SexCodeController::execSetStucode(const StuCodeDTO::Wrapper& stucodeDto, const PayloadDTO& payload)
{
	StuCodeService service;
	auto jvo = StringJsonVO::createShared();
	if (!stucodeDto->name || stucodeDto->name->empty() || !stucodeDto->code || stucodeDto->code->empty())
	{
		jvo->fail("");
		return jvo;
	}
	auto result = service.setStuCode(stucodeDto, payload);

	if (result)
	{
		jvo->success("success");
	}
	else
	{
		jvo->fail("failed");
	}
	return jvo;
}

StringJsonVO::Wrapper SexCodeController::execDelStucode(const StuCodeDelDTO::Wrapper& stucodeDto)
{
	StuCodeService service;
	auto jvo = StringJsonVO::createShared();
	if (!stucodeDto->delList || stucodeDto->delList->empty())
	{
		jvo->fail("");
		return jvo;
	}

	auto result = service.setDelCode(stucodeDto);

	if (result)
	{
		jvo->success("success");
	}
	else
	{
		jvo->fail("failed");
	}
	return jvo;
}

StringJsonVO::Wrapper SexCodeController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{

	//1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	// ���ļ��ж�ȡ
	auto jvo = StringJsonVO::createShared();
	if (file)
	{
		auto readData = ExcelComponent::readIntoVector(file->data(), file->size(), "Sheet1");
		auto time = SimpleDateTimeFormat::format();
		auto name = payload.getUsername();
		auto by = payload.getRealname();
		auto org = payload.getOrgcode();
		auto company = payload.getCompanycode();
		SqlSession sqlsession;
		for (auto row : readData)
		{
			std::vector<string> temp(3, "");
			int i = 0;
			for (auto cellVal : row)
			{
				temp[i] = cellVal;
				i++;
			}
			string sql = "INSERT INTO `ba_sex_sta` (`id`, `create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`,`sex_sta_code`, `sex_sta_name`) VALUES(?, ?, ?,?,?,?,?,?,?,?,?)";
			auto ch = sqlsession.executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s", temp[0], name, by, time, name, by, time, org, company, temp[1], temp[2]);
			if (ch < 0)
			{
				jvo->success("fail");
				return jvo;
			}
		}
	}

	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> SexCodeController::execDownloadFile()
{
	// �����ļ�ȫ·��
	std::string fullPath = "public/static/file/xlsx";
	//��ȡ���ݿ�����
	SqlSession sqlsession;
	// ��ѯ����
	SqlParams params;
	string sql = "SELECT id,sex_sta_code,sex_sta_name FROM ba_sex_sta ";
	SexMapper mapper;
	list<SexDO> lres = sqlsession.executeQuery<SexDO>(sql, mapper);
	//���ݿ����ݴ����ά����
	std::vector<std::vector<std::string>> chvec;
	for (auto chl : lres)
	{
		std::vector<string> vec;
		vec.push_back(chl.getId());
		vec.push_back(chl.getSexCode());
		vec.push_back(chl.getSexName());
		chvec.push_back(vec);
	}

	//��Excle���ݵ��뵽String��
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("test"), chvec);
	const char* data = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(data, buff.size());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=sex.xlsx");

	// Ӱ��ɹ����
	return response;
}