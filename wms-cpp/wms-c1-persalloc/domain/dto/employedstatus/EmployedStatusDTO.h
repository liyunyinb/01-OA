#pragma once

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ��ɾ�����ݴ������
 */
class EmployedStatusRemoveDTO : public oatpp::DTO
{
	DTO_INIT(EmployedStatusRemoveDTO, DTO);


	// ��ְ״̬����
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("employed.field.code");
	}
};

/**
 * ʾ���������
 */
class EmployedStatusDTO : public EmployedStatusRemoveDTO
{
	DTO_INIT(EmployedStatusDTO, EmployedStatusRemoveDTO);
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("employed.field.id");
	}
	// ��ְ״̬����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employed.field.name");
	}
};

class EmployedBatchRemoveDTO : public oatpp::DTO {

	DTO_INIT(EmployedBatchRemoveDTO, DTO);

	DTO_FIELD(oatpp::List<oatpp::Object<EmployedStatusRemoveDTO>>, rows) = {};
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("employed.field.code");
	}
};

#include OATPP_CODEGEN_END(DTO)