#ifndef _REGIONINFO_CONTROLLER_
#define _REGIONINFO_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/regioninfo/RegioninfoDTO.h"
#include "domain/query/dareainfo/DareaInfoQuery.h"
#include "domain/dto/regioninfo/DareaInfoDTO.h"
#include "domain/vo/regioninfo/DareaInfoVO.h"
#include "domain/vo/regioninfo/RegionNameJsonVO.h"
#include "domain/dto/regioninfo/RegionNameDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DareaInfoController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(DareaInfoController);
public:
	// ����������Ϣ
	ENDPOINT_INFO(Export) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DareaInfo.export"));
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, "/areaconf/dareainfo/export", Export, API_HANDLER_AUTH_PARAME) {
		return execExport();
	}
	// ���������Ϣ
	ENDPOINT_INFO(Import) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("DareaInfo.import"), StringJsonVO::Wrapper);
	}
	ENDPOINT(API_M_POST, "/areaconf/dareainfo/import", Import, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execImport(request, authObject->getPayload()));
	}
	// �������Ϣ�����б�
	ENDPOINT_INFO(NameList) {
		// ��������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("region.info.namelist"), RegionNameJsonVO::Wrapper);
	}
	ENDPOINT(API_M_GET, "/areaconf/dareainfo/namelist", NameList, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryName());
	}
	// ��ȡ������Ϣ�б�
	ENDPOINT_INFO(InfoList) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("DareaInfo.dareainfoAll"), DareaInfoPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "area_code", ZH_WORDS_GETTER("DareaInfo.area_code"), "A-001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "area_name", ZH_WORDS_GETTER("DareaInfo.area_name"), "xxx", false);
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DareaInfoPageJsonVO);
	}
	ENDPOINT(API_M_GET, "/areaconf/dareainfo/infolist", InfoList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, DareaInfoQuery, queryParams);
		API_HANDLER_RESP_VO(executeQueryAll(query));
	}
	// ¼�������Ϣ
	ENDPOINT_INFO(Add) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DareaInfo.dareainfoAdd"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "area_code", ZH_WORDS_GETTER("DareaInfo.area_code"), "ex-code", true);
		API_DEF_ADD_QUERY_PARAMS(String, "area_name", ZH_WORDS_GETTER("DareaInfo.area_name"), "ex-name", true);
	}
	ENDPOINT(API_M_POST, "/areaconf/dareainfo/add", Add, BODY_DTO(DareaInfoAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDareaInfo(dto, authObject->getPayload()));
	}
	// ɾ��������Ϣ
	ENDPOINT_INFO(Del) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("DareaInfo.dareainfoRom"), StringJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("DareaInfo.id"), "", true);
	}
	ENDPOINT(API_M_DEL, "/areaconf/dareainfo/del/{id}", Del, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execRemoveDareaInfo(id));
	}
	// �޸Ĵ�����Ϣ
	ENDPOINT_INFO(Modify) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DareaInfo.dareainfoUpd"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("DareaInfo.id"), "id", true);
		API_DEF_ADD_QUERY_PARAMS(String, "area_code", ZH_WORDS_GETTER("DareaInfo.area_code"), "code", true);
		API_DEF_ADD_QUERY_PARAMS(String, "area_name", ZH_WORDS_GETTER("DareaInfo.area_name"), "name", true);
	}
	ENDPOINT(API_M_PUT, "/areaconf/dareainfo/modify", Modify, BODY_DTO(DareaInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyDareaInfo(dto,authObject->getPayload()));
	}
private:
	std::shared_ptr<OutgoingResponse> execExport();
	StringJsonVO::Wrapper execImport(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	DareaInfoPageJsonVO::Wrapper executeQueryAll(const DareaInfoQuery::Wrapper& query);
	StringJsonVO::Wrapper execAddDareaInfo(const DareaInfoAddDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execModifyDareaInfo(const DareaInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execRemoveDareaInfo(const String& id);
	RegionNameJsonVO::Wrapper execQueryName();
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_REGIONINFO_CONTROLLER_

