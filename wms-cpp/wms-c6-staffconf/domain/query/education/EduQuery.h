#pragma once

#ifndef _EDU_QUERY_
#define _EDU_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class EduQuery : public PageQuery
{
	DTO_INIT(EduQuery, PageQuery);
	 //�ֶ�id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("education.filed.id");
	}
	// ѧ������
	DTO_FIELD(String, educode);
	DTO_FIELD_INFO(educode) {
		info->description = ZH_WORDS_GETTER("education.filed.educode");
	}
	// ѧ������
	DTO_FIELD(String, eduname);
	DTO_FIELD_INFO(eduname) {
		info->description = ZH_WORDS_GETTER("education.filed.eduname");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EDU_QUERY_