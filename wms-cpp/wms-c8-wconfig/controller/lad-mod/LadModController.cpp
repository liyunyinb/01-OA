
#include "stdafx.h"
#include "LadModController.h"
#include "../../service/lad-mod/LadModService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../lib-common/include/CommonMacros.h"

LadModPageJsonVO::Wrapper LadModController::execQueryAll(const LadModQuery::Wrapper& query)
{
	LadModService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = LadModPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper LadModController::execAddLad(const LadModAddDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->code || !dto->name)
	{
		return nullptr;
	}
	// ��ЧֵУ��
	if ( dto->code->empty() || dto->name->empty())
	{
		return nullptr;
	}

	// ����һ��Service
	LadModService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
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

Uint64JsonVO::Wrapper LadModController::execModifyLadMod(const LadModDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id || dto->id <= 0)
	{
		return nullptr;
	}
	// ����һ��Service
	LadModService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper LadModController::execDeleteLad(const oatpp::UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����һ��Service
	LadModService service;
	// ִ������ɾ��
	if (service.deleteLad(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper LadModController::execBatchDeleteLad(const BatchDeleteRequestDto::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����һ��Service
	LadModService service;
	// ִ������ɾ��
	if (service.batchDeleteLad(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(-1);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper LadModController::execImportLad(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO(reader, "file", -1);

	// 3 ��ȡ����
	request->transferBody(&reader);

	// 4 ��������
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* �ļ����� */
		string filename = partfile->getFilename().getValue("");
		/* ���Խ��ļ����浽�������� */
		string fullPath = "public/lad/import/" + filename;

		//�ж�Ŀ¼�Ƿ���ڣ������ڴ���Ŀ¼
		auto dir = fullPath.substr(0, fullPath.find_last_of("/") + 1);
		const size_t dirLen = dir.length();
		if (dirLen > 512)
		{
			printf("file path too long\n");
			auto jvo = StringJsonVO::createShared();
			jvo->fail("error");
			return jvo;
		}
		char tmpDirPath[512] = { 0 };
		for (size_t i = 0; i < dirLen; i++)
		{
			tmpDirPath[i] = dir[i];
			if (tmpDirPath[i] == '/')
			{
				if (ACCESS(tmpDirPath, 0) != 0)
				{
					if (MKDIR(tmpDirPath) != 0)
					{
						printf("create dir %s fail\n", tmpDirPath);
						auto jvo = StringJsonVO::createShared();
						jvo->fail("error");
						return jvo;
					}
				}
			}
		}

		file.saveToFile(fullPath.c_str());
		
		LadModService service;
		int result = service.importLad(fullPath);
		auto jvo = StringJsonVO::createShared();
		if (result == -1)
		{
			jvo->fail("error");
			return jvo;
		}
		else if (result == 0)
		{
			jvo->success("success");
			return jvo;
		}
	}
	else {
		// 5 ��Ӧ���
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Parameter name must be file");
		return jvo;
	}
}

StringJsonVO::Wrapper LadModController::execExportLad()
{
	LadModService service;
	auto jvo = StringJsonVO::createShared();
	jvo->success(service.exportLad());
	return jvo;
}