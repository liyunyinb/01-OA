#ifndef _SEXCODE_CONTROLLER_
#define _SEXCODE_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/stucode/StuCodeVO.h"	
#include "domain/dto/stucode/StuCodeDTO.h"
#include "domain/dto/stucode/StuCodeDelDTO.h"
#include "domain/query/stucode/StuCodeQuery.h"
#include "domain/vo/file/FileVO.h"
#include "oatpp-swagger/Types.hpp"
#include "service/StuCodeService.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include <filesystem>  // C++17 ���ļ�ϵͳ��
#include <fstream>     // �ļ�����
#include <string>      // �ַ�������
#include <iostream>    // �����־
#include "Macros.h"
#include "ExcelComponent.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class SexCodeController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(SexCodeController);
public:
	// ��ȡ�Ա�����б�
	ENDPOINT_INFO(CodeList)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("stucode.get"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StuCodePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("stucode.field.code"), "ES004", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("stucode.field.name"), ZH_WORDS_GETTER("stucode.field.simple.name"), false);
	}
	ENDPOINT(API_M_GET, "/staffconf/sexcode/list", CodeList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(stucodeQuery, StuCodeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryStucode(stucodeQuery));
	}
	// �޸��Ա����
	ENDPOINT_INFO(Modify)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("stucode.modify"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("sex.filed.id"), "40289fe39406320f01940873c96f002e", true);
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("sex.filed.sexcode"), "SEX004", true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sex.filed.sexname"), "xxxx", true);
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/staffconf/sexcode/modify", Modify, BODY_DTO(StuCodeDTO::Wrapper, stucodeDto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execModifyStucode(stucodeDto, authObject->getPayload()));
	}
	// ¼���Ա����
	ENDPOINT_INFO(Add)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("stucode.set"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("sex.filed.sexcode"), "SEX004", true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sex.filed.sexname"), "xxxx", true);
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, "/staffconf/sexcode/add", Add, BODY_DTO(StuCodeDTO::Wrapper, stucodeDto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execSetStucode(stucodeDto, authObject->getPayload()));
	}
	// ɾ���Ա����
	ENDPOINT_INFO(Del)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("stucode.del"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_DEL, "/staffconf/sexcode/delete", Del, BODY_DTO(StuCodeDelDTO::Wrapper, stucodeDto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execDelStucode(stucodeDto));
	}
	// �����Ա����
	ENDPOINT_INFO(Import) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("file.upload.summary"), StringJsonVO::Wrapper);
	}
	ENDPOINT(API_M_POST, "/staffconf/sexcode/import", Import, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execUploadOne(request, authObject->getPayload()));
	}
	// �����Ա����
	ENDPOINT_INFO(Export) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("file.download.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, "/staffconf/sexcode/export", Export, API_HANDLER_AUTH_PARAME) {
		return execDownloadFile();
	}
private:
	StuCodePageJsonVO::Wrapper execQueryStucode(StuCodeQuery::Wrapper& stucodeQuery);
	StringJsonVO::Wrapper execModifyStucode(const StuCodeDTO::Wrapper& stucodeDto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execSetStucode(const StuCodeDTO::Wrapper& stucodeDto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDelStucode(const StuCodeDelDTO::Wrapper& stucodeDto);
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	std::shared_ptr<OutgoingResponse> execDownloadFile();
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_SEX_CONTROLLER_
