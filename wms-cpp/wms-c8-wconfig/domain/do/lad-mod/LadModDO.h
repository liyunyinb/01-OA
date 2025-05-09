#pragma once

#ifndef _LADMOD_DO_
#define _LADMOD_DO_
#include "../DoInclude.h"

/**
 * �����ʽ-���ݿ�ʵ����
 */
class LadModDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �����ʽ����
	CC_SYNTHESIZE(string, code, Code);
	// �����ʽ����
	CC_SYNTHESIZE(string, name, Name);
public:
	LadModDO() {
		id = 0;
		code = "";
		name = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<LadModDO> PtrLadModDO;
#endif // !_LadMod_DO_
