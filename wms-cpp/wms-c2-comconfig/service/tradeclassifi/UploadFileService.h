#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/12 9:40:33

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
#ifndef _UPLOADFILESERVICE_
#define _UPLOADFILESERVICE_
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"
#include "stdafx.h"
#include "domain/dto/tradeclassifi/UploadFileDTO.h"


class UploadFileService
{
public:
	// 将解析的数据上传至数据库
	uint64_t saveData(const UploadFileDTO::Wrapper& dto);
};

#endif