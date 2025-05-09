#pragma once
/*
 @Author: nanbowan
*/
#include "../DoInclude.h"

/**
 * �����������ݿ�ʵ����
 */
class OrderTypesDO
{
	// Ψһid
	CC_SYNTHESIZE(string, id, Id);
	// �������ʹ���
	CC_SYNTHESIZE(string, order_type_code, Code);
	// ������������
	CC_SYNTHESIZE(string, order_type_name, Name);

public:
	OrderTypesDO() {
		id = "0";
		order_type_code = "";
		order_type_name = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<OrderTypesDO> PtrOrderTypesDO;


