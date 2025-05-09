#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/3 20:53

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _DAY_COST_DO_
#define _DAY_COST_DO_
#include "../DoInclude.h"

/**
 * ��Ӧ���ݿ��wm_day_cost��ʵ����
 */
class DayCostDO
{
	// Ψһ���,����
	CC_SYNTHESIZE(string, id, Id);
	// ����������
	CC_SYNTHESIZE(string, create_name, CreateName);
	// �����˵�¼����
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// ��������(��������)
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// ����������
	CC_SYNTHESIZE(string, update_name, UpdateName);
	// �����˵�¼����
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	// ��������(��������)
	CC_SYNTHESIZE(string, update_date, UpdateDate);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// ������˾
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	// �ͻ�����
	CC_SYNTHESIZE(string, cus_code, CusCode);
	// �ͻ�����
	CC_SYNTHESIZE(string, cus_name, CusName);
	// ���ñ���
	CC_SYNTHESIZE(string, cost_code, CostCode);
	// ��������
	CC_SYNTHESIZE(string, cost_name, CostName);
	// ��������(��������)
	CC_SYNTHESIZE(string, cost_date, CostDate);
	// ÿ�շ���(ԭ��)
	CC_SYNTHESIZE(string, day_cost_yj, DayCostYj);
	// ����˰��
	CC_SYNTHESIZE(string, day_cost_bhs, DayCostBhs);
	// ˰��
	CC_SYNTHESIZE(string, day_cost_se, DayCostSe);
	// ��˰��
	CC_SYNTHESIZE(string, day_cost_hsj, DayCostHsj);
	// ������Դ
	CC_SYNTHESIZE(string, cost_ori, CostOri);
	// ��ע
	CC_SYNTHESIZE(string, beizhu, BeiZhu);
	// ״̬
	CC_SYNTHESIZE(string, cost_sta, CostSta);
	// �Ʒ�����
	CC_SYNTHESIZE(string, cost_sl, CostSl);
	// ������λ
	CC_SYNTHESIZE(string, cost_unit, CostUnit);
	// �Ƿ��ѽ���
	CC_SYNTHESIZE(string, cost_js, CostJs);
public:
	DayCostDO() {
		id = "Ψһ���,����";
		create_name = "����������";
		create_by = "�����˵�¼����";
		create_date = "��������(��������)";
		update_name = "����������";
		update_by = "�����˵�¼����";
		update_date = "��������(��������)";
		sys_org_code = "��������";
		sys_company_code = "������˾";
		cus_code = "�ͻ�����";
		cus_name = "�ͻ�����";
		cost_code = "���ñ���";
		cost_name = "��������";
		cost_date = "��������(��������)";
		day_cost_yj = "ÿ�շ���";
		day_cost_bhs = "����˰��";
		day_cost_se = "˰��";
		day_cost_hsj = "��˰��";
		cost_ori = "������Դ";
		beizhu = "��ע";
		cost_sta = "״̬";
		cost_sl = "�Ʒ�����";
		cost_unit = "������λ";
		cost_js = "�Ƿ��ѽ���";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<DayCostDO> PtrDayCostDO;

#endif // !_DAY_COST_DO_
