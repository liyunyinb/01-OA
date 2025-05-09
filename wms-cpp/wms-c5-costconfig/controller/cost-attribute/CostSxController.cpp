 /*
  Copyright Zero One Star. All rights reserved.

  @Author: wrzljrj
 @Date: 2025/02/22 18:33:26

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


 #include "stdafx.h"
 #include "CostSxController.h"
 #include "service/cost-attribute/CostAttributeService.h"


 // ��������
 CostSxModifyDTO::Wrapper CostSxController::buildFullDTO(const CostSxBaseModifyDTO::Wrapper& baseDto, const PayloadDTO& payload) {
 	auto fullDto = CostSxModifyDTO::createShared();

 	// ���ƻ����ֶ�
 	fullDto->id = baseDto->id;
 	fullDto->name = baseDto->name;
 	fullDto->code = baseDto->code;
	

 	// ���Token�е���Ϣ
 	//fullDto->create_name = payload.getUsername();
 	//fullDto->create_by = payload.getUsername();
 	fullDto->update_by = payload.getUsername();
 	fullDto->sys_org_code = payload.getOrgcode();
 	fullDto->sys_company_code = payload.getCompanycode();
 	//fullDto->create_date = DateUtil::getCurrentTime();

 	return fullDto;
 }

 CostSxAddDTO::Wrapper CostSxController::buildFullDTO(const CostSxBaseAddDTO::Wrapper& baseDto, const PayloadDTO& payload) {
 	auto fullDto = CostSxAddDTO::createShared();

 	// ���ƻ����ֶ�
 	fullDto->name = baseDto->name;
 	fullDto->code = baseDto->code;


 	// ���Token�е���Ϣ
 	//fullDto->create_name = payload.getUsername();
 	fullDto->create_by = payload.getUsername();
 	fullDto->update_by = payload.getUsername();
 	fullDto->sys_org_code = payload.getOrgcode();
 	fullDto->sys_company_code = payload.getCompanycode();
 	//fullDto->sys_org_code = payload->getOrgCode();
 	//fullDto->sys_company_code = payload->getCompanyCode();
 	//fullDto->create_date = DateUtil::getCurrentTime();

 	return fullDto;
 }


 // �����û����Խӿڴ���
 StringJsonVO::Wrapper CostSxController::execAddCostSx(const CostSxAddDTO::Wrapper& dto) {

 	// ����Ҫ������֤
 	// ֱ�Ӵ���service����
 	CostAttributeService service;

 	// serviceִ�в���,��Ȼʹ��DTO,���ز�����id 
 	// �Ƿ���ֻ�÷����Ƿ�����ɹ� ?
 	auto res = service.insert(dto);
 	auto jvo = StringJsonVO::createShared();

 	// ����ɹ�
 	if (res != "") {
 		jvo->success(res);
 	}
 	else {
 		jvo->fail(res);
 	}

 	return jvo;
 }
 // �޸��û����Խӿڴ���
 StringJsonVO::Wrapper CostSxController::execModifyCostSx(const CostSxModifyDTO::Wrapper& dto) {

 	// ��֤��id�Ƿ�Ϸ�
 	// ����������ֻҪ�����id���ڣ����Ǿ���Ϊ�ǺϷ���
 	auto jvo = StringJsonVO::createShared();
 	if (dto->id == "") {
 		// �Ƿ���³ɹ�
 		jvo->fail("");
 	}
 	else {
 		CostAttributeService service;
 		auto res = service.update(dto);
 		if (res) {
 			jvo->success(dto->id);
 		}
 		else {
 			jvo->fail(dto->id);
 		}
 	}


 	return jvo;
 }
 // ��ѯ�û��������ƽӿڴ���
 CostSxNameListPageJsonVO::Wrapper CostSxController::execQuerySxName(const CostSxQuery::Wrapper& query) {

 	// ֱ�ӵ���service
 	CostAttributeService service;

 	auto res = service.listName(query);

 	// �õ���Ӧ���Ǹ��б� ?
 	// ��ô���Ǳ��� ? ��ֱ�ӷ��ؿ���
 	auto jvo = CostSxNameListPageJsonVO::createShared();

 	jvo->success(res);

 	return jvo;
 }
 // ��ѯ�û�����(��ҳ)�ӿڴ��� ��ǰ������Ʋ�ѯ����һ��
 CostSxPageJsonVO::Wrapper CostSxController::execQuerySxPage(const CostSxQuery::Wrapper& query) {

 	// ֱ�ӵ���service
 	CostAttributeService service;

 	auto res = service.listAll(query);

 	// �õ���Ӧ���Ǹ��б� ?
 	// ��ô���Ǳ��� ? ��ֱ�ӷ��ؿ���
 	auto jvo = CostSxPageJsonVO::createShared();

 	jvo->success(res);

 	return jvo;
 }