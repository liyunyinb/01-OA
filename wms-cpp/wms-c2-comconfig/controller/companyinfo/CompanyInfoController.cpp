#include "stdafx.h"
#include "CompanyInfoController.h"

inline void init(const CompanyAddInfoDTO::Wrapper& correct, const CompanyAddInfoDTO::Wrapper& wrong) {
	correct->companyId = "1";
	correct->zhabbr = ZH_WORDS_GETTER("companyinfo.zhabbr");
	correct->zhful = ZH_WORDS_GETTER("companyinfo.zhful");
	correct->zhaddr = ZH_WORDS_GETTER("companyinfo.zhaddr");
	correct->enabbr = "English Abbreviation";
	correct->enful = "English Full Name";

	wrong->companyId = "-1";
	wrong->zhabbr = "";
	wrong->zhful = "";
	wrong->zhaddr = "";
	wrong->enabbr = "";
	wrong->enful = "";
}

CompanyInfoJsonVO::Wrapper CompanyInfoController::execAddCompanyInfo(const CompanyAddInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = CompanyInfoJsonVO::createShared();

	auto correct = CompanyAddInfoDTO::createShared();
	auto wrong = CompanyAddInfoDTO::createShared();

	init(correct, wrong);

	if (!dto->companyId || !dto->zhabbr || !dto->zhful || !dto->zhaddr || !dto->enabbr || !dto->enful)
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		//jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->zhabbr->empty() || dto->zhful->empty() || dto->zhaddr->empty() || dto->enabbr->empty() || dto->enful->empty())
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		//jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CompanyInfoService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(correct);
		//jvo->success(nullptr);
	}
	else
	{
		jvo->fail(wrong);
		//jvo->fail(nullptr);
	}
	return jvo;
}
// 3.3 ��ʾ��ҵ��Ϣ¼�޸�����
CompanyInfoJsonVO::Wrapper CompanyInfoController::execModifyCompanyInfo(const CompanyUpdateInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = CompanyInfoJsonVO::createShared();

	auto correct = CompanyAddInfoDTO::createShared();
	auto wrong = CompanyAddInfoDTO::createShared();

	init(correct, wrong);

	// ����У��
	if (!dto->companyId)
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CompanyInfoService service;
	// ִ�������޸�
	if (service.updateData(dto, payload)) {
		jvo->success(correct);
	}
	else
	{
		jvo->fail(wrong);
	}
	// ��Ӧ���
	return jvo;
}

/*�����Ҫ�ϴ���������˾id�Ƿ�Ϸ�*/
inline bool check1(const CompanyRemoveInfoDTO::Wrapper& id) {
	Vector<String> ids = id->companyId;
	for (const auto& companyId : *ids) {
		if (!companyId) {
			return false;
		}
	}
	return true;
}

inline vector<string> to_vector(const CompanyRemoveInfoDTO::Wrapper& id) {
	vector<string> ans;
	Vector<String> ids = id->companyId;
	for (const auto& companyId : *ids) {
		ans.push_back(companyId);
	}
	return ans;
}

// 3.3 ��ʾ��ҵ��Ϣ¼ɾ������
CompanyInfoJsonVO::Wrapper CompanyInfoController::execRemoveCompanyInfo(const CompanyRemoveInfoDTO::Wrapper& id) {
	auto jvo = CompanyInfoJsonVO::createShared();

	auto correct = CompanyAddInfoDTO::createShared();
	auto wrong = CompanyAddInfoDTO::createShared();

	init(correct, wrong);

	// ����У��
	if (!check1(id))
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CompanyInfoService service;

	// ִ������ɾ��
	if (service.removeData(to_vector(id))) {
		jvo->success(correct);
	}
	else
	{
		jvo->fail(wrong);
	}

	return jvo;
}