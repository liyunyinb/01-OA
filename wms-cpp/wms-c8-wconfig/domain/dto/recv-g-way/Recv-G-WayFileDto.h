#pragma once
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
#ifndef _Recv_G_Way_DTO_
#define _Recv_G_Way_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * �ӻ��޸Ĺ��� ���ݶ��󣬰���Ҫ��ʾ�Ļ�������
 */

/**
 * �ӻ��������ݶ��󣬰���Ҫ��ʾ�Ļ������ݡ�
 */
class Recv_G_WayAddDto : public oatpp::DTO
{
	DTO_INIT(Recv_G_WayAddDto, DTO);

	DTO_FIELD(String, del_mode_name);
	DTO_FIELD_INFO(del_mode_name) {
		info->description = ZH_WORDS_GETTER("recv_g_way.file.del_mode_name");
	}
	DTO_FIELD(String, del_mode_code);
	DTO_FIELD_INFO(del_mode_code) {
		info->description = ZH_WORDS_GETTER("recv_g_way.file.del_mode_code");
	}
	
};

/**
 * �ӻ��޸Ĺ��� ���ݶ��󣬰���Ҫ��ʾ�Ļ�������
 */
class Recv_G_WayEditDto : public Recv_G_WayAddDto
{
	
	DTO_INIT(Recv_G_WayEditDto, Recv_G_WayAddDto);
	// ���
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("recv_g_way.file.id");
	}
};


/**
 * �ӻ���ѯ���� ���ݶ��󣬰���Ҫ��ʾ�Ļ������ݡ�
 */
class Recv_G_WayAllDto : public PageDTO<Recv_G_WayEditDto::Wrapper>
{
	DTO_INIT(Recv_G_WayAllDto, PageDTO<Recv_G_WayEditDto::Wrapper>);

};



class EditorImageDTO : public oatpp::DTO
{
	DTO_INIT(EditorImageDTO, DTO);
	// ͼƬsrc
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("recv-g-way-file.field.img-url"), true, {});
	// ͼƬ��������
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("recv-g-way-file.field.img-alt"));
	// ͼƬ���ӵ�ַ
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("recv-g-way-file.field.img-href"));
public:
	EditorImageDTO() {}
	EditorImageDTO(String url, String alt = "", String href = "")
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};





#include OATPP_CODEGEN_END(DTO)
#endif 