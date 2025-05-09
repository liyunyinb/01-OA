#pragma once

#ifndef _CANGKU_DAO_
#define _CANGKU_DAO_

#include "BaseDAO.h"
#include "../../domain/do/BinDO.h"
#include "../../domain/do/StoreDO.h"

class CangkuDAO : public BaseDAO {
public:
	//	���Ҳֿ������б�
	std::list<StoreDO> getCangkuNameList();
	//	ͨ���ֿ����ɾ��ָ���ֿ�
	bool deleteCangkuById(string id);
	//	���ݲֿ�����ȡ��������Ĳֿⱨ������
	std::vector<string> getExcelData(string store_code);
	//	��ȡ��������вֿⱨ������
	std::vector<std::vector<std::string>> getAllExcelData();
};

#endif // !_CANGKU_DAO_
