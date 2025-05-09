#pragma once
#ifndef _PRPODUCTDTO_
#define _PRPODUCTDTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ʒ�б�
 */

class ProductListDTO : public oatpp::DTO
{
	DTO_INIT(ProductListDTO, DTO);
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, categoryname, ZH_WORDS_GETTER("product.field.categoryname"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, categorynum, ZH_WORDS_GETTER("product.field.categorynum"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, createtime, ZH_WORDS_GETTER("product.field.createtime"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(UInt64, categorylevel, ZH_WORDS_GETTER("product.field.categorylevel"));
	// ����Ŀ¼
	API_DTO_FIELD_DEFAULT(UInt64, pid, ZH_WORDS_GETTER("product.field.pid"));
	// ����Ŀ¼
	API_DTO_FIELD_DEFAULT(String, topnode, ZH_WORDS_GETTER("product.field.top"));
	
	
};


class ProductAddDTO : public oatpp::DTO
{
	DTO_INIT(ProductAddDTO, DTO);
	// ��Ʒ��Ŀ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("product.field.categoryname");
	}
	// ����
	DTO_FIELD(String, categorynum);
	DTO_FIELD_INFO(categorynum) {
		info->description = ZH_WORDS_GETTER("product.field.categorynum");
	}
	// ��Ʒ����
	DTO_FIELD(UInt64, categorylevel);
	DTO_FIELD_INFO(categorylevel) {
		info->description = ZH_WORDS_GETTER("product.field.categorylevel");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRPODUCTDTO_