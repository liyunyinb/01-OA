#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/08 19:14:56

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
#ifndef _COMPANYNAMESERVICE_
#define _COMPANYNAMESERVICE_
#include <list>
#include "domain/dto/companyattribute/CompanyNameDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CompanyNameService
{
public:
	// 通过ID查询单个数据
	CompanyNameDTO::Wrapper getCompanyName();
};

#endif // !_SAMPLE_SERVICE_

