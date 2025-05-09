#pragma once
#ifndef _CDMService_
#define _CDMService_
#include<list>
#include "domain/vo/CDMattr/CDMinfoVO.h"
#include "domain/dto/CDMattr/CDMDTO.h"
#include "domain/do/comdegdm/CdmDO.h"
#include "dao/comdegdm/CdmDAO.h"
class CdmService {
public:

	bool updateData(const CdmDTO::Wrapper& dto);
	bool removeData(vector<string>& id);
	// ����com_type_code com_type_name �Ĳ�ѯ���
	vector<std::vector<std::string>> getdata();
};
#endif 