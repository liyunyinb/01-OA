#pragma once
#ifndef _TIN_TRANSFER_QUERY_
#define _TIN_TRANSFER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������ת�Ʒ�ҳ��ѯ����
 */
class TinTransferQuery : public PageQuery
{
	DTO_INIT(TinTransferQuery, PageQuery);

	//Ψһ��ʶ
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("assignment.field.id");
	}

	// �ƶ�����
	DTO_FIELD(String, moveDate);
	DTO_FIELD_INFO(moveDate) {
		info->description = ZH_WORDS_GETTER("assignment.field.move-date");
	}
	// ������ʱ��
	DTO_FIELD(String, toMoveDate);
	DTO_FIELD_INFO(toMoveDate) {
		info->description = ZH_WORDS_GETTER("assignment.field.to-move-date");
	}
	// �������
	DTO_FIELD(String, inventoryType);
	DTO_FIELD_INFO(inventoryType) {
		info->description = ZH_WORDS_GETTER("assignment.field.inventory-type");
	}
	// ��λ
	DTO_FIELD(String, bin);
	DTO_FIELD_INFO(bin) {
		info->description = ZH_WORDS_GETTER("assignment.field.bin");
	}
	// ����
	DTO_FIELD(String, tin);
	DTO_FIELD_INFO(tin) {
		info->description = ZH_WORDS_GETTER("assignment.field.tin");
	}
	// ����
	DTO_FIELD(String, cusCode);
	DTO_FIELD_INFO(cusCode) {
		info->description = ZH_WORDS_GETTER("assignment.field.cus-code");
	}
	// ��������
	DTO_FIELD(String, cusName);
	DTO_FIELD_INFO(cusName) {
		info->description = ZH_WORDS_GETTER("assignment.field.cus-name");
	}
	// ��Ʒ����
	DTO_FIELD(String, goodsID);
	DTO_FIELD_INFO(goodsID) {
		info->description = ZH_WORDS_GETTER("assignment.field.goods-id");
	}
	// ��Ʒ����
	DTO_FIELD(String, goodsName);
	DTO_FIELD_INFO(goodsName) {
		info->description = ZH_WORDS_GETTER("assignment.field.goods-name");
	}
	// ��������
	DTO_FIELD(String, produceDate);
	DTO_FIELD_INFO(produceDate) {
		info->description = ZH_WORDS_GETTER("assignment.field.produce-date");
	}
	// ����������
	DTO_FIELD(String, toProduceDate);
	DTO_FIELD_INFO(toProduceDate) {
		info->description = ZH_WORDS_GETTER("assignment.field.to-produce-date");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TIN_TRANSFER_QUERY_