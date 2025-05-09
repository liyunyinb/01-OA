#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_SERVICE_
#define _COMPANYATTR_SERVICE_
#include <list>
#include"domain/query/companyattr/CompanyattrQuery.h"
#include"domain/vo/companyattr/CompanyattrVO.h"
#include"domain/dto/companyattr/CompanyattrDTO.h"
/*
* ��ҵ���Է�ҳ��ѯ���������޸ķ���ʵ��
*/
class CompanyattrService
{
public:
	// ��ҳ��ѯ��������
	CompanyattrListPageDTO::Wrapper listAll(const CompanyattrQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const CompanyattrListDTO::Wrapper& dto, const PayloadDTO& payload);
	//��������
	bool updateData(const CompanyattrIdListDTO::Wrapper& dto, const PayloadDTO& payload);
};


#endif // !_COMPANYATTR_SERVICE_
