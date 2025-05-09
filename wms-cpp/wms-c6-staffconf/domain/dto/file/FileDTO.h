#pragma once

#ifndef _FILEDTO_H_
#define _FILEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editorͼƬ��Ϣ�������ݶ���
 */
class EditorImageDTO : public oatpp::DTO
{
	DTO_INIT(EditorImageDTO, DTO);
	// ͼƬsrc
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("file.field.img-url"), true, {});
	// ͼƬ��������
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.img-alt"));
	// ͼƬ���ӵ�ַ
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.img-href"));
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

#endif // !_FILEDTO_H_