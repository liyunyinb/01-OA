#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: todou
 @Date: 2022/10/25 0:27:04

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

#ifndef _COSTSX_CONTROLLER_
#define _COSTSX_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/cost-attribute/CostSxQuery.h"
#include "domain/dto/cost-attribute/CostSxDTO.h"
#include "domain/vo/cost-attribute/CostSxVO.h"
#include "iostream"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �ͻ��Ʒ�����
 */
class CostSxController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{

	API_ACCESS_DECLARE(CostSxController);

public:

	// ��ѯ�ͻ��������ƽӿ�����
	ENDPOINT_INFO(queryCostSxName) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("CostSxMethod.queryName"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CostSxNameListPageJsonVO);

		

		// �ͻ����Ա���
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("CostSxQuery.filed.code"), ZH_WORDS_GETTER("CostSxMethod.example.add.code"), false);

		// �ͻ���������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("CostSxQuery.filed.name"), ZH_WORDS_GETTER("CostSxMethod.example.add.name"), false);

		// ����������
		API_DEF_ADD_QUERY_PARAMS(String, "createName", ZH_WORDS_GETTER("CostSxQuery.filed.create_name"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_name"), false);

		// �����˵�¼����
		API_DEF_ADD_QUERY_PARAMS(String, "createBy", ZH_WORDS_GETTER("CostSxQuery.filed.create_by"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_by"), false);

		//// ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "createDate", ZH_WORDS_GETTER("CostSxQuery.filed.create_date"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_date"), false);

		// ����������
		API_DEF_ADD_QUERY_PARAMS(String, "updateName", ZH_WORDS_GETTER("CostSxQuery.filed.update_name"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_name"), false);

		// �����˵�¼����
		API_DEF_ADD_QUERY_PARAMS(String, "updateBy", ZH_WORDS_GETTER("CostSxQuery.filed.update_by"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_by"), false);

		//// ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "updateDate", ZH_WORDS_GETTER("CostSxQuery.filed.update_date"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_date"), false);

		// ��������
		API_DEF_ADD_QUERY_PARAMS(String, "sysOrgCode", ZH_WORDS_GETTER("CostSxQuery.filed.sys_org_code"), ZH_WORDS_GETTER("CostSxMethod.example.add.sys_org_code"), false);

		// ������˾
		API_DEF_ADD_QUERY_PARAMS(String, "sysCompanyCode", ZH_WORDS_GETTER("CostSxQuery.filed.sys_company_code"), ZH_WORDS_GETTER("CostSxMethod.example.add.sys_company_code"), false);

	}
	// ��ѯ�ͻ��������ƽӿڶ���
	// ��������Ͼ��������鿴�������ư� ??? �ǲ���Ҫʲô�����Ĳ�ѯ���� ?
	ENDPOINT(API_M_GET, "/cost-config/query-cost-attribute-name", queryCostSxName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(costSxQuery, CostSxQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySxName(costSxQuery));
	}

	//// ��ѯ�ͻ���ϸ���ԣ���ҳ���ӿ�����
	ENDPOINT_INFO(queryCostSxPage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("CostSxMethod.queryPage"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CostSxPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

		// �ͻ����Ա���
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("CostSxQuery.filed.code"), ZH_WORDS_GETTER("CostSxMethod.example.add.code"), false);

		// �ͻ���������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("CostSxQuery.filed.name"), ZH_WORDS_GETTER("CostSxMethod.example.add.name"), false);

		// ����������
		API_DEF_ADD_QUERY_PARAMS(String, "createName", ZH_WORDS_GETTER("CostSxQuery.filed.create_name"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_name"), false);

		// �����˵�¼����
		API_DEF_ADD_QUERY_PARAMS(String, "createBy", ZH_WORDS_GETTER("CostSxQuery.filed.create_by"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_by"), false);

		//// ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "createDate", ZH_WORDS_GETTER("CostSxQuery.filed.create_date"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_date"), false);

		// ����������
		API_DEF_ADD_QUERY_PARAMS(String, "updateName", ZH_WORDS_GETTER("CostSxQuery.filed.update_name"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_name"), false);

		// �����˵�¼����
		API_DEF_ADD_QUERY_PARAMS(String, "updateBy", ZH_WORDS_GETTER("CostSxQuery.filed.update_by"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_by"), false);

		//// ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "updateDate", ZH_WORDS_GETTER("CostSxQuery.filed.update_date"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_date"), false);

		// ��������
		API_DEF_ADD_QUERY_PARAMS(String, "sysOrgCode", ZH_WORDS_GETTER("CostSxQuery.filed.sys_org_code"), ZH_WORDS_GETTER("CostSxMethod.example.add.sys_org_code"), false);

		// ������˾
		API_DEF_ADD_QUERY_PARAMS(String, "sysCompanyCode", ZH_WORDS_GETTER("CostSxQuery.filed.sys_company_code"), ZH_WORDS_GETTER("CostSxMethod.example.add.sys_company_code"), false);
	}
	// ��ѯ�ͻ�����(��ҳ)�ӿڶ���
	ENDPOINT(API_M_GET, "/cost-config/query-cost-attribute-page", queryCostSxPage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(costSxQuery, CostSxQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySxPage(costSxQuery));
	}
	// 
	// �����ͻ����Խӿ�����
	ENDPOINT_INFO(addCostSx) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("CostSxMethod.add"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ 
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

	}
	// �����ͻ����Խӿڴ���
	ENDPOINT(API_M_POST, "/cost-config/add-cost-attribute", addCostSx, BODY_DTO(CostSxBaseAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		CostSxAddDTO::Wrapper adto = buildFullDTO(dto, authObject.get()->getPayload());
		API_HANDLER_RESP_VO(execAddCostSx(adto));
	}


	// �޸Ŀͻ����Խӿ�����
	ENDPOINT_INFO(modifyCostSx) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("CostSxMethod.modify"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ 
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

	}
	// �޸Ŀͻ����Խӿڴ���
	ENDPOINT(API_M_PUT, "/cost-config/update-cost-attribute", modifyCostSx, BODY_DTO(CostSxBaseModifyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		//����ִ�к�����Ӧ���
	   // ���û���κ��ֶεõ��޸Ļ᷵�ش���
		CostSxModifyDTO::Wrapper mdto = buildFullDTO(dto, authObject.get()->getPayload());

		API_HANDLER_RESP_VO(execModifyCostSx(mdto));
	};

private:

	// �����û����Խӿڴ���
	StringJsonVO::Wrapper execAddCostSx(const CostSxAddDTO::Wrapper&);
	// �޸��û����Խӿڴ���
	StringJsonVO::Wrapper execModifyCostSx(const CostSxModifyDTO::Wrapper&);
	// ��ѯ�û��������ƽӿڴ���
	CostSxNameListPageJsonVO::Wrapper execQuerySxName(const CostSxQuery::Wrapper&);
	// ��ѯ�û�����(��ҳ)�ӿڴ���
	CostSxPageJsonVO::Wrapper execQuerySxPage(const CostSxQuery::Wrapper&);

	// ������������װ����DTO
	CostSxModifyDTO::Wrapper buildFullDTO(const CostSxBaseModifyDTO::Wrapper& baseDto, const PayloadDTO& payload);
	CostSxAddDTO::Wrapper buildFullDTO(const CostSxBaseAddDTO::Wrapper& baseDto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 
