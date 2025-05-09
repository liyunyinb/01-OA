#pragma once
/*
 @Author: nanbowan
*/

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������ݴ������
 */
class FileAddDTO : public oatpp::DTO
{
	DTO_INIT(FileAddDTO, DTO);
	// �������ͱ���
	DTO_FIELD(String, order_type_code);
	DTO_FIELD_INFO(order_type_code) {
		info->description = ZH_WORDS_GETTER("dictionary.order.code.summary");
	}
	// ������������
	DTO_FIELD(String, order_type_name);
	DTO_FIELD_INFO(order_type_name) {
		info->description = ZH_WORDS_GETTER("dictionary.order.type.summary");
	}
};

/*
* �ļ����Ͷ���
*/
class FileDTO :public oatpp::DTO
{
	DTO_INIT(FileDTO, DTO);

	//�������ʹ���
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("dictionary.order.code.summary"));

	//������������
	API_DTO_FIELD_DEFAULT(String, order_name_name, ZH_WORDS_GETTER("dictionary.order.type.summary"));

};


#include OATPP_CODEGEN_END(DTO)
