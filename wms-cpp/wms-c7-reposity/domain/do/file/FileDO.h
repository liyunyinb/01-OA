#pragma once
/*
 @Author: nanbowan
*/

#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * �����������ݿ�ʵ����
 */
class FileDO
{
	// �������ʹ���
	CC_SYNTHESIZE(string, order_type_code, Code);
	// ������������
	CC_SYNTHESIZE(string, order_type_name, Name);

public:
	FileDO() {
		order_type_code = "";
		order_type_name = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<FileDO> PtrFileDO;
#endif // !_SAMPLE_DO_

