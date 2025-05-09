#pragma once
#ifndef _EXPORT_QUERY_
#define _EXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����͵�����˾��Ϣ��ҳ��ѯ����
 */
class ExportAddQuery : public PageQuery
{
	DTO_INIT(ExportAddQuery, PageQuery);
	// ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("chengfeng.id");
	}
	// ��ҵ�������
	DTO_FIELD(String, classfl_code);
	DTO_FIELD_INFO(classfl_code) {
		info->description = ZH_WORDS_GETTER("chengfeng.code");
	}
	// ��ҵ��������
	DTO_FIELD(String, classfl_name);
	DTO_FIELD_INFO(classfl_name) {
		info->description = ZH_WORDS_GETTER("chengfeng.name");
	}
	// ͣ��
	DTO_FIELD(String, classfl_del);
	DTO_FIELD_INFO(classfl_del) {
		info->description = ZH_WORDS_GETTER("chengfeng.del");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_QUERY_

