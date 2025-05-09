#pragma once
#include <list>
#include <stdint.h>

//#include "domain/vo/employedstatus/employedVO.h"
//#include "domain/query/employedstatus/employedQuery.h"
#include "domain/dto/employedstatus/EmployedStatusDTO.h"

// ������ApiHelper��ʶ��String ��֪��Ϊʲô
#include "ApiHelper.h"
typedef oatpp::data::mapping::type::String String;
/**
 * ��ְ״̬����ʵ��
 */
class EmployedService
{
public:

	bool removeData(const EmployedStatusRemoveDTO::Wrapper& dto);
	// ��ҳ��ѯ��������
	//SamplePageDTO::Wrapper listAll(const SampleQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	//SampleDTO::Wrapper getById(uint64_t id);
	// ��������
	//uint64_t saveData(const SampleAddDTO::Wrapper& dto);
 


	// �޸�����	// ��������
	//bool updateData(const EmployedDTO::Wrapper& dto);
	// ͨ��IDɾ������

	// ������ְ״̬���е���������
	bool exportAllData(string localpath);
	// ��������
	bool importAllData(const vector<vector<string>>& ptr_data, const PayloadDTO& payload);
};