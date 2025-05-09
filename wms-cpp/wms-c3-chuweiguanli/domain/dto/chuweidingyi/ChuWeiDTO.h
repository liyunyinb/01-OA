#pragma once
#ifndef _CHUWEI_DTO_
#define _CHUWEI_DTO_

#include "../../GlobalInclude.h"
#include <oatpp/core/Types.hpp> 

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б��������
 */
class ChuWeiBaseDTO : public oatpp::DTO
{
	DTO_INIT(ChuWeiBaseDTO, DTO);
	// �ֿ�
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("Chuwei.field.store");
	}
	//����ԭ��ʽ�����ú�
	//��λ����
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("Chuwei.field.ku_wei_bian_ma"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, ku_wei_tiao_ma, ZH_WORDS_GETTER("Chuwei.field.ku_wei_tiao_ma"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, ku_wei_lei_xing, ZH_WORDS_GETTER("Chuwei.field.ku_wei_lei_xing"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, ku_wei_shu_xing, ZH_WORDS_GETTER("Chuwei.field.ku_wei_shu_xing"));
	//��Ʒ����
	API_DTO_FIELD_DEFAULT(String, CHP_SHU_XING, ZH_WORDS_GETTER("Chuwei.field.CHP_SHU_XING"));
	//�ϼܴ���
	API_DTO_FIELD_DEFAULT(String, shang_jia_ci_xu, ZH_WORDS_GETTER("Chuwei.field.shang_jia_ci_xu"));
	//ȡ������
	API_DTO_FIELD_DEFAULT(String, qu_huo_ci_xu, ZH_WORDS_GETTER("Chuwei.field.qu_huo_ci_xu"));
	//�����ͻ�
	API_DTO_FIELD_DEFAULT(String, suo_shu_ke_hu, ZH_WORDS_GETTER("Chuwei.field.customer"));
	/*   DO�в���Ҫ�ⲿ������
	//��С����
	API_DTO_FIELD_DEFAULT(String, suo_shu_ke_hu, ZH_WORDS_GETTER("Chuwei.field.customer"));
	//�������
	API_DTO_FIELD_DEFAULT(String, suo_shu_ke_hu, ZH_WORDS_GETTER("Chuwei.field.customer"));
	//��λ���
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("Chuwei.field.state"));
	//�����
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("Chuwei.field.state"));
	*/
	//������
	API_DTO_FIELD_DEFAULT(String, zui_da_ti_ji, ZH_WORDS_GETTER("Chuwei.field.zui_da_ti_ji"));
	//�������
	API_DTO_FIELD_DEFAULT(String, zui_da_zhong_liang, ZH_WORDS_GETTER("Chuwei.field.zui_da_zhong_liang"));
	//�������
	API_DTO_FIELD_DEFAULT(String, zui_da_tuo_pan, ZH_WORDS_GETTER("Chuwei.field.zui_da_tuo_pan"));
	//����
	API_DTO_FIELD_DEFAULT(String, chang, ZH_WORDS_GETTER("Chuwei.field.chang"));
	//���
	API_DTO_FIELD_DEFAULT(String, kuan, ZH_WORDS_GETTER("Chuwei.field.kuan"));
	//�߶�
	API_DTO_FIELD_DEFAULT(String, gao, ZH_WORDS_GETTER("Chuwei.field.gao"));
	//�Ƿ�ͣ��
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("Chuwei.field.ting_yong"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, ming_xi, ZH_WORDS_GETTER("Chuwei.field.ming_xi"));
	//��ע1
	API_DTO_FIELD_DEFAULT(String, ming_xi1, ZH_WORDS_GETTER("Chuwei.field.ming_xi1"));
	//��ע2
	API_DTO_FIELD_DEFAULT(String, ming_xi2, ZH_WORDS_GETTER("Chuwei.field.ming_xi2"));
	//����
	API_DTO_FIELD_DEFAULT(String, ming_xi3, ZH_WORDS_GETTER("Chuwei.field.ming_xi3"));
	//���ӱ�ǩID
	API_DTO_FIELD_DEFAULT(String, LORA_bqid, ZH_WORDS_GETTER("Chuwei.field.LORA_bqid"));
	//x����
	API_DTO_FIELD_DEFAULT(String, xnode, ZH_WORDS_GETTER("Chuwei.field.xnode"));
	//y����
	API_DTO_FIELD_DEFAULT(String, ynode, ZH_WORDS_GETTER("Chuwei.field.ynode"));
	//z����
	API_DTO_FIELD_DEFAULT(String, znode, ZH_WORDS_GETTER("Chuwei.field.znode"));
};

/**
 * ��λ�б�����󣨸���id��
 */
class ChuWeiDTO : public ChuWeiBaseDTO
{
	DTO_INIT(ChuWeiDTO, ChuWeiBaseDTO);
	// ����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("chuwei.id"));
};


/**
 * ��λ�б��ҳ���ݶ���
 */
class ChuWeiPageDTO : public PageDTO<ChuWeiDTO::Wrapper>
{
	DTO_INIT(ChuWeiPageDTO, PageDTO<ChuWeiDTO::Wrapper>);
};

/**
 * ɾ����λ��֧������ɾ��
 */
class BatchDeleteDTO : public oatpp::DTO {
	DTO_INIT(BatchDeleteDTO, DTO);
	// ʹ�� OATPP �б�����
	DTO_FIELD(oatpp::List<oatpp::String>::ObjectWrapper, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("Chuwei.field.ids");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHUWEI_DTO_