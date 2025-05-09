#include "stdafx.h"
#include "UnloadingFeeController.h"
#include "../../service/unloading-fee/UnloadingFeeService.h"
#include "../ApiDeclarativeServicesHelper.h"


// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

//��ҳ��ѯ���ж����
UnloadingFeePageJsonVO::Wrapper UnloadingFeeController::execPageQueryUnloadingFee(const UnloadingFeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	//����һ��Service
	UnloadingFeeService service;
	//ִ�����ݲ�ѯ
	auto res = service.pageQueryUnloadingFee(query);
	// ��Ӧ���
	auto jvo = UnloadingFeePageJsonVO::createShared();
	jvo->success(res);
	return jvo;
}


//�������ж����
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> UnloadingFeeController::execDownloadUnLoadingFee(const UnloadingFeeQuery::Wrapper& query)
{
	//����һ��Service
	UnloadingFeeService service;
	//ִ�����ݲ�ѯ,��ȡ��ѯ����
	list<UnloadingFeeDO> res = service.DownloadUnloadingFee(query);

	//����ѯ����ת���ɵ�������
	std::vector<std::vector<std::string>> data;
	//��ʼ������
	std::vector<std::string> title;

	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.fee"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.acceptor"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.acceptDate"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.orderNo"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.goods"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.goodsName"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.unloadingNum"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.unloadingWeight"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.feeRMB"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.price"));
	data.push_back(title);

	//�������
	for (auto a : res)
	{
		std::vector<std::string> row;
		row.push_back(a.getFee());
		row.push_back(a.getAcceptor());
		row.push_back(a.getAcceptDate());
		row.push_back(a.getOrderNo());
		row.push_back(a.getGoods());
		row.push_back(a.getGoodsName());
		row.push_back(to_string(a.getUnloadingNum()));
		row.push_back(to_string(a.getUnloadingWeight()));
		row.push_back(to_string(a.getFeeRMB()));
		row.push_back(to_string(a.getPrice()));
		data.push_back(row);
	}

	// ��Excel���ݵ�����String��
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("file.field.filename"), data);
	const char* resData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(resData, buff.size());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to load data: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "Data Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ��ȡ��ǰʱ���
	auto now = std::chrono::system_clock::now();

	// ��ʱ���ת��Ϊʱ���
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	// ʹ�� stringstream ����ʱ���ʽ��
	std::ostringstream oss;
	oss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S");

	//�����ļ���
	string filename = "unloading_fee_" + oss.str() + ".xlsx";

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	return response;
}