#ifndef _AREAINFO_QUERY_
#define _AREAINFO_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class AreaInfoQuery : public PageQuery
{
	DTO_INIT(AreaInfoQuery, PageQuery);
	// ��������
	DTO_FIELD(String, city_code);
	DTO_FIELD_INFO(city_code) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_code");
	}
	// ��������
	DTO_FIELD(String, city_name);
	DTO_FIELD_INFO(city_name) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_name");
	}
	// ����������
	DTO_FIELD(String, city_serc);
	DTO_FIELD_INFO(city_serc) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_serc");
	}
	// ��������
	DTO_FIELD(String, city_type_name);
	DTO_FIELD_INFO(city_type_name) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_type_name");
	}
	// Ƭ����Ϣ
	DTO_FIELD(String, barea_name);
	DTO_FIELD_INFO(barea_name) {
		info->description = ZH_WORDS_GETTER("AreaInfo.barea_name");
	}
	// ������Ϣ
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("AreaInfo.area_name");
	}
	// ͣ��
	DTO_FIELD(String, city_del);
	DTO_FIELD_INFO(city_del) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_del");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 