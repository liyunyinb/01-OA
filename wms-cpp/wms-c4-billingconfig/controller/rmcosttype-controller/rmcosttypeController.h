#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/costtype/costtypeQuery.h"
#include "domain/dto/costtype/costtypeDTO.h"
#include "domain/vo/costtype/costtypeVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class rmcosttypeController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(rmcosttypeController)
public:
    //ɾ����������
    //// 3.1 ����ɾ���ӿ�����
    //ENDPOINT_INFO(remove) {
    //    // �������ͷ��������Լ���Ȩ֧��
    //    API_DEF_ADD_COMMON_AUTH("delete cost type", Uint64JsonVO::Wrapper);
    //    // ��������·������˵��
    //    API_DEF_ADD_PATH_PARAMS(UInt64, "id", "id", 1, true);
    //}
    //// 3.2 ����ɾ���ӿڴ���
    //API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sample/{id}", remove, PATH(UInt64, id), execRemovecosttype(id));
    //Uint64JsonVO::Wrapper execRemovecosttype(const UInt64& id);


   
// 3.1 ����ɾ���ӿ�����
    ENDPOINT_INFO(remove) {
        // �������ͷ��������Լ���Ȩ֧��
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("costtype.delete"), StringJsonVO::Wrapper);
        // ��������·������˵������ UInt64 ��Ϊ oatpp::String
        API_DEF_ADD_PATH_PARAMS(String, "id", "id", 1, true);
    }
    // 3.2 ����ɾ���ӿڴ���
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/rm/{id}", remove, PATH(String, id), execRemovecosttype(id));
    StringJsonVO::Wrapper execRemovecosttype(const String& id);




    ENDPOINT_INFO(remove_more) {
        // �������ͷ��������Լ���Ȩ֧��
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("costtype.mdelete"), StringJsonVO::Wrapper);
        // ��������·������˵������ UInt64 ��Ϊ oatpp::String
        API_DEF_ADD_PATH_PARAMS(String, "ids", "Comma-separated list of ids", 1, true);
    }
    // 3.2 ����ɾ���ӿڴ���
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/rm_more/{ids}", remove_more, PATH(String, ids), execRemovecosttype_more(ids));
    StringJsonVO::Wrapper execRemovecosttype_more(const String& ids);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

