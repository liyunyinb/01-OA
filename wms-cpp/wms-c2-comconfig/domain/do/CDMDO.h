#pragma
#ifndef CDMDO
#define CDMDO
#include"DoInclude.h"

class CdmDO
{
	CC_SYNTHESIZE(string, id, Id);//����
	CC_SYNTHESIZE(string, name, CDMName); // ��ҵ����
public:
	CdmDO() {
		id = "";
		name = "";
	}
};
#endif 