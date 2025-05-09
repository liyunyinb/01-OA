#ifndef _EDUCODE_CONTROLLER_
#define _EDUCODE_CONTROLLER_

#include"domain/dto/education/EducationalDTO.h"
#include"domain/vo/education/EducationalVO.h"
#include"domain/dto/education/EduDTO.h"
#include"domain/vo/education/EduVO.h"
#include"domain/query/education/EduQuery.h"
#include"domain/vo/BaseJsonVO.h"
#include"domain/GlobalInclude.h"
#include"service/DelEduCode/DelEduCodeService.h"
#include"dao/DelEduCode/DelEduCodeDAO.h"
#include"domain/do/education/EduCodeDO.h"
#include"domain/do/education/EduCodeMapper.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class EduCodeController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(EduCodeController);
public:
    // ��ȡѧ�������б�
    ENDPOINT_INFO(CodeList) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("education.get.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(EduPageJsonVO);
        // �����ҳ��ѯ��������
        API_DEF_ADD_PAGE_PARAMS();
        // ����������ѯ��������
        API_DEF_ADD_QUERY_PARAMS(String, "educode", ZH_WORDS_GETTER("education.field.educode"), "dx", false);
        API_DEF_ADD_QUERY_PARAMS(String, "eduname", ZH_WORDS_GETTER("education.field.eduname"), ZH_WORDS_GETTER("test"), false);
    }
    ENDPOINT(API_M_GET, "/staffconf/educode/list", CodeList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(eduQuery, EduQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryEdu(eduQuery));
    }
	// �޸�ѧ������
    ENDPOINT_INFO(Modify) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("educational_background.modify"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ����������ѯ��������
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("education.field.id"), "40289fe39406320f01940873c96f002e", true);
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("education.field.educode"), "SEX004", true);
        API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("education.field.eduname"), "xxxx", true);
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/staffconf/educode/modify", Modify, BODY_DTO(EducationalDTO::Wrapper, educationalDTO), execModifyEducode(educationalDTO, authObject->getPayload()));
    // ����ѧ������
    ENDPOINT_INFO(Export) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("educational_background.export"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
    }
    ENDPOINT(API_M_GET, "/staffconf/educode/export", Export, API_HANDLER_AUTH_PARAME) {
        return execexportEducode();
    }
    // ����ѧ������
    ENDPOINT_INFO(Import) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("educational_background.import"), StringJsonVO::Wrapper);
    }
    ENDPOINT(API_M_POST, "/staffconf/educode/import", Import, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(importEduCode(request, authObject->getPayload()));
    }
    // ɾ��ѧ������
	ENDPOINT_INFO(Del) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("educational_background.delete"), String);
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("educational_background.field.Education_code"), "", true);
	}
	ENDPOINT(API_M_DEL, "/staffconf/educode/delete", Del, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execDelEducate(id));
	}
    // ����ѧ������
    ENDPOINT_INFO(Add) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("education.post.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        API_DEF_ADD_QUERY_PARAMS(String, "educode", ZH_WORDS_GETTER("education.field.educode"), "EDU004", true);
        API_DEF_ADD_QUERY_PARAMS(String, "eduname", ZH_WORDS_GETTER("education.field.eduname"), "xxxx", true);
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    ENDPOINT(API_M_POST, "/staffconf/educode/add", Add, BODY_DTO(EduAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execAddEdu(dto, authObject->getPayload()));
    }

private:
    EduPageJsonVO::Wrapper execQueryEdu(const EduQuery::Wrapper& query);
    Uint64JsonVO::Wrapper execAddEdu(const EduAddDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execModifyEducode(const EducationalDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDelEducate(const String& id);
    StringJsonVO::Wrapper importEduCode(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
    std::shared_ptr<OutgoingResponse> execexportEducode();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EDUCATION_CONTROLLER_

