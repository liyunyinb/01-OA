#pragma once
#ifndef _APIXIANGXIXINXI_
#define _APIXIANGXIXINXI_

#include "../../domain/dto/chuweidingyi/xiangxixinxiDTO.h"
#include "../../domain/query/chuweidingyi/xiangxixinxiQUERY.h"
#include "../../domain/vo/chuweidingyi/xiangxixinxiVO.h"
#include "domain/vo/BaseJsonVO.h"



// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class apixiangxixinxi : public oatpp::web::server::api::ApiController 
{
	API_ACCESS_DECLARE(apixiangxixinxi);

public:
 
	//��ѯ��������--------------------------
	ENDPOINT_INFO(xinxiall) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("chuweixiangxixinxi.api.chaxunxinxi"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(xiangxixinxiJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "weiyiid", ZH_WORDS_GETTER("chuweixiangxixinxi.bs.id"), "2ce255sad", false);
	}
    ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/huo-qu-chu-wei-xiang-xi-xin-xi", xinxiall, QUERIES(QueryParams, weiyiid), API_HANDLER_AUTH_PARAME) {

        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(cusZhanShi, xiangxixinxiQUERY, weiyiid);
        // ����ִ�к�����Ӧ���
        //API_HANDLER_RESP_VO(execXiangXiXinXiZhanShi(cusZhanShi));
		API_HANDLER_RESP_VO(execXiangXiXinXiZhanShi(cusZhanShi, authObject->getPayload()));
    }



	//������λ/�ļ�����------------------------------------------------------------------------
	//
	ENDPOINT_INFO(daochuout) {
	
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("daochu.daochuwenjian"));
		//Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		API_DEF_ADD_QUERY_PARAMS(String, "weiyiid", ZH_WORDS_GETTER("chuweixiangxixinxi.bs.id"), "2ce255sad", false);
	}
	ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/dao-chu-chu-wei", daochuout, BODY_DTO(daochuchuweiDTO::Wrapper, id_zhi), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDaoChuChuWei(id_zhi, authObject->getPayload()));
	}




	ENDPOINT_INFO(daoru) {

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("daoru.dr.wenjianshangchaun"));
		//Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		
	}
	ENDPOINT(API_M_POST, "/chuweiguanli/chuweidingyi/dao-ru-chu-wei", daoru, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDaoRuWenJianOne(request, authObject->getPayload()));
	}
	

private:
    xiangxixinxiJsonVO::Wrapper execXiangXiXinXiZhanShi(const xiangxixinxiQUERY::Wrapper& query, const PayloadDTO& payload);


	StringJsonVO::Wrapper execDaoChuChuWei(const daochuchuweiDTO::Wrapper& id_zhi, const PayloadDTO& payload);


	StringJsonVO::Wrapper execDaoRuWenJianOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);


};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APIXIANGXIXINXI_