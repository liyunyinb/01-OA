#pragma once
/*
 @Author: 002
 @Date: 2025.3.7
*/
#ifndef _REGION_INFO_SERVICE_
#define _REGION_INFO_SERVICE_
#include <list>
#include "domain/dto/regioninfo/RegioninfoDTO.h"
#include "domain/do/regioninfo/RegionInfoDO.h"
#include "domain/dto/regioninfo/RegionNameDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RegionInfoService
{
public:
	// ��������
	uint64_t saveData(const RegionInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	// ͨ��region_codeɾ������
	bool removeData(std::string region_code);
	// �޸�����
	bool updateData(const RegionModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	// ��������
	void import(std::vector<std::vector<std::string>> data, const PayloadDTO& payload);
	oatpp::Vector<RegionNameDTO::Wrapper> getByName();
};

#endif // !_SAMPLE_SERVICE_

#pragma once
