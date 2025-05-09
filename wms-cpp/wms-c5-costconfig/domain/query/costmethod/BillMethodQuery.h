#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

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
#ifndef _BILLMETHOD_H_
#define _BILLMETHOD_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class BillmethodQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(BillmethodQuery, PageQuery);
	// �ǳ�
	API_DTO_FIELD_DEFAULT(String, pronut_code, ZH_WORDS_GETTER("pronut_code"));
	API_DTO_FIELD_DEFAULT(String, pronut_name, ZH_WORDS_GETTER("pronut_name"));
};
class BillmethodQueryomit : oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(BillmethodQuery, oatpp::DTO);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _BILLMETHOD_H_
