/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/2/27 22:17

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "CostDetailController.h"
#include "../../service/cost-detail/CostDetailService.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

//ͨ����ȡList<String>���id,�޸Ķ�Ӧ���ֵ��տ�����
StringJsonVO::Wrapper CostDetailController::execChargeCost(List<String> ids)
{
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//����У��
	for (const auto& id : *ids)
	{
		//�����Ƿ��д����ַ���Ϊ��
		if (*id == "")
		{
			jvo->init(String("error: parameter::id cannot be empty!"), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	//����service
	CostDetailService service;
	int success = 1;
	String wrong_ids = "";
	for (const auto& id : *ids)//�ɹ���״̬success,����������һ��id;ʧ����fail,��������ʧ�ܵ�id
	{
		if (service.charge(id))//�ɹ��޸ĸ�id��Ӧ������
		{
			jvo->data=id;//�ڲ�ʵ��Ϊ����jvo->setStatus��jvo->data=id
		}
		else//����
		{
			success = 0;
			wrong_ids = wrong_ids + id + ",";
		}
	}
	if (success == 1)//û�г���
	{
		jvo->success(jvo->data);
	}
	else
	{
		jvo->fail(wrong_ids);
	}
	return jvo;
}

StringJsonVO::Wrapper CostDetailController::execDischargeCost(List<String> ids)
{
	//���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//����У��
	for (const auto& id : *ids)
	{
		//�����Ƿ��д����ַ���Ϊ��
		if (*id== "")
		{
			jvo->init(String("error: parameter::id cannot be empty!"), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	//����service
	CostDetailService service;
	int success = 1;
	String wrong_ids = "";
	for (const auto& id : *ids)//�ɹ���״̬success,����������һ��id;ʧ����fail,��������ʧ�ܵ�id
	{
		if (service.discharge(id))//�ɹ��޸ĸ�id��Ӧ������
		{
			jvo->data = id;//�ڲ�ʵ��Ϊ����jvo->setStatus��jvo->data=id
		}
		else//����
		{
			success = 0;
			wrong_ids = wrong_ids + id + ",";
		}
	}
	if (success == 1)//û�г���
	{
		jvo->success(jvo->data);
	}
	else
	{
		jvo->fail(wrong_ids);
	}
	return jvo;
}
StringJsonVO::Wrapper CostDetailController::execUploadCostDetail(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 1 ��ʼ�������Ͷ�ȡ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);//���ϴ��������,���Ǻ���ֻ����"file"����

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 ��������
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* ���Խ��ļ����浽�������� */
		//string fullPath = "public/static/file/" + filename;
		//file.saveToFile(fullPath.c_str());

		if (false)//�Ƿ��ϴ���FastDFS,��ѡ
		{
			/* �����ϴ���FastDFS */
			ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
			// ��ȡ�ļ���׺��
			string suffix = "";
			size_t pos = filename.rfind(".");
			if (pos != string::npos)
			{
				suffix = filename.substr(pos + 1);
			}
			// �ϴ��ļ�
			string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
			downloadUrl = urlPrefix + downloadUrl;
			OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		}
	}
	// 5 ��Ӧ���:�ļ��ϴ���String��file,Ҫ��file�������������ݿ�
	auto jvo = StringJsonVO::createShared();
	ExcelComponent excel;
	const char* data = file->data();
	vector<vector<string>> matrix=excel.readIntoVector(data, file->size(), ZH_WORDS_GETTER("cost-detail.upload.field.sheetname"));
	//��ÿ��������װ��DTO�����service�����,ǰ3��Ϊ��ͷ
	int lines = matrix.size();
	for (int i = 3; i < lines; ++i)
	{
		CostExportDTO dto;
		dto.creator = matrix[i][0];
		dto.createdate = matrix[i][1];
		dto.updater= matrix[i][2];
		dto.updatedate= matrix[i][3];
		dto.client= matrix[i][4];
		dto.clientname= matrix[i][5];
		dto.cost= matrix[i][6];
		dto.costname= matrix[i][7];
		dto.costdate= matrix[i][8];
		dto.oldprice= matrix[i][9];
		dto.notax = matrix[i][10];
		dto.tax = matrix[i][11];
		dto.taxprice = matrix[i][12];
		dto.source = matrix[i][13];
		dto.remark = matrix[i][14];
		dto.state = matrix[i][15];
		dto.status = matrix[i][16];
		dto.count = matrix[i][17];
		dto.unit = matrix[i][18];
		//�Ӹ��ض�ȡ��Ϣ
		dto.create_by = payload.getRealname();
		dto.org_code = payload.getOrgcode();
		dto.company_code = payload.getCompanycode();
		CostDetailService service;
		uint64_t id=service.addData(&dto);
		if (id <= 0)
		{
			jvo->fail("fail");
			return jvo;
		}
	}
	jvo->success("OK");
	return jvo;
}
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CostDetailController::execDownloadCostDetail(const List<String>& ids)
{
	//����service�㵼��ȫ������
	CostDetailService service;
	auto result=service.exportAll(ids);
	//����ѯ������ϱ�ͷ
	vector<string> title = { 
		ZH_WORDS_GETTER("cost-detail.download.field.creator-name"),
		ZH_WORDS_GETTER("cost-detail.download.field.create-date"),
		ZH_WORDS_GETTER("cost-detail.download.field.updater-name"),
		ZH_WORDS_GETTER("cost-detail.download.field.update-date"),
		ZH_WORDS_GETTER("cost-detail.download.field.clinet"),
		ZH_WORDS_GETTER("cost-detail.download.field.client-name"),
		ZH_WORDS_GETTER("cost-detail.download.field.cost"),
		ZH_WORDS_GETTER("cost-detail.download.field.cost-name"),
		ZH_WORDS_GETTER("cost-detail.download.field.cost-date"),
		ZH_WORDS_GETTER("cost-detail.download.field.old-price"),
		ZH_WORDS_GETTER("cost-detail.download.field.no-tax"),
		ZH_WORDS_GETTER("cost-detail.download.field.tax"),
		ZH_WORDS_GETTER("cost-detail.download.field.tax-cost"),
		ZH_WORDS_GETTER("cost-detail.download.field.source"),
		ZH_WORDS_GETTER("cost-detail.download.field.remark"),
		ZH_WORDS_GETTER("cost-detail.download.field.state"),
		ZH_WORDS_GETTER("cost-detail.download.field.status"),
		ZH_WORDS_GETTER("cost-detail.download.field.count"),
		ZH_WORDS_GETTER("cost-detail.download.field.unit") };
	result.insert(result.begin(),title);
	//����excel
	ExcelComponent excel;
	//excel.writeVectorToFile("C:/Users/wcy/Desktop/save.xlsx", ZH_WORDS_GETTER("cost-detail.download.field.sheetname"), result);//���浽����
	//���ظ�ǰ��
	auto buff=excel.writeVectorToBuff(ZH_WORDS_GETTER("cost-detail.download.field.sheetname"), result);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());
	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to export data: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "Data Not Found");
	}
	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);
	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + ZH_WORDS_GETTER("cost-detail.download.field.filename"));

	// Ӱ��ɹ����
	return response;
}