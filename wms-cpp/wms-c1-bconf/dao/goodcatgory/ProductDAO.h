#pragma once
#ifndef _PRODUCT_DAO_
#define _PRODUCT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/goodcategory/ProductDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class ProductDAO : public BaseDAO
{
public:
	
	// ������Ʒ��Ŀ
	uint64_t save(const ProductDO& iObj);
	// �޸���Ʒ��Ŀ
	int update(const ProductDO& uObj);
	// ɾ����Ʒ��Ŀ
	int remove(std::string id);
};
#endif // !_PRODUCT_DAO_