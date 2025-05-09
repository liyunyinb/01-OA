#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: èͷ����
 @Date: 2025/03/10 16:09:12

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.ations under the License.
*/
#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class Recv_G_WayDO
{
	CC_SYNTHESIZE(string, id, Id);
	// �ӻ�id
	CC_SYNTHESIZE(string, del_mode_code, Del_mode_code);
	// �ӻ�����
	CC_SYNTHESIZE(string, del_mode_name, Del_mode_name);

public:
	Recv_G_WayDO() {
		id = "";
		del_mode_code = "";
		del_mode_name = "";
		
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<Recv_G_WayDO> PtrRecv_G_WayDO;
#endif // !_SAMPLE_DO_