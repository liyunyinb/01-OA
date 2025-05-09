#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/11 17:03:38

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
#ifndef _INFOFILEDTO_
#define _INFOFILEDTO_
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  id : ��ҵ�ȼ�ID
   typecode : ��ҵ�ȼ�����
   typenames : ��ҵ�ȼ�����
   createname : ������
   createby : �����˵�¼����
   createdate : ��������
   sysorgcode : ��������
   syscompanycode : ������˾
 */
class InfoFileDTO : public oatpp::DTO
{
	DTO_INIT(InfoFileDTO, DTO);
	// ��ҵ�ȼ�ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("CostConfigQuery.way.id"));
	// ��ҵ�ȼ�����
	API_DTO_FIELD_DEFAULT(String, typecodes, ZH_WORDS_GETTER("CostConfigQuery.way.code"));
	// ��ҵ�ȼ�����
	API_DTO_FIELD_DEFAULT(String, typenames, ZH_WORDS_GETTER("CostConfigQuery.way.name"));
	// ������
	API_DTO_FIELD_DEFAULT(String, creadename, ZH_WORDS_GETTER("attrikq.remove-attri.field.createname"));
	// �����˵�¼����
	API_DTO_FIELD_DEFAULT(String, createby, ZH_WORDS_GETTER("attrikq.remove-attri.field.createby"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, createdate, ZH_WORDS_GETTER("attrikq.remove-attri.field.createdate"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, sysorgcode, ZH_WORDS_GETTER("attrikq.remove-attri.field.sysorgcode"));
	// ������˾
	API_DTO_FIELD_DEFAULT(String, syscompanycode, ZH_WORDS_GETTER("attrikq.remove-attri.field.syscompanycode"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAM
