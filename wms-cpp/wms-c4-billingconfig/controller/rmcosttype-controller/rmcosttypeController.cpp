
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "rmcosttypeController.h"
#include "../../service/costtype/costtypeService.h"
#include "../ApiDeclarativeServicesHelper.h"



//Uint64JsonVO::Wrapper rmcosttypeController::execRemovecosttype(const UInt64& id)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (!id || id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	costtypeService service;
//	// ִ������ɾ��
//	if (service.removeData(id.getValue(0))) {
//		jvo->success(id);
//	}
//	else
//	{
//		jvo->fail(id);
//	}
//	// ��Ӧ���
//	return jvo;
//	
//}

StringJsonVO::Wrapper rmcosttypeController::execRemovecosttype(const String& id)
{
    // ���巵�����ݶ���
    auto jvo = StringJsonVO::createShared();
    // ����У�飬����ַ����Ƿ�Ϊ��
    if (id->empty())
    {
        jvo->init(String(), RS_PARAMS_INVALID);
        return jvo;
    }
    // ����һ��Service
    costtypeService service;
    // ִ������ɾ��
    if (service.removeData(id.getValue(""))) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    // ��Ӧ���
    return jvo;
}



StringJsonVO::Wrapper rmcosttypeController::execRemovecosttype_more(const String& ids)
{
    // ���巵�����ݶ���
    auto jvo = StringJsonVO::createShared();
    // ����У�飬����ַ����Ƿ�Ϊ��
    if (ids->empty())
    {
        jvo->init(String(), RS_PARAMS_INVALID);
        return jvo;
    }

    // ��� ids �ַ���
    std::vector<std::string> idList;
    std::stringstream ss(URIUtil::urlDecode(ids.getValue("")));
    std::string id;
    while (std::getline(ss, id, ',')) {
        idList.push_back(id);
    }

    // ����һ�� Service
    costtypeService service;
    // ִ����������ɾ��
    if (service.removeData_more(idList)) {
        jvo->success(ids);
    }
    else
    {
        jvo->fail(ids);
    }
    // ��Ӧ���
    return jvo;
}