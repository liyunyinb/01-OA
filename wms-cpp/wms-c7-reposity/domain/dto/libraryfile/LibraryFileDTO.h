#pragma once
/*
 @Author: nanbowan
*/

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������ݴ������
 */
class LibraryFileAddDTO : public oatpp::DTO
{
	DTO_INIT(LibraryFileAddDTO, DTO);
	// ��λ����
	DTO_FIELD(String, bin_type_code);
	DTO_FIELD_INFO(bin_type_code) {
		info->description = ZH_WORDS_GETTER("dictionary.library.code.summary");
	}
	// ��λ����
	DTO_FIELD(String, bin_type_name);
	DTO_FIELD_INFO(bin_type_name) {
		info->description = ZH_WORDS_GETTER("dictionary.library.type.summary");
	}
};

/*
* �ļ����Ͷ���
*/
class LibraryFileDTO :public oatpp::DTO
{
	DTO_INIT(LibraryFileDTO, DTO);

	//�������ʹ���
	API_DTO_FIELD_DEFAULT(String, bin_type_code, ZH_WORDS_GETTER("dictionary.library.code.summary"));

	//������������
	API_DTO_FIELD_DEFAULT(String, bin_type_name, ZH_WORDS_GETTER("dictionary.library.type.summary"));

};


#include OATPP_CODEGEN_END(DTO)
