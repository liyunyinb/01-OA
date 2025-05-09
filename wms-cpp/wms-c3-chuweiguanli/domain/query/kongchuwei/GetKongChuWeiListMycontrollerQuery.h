#pragma once


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �մ�λ��ҳ��ѯ����
 */
class GetKongChuWeiListMycontrollerQuery : public PageQuery
{

	DTO_INIT(GetKongChuWeiListMycontrollerQuery, PageQuery);

	//Ψһ��ʶ
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.id");
	}

	// �ֿ�
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.bin_store");
	}
	// ��λ����
	DTO_FIELD(String,chuweishuxing);
	DTO_FIELD_INFO(chuweishuxing) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.chuweishuxing");
	}
	// ��Ʒ����
	DTO_FIELD(String, chp_shu_xing);
	DTO_FIELD_INFO(chp_shu_xing) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.chp_shu_xing");
	}
	// ��λ����
	DTO_FIELD(String, chuweibaima);
	DTO_FIELD_INFO(chuweibaima) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.chuweibaima");
	}
	// �����ͻ�
	DTO_FIELD(String, suo_shu_ke_hu);
	DTO_FIELD_INFO(suo_shu_ke_hu) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.suo_shu_ke_hu");
	}
	// ������
	DTO_FIELD(String, zui_da_ti_ji);
	DTO_FIELD_INFO(zui_da_ti_ji) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.zui_da_ti_ji");
	}
	// �ϼܴ���
	DTO_FIELD(String, shang_jia_ci_XU);
	DTO_FIELD_INFO(shang_jia_ci_XU) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.shang_jia_ci_XU");
	}
	// ����
	DTO_FIELD(String, chang);
	DTO_FIELD_INFO(chang) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.chang");
	}

	// ���
	DTO_FIELD(String, kuan);
	DTO_FIELD_INFO(kuan) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.kuan");
	}

	// �߶�
	DTO_FIELD(String, gao);
	DTO_FIELD_INFO(gao) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.gao");
	}
	// �������
	DTO_FIELD(String, zui_da_tuo_pan);
	DTO_FIELD_INFO(zui_da_tuo_pan) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.zui_da_tuo_pan");
	}

	//�Ƿ�ͣ��
	DTO_FIELD(String, zhuang_tai);
	DTO_FIELD_INFO(zhuang_tai) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.zhuang_tai");
	}
	//��λ����
	DTO_FIELD(String, ku_wei_lei_xing);
	DTO_FIELD_INFO(ku_wei_lei_xing) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.ku_wei_lei_xing");
	}

};

#include OATPP_CODEGEN_END(DTO)
