#pragma once
/*
 @Author: nanbowan
*/

#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * �¶��������ݿ�ʵ����
 */
class LibraryFileDO
{
	// ��λ����
	CC_SYNTHESIZE(string, bin_type_code, Code);
	// ��λ����
	CC_SYNTHESIZE(string, bin_type_name, Name);

public:
	LibraryFileDO() {
		bin_type_code = "";
		bin_type_name = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<LibraryFileDO> PtrLibraryFileDO;
#endif 

