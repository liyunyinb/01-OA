#pragma once
/*
 @Author: nanbowan
*/
#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �޸��¶����Զ���
*/
class ModifyLibraryDTO :public oatpp::DTO
{
	DTO_INIT(ModifyLibraryDTO, DTO);

	//Ҫ�޸ĵĿ�λ���͵�Ψһid
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("dictionary.library.id.summary"));

	//�¿�λ���ʹ���
	API_DTO_FIELD_DEFAULT(String, bin_type_code, ZH_WORDS_GETTER("dictionary.library.code.summary"));

	//�¿�λ��������
	API_DTO_FIELD_DEFAULT(String, bin_type_name, ZH_WORDS_GETTER("dictionary.library.type.summary"));

};


#include OATPP_CODEGEN_END(DTO)
