#pragma once

#ifndef _BIN_TRANSFER_DTO_
#define _BIN_TRANSFER_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * "���ɴ�λת��" - �б����ݶ���
 */

class BinTransferListDTO : public oatpp::DTO
{
	DTO_INIT(BinTransferListDTO, DTO);

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

	//��Ʒ����
	DTO_FIELD(Int64, goodsNum);
	DTO_FIELD_INFO(goodsNum) {
		info->description = ZH_WORDS_GETTER("assignment.field.goods-num");
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

	//������
	DTO_FIELD(String, produceShelfLife);
	DTO_FIELD_INFO(produceShelfLife) {
		info->description = ZH_WORDS_GETTER("assignment.field.produce-shelf-life");
	}
	//��λ
	DTO_FIELD(String, produceUnit);
	DTO_FIELD_INFO(produceUnit) {
		info->description = ZH_WORDS_GETTER("assignment.field.produce-unit");
	}
	//״̬
	DTO_FIELD(String, moveSta);
	DTO_FIELD_INFO(moveSta) {
		info->description = ZH_WORDS_GETTER("assignment.field.move-sta");
	}
};


/**
 * "���ɴ�λת��" - �������ɴ�λת������
 */

class BinTransferBatchDTO : public oatpp::DTO {
	DTO_INIT(BinTransferBatchDTO, DTO);
	DTO_FIELD(Vector<Object<BinTransferListDTO>>, items);
	DTO_FIELD_INFO(items) {
		info->description = ZH_WORDS_GETTER("assignment.fileld.items");
	}
};

/**
 * "���ɴ�λת��" - �������
 */
class BinTransferDTO : public BinTransferListDTO {
	DTO_INIT(BinTransferDTO, BinTransferListDTO);
};

/**
 * "��������ת��" - ��ҳ���ݶ���
 */
class BinTransferPageDTO : public PageDTO<BinTransferDTO::Wrapper>
{
	DTO_INIT(BinTransferPageDTO, PageDTO<BinTransferDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BIN_TRANSFER_DTO_