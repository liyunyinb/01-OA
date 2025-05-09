#pragma once
/*
 @Author: nanbowan
*/
#include "../DoInclude.h"

/**
 * �����������ݿ�ʵ����
 */
class LibraryDO
{
	// Ψһid
	CC_SYNTHESIZE(string, id, Id);
	// ��λ����
	CC_SYNTHESIZE(string, bin_type_code, Code);
	// ��λ����
	CC_SYNTHESIZE(string, bin_type_name, Name);

public:
	LibraryDO() {
		id = "0";
		bin_type_code = "";
		bin_type_name = "";
	}
};

// ��DO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<LibraryDO> PtrLibraryDO;


