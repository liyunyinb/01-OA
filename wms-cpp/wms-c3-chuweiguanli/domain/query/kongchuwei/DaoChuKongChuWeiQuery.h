#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_QUERY_
#define _DAO_CHU_KONG_CHU_WEI_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ���ݲ�ѯ����
 */
class DaoChuKongChuWeiQuery : public PageQuery
{
	DTO_INIT(DaoChuKongChuWeiQuery, PageQuery);
	// �ֿ�
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("store.field.bin_store");
	}

	//��λ����
	API_DTO_FIELD_DEFAULT(String, ku_wei_shu_xing, ZH_WORDS_GETTER("store.field.ku_wei_shu_xing"));
	//��Ʒ����
	API_DTO_FIELD_DEFAULT(String, CHP_SHU_XING, ZH_WORDS_GETTER("store.field.CHP_SHU_XING"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("store.field.ku_wei_bian_ma"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DAO_CHU_KONG_CHU_WEI_QUERY_