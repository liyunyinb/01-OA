#pragma once

#ifndef _DELETETUOPAN_DTO_
#define _DELETETUOPAN_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ɾ�����̴������
 */

class DeleteTuopanDTO : public oatpp::DTO
{
	DTO_INIT(DeleteTuopanDTO, DTO);

	// ����
	DTO_FIELD(List<String>, id) ;
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("tuopan.id");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETETUOPAN_DTO_