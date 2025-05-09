#pragma once
#include"../../domain/dto/chanpingshuxingdto/ShuxingDTO.h"
#include"../../domain/GlobalInclude.h"

#include "Macros.h"
#include "ExcelComponent.h"
class  ShuxingService {
public:
	//�޸�����
	bool modify_data(const ShuxingDTO::Wrapper& dto, const PayloadDTO& payload);
	//ɾ������
	bool delete_data(const ShuxingShanChuDTO::Wrapper& dto);
	//��������
	vector<array<string,2>>upload_data();
	//��������
	bool load_data(const ShuxingDaoruDTO& dto);
};