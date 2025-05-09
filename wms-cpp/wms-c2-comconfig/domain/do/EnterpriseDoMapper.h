#pragma once
#ifndef _EnterpriseDoMapper_H_
#define _EnterpriseDoMapper_H_
#include "enterpriseDO.h"
#include "Mapper.h"
class EnterpriseDoMapper : public Mapper<EnterpriseDO>
{
public:
	EnterpriseDO mapper(ResultSet* res) const override
	{
		EnterpriseDO ans;

		//��ȡ��ѯ����ĵ�1������
		ans.setComTypeName(res->getString(1));
		return ans;
	}
};
class EnterpriseDoMapper1 : public Mapper<EnterpriseDO>
{
public:
	EnterpriseDO mapper(ResultSet* res) const override
	{
		EnterpriseDO ans;

		//��ȡ��ѯ����ĵ�1������
		ans.setComTypeCode(res->getString(1));
		ans.setComTypeName(res->getString(2));
		ans.setComTypeDel(res->getUInt64(3));
		return ans;
	}
};
#endif // !_EnterpriseDoMapper_H_
