#pragma once
#ifndef _CHECK_DO_
#define _CHECK_DO_
#include "../DoInclude.h"

/**
 * �̵����ݶ���
 */
class CheckDO
{
    // ID
    CC_SYNTHESIZE(string, id, Id);
    // ����������
    CC_SYNTHESIZE(string, create_name, Create_name);
    // �����˵�¼����
    CC_SYNTHESIZE(string, create_by, Create_by);
    // ��������
    CC_SYNTHESIZE(string, create_date, Create_date);
    // ����������
    CC_SYNTHESIZE(string, update_name, Update_name);
    // �����˵�¼����
    CC_SYNTHESIZE(string, update_by, Update_by);
    // ��������
    CC_SYNTHESIZE(string, update_date, Update_date);
    // ��������
    CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
    // ������˾
    CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
    // ��λ
    CC_SYNTHESIZE(string, bin_id, Bin_id);
    // ����
    CC_SYNTHESIZE(string, tin_id, Tin_id);
    // ��Ʒ����
    CC_SYNTHESIZE(string, goods_id, Goods_id);
    // ��Ʒ����
    CC_SYNTHESIZE(string, goods_name, Goods_name);
    // ����
    CC_SYNTHESIZE(string, goods_qua, Goods_qua);
    // ��λ
    CC_SYNTHESIZE(string, goods_unit, Goods_unit);
    // ��������
    CC_SYNTHESIZE(string, goods_pro_data, Goods_pro_data);
    // ����
    CC_SYNTHESIZE(string, goods_batch, Goods_batch);
    // �̵�����
    CC_SYNTHESIZE(string, stt_qua, Stt_qua);
    // �ͻ�����
    CC_SYNTHESIZE(string, cus_name, Cus_name);
    // �ͻ�
    CC_SYNTHESIZE(string, cus_code, Cus_code);
    // �̵�״̬
    CC_SYNTHESIZE(string, stt_sta, Stt_sta);
    // ������λ
    CC_SYNTHESIZE(string, base_unit, Base_unit);
    // ������λ����
    CC_SYNTHESIZE(string, base_goodscount, Base_goodscount);
    //stt_id
    CC_SYNTHESIZE(string, stt_id, Stt_id);
    // ��Ʒͳһ����
    CC_SYNTHESIZE(string, goods_code, Goods_code);
    // �̵�����
    CC_SYNTHESIZE(string, stt_type, Stt_type);
    // ����
    CC_SYNTHESIZE(string, dong_xian, Dong_xian);

public:
    CheckDO() {
        id = "";
        create_name = "";
        create_by = "";
        create_date = "";
        update_name = "";
        update_by = "";
        update_date = "";
        sys_org_code = "";
        sys_company_code = "";
        bin_id = "";
        tin_id = "";
        goods_id = "";
        goods_name = "";
        goods_qua = "";
        goods_unit = "";
        goods_pro_data = "";
        goods_batch = "";
        stt_qua = "";
        cus_name = "";
        cus_code = "";
        stt_sta = "";
        base_unit = "";
        base_goodscount = "";
        stt_id = "";
        dong_xian = "";
        goods_code = "";
        stt_type = "";
    }
};

// ����ָ�����Ͷ���
typedef std::shared_ptr<CheckDO> PtrCheckDO;
#endif // !_CHECK_DO_