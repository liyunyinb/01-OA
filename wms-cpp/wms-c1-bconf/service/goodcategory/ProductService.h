#pragma once
#ifndef _PRODUCT_SERVICE_
#define _PRODUCT_SERVICE_
#include <list>
#include"../../domain/dto/goodcategory/ProductDTO.h"
#include"../../domain/vo/goodcategory/ProductVO.h"

/**
 *	��Ʒ��Ŀ¼�롢��Ʒ��Ŀ�޸ġ���Ʒ��Ŀɾ����Service��
 */
class ProductService
{
public:

	// ������Ʒ��Ŀ
	uint64_t saveCategory(const ProductListDTO::Wrapper& dto);
	// �޸���Ʒ��Ŀ
	bool updateCategory(const ProductListDTO::Wrapper& dto);
	// ɾ����Ʒ��Ŀ
	bool removeCategory(const std::string& id);
};

#endif // !_PRODUCT_SERVICE_