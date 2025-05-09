#include "stdafx.h"
#include "BillingNameController.h"
//#include "../../service/billing-configuration/CostNameService.h"
#include "../../service/billing-name/BillingNameService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../lib-common/include/ExcelComponent.h"
#include "ApiHelper.h"
#include "../../domain/vo/file/FileVO.h"
#include <oatpp/web/protocol/http/Http.hpp>
StringJsonVO::Wrapper BillingNameController::execbatchdeleteBillingName(const BillingNameBatchDTO::Wrapper& bathdto)
{
	auto jvo = StringJsonVO::createShared();
	string resultfail = string("fail");
	string resultsuccess = string("success");
	BillingNameService  service;
	//service.batchdeleteData(bathdto);
	if (service.batchdeleteData(bathdto))
	{
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}

}
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> BillingNameController::execExportName(const BillingNameQuery::Wrapper& query)
{

	BillingNameService service;
	auto result = service.exportData(query);
	std::vector<BillingNameDO> datas(result.begin(), result.end());

	// ������ͷ����
	std::vector<std::string> headers = {
		ZH_WORDS_GETTER("billing-name.field.cost_code"),
		ZH_WORDS_GETTER("billing-name.field.cost_name"),
		ZH_WORDS_GETTER("billing-name.field.cost_type_code"),
	};
	std::vector<std::vector<std::string>> data;
	data.push_back(headers);

	for (int i = 0; i < datas.size(); ++i)
	{
		std::vector<std::string> row;

		row.push_back(datas[i].getCost_code());
		row.push_back(datas[i].getCost_name());
		row.push_back(datas[i].getCost_type_code());
		data.push_back(row);
	}

	// ���屣������λ�ú�ҳǩ����
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫ�������ļ��л�ȡ
	std::string sheetName = ZH_WORDS_GETTER("billing-name.excelname.s1");
	//�ļ���
	std::string filename = ZH_WORDS_GETTER("billing-name.filename.s2") + ".xlsx";
	// ���浽�ļ�
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(sheetName, data);//������д���ĸ����ݱ��У�����ת���ɶ���������
	const char* tsData = reinterpret_cast<const char*>(buff.data());//�Ѷ���������ת����char����
	auto fstring = String(tsData, buff.size());//�ٰ�char���͵�����ת����Oat++�е�String
	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=billingname.xlsx");
	//"Content-Disposition"��ָ�����ݵĳ��ַ�ʽ�������������δ�������ļ�����
	//attachment����ʾ����ļ���һ�������������Ӧ�õ������ضԻ��򣨶�����ֱ����������д򿪣���
	//filename = OffRackAdjustment.xlsx��ָ������ʱ��Ĭ���ļ�����
	return response;
}
StringJsonVO::Wrapper BillingNameController::execuploadName(std::shared_ptr<IncomingRequest> request)
{
	//// 1 ��ʼ��
	
	auto jvo = StringJsonVO::createShared();
	API_MULTIPART_INIT(container, reader);
	////// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	////// 3 ��ȡ����
	request->transferBody(&reader);
	////// 4 ��������
	/////* todo: ���������ݾ����߼�����Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	/////* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	auto vectordto = BillingNameVectorDTO::createShared();
	
	auto fileData="";
	auto fileSize=0;
	std::string filename = "";
	std::string sheetName = ZH_WORDS_GETTER("billing-name.excelname.s1");
	BillingNameService  service;
	if (file)
	{
		ExcelComponent excel;
	//	// 5. ��ȡ�ļ�����
		 fileData = file->data();  // ��ȡ����������
		 fileSize = file->size();
		filename = partfile->getFilename().getValue(""); // ��ȡԭʼ�ļ���
		
		 std::vector<std::vector<std::string>> result= excel.readIntoVector(fileData,fileSize,sheetName);
		 for (int i = 1; i < result.size(); i++)
		 {
			
				 auto dto = BillingNamefileDTO::createShared();  // ��������
				 dto->id = oatpp::String(result[i][0]);
				 dto->cost_code= oatpp::String(result[i][1]);
				 dto->cost_name = oatpp::String(result[i][2]);
				 dto->cost_type_code = oatpp::String(result[i][3]);
				 if (!service.batchinsertData(dto))
				 {
					 jvo->fail("No file uploaded");
					 return jvo;
				}
		 }
		

	}
	else
	{
		jvo->fail("No file uploaded");
		return jvo;
	}
	////�����͵õ���һ��dto����Ҫ���ľ��ǰ�dtoת����do
	
		jvo->success("uploaded file success");
	return jvo;
}