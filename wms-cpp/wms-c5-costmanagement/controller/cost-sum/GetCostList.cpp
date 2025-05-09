#include "stdafx.h"
#include "GetCostList.h"
#include "../../service/cost-sum/CostSumService.h"
 CostSumPageJsonVO ::Wrapper GetCostSumList::executequery(const CostSumQuery::Wrapper& query)
{
	 auto cs = CostSumPageJsonVO::createShared();
	 CostSumService service;
	 auto res = service.listall(query);
	 cs->success(res);
	 return cs;
}
 std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> GetCostSumList::execDownloadFile(const CostSumQuery::Wrapper& query)
 {
	 CostSumService service;
	 list<CostSumDO> res = service.exportdata(query);
	 std::vector<std::vector<std::string>> data;
	 std::vector<std::string> title;
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_data"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cus_code"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cus_name"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_code"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_name"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_sl"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_unit"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_yj"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_bhs"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_se"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_hsj"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_js"));
	 data.push_back(title);
	 for (auto a : res)
	 {
		 std::vector<std::string> row;
		 row.push_back(a.getcost_date());
		 row.push_back(a.getclient_c());
		 row.push_back(a.getclient_name());
		 row.push_back(a.getcost_c());
		 row.push_back(a.getcost_name());
		 row.push_back(a.getNumber());
		 row.push_back(a.getUnit());
		 row.push_back(a.getorg_price());
		 row.push_back(a.getno_tax());
		 row.push_back(a.getTax());
		 row.push_back(a.gettax_price());
		 row.push_back(a.getCost_Js());
		 data.push_back(row);
	 }
	 ExcelComponent excel;
	 auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("excel.info"), data);
	 const char* resData = reinterpret_cast<const char*>(buff.data());
	 auto fstring = String(resData, buff.size());

	 // �ж��Ƿ��ȡ�ɹ�
	 if (!fstring)
	 {
		 std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		 return createResponse(Status::CODE_404, "File Not Found");
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
	 response->putHeader("Content-Disposition", "attachment; filename="+filename);
	 return response;
 }