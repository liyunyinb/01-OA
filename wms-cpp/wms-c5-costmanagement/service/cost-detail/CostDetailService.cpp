/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/4 14:30

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
#include "stdafx.h"
#include "CostDetailService.h"
#include "../../dao/cost-detail/CostDetailDAO.h"
#include "id/UuidFacade.h"

bool CostDetailService::charge(const oatpp::String& id)
{
	//��Ϊ�Ǹ���idֱ���޸����ݵ�����,��ֱ�ӵ���dao���޸ļ���
	CostDetailDAO dao;
	return dao.charge(id) == 1;//1Ϊ��������ֵ
}
bool CostDetailService::discharge(const oatpp::String& id)
{
	//��Ϊ�Ǹ���idֱ���޸����ݵ�����,��ֱ�ӵ���dao���޸ļ���
	CostDetailDAO dao;
	return dao.discharge(id) == 1;//1Ϊ��������ֵ
}
uint64_t CostDetailService::addData(const CostExportDTO* dto)
{
	// ��װDO����
	DayCostDO data;
	//����uuid�㷨����id
	UuidFacade uuid(1);
	string id;
	for (auto ch : uuid.genUuid())
	{
		if (ch != '-')
			id += ch;
	}
	data.setId(id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CreateName,creator, CreateDate,createdate, UpdateName, updater, UpdateDate, updatedate, CusCode,client, CusName,clientname, CostCode,cost);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CusName, costname, CostDate, costdate, DayCostYj, oldprice, DayCostBhs, notax, DayCostSe, tax, DayCostHsj, taxprice, CostOri, source, BeiZhu, remark, CostSta, state, CostJs, status, CostSl, count, CostUnit, unit);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CreateBy, create_by, SysOrgCode, org_code, SysCompanyCode, company_code);//�������������Ϣ
	//�������
	CostDetailDAO dao;
	return dao.insert(data);
}

vector<vector<string>> CostDetailService::exportAll(const oatpp::List<oatpp::String>& ids)
{
	CostDetailDAO dao;
	list<DayCostDO> DOlists;
	if (ids->size() > 0)
	{
		//��ÿ��id��ѯ���ؽ��
		for (auto id = ids->begin(); id != ids->end(); ++id)
		{
			DOlists.push_back(dao.selectById(*id));
		}
	}
	else
	{
		DOlists = dao.exportAll(ids);
	}
	
	//��DO�б������vector<vector<string>>
	vector<vector<string>> ret;
	for (auto line : DOlists)
	{
		vector<string> col;
		col.push_back(line.getCreateName());
		col.push_back(line.getCreateDate());
		col.push_back(line.getUpdateName());
		col.push_back(line.getUpdateDate());
		col.push_back(line.getCusCode());
		col.push_back(line.getCusName());
		col.push_back(line.getCostCode());
		col.push_back(line.getCostName());
		col.push_back(line.getCostDate());
		col.push_back(line.getDayCostYj());
		col.push_back(line.getDayCostBhs());
		col.push_back(line.getDayCostSe());
		col.push_back(line.getDayCostHsj());
		col.push_back(line.getCostOri());
		col.push_back(line.getBeiZhu());
		col.push_back(line.getCostSta());
		col.push_back(line.getCostJs());
		col.push_back(line.getCostSl());
		col.push_back(line.getCostUnit());
		ret.push_back(col);
	}
	return ret;
}