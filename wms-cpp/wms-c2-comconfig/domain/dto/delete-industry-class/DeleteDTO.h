#pragma once
#ifndef _DELETE_DTO_
#define _DELETE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
* �޸���ҵ�������
*/
class DeleteDTO :public oatpp::DTO
{
	DTO_INIT(DeleteDTO, DTO);

	//��ҵ����Ψһid
	API_DTO_FIELD_DEFAULT(Vector<String>, Id, ZH_WORDS_GETTER("chengfeng.id"));

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETE_DTO_