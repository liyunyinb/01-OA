#pragma once

#ifndef _XIANGXIXINXICHAXUNQUERY_
#define _XIANGXIXINXICHAXUNQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ϸ��Ϣ��ѯ����-------��������ò���
 */
//class xaingxixinxichaxun : public PageQuery
//{
//	DTO_INIT(xaingxixinxichaxun,PageQuery);
//	// �ֿ�
//	DTO_FIELD(String, cangku);
//	DTO_FIELD_INFO(cangku) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.cangku");
//	}
//
//	// ��λ����
//	DTO_FIELD(String, bianma);
//	DTO_FIELD_INFO(bianma) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.bianma");
//	}
//	
//	// ��λ����
//	DTO_FIELD(String, tiaoma);
//	DTO_FIELD_INFO(tiaoma) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiaoma");
//	}
//
//
//	// ��λ����
//	DTO_FIELD(String, leixing);
//	DTO_FIELD_INFO(leixing) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.leixing");
//	}
//
//	// ��λ����
//	DTO_FIELD(String, shuxing);
//	DTO_FIELD_INFO(shuxing) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shuxing");
//	}
//
//	//��Ʒ����
//	DTO_FIELD(String, chanpinshuxing);
//	DTO_FIELD_INFO(chanpinshuxing) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chanpinshuxing");
//	}
//
//	// �ϼܴ���
//	DTO_FIELD(String, shangjiacixu);
//	DTO_FIELD_INFO(shangjiacixu) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shangjiacixu");
//	}
//
//	// ȡ������
//	DTO_FIELD(String, quhuocixu);
//	DTO_FIELD_INFO(quhuocixu) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.quhuocixu");
//	}
//
//};


//���ݱ�Ψһid
class xiangxixinxiQUERY :public oatpp::DTO
{
	DTO_INIT(xiangxixinxiQUERY, DTO);
	// �ֿ�
	DTO_FIELD(String, weiyiid);
	DTO_FIELD_INFO(weiyiid) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.bs.id");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !__XIANGXIXINXICHAXUNQUERY_