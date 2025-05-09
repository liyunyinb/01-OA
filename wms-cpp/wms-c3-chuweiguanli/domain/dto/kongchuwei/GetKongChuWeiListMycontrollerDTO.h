#pragma once
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * "�մ�λ" - �մ�λ�б�
 */

class GetKongChuWeiListMycontrollerlistDTO : public oatpp::DTO
{
	DTO_INIT(GetKongChuWeiListMycontrollerlistDTO, DTO);

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
	DTO_FIELD(String, chuweishuxing);
	DTO_FIELD_INFO(chuweishuxing) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.chuweishuxing");
	}
	// ��Ʒ����
	DTO_FIELD(String, chp_shu_xing);
	DTO_FIELD_INFO(chp_shu_xing) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.chp_shu_xing");
	}
	// ��λ����
	DTO_FIELD(String, chuweibianma);
	DTO_FIELD_INFO(chuweibianma) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.chuweibianma");
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


/**
 * "�մ�λ" - ��ȡ�����б�
 */

class GetKongChuWeiListMycontrollerBatchDTO : public oatpp::DTO {
	DTO_INIT(GetKongChuWeiListMycontrollerBatchDTO, DTO);
	DTO_FIELD(Vector<Object<GetKongChuWeiListMycontrollerlistDTO>>, items);
	DTO_FIELD_INFO(items) {
		info->description = ZH_WORDS_GETTER("kongchuwei.quary.item");
	}
};

class GetKongChuWeiListMycontrollerDTO : public GetKongChuWeiListMycontrollerlistDTO {
	DTO_INIT(GetKongChuWeiListMycontrollerDTO, GetKongChuWeiListMycontrollerlistDTO);
};

/**
 * "�մ�λ" - ��ҳ���ݶ���
 */
class GetKongChuWeiListMycontrollerPageDTO : public PageDTO<GetKongChuWeiListMycontrollerDTO::Wrapper>
{
	DTO_INIT(GetKongChuWeiListMycontrollerPageDTO, PageDTO<GetKongChuWeiListMycontrollerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO) // !_BIN_TRANSFER_DTO_
