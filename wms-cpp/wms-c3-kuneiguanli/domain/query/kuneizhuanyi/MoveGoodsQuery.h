#pragma once

#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ��ҳ��ѯת�������б�
*/
class MoveGoodsQuery : public PageQuery {
	DTO_INIT(MoveGoodsQuery, PageQuery);
	// ת������ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("move-goods.field.id");
	}
	// ��Ʒ����
	DTO_FIELD(String, goodsID);
	DTO_FIELD_INFO(goodsID) {
		info->description = ZH_WORDS_GETTER("move-goods.field.goods-id");
	}
	// ��Ʒ����
	DTO_FIELD(String, goodsName);
	DTO_FIELD_INFO(goodsName) {
		info->description = ZH_WORDS_GETTER("move-goods.field.goods-name");
	}
	// ����
	DTO_FIELD(String, cusCode);
	DTO_FIELD_INFO(cusCode) {
		info->description = ZH_WORDS_GETTER("move-goods.field.cus-code");
	}
	// ��������
	DTO_FIELD(String, cusName);
	DTO_FIELD_INFO(cusName) {
		info->description = ZH_WORDS_GETTER("move-goods.field.cus-name");
	}
	// ������
	DTO_FIELD(String, toCusCode);
	DTO_FIELD_INFO(toCusCode) {
		info->description = ZH_WORDS_GETTER("move-goods.field.to-cus-code");
	}
	// ����������
	DTO_FIELD(String, toCusName);
	DTO_FIELD_INFO(toCusName) {
		info->description = ZH_WORDS_GETTER("move-goods.field.to-cus-name");
	}
	// Դ����
	DTO_FIELD(String, tinFrom);
	DTO_FIELD_INFO(tinFrom) {
		info->description = ZH_WORDS_GETTER("move-goods.field.tin-from");
	}
	// ������
	DTO_FIELD(String, tinTo);
	DTO_FIELD_INFO(tinTo) {
		info->description = ZH_WORDS_GETTER("move-goods.field.tin-to");
	}
	// Դ��λ
	DTO_FIELD(String, binFrom);
	DTO_FIELD_INFO(binFrom) {
		info->description = ZH_WORDS_GETTER("move-goods.field.bin-from");
	}
	// ����λ
	DTO_FIELD(String, binTo);
	DTO_FIELD_INFO(binTo) {
		info->description = ZH_WORDS_GETTER("move-goods.field.bin-to");
	}
	// ״̬
	DTO_FIELD(String, moveSta);
	DTO_FIELD_INFO(moveSta) {
		info->description = ZH_WORDS_GETTER("move-goods.field.move-sta");
	}
	// ִ��״̬
	DTO_FIELD(String, runSta);
	DTO_FIELD_INFO(runSta) {
		info->description = ZH_WORDS_GETTER("move-goods.field.run-sta");
	}
};

/**
* ��ѯת�����������Ϣ
*/
class MoveGoodsBaseQuery : public PageQuery {
	DTO_INIT(MoveGoodsBaseQuery, PageQuery);
	// ת������ID
	DTO_FIELD(oatpp::List<oatpp::String>, items);
	DTO_FIELD_INFO(items) {
		info->description = ZH_WORDS_GETTER("move-goods.field.items");
	}
};

// ��ѯ����ת������
class MoveGoodsExcelQuery : public oatpp::DTO
{
	DTO_INIT(MoveGoodsExcelQuery, DTO);

	DTO_FIELD(String, file_path);
	DTO_FIELD_INFO(file_path) {
		info->description = ZH_WORDS_GETTER("move-goods.field.file_path");
	}

	DTO_FIELD(String, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("move-goods.field.id");
	}
};

#include OATPP_CODEGEN_END(DTO)
