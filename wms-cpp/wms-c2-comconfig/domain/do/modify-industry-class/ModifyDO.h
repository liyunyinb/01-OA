#pragma once
#ifndef _MODIFY_DO_
#define _MODIFY_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ModifyDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ��ҵ�������
	CC_SYNTHESIZE(string, classfl_code, Classfl_code);
	// ��ҵ��������
	CC_SYNTHESIZE(string, classfl_name, Classfl_name);
	// ͣ��
	CC_SYNTHESIZE(string, classfl_del, Classfl_del);
public:
	ModifyDO() {
		id = "";
		classfl_code = "";
		classfl_name = "";
		classfl_del = "";
	}
};

// ��ModifyDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ModifyDO> PtrModifyDO;
#endif // !_MODIFY_DO_
