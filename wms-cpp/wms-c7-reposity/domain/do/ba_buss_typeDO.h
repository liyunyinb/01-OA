#pragma once
#include "../arch-demo/domain/do/DoInclude.h"

class ba_buss_typeDO
{
	// ���
	CC_SYNTHESIZE(uint16_t, id, Id);
	// ҵ�����ʹ���
	CC_SYNTHESIZE(string, num, Num);
	// ҵ����������
	CC_SYNTHESIZE(string, name, Name);
	// ҵ�����ͱ�ע
	CC_SYNTHESIZE(string, desc, Desc);
public:
	ba_buss_typeDO() {
		id = 1;
		num = "";
		name = "";
		desc = "";
	}
};