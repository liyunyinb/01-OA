#pragma once

#ifndef _SEX_DO_
#define _SEX_DO_
#include "../DoInclude.h"

/**
 * �Ա���Ϣ���ݿ�ʵ����
 */
class SexDO
{
	//�ֶ�id
	CC_SYNTHESIZE(string, id, Id);
	// �Ա����
	CC_SYNTHESIZE(string, sexcode, SexCode);
	// �Ա�����
	CC_SYNTHESIZE(string, sexname, SexName);
public:
	SexDO() {
		id = "";
		sexcode = "";
		sexname = "";
	}
};

// ��SexDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<SexDO> PtrSexDO;
#endif // !_SEX_DO_