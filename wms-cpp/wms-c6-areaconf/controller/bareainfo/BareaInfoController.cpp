#include "stdafx.h"
#include "BareaInfoController.h"
#include "dao/districtinfo/BareaInfoDAO.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "service/regioninfo/DareaInfoService.h"
#include "service/regioninfo/RegionInfoService.h"
#include "service/districtinfo/BareaInfoService.h"
#include "domain/do/regioninfo/RegionInfoDO.h"
#include <string>
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

StringJsonVO::Wrapper BareaInfoController::execImport(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		// �����ļ�ȫ·��
		std::string fullPath = "./file/bareainfo.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<string>> vec = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("BareaInfo.info"));
		RegionInfoService service;
		service.import(vec, payload);
	}
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> BareaInfoController::execExport()
{
	BareaInfoDAO dao;
	std::list<BareaInfoDO> d = dao.exportBareaInfo();
	std::vector<std::vector<std::string>> data;
	std::vector<std::string> head;
	head.push_back(ZH_WORDS_GETTER("BareaInfo.excel.head1"));
	head.push_back(ZH_WORDS_GETTER("BareaInfo.excel.head2"));
	head.push_back(ZH_WORDS_GETTER("BareaInfo.excel.head3"));
	data.push_back(head);
	for (BareaInfoDO Obj : d)
	{
		std::vector<std::string> vec;
		vec.push_back(Obj.getBarea_code());
		vec.push_back(Obj.getBarea_name());
		vec.push_back(std::to_string(Obj.getBarea_rdata()));
		data.push_back(vec);
	}

	ExcelComponent excel;
	std::string filename = "./file/bareainfo.xlsx";
	std::string sheet = ZH_WORDS_GETTER("AreaInfo.barea_name");
	excel.loadFile(filename);
	excel.writeVectorToFile(filename, sheet, data);

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(filename.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=bareainfo.xlsx");

	// Ӱ��ɹ����
	return response;
}

Uint64JsonVO::Wrapper BareaInfoController::execAdd(const RegionInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->region_code || !dto->region_name || !dto->region_rdata)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	RegionInfoService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper BareaInfoController::execDelete(const String& region_code)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!region_code || region_code->empty())
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RegionInfoService service;
	// ִ������ɾ��

	if (service.removeData(region_code)) {
		jvo->success(region_code);
	}
	else
	{
		jvo->fail(region_code);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper BareaInfoController::execModify(const RegionModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->region_code || !dto->region_name || !dto->region_rdata || !dto->id)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RegionInfoService service;
	// ִ�������޸�
	if (service.updateData(dto, payload)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail("-1");
	}
	// ��Ӧ���
	return jvo;
}

BareaNameListJsonVO::Wrapper BareaInfoController::execNameList()
{
	auto jvo = BareaNameListJsonVO::createShared();
	BareaInfoDAO dao;
	auto namelist = dao.nameList();
	auto list = List<BareaNameDTO::Wrapper>::createShared();
	for (auto obj : namelist)
	{
		auto dto = BareaNameDTO::createShared();
		dto->id = obj.getId();
		dto->name = obj.getBarea_name();
		list->push_back(dto);
	}
	jvo->success(list);
	return jvo;
}

BareaInfoPageJsonVO::Wrapper BareaInfoController::execInfoList(const BareaInfoQuery::Wrapper& query)
{
	auto jvo = BareaInfoPageJsonVO::createShared();
	BareaInfoService service;
	auto list = service.list(query);
	jvo->success(list);
	return jvo;
}