#include "stdafx.h"
#include "LoadingFeeController.h"
#include "../../service/loading-fee/LoadingFeeService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

//��ҳ��ѯ���װ����
LoadingFeePageJsonVO::Wrapper LoadingFeeController::execPageQueryLoadingFee(const LoadingFeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	//����һ��Service
	LoadingFeeService service;
	//ִ�����ݲ�ѯ
	auto res = service.pageQueryLoadingFee(query);
	// ��Ӧ���
	auto jvo = LoadingFeePageJsonVO::createShared();
	jvo->success(res);
	return jvo;
}

// ִ���ļ����ش���
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> LoadingFeeController::execDownloadLoadingFee(const LoadingFeeQuery::Wrapper& query)
{
	//����һ��Service
	LoadingFeeService service;
	//ִ�����ݲ�ѯ,��ȡ��ѯ����
	list<LoadingFeeDO> res = service.DownloadLoadingFee(query);

	//����ѯ����ת���ɵ�������
	std::vector<std::vector<std::string>> data;
	//��ʼ������
	std::vector<std::string> title;
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.fee"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.operator"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.operateDate"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.orderNo"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.goods"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.goodsName"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.goodsNum"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.goodsWeight"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.feeRMB"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.price"));
	data.push_back(title);

	//�������
	for (auto a : res)
	{
		std::vector<std::string> row;
		row.push_back(a.getFee());
		row.push_back(a.getXOperator());
		row.push_back(a.getOperateDate());
		row.push_back(a.getOrderNo());
		row.push_back(a.getGoods());
		row.push_back(a.getGoodsName());
		row.push_back(to_string(a.getGoodsNum()));
		row.push_back(to_string(a.getGoodsWeight()));
		row.push_back(to_string(a.getFeeRMB()));
		row.push_back(to_string(a.getPrice()));
		data.push_back(row);
	}

	// ��Excel���ݵ�����String��
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("file.field.filename"), data);
	const char* resData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(resData, buff.size());

	// �ж��Ƿ��ȡ����
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
	string filename = "loading_fee_" + oss.str() + ".xlsx";

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	return response;
}