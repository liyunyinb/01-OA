#pragma once
#ifndef _INVENTORYLIST_QUERY_
#define _INVENTORYLIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class InventorylistQuery : public PageQuery
{
	DTO_INIT(InventorylistQuery, PageQuery);
	// �ƶ�����
	API_DTO_FIELD_DEFAULT(String, yidongriqi, ZH_WORDS_GETTER("overall.inventorylist.yidongriqi"));
	// �������
	API_DTO_FIELD_DEFAULT(String, cktype, ZH_WORDS_GETTER("overall.inventorylist.cktype"));
	// ��λ
	API_DTO_FIELD_DEFAULT(String, chuwei, ZH_WORDS_GETTER("overall.inventorylist.chuwei"));
	// ����
	API_DTO_FIELD_DEFAULT(String, tuopan, ZH_WORDS_GETTER("overall.inventorylist.tuopan"));
	// ����
	API_DTO_FIELD_DEFAULT(String, huozhu, ZH_WORDS_GETTER("overall.inventorylist.huozhu"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, huozhumingcheng, ZH_WORDS_GETTER("overall.inventorylist.huozhumingcheng"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, shangpinbianma, ZH_WORDS_GETTER("overall.inventorylist.shangpinbianma"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, shangpinshuliang, ZH_WORDS_GETTER("overall.inventorylist.shangpinshuliang"));
	// ��Ʒ����
	API_DTO_FIELD_DEFAULT(String, shangpinmincheng, ZH_WORDS_GETTER("overall.inventorylist.shangpinmincheng"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, shengchanriqi, ZH_WORDS_GETTER("overall.inventorylist.shengchanriqi"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INVENTORYLIST_QUERY_