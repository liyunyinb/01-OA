#pragma once
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO) ///< Begin DTO codegen section

class RegionInfoDTO : public oatpp::DTO {

	DTO_INIT(RegionInfoDTO, DTO /* extends */)

	// Ƭ������
	DTO_FIELD(String, region_code);
	DTO_FIELD_INFO(region_code) {
		info->description = ZH_WORDS_GETTER("region.field.code");
	}
	// Ƭ������
	DTO_FIELD(String, region_name);
	DTO_FIELD_INFO(region_name) {
		info->description = ZH_WORDS_GETTER("region.field.name");
	}
	// �ص���ʱ
	DTO_FIELD(Float64, region_rdata);
	DTO_FIELD_INFO(region_rdata) {
		info->description = ZH_WORDS_GETTER("region.field.rdate");
	}

};


class RegionModifyDTO : public oatpp::DTO {

	DTO_INIT(RegionModifyDTO, DTO /* extends */)

	// Ƭ��id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("region.field.id");
	}
	// Ƭ������
	DTO_FIELD(String, region_code);
	DTO_FIELD_INFO(region_code) {
		info->description = ZH_WORDS_GETTER("region.field.code");
	}
	// Ƭ������
	DTO_FIELD(String, region_name);
	DTO_FIELD_INFO(region_name) {
		info->description = ZH_WORDS_GETTER("region.field.name");
	}
	// �ص���ʱ
	DTO_FIELD(Float64, region_rdata);
	DTO_FIELD_INFO(region_rdata) {
		info->description = ZH_WORDS_GETTER("region.field.rdate");
	}

};

#include OATPP_CODEGEN_END(DTO) ///< End DTO codegen section