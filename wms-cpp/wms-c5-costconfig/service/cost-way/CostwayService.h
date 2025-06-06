#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _COSTWAY_SERVICE_
#define _COSTWAY_SERVICE_
#include <list>
#include "../../domain/vo/cost-way/DeleteVO.h"
#include "../../domain/query/cost-way/DeleteQuery.h"
#include "../../domain/dto/cost-way/DeleteDTO.h"
#include "../../domain/dto/cost-way/UploadExcelDTO.h"
#include "../../domain/do/cost-way/CostwayDO.h"
/**
 */
class CostwayService
{
public:
	// 通过计费方式编码删除数据
	bool removeDataById(string pronut_code);
	//保存数据
	uint64_t saveData(const UploadExcelDTO::Wrapper& dto);
	//查询所有数据
	list<CostwayDO> listAll();
};

#endif // !_COSTWAY_SERVICE_

