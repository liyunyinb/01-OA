#pragma once
#ifndef CDMDAO
#define CDMDAO
#include "domain/do/comdegdm/CdmDO.h"
#include "BaseDAO.h"

class CdmDAO : public BaseDAO
{
public:
	// �޸�����
   int  update(const CdmDO& uObj);
   //ͨ��id����ɾ������
   int deleteById(vector<string>& ids);
   // ��ѯ���е�com_type_code �� com_type_name���ݣ���ҵ����
   std::list<CdmDO> getAllattri();
};
#endif 