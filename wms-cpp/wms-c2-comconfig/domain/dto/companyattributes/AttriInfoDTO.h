#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: killerqueen
 @Date: 2025/2/24 10:50:38

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
#ifndef _ATTRIINFO_DTO_
#define _ATTRIINFO_DTO_
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  id : ��ҵ����ID
   typecode : ��ҵ���Դ���
   typecode : ��ҵ���Դ���
   typenames : ��ҵ��������
   createname : ������
   createby : �����˵�¼����
   createdate : ��������
   sysorgcode : ��������
   syscompanycode : ������˾
 */
class AttriInfoJsonDTO : public oatpp::DTO
{
	DTO_INIT(AttriInfoJsonDTO, DTO);
	// ��ҵ����ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("attrikq.remove-attri.field.id"));
	// ��ҵ���Դ���
	API_DTO_FIELD_DEFAULT(String, typecodes, ZH_WORDS_GETTER("attrikq.remove-attri.field.typecode"));
	// ��ҵ��������
	API_DTO_FIELD_DEFAULT(String, typenames, ZH_WORDS_GETTER("attrikq.remove-attri.field.typename"));
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


/*
ids : ��ҵ��������ɾ��ID�б�
*/
class AttriDeleteInfoDTO : public oatpp::DTO
{
	DTO_INIT(AttriDeleteInfoDTO, DTO);
	// ��ҵ����ID
	API_DTO_FIELD_DEFAULT(Vector<String>, ids, ZH_WORDS_GETTER("attrikq.remove-attri.field.ids"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAM