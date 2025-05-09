#pragma once
/*
 @Author: 002
 @Date: 2025.3.4
*/
#ifndef _CITY_TYPE_DAO_
#define _CITY_TYPE_DAO_
#include "BaseDAO.h"
#include "domain/do/citytype/CityTypeDO.h"
#include "domain/query/citytype/CityTypeQuery.h"

/**
 * ba_city_type�����ݿ����ʵ��
 */
class CityTypeDAO : public BaseDAO
{
public:
	bool add(const CityTypeAddDO& obj);
	void add(const list<CityTypeAddDO>& obj);
	bool upd(const CityTypeUpdDO& obj);
	//��ѯ����
	std::list<CityTypeNameDO> getDistinctCityTypes();
	std::list<CityTypeDO> selectWithPage(const CityTypeQuery::Wrapper& query);
	std::list<CityTypeBaseDO> listAll();
	// ͨ��IDɾ������
	int deleteById(string id);
	uint64_t insertCityType(const std::string& cityName, const std::string& cityCode, const PayloadDTO& payload);
};
#endif // !_CITY_TYPE_DAO_
