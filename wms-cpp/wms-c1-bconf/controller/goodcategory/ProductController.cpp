#include "stdafx.h"
#include "ProductController.h"
#include"../../service/goodcategory/ProductService.h"
StringJsonVO::Wrapper ProductController::execAddProduct(const ProductListDTO::Wrapper& dto) {
	auto product = StringJsonVO::createShared();
	// ���巵�����ݶ���
	
	// ����У��
	// �ǿ�У��
	
	if (!dto->categorylevel || !dto->categoryname || !dto->categorynum)
	{
		product->init(String(""), RS_PARAMS_INVALID);
		return product;
	}
	
	// ��ЧֵУ��

	if (dto->categorynum ->empty() || !dto->categorylevel || dto->categoryname->empty())
	{
		product->init(String(""), RS_PARAMS_INVALID);
		return product;
	}

	// ����һ��Service
	ProductService service;
	// ִ����������
	uint64_t id = service.saveCategory(dto);
	if (id > 0) {
		product->success(String(std::to_string(id)));
	}
	else
	{
		product->fail(String(std::to_string(id)));
	}
	//��Ӧ���
	return product;
	
}
StringJsonVO::Wrapper ProductController::execModifyProduct(const ProductListDTO::Wrapper& dto) {
	// ���巵�����ݶ���
	auto product = StringJsonVO::createShared();
	// ����У��
	
	if (!dto->categoryname->empty() || dto->categorynum->empty())
	{
		product->init(String(""), RS_PARAMS_INVALID);
		return product;
	}
	
	// ����һ��Service
	ProductService service;
	// ִ�������޸�
	
	if (service.updateCategory(dto)) {
		product->success(dto->categoryname);
	}
	
	else
	{
		product->fail(dto->categoryname);
	}
	
	// ��Ӧ���
	return product;
	
}
StringJsonVO::Wrapper ProductController::execRemoveProduct(const String& id) {
	// ���巵�����ݶ���
	auto product = StringJsonVO::createShared();
	// ����У��
	if (id.getValue("").empty())
	{
		product->init(String(""), RS_PARAMS_INVALID);
		return product;
	}
	
	// ����һ��Service
	ProductService service;
	// ִ������ɾ��
	if (service.removeCategory(id.getValue(""))) {		//�����и�move�������ش��󣬵���֪����ô��
		product->success(id);
	}
	else
	{
		product->fail(id);
	}
	
	// ��Ӧ���
	return product;
	
}