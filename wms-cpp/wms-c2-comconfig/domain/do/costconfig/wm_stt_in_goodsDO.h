#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/2/22 14:33

*/
#ifndef _WM_STT_IN_GOODS_DO_
#define _WM_STT_IN_GOODS_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class Wm_Stt_In_GoodsDO
{
	// ���  
	CC_SYNTHESIZE(string, id, Id);
	// ����������  
	CC_SYNTHESIZE(string, create_name, CreateName);
	// �����˵�¼����  
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// ��������  
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// ����������  
	CC_SYNTHESIZE(string, update_name, UpdateName);
	// �����˵�¼����  
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	// ��������  
	CC_SYNTHESIZE(string, update_date, UpdateDate);
	// ��������  
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// ������˾  
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	// ��λ����  
	CC_SYNTHESIZE(string, bin_id, BinId);
	// ���̱���  
	CC_SYNTHESIZE(string, tin_id, TinId);
	// ��Ʒ����  
	CC_SYNTHESIZE(string, goods_id, GoodsId);
	// ��Ʒ����  
	CC_SYNTHESIZE(string, goods_name, GoodsName);
	// ����  
	CC_SYNTHESIZE(string, goods_qua, GoodsQua);
	// ��λ  
	CC_SYNTHESIZE(string, goods_unit, GoodsUnit);
	// ��������  
	CC_SYNTHESIZE(string, goods_pro_date, GoodsProDate);
	// ����  
	CC_SYNTHESIZE(string, goods_batch, GoodsBatch);
	// �̵�����  
	CC_SYNTHESIZE(string, stt_qua, SttQua);
	// �ͻ�����  
	CC_SYNTHESIZE(string, cus_name, CusName);
	// �ͻ�  
	CC_SYNTHESIZE(string, cus_code, CusCode);
	// �̵�״̬  
	CC_SYNTHESIZE(string, stt_sta, SttSta);
	// ������λ  
	CC_SYNTHESIZE(string, base_unit, BaseUnit);
	// ������λ����  
	CC_SYNTHESIZE(string, base_goodscount, BaseGoodscount);
	// stt_id  
	CC_SYNTHESIZE(string, stt_id, SttId);
	// ��Ʒͳһ����  
	CC_SYNTHESIZE(string, goods_code, GoodsCode);
	// �̵�����  
	CC_SYNTHESIZE(string, stt_type, SttType);
	// ����  
	CC_SYNTHESIZE(string, dong_xian, DongXian);
	
	
public:
	Wm_Stt_In_GoodsDO()
		: id("")
		, create_name("")
		, create_by("")
		, create_date("")
		, update_name("")
		, update_by("")
		, update_date("")
		, sys_org_code("")
		, sys_company_code("")
		, bin_id("")
		, tin_id("")
		, goods_id("")
		, goods_name("")
		, goods_qua("")
		, goods_unit("")
		, goods_pro_date("")
		, goods_batch("")
		, stt_qua("")
		, cus_name("")
		, cus_code("")
		, stt_sta("")
		, base_unit("")
		, base_goodscount("")
		, stt_id("")
		, goods_code("")
		, stt_type("")
		, dong_xian("")
	{
	}
};

// ��Wm_Stt_In_GoodsDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<Wm_Stt_In_GoodsDO> PtrWm_Stt_In_GoodsDO;
#endif // _WM_STT_IN_GOODS_DO_
