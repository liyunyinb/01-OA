#pragma once
#ifndef _INVENTORYLIST_DTO_
#define _INVENTORYLIST_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class InventoryBaseDTO : public oatpp::DTO
{
	DTO_INIT(InventoryBaseDTO, DTO);
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

class InventoryAddDTO : public InventoryBaseDTO
{
	DTO_INIT(InventoryAddDTO, InventoryBaseDTO);
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

/**
 * �̵�����ϸ�����б�
 */
class InventoryDtailDTO : public InventoryAddDTO
{
	DTO_INIT(InventoryDtailDTO, InventoryAddDTO);
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

/**
 * �̵����б��ҳ����
 */
class InventorylistDto : public PageDTO<InventoryBaseDTO::Wrapper>
{
	DTO_INIT(InventorylistDto, PageDTO<InventoryBaseDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_