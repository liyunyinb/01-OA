#pragma once
#ifndef _ORDERTYPE_DO_H
#define _ORDERTYPE_DO_H
#include "../DoInclude.h"

class OrderTypeAddDO {
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// �������ʹ���
	CC_SYNTHESIZE(string, order_type_code, OrderTypeCode);
	// ������������
	CC_SYNTHESIZE(string, order_type_name, OrderTypeName);
	// ��������
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// ����������
	CC_SYNTHESIZE(string, create_name, CreateName);
	// �����˵�¼����
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// ������˾
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
public:
	OrderTypeAddDO() : id(""), order_type_code(""), order_type_name("") {}
	OrderTypeAddDO(string id, string order_type_code, string order_type_name)
	{
		this->id = id;
		this->order_type_code = order_type_code;
		this->order_type_name = order_type_name;
	}
};

class OrderTypeDO {
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// �������ʹ���
	CC_SYNTHESIZE(string, order_type_code, OrderTypeCode);
	// ������������
	CC_SYNTHESIZE(string, order_type_name, OrderTypeName);
public:
	OrderTypeDO() :id(""), order_type_code(""), order_type_name("") {}
	OrderTypeDO(string id, string order_type_code, string order_type_name)
	{
		this->id = id;
		this->order_type_code = order_type_code;
		this->order_type_name = order_type_name;
	}
};


class OrderTypeNameDO {
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// ������������
	CC_SYNTHESIZE(string, order_type_name, OrderTypeName);
public:
	OrderTypeNameDO() :id(""), order_type_name("") {}
	OrderTypeNameDO(string id, string order_type_name)
	{
		this->id = id;
		this->order_type_name = order_type_name;
	}
};

typedef std::shared_ptr<OrderTypeDO> PtrOrderTypeDO;
typedef std::shared_ptr<OrderTypeNameDO> PtrOrderTypeNameDO;

#endif //!_ORDERTYPE_DO_H