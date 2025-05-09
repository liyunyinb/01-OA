#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/2/27 22:17

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

#ifndef _COST_DETAIL_DTO_
#define _COST_DETAIL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//����������DTO,�������������Ҫ������
class CostAddDTO : public oatpp::DTO
{
	DTO_INIT(CostAddDTO, DTO);
	// �ͻ�
	DTO_FIELD(String, client);
	DTO_FIELD_INFO(client) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.client");
	}
	// ����(����)
	DTO_FIELD(String, cost);
	DTO_FIELD_INFO(cost) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.cost");
	}
	// ��������
	DTO_FIELD(String, costdate);
	DTO_FIELD_INFO(costdate) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.costdate");
	}
	//ԭ��
	DTO_FIELD(String, oldprice);
	DTO_FIELD_INFO(oldprice) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.oldprice");
	}
	//����˰��
	DTO_FIELD(String, notax);
	DTO_FIELD_INFO(notax) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.notax");
	}
	//˰��
	DTO_FIELD(String, tax);
	DTO_FIELD_INFO(tax) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.tax");
	}
	//��˰��
	DTO_FIELD(String, taxprice);
	DTO_FIELD_INFO(taxprice) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.taxprice");
	}
	//������Դ
	DTO_FIELD(String, source);
	DTO_FIELD_INFO(source) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.source");
	}
	//��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.remark");
	}
	//״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.state");
	}
	//�Ʒ�����
	DTO_FIELD(String, count);
	DTO_FIELD_INFO(count) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.count");
	}
	//������λ
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.unit");
	}
};
//���ڵ�����DTO,����������excel��Ҫ������
class CostExportDTO :public CostAddDTO
{
	DTO_INIT(CostExportDTO, CostAddDTO);
	//������
	DTO_FIELD(String, creator);
	DTO_FIELD_INFO(creator) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.creator");
	}
	//��������
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.createdate");
	}
	//������
	DTO_FIELD(String, updater);
	DTO_FIELD_INFO(updater) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.updater");
	}
	//��������
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.updatedate");
	}
	//�ͻ�����
	DTO_FIELD(String, clientname);
	DTO_FIELD_INFO(clientname) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.clientname");
	}
	//��������
	DTO_FIELD(String, costname);
	DTO_FIELD_INFO(costname) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.costname");
	}
	//����״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.status");
	}
	//�����˵�¼����(��payload��ȡ)
	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.create-by");
	}
	//��������(��payload��ȡ)
	DTO_FIELD(String, org_code);
	DTO_FIELD_INFO(org_code) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.org-code");
	}
	//������˾(��payload��ȡ)
	DTO_FIELD(String, company_code);
	DTO_FIELD_INFO(company_code) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.company-code");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_DETAIL_DTO_