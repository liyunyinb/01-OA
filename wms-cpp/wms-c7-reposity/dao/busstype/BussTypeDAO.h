#pragma once
#ifndef _BUSSTYPE_DAO_
#define _BUSSTYPE_DAO_

#include "BaseDAO.h"
#include "../../domain/query/busstype/BussTypeQuery.h"
#include "../../domain/do/busstype/BussTypeDO.h"
#include "../../domain/do/DoInclude.h"

class BussTypeDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const BussTypeQuery::Wrapper& query, SqlParams& params);
public:
	// ��ҳ��ѯ����
	std::list<BussTypeDO> selectWithPage(const BussTypeQuery::Wrapper& query);
	// ͨ��ҵ���������Ʋ�ѯ����
	std::list<BussTypeDO> selectByName(const string& name);
	// ͨ��ҵ�����ʹ����ѯ����
	std::list<BussTypeDO> selectByCode(const string& code);
	// ͨ��ҵ�����ͱ�ע��ѯ����
	std::list<BussTypeDO> selectByText(const string& text);
	// ��������
	uint64_t insert(const BussTypeDO& iObj);
	// ͳ����������
	uint64_t count(const BussTypeQuery::Wrapper& query);
	// �޸�����
	int update(const BussTypeDO& uObj);
};
#endif // _BUSSTYPE_DAO_
