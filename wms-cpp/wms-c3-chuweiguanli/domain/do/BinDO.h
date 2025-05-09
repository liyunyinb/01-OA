#pragma once
#ifndef _BINDO_
#define _BINDO_
#include "domain/GlobalInclude.h"

class BinDO {
    CC_SYNTHESIZE(string, id, Id); // Ψһ��ʶ ����
    CC_SYNTHESIZE(string, create_name, CreateName); // ����������
    CC_SYNTHESIZE(string, create_by, CreateBy); // �����˵�¼����
    CC_SYNTHESIZE(string, create_date, CreateDate); // ��������
    CC_SYNTHESIZE(string, update_name, UpdateName); // ����������
    CC_SYNTHESIZE(string, update_by, UpdateBy); // �����˵�¼����
    CC_SYNTHESIZE(string, update_date, UpdateDate); // ��������
    CC_SYNTHESIZE(string, sys_org_code, SysOrgCode); // ��������
    CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode); // ������˾
    CC_SYNTHESIZE(string, ku_wei_ming_cheng, KuWeiMingCheng); // ��λ����
    CC_SYNTHESIZE(string, ku_wei_bian_ma, KuWeiBianMa); // ��λ����
    CC_SYNTHESIZE(string, ku_wei_tiao_ma, KuWeiTiaoMa); // ��λ����
    CC_SYNTHESIZE(string, ku_wei_lei_xing, KuWeiLeiXing); // ��λ����
    CC_SYNTHESIZE(string, ku_wei_shu_xing, KuWeiShuXing); // ��λ����
    CC_SYNTHESIZE(string, shang_jia_ci_xu, ShangJiaCiXu); // �ϼܴ���
    CC_SYNTHESIZE(string, qu_huo_ci_xu, QuHuoCiXu); // ȡ������
    CC_SYNTHESIZE(string, suo_shu_ke_hu, SuoShuKeHu); // �����ͻ�
    CC_SYNTHESIZE(string, ti_ji_dan_wei, TiJiDanWei); // �����λ
    CC_SYNTHESIZE(string, zhong_liang_dan_wei, ZhongLiangDanWei); // ������λ
    CC_SYNTHESIZE(string, mian_ji_dan_wei, MianJiDanWei); // �����λ
    CC_SYNTHESIZE(string, zui_da_ti_ji, ZuiDaTiJi); // ������
    CC_SYNTHESIZE(string, zui_da_zhong_liang, ZuiDaZhongLiang); // �������
    CC_SYNTHESIZE(string, zui_da_mian_ji, ZuiDaMianJi); // ������
    CC_SYNTHESIZE(string, zui_da_tuo_pan, ZuiDaTuoPan); // �������
    CC_SYNTHESIZE(string, chang, Chang); // ����
    CC_SYNTHESIZE(string, kuan, Kuan); // ���
    CC_SYNTHESIZE(string, gao, Gao); // �߶�
    CC_SYNTHESIZE(string, ting_yong, TingYong); // ͣ��
    CC_SYNTHESIZE(string, ming_xi, MingXi); // ��ϸ
    CC_SYNTHESIZE(string, bin_store, BinStore); // �ֿ�
    CC_SYNTHESIZE(string, CHP_SHU_XING, CHPShuXing); // ��Ʒ����
    CC_SYNTHESIZE(string, ming_xi1, MingXi1); // ��ע1
    CC_SYNTHESIZE(string, ming_xi2, MingXi2); // ��ע2
    CC_SYNTHESIZE(string, ming_xi3, MingXi3); // ����
    CC_SYNTHESIZE(string, LORA_bqid, LORABqid); // LORA��ǩID
    CC_SYNTHESIZE(string, xnode, XNode); // X����
    CC_SYNTHESIZE(string, ynode, YNode); // Y����
    CC_SYNTHESIZE(string, znode, ZNode); // Z����


public:

    BinDO() :
        id(""), create_name(""), create_by(""), create_date(""), update_name(""), update_by(""), update_date(""),
        sys_org_code(""), sys_company_code(""), ku_wei_ming_cheng(""), ku_wei_bian_ma(""), ku_wei_tiao_ma(""),
        ku_wei_lei_xing(""), ku_wei_shu_xing(""), shang_jia_ci_xu(""), qu_huo_ci_xu(""), suo_shu_ke_hu(""),
        ti_ji_dan_wei(""), zhong_liang_dan_wei(""), mian_ji_dan_wei(""), zui_da_ti_ji(""), zui_da_zhong_liang(""),
        zui_da_mian_ji(""), zui_da_tuo_pan(""), chang(""), kuan(""), gao(""), ting_yong(""), ming_xi(""),
        bin_store(""), CHP_SHU_XING(""), ming_xi1(""), ming_xi2(""), ming_xi3(""), LORA_bqid(""), xnode(""), ynode(""), znode("") {
    }
};



#endif // !_BINDO_