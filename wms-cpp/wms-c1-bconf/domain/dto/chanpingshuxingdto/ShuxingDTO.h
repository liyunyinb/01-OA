#pragma once
#ifndef _SHUXINGDTO_H_
#define _SHUXINGDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class ShuxingDTO :public oatpp::DTO
{
public:
	DTO_INIT(ShuxingDTO, DTO);
	//id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.id");
	}
	////����������
	//DTO_FIELD(String, update_name);
	//DTO_FIELD_INFO(update_name) {
	//	info->description = ZH_WORDS_GETTER("ShuxingDTO.update_name");
	//}
	////�����˵�¼����
	//DTO_FIELD(String, update_by
	//);
	//DTO_FIELD_INFO(update_by
	//) {
	//	info->description = ZH_WORDS_GETTER("ShuxingDTO.update_by");
	//}
	//��Ʒ���Ա���
	DTO_FIELD(String, goods_type_code);
	DTO_FIELD_INFO(goods_type_code) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.goods_type_code");
	}
	//��Ʒ��������
	DTO_FIELD(String, goods_type_name);
	DTO_FIELD_INFO(goods_type_name) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.goods_type_name");
	}
private:

};
class ShuxingShanChuDTO :public oatpp::DTO {
	DTO_INIT(ShuxingShanChuDTO, DTO);
	DTO_FIELD(List<String>, ids);
	DTO_FIELD_INFO(ids) {
		info->description= ZH_WORDS_GETTER("ShuxingShanChuDTO.ids");
	}
};
class ShuxingDaoruDTO :public oatpp::DTO
{
public:
	DTO_INIT(ShuxingDaoruDTO, DTO);
	//����������
	DTO_FIELD(String, create_name);
	DTO_FIELD_INFO(create_name) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.create_name");
	}
	//�����˵�¼����
	DTO_FIELD(String, create_by
	);
	DTO_FIELD_INFO(create_by
	) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.create_by");
	}
	//��������
	DTO_FIELD(String, sys_org_code
	);
	DTO_FIELD_INFO(sys_org_code
	) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.sys_org_code");
	}
	//������˾
	DTO_FIELD(String, sys_company_code
	);
	DTO_FIELD_INFO(sys_company_code
	) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.sys_company_code");
	}
	 
	//�ļ�
	DTO_FIELD(String, file);
	DTO_FIELD_INFO(file) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.file");
	}
	//ҳǩ����
	DTO_FIELD(String, sheet_name
	);
	DTO_FIELD_INFO(sheet_name
	) {
		info->description = ZH_WORDS_GETTER("ShuxingDTO.sheet_name");
	}
private:

};
#include OATPP_CODEGEN_END(DTO)

#endif // !SHUXINGDTO
