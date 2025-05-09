#pragma once
#ifndef _CANGKUDINGYISERVICE_H_
#define _CANGKUDINGYISERVICE_H_

#include<list>
#include "domain/dto/cangkudingyi/deleteCangkuDTO.h"
#include "domain/dto/cangkudingyi/CangkuNameListDTO.h"

class CangKuDingYiService {
public:
	//	��ȡ�ֿ������б�(�޲�)
	oatpp::List<CangkuNameListDTO::Wrapper> getCangkuNameList();
	//	ͨ���ֿ�IDɾ���ֿ�(֧������)
	bool deleteCangkuById_List(oatpp::List<oatpp::String>& id_list);
	//	ͨ���ֿ�ID�б����ֿ���Ϣ, �����ļ�·��
	string getpath_exportCangkuByCodeList(oatpp::List<oatpp::String>& code_list);

};


#endif