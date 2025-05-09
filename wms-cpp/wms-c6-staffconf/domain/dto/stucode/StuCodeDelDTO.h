#pragma once
#ifndef _STUCODEDEL_DTO_
#define _STUCODEDEL_DTO_

#include "../../GlobalInclude.h"
#include "StuCodeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class StuCodeDelDTO : public oatpp::DTO
{
	DTO_INIT(StuCodeDelDTO, DTO);

	DTO_FIELD(List<String>, delList);
	DTO_FIELD_INFO(delList)
	{
		info->description = "del id list";
	}
};

class StuCodeDelListDTO : public oatpp::DTO
{
	DTO_INIT(StuCodeDelListDTO, DTO);
	DTO_FIELD(List<StuCodeDelDTO::Wrapper>, stucodeDelList);
};

/**
 * ʾ����ҳ�������
 */
class StuCodeDelPageDTO : public PageDTO<StuCodeDelDTO::Wrapper>
{
	DTO_INIT(StuCodeDelPageDTO, PageDTO<StuCodeDelDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_STUCODEDEL_DTO_
