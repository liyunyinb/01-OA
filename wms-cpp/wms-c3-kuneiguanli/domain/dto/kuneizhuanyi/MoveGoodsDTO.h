#pragma once

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ����DTO����������ת������Ĺ����ֶ�
*/
class MoveGoodsBaseDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBaseDTO, DTO);
    // ת������ID
    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("move-goods.field.id");
    }
    // �ƶ�����
    DTO_FIELD(String, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
    }
    // ������
    DTO_FIELD(String, tinId);
    DTO_FIELD_INFO(tinId) {
        info->description = ZH_WORDS_GETTER("move-goods.field.tin-id");
    }
    // ����λ
    DTO_FIELD(String, binTo);
    DTO_FIELD_INFO(binTo) {
        info->description = ZH_WORDS_GETTER("move-goods.field.bin-to");
    }
};

/**
* �޸�ת�������DTO
* ���������޸�ת������������ֶ�
*/
class MoveGoodsModifyDTO : public MoveGoodsBaseDTO {
    DTO_INIT(MoveGoodsModifyDTO, MoveGoodsBaseDTO);
    // ����������
    DTO_FIELD(String, toCustomerName);
    DTO_FIELD_INFO(toCustomerName) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-cus-name");
    }
    // ��������
    DTO_FIELD(String, produceDate);
    DTO_FIELD_INFO(produceDate) {
        info->description = ZH_WORDS_GETTER("move-goods.field.produce-date");
    }
    // ����������
    DTO_FIELD(String, toProduceDate);
    DTO_FIELD_INFO(toProduceDate) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-produce-date");
    }
    // ״̬
    DTO_FIELD(String, moveStatus);
    DTO_FIELD_INFO(moveStatus) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-sta");
    }
};

/**
* ��ȡת��������ϸ��Ϣ��DTO
* �������л�ȡת��������ϸ��Ϣ������ֶ�
*/
class MoveGoodsDetailedDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsDetailedDTO, DTO);
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
    // ��������
    DTO_FIELD(String, nowNum);
    DTO_FIELD_INFO(nowNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.now-num");
    }
    // �ƶ�����
    DTO_FIELD(String, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
    }
    // ��������
    DTO_FIELD(String, produceDate);
    DTO_FIELD_INFO(produceDate) {
        info->description = ZH_WORDS_GETTER("move-goods.field.produce-date");
    }
    // ����������
    DTO_FIELD(String, toProduceDate);
    DTO_FIELD_INFO(toProduceDate) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-produce-date");
    }
    // ��λ
    DTO_FIELD(String, goodsUnit);
    DTO_FIELD_INFO(goodsUnit) {
        info->description = ZH_WORDS_GETTER("move-goods.field.goods-unit");
    }
    // ��������
    DTO_FIELD(String, cusCode);
    DTO_FIELD_INFO(cusCode) {
        info->description = ZH_WORDS_GETTER("move-goods.field.cus-code");
    }
    // ��������
    DTO_FIELD(String, cusName);
    DTO_FIELD_INFO(cusName) {
        info->description = ZH_WORDS_GETTER("move-goods.field.cus-name");
    }
    // ����������
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
    DTO_FIELD(String, moveStatus);
    DTO_FIELD_INFO(moveStatus) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-sta");
    }
};

/**
* ����ת�������DTO
* ��������ת���������ɵ�excel���ĵ�ַ
*/
class MoveGoodsDownLoadDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsDownLoadDTO, oatpp::DTO);
    // ���ص���ת�������ļ���ַ
    DTO_FIELD(String, downLoadMoveGoods);
    DTO_FIELD_INFO(downLoadMoveGoods) {
        info->description = ZH_WORDS_GETTER("move-goods.field.down-load-move-goods");
    }
};


/**
* ����ת�������DTO
*/
class MoveGoodsBatchDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBatchDTO, DTO);
    DTO_FIELD(Vector<Object<MoveGoodsBaseDTO>>, items);
    DTO_FIELD_INFO(items) {
        info->description = ZH_WORDS_GETTER("move-goods.field.items");
    }
};


/**
* �������
* ��������ת���������Ϣ
*/
class MoveGoodsDTO : public MoveGoodsModifyDTO {
    DTO_INIT(MoveGoodsDTO, MoveGoodsModifyDTO);
};

/**
* ��ҳ��ȡת���������
*/
class MoveGoodsPageDTO : public PageDTO<MoveGoodsDTO::Wrapper> {
    DTO_INIT(MoveGoodsPageDTO, PageDTO<MoveGoodsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
