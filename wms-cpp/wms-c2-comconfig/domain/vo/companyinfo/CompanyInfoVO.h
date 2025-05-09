#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
 @Date: 2025/2/22 20:45:06

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
#ifndef _COMPANYINFO_VO_
#define _COMPANYINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/companyinfo/CompanyInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ¼����Ϣ���JsonVO����������ҳ����ʾ��¼��Ĺ�˾��Ϣ
 */
class CompanyInfoJsonVO : public JsonVO<CompanyInfoDTO::Wrapper> {
	DTO_INIT(CompanyInfoJsonVO, JsonVO<CompanyInfoDTO::Wrapper>);};

#include OATPP_CODEGEN_END(DTO)

#endif
