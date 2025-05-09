/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "PlcService.h"
#include "../../dao/plc-file/PlcDAO.h"

bool PlcService::saveData(const PlcAddDTO::Wrapper& dto, string name, string realname, string orgcode, string companycode)
{
	// ��װDO����
	PlcDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, plc_ip, plc_ip, plc_port, plc_port, plc_type, plc_type, com_remark, com_remark, com_time, com_time, com_seq, com_seq, com_cons, com_cons, remark1, remark1, com_no, com_no, query01, query01, query02, query02, setp_time, setp_time, setp_num, setp_num);
	// ִ���������
	PlcDAO dao;
	return dao.insert(data, name, realname, orgcode, companycode);
}
PlcListPageDTO::Wrapper PlcService::listAll(const PlcFileQuery::Wrapper& query)
{
	auto pages = PlcListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	//��ѯ������
	PlcDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PlcBaseDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PlcBaseDO sub : result)
	{
		auto dto = PlcListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id , id, plc_ip, plc_ip, plc_port, plc_port, plc_type, plc_type, com_remark, remark1, com_no, com_no);
		pages->addData(dto);
	}
	return pages;
}
PlcdetailDTO::Wrapper PlcService::getById(string id)
{
	// ��ѯ����
	PlcDAO dao;
	auto res = dao.selectById(id);
	// û�в�ѯ������     
	if (!res)
		return nullptr;
	// ��ѯ������ת����DTO
	auto dto = PlcdetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, id, plc_ip, plc_ip, plc_port, plc_port, plc_type, plc_type, com_remark, com_remark, com_time, com_time, com_seq, com_seq, com_cons, com_cons, remark1, remark1, com_no, com_no, query01, query01, query02, query02, setp_time, setp_time, setp_num, setp_num);
	return dto;
}
bool PlcService::updateData(const PlcdetailDTO::Wrapper& dto)
{
	PlcDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, id ,id, plc_ip, plc_ip, plc_port, plc_port, plc_type, plc_type, com_remark, com_remark, com_time, com_time, com_seq, com_seq, com_cons, com_cons, remark1, remark1, com_no, com_no, query01, query01, query02, query02, setp_time, setp_time, setp_num, setp_num);
	// ִ�������޸�
	PlcDAO dao;
	return dao.update(data);
}
bool PlcService::removeData(string id)
{
	PlcDAO dao;
	return dao.deleteById(id);
}