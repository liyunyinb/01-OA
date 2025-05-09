#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_DTO_
#define _DAO_CHU_KONG_CHU_WEI_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �մ�λ�������ݶ���
 */
class DaoChuKongChuWeiDTO : public oatpp::DTO
{
	DTO_INIT(DaoChuKongChuWeiDTO, DTO);
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
	//�����ͻ�
	API_DTO_FIELD_DEFAULT(String, suo_shu_ke_hu, ZH_WORDS_GETTER("store.field.suo_shu_ke_hu"));
	//������
	API_DTO_FIELD_DEFAULT(String, zui_da_ti_ji, ZH_WORDS_GETTER("store.field.zui_da_ti_ji"));
	//�ϼܴ���
	API_DTO_FIELD_DEFAULT(String, shang_jia_ci_xu, ZH_WORDS_GETTER("store.field.shang_jia_ci_xu"));
	//��
	API_DTO_FIELD_DEFAULT(String, chang, ZH_WORDS_GETTER("store.field.chang"));
	//��
	API_DTO_FIELD_DEFAULT(String, kuan, ZH_WORDS_GETTER("store.field.kuan"));
	//��
	API_DTO_FIELD_DEFAULT(String, gao, ZH_WORDS_GETTER("store.field.gao"));
	//�������
	API_DTO_FIELD_DEFAULT(String, zui_da_tuo_pan, ZH_WORDS_GETTER("store.field.zui_da_tuo_pan"));
	//ͣ��
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("store.field.ting_yong"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, ku_wei_lei_xing, ZH_WORDS_GETTER("store.field.ku_wei_lei_xing"));
};

class DaoChuKongChuWeiPageDTO : public PageDTO<DaoChuKongChuWeiDTO::Wrapper>
{
	DTO_INIT(DaoChuKongChuWeiPageDTO, PageDTO<DaoChuKongChuWeiDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DAO_CHU_KONG_CHU_WEI_DTO_
