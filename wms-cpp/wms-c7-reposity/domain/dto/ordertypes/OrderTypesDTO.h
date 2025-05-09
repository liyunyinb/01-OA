#pragma once
/*
 @Author: nanbowan
*/
#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �޸Ķ������Ͷ���
*/
class ModifyOrderTypeDTO :public oatpp::DTO
{
	DTO_INIT(ModifyOrderTypeDTO, DTO);

	//Ҫ�޸ĵĶ������͵�Ψһid
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("dictionary.order.id.summary"));

	//�¶������ʹ���
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("dictionary.order.code.summary"));

	//�¶�����������
	API_DTO_FIELD_DEFAULT(String, order_type_name, ZH_WORDS_GETTER("dictionary.order.type.summary"));

};


#include OATPP_CODEGEN_END(DTO)
