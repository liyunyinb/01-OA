#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: maomao
 @Date: 2025/2/24 11:10:36

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
#ifndef _DEFPLAT_DTO_
#define _DEFPLAT_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��̨����ģ�� ɾ����̨���� ���ݶ��󣬰���Ҫ��ʾ�Ļ�������
 */
class DefDelDto : public oatpp::DTO
{
	DTO_INIT(DefDelDto, DTO);

	// ��̨id
	API_DTO_FIELD_DEFAULT(String, id, "id");

};
/**
 * ��̨����ģ�� ��̨�޸Ĺ��� ���ݶ��󣬰���Ҫ��ʾ�Ļ�������
 */
class DefEditDto : public oatpp::DTO
{
	DTO_INIT(DefEditDto, DTO);

	// Ҫ�޸ĵ���̨��id
	API_DTO_FIELD_DEFAULT(String, id, "id");
	//��ĵ��������������Ҫ�͵ڶ���һ��
	// �޸ĺ����̨����
	API_DTO_FIELD_DEFAULT(String, platform_code, "platform_code");

	// �޸ĺ����̨����
	API_DTO_FIELD_DEFAULT(String, platform_name, " platform_name");

};
/**
 * ��̨����ģ�� ������̨���� ���ݶ��󣬰���Ҫ��ʾ�Ļ�������
 */
class DefPutDto : public oatpp::DTO
{
	DTO_INIT(DefPutDto, DTO);

	// ��̨id
	API_DTO_FIELD_DEFAULT(String, id, "PlatformIP");

};

#include OATPP_CODEGEN_END(DTO)
#endif //_DEFPLAT_DTO_