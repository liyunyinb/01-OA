/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/26 11:34:24

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
#include "CostAttributeService.h"
#include "../../domain/do/cost-attribute/CostAttributeDO.h"
#include "../../dao/cost-attribute/CostAttributeDAO.h"
#include "SimpleDateTimeFormat.h"
#include "../../dao/cost-attribute/CostAttributeDAO.h"
#include "FastDfsClient.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

// ¼���û�����
string CostAttributeService::insert(const CostSxAddDTO::Wrapper& dto)
{
	// ��װDO����
    CostSxDO data;
    // ����ʱ��
    string now = SimpleDateTimeFormat::format();
    dto->update_date = now;
    dto->create_date = now;

	ZO_STAR_DOMAIN_DTO_TO_DO(
        data, dto,
        Code, code,
        Name, name,
        CreateName, create_name,
        CreateBy, create_by,
        CreateDate, create_date,
        UpdateName, update_name,
        UpdateBy, update_by,
        UpdateDate, update_date,
        SysOrgCode, sys_org_code,
        SysCompanyCode, sys_company_code);
	// ִ�����ݲ���
	CostAttributeDao dao;
	return dao.insert(data);
}

// �����û��������
bool CostAttributeService::update(const CostSxModifyDTO::Wrapper& dto)
{
    // ��װDO����
    CostSxDO data;
    // ����ʱ��
    string now = SimpleDateTimeFormat::format();
    dto->update_date = now;
    ZO_STAR_DOMAIN_DTO_TO_DO(
        data, dto,
        Id,id,
        Code, code,
        Name, name,
        UpdateName, update_name,
        UpdateBy, update_by,
        UpdateDate, update_date,
        SysOrgCode, sys_org_code,
        SysCompanyCode, sys_company_code);
    // ִ�����ݸ���
    CostAttributeDao dao;
    return dao.update(data);
}

// ��ѯ�ͻ���������
CostSxNameListPageDTO::Wrapper CostAttributeService::listName(const CostSxQuery::Wrapper& query) {
    // �������ض���
    auto pages = CostSxNameListPageDTO::createShared();

    // ��ѯ����������
    CostAttributeDao dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    list<CostSxDO> result = dao.selectNameWithPage(query);
    // ��DOת����DTO
    for (CostSxDO sub : result)
    {
        auto dto = CostSxNameListDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name);
        pages->addData(dto);
    }
    return pages;

}

// ��ѯ�ͻ�����
CostSxPageDTO::Wrapper CostAttributeService::listAll(const CostSxQuery::Wrapper& query) {
    // �������ض���
    auto pages = CostSxPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    CostAttributeDao dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // ��ҳ��ѯ����
    pages->total = count;
    pages->calcPages();
    list<CostSxDO> result = dao.selectAllWithPage(query);
    // ��DOת����DTO
    for (CostSxDO sub : result)
    {
        auto dto = CostSxDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
            id, Id,                   // ���
            name, Name,               // �ͻ���������
            code, Code,               // �ͻ����Ա���
            create_name, CreateName,  // ����������
            create_by, CreateBy,      // �����˵�¼����
            create_date, CreateDate,  // ��������
            update_name, UpdateName,  // ����������
            update_by, UpdateBy,      // �����˵�¼����
            update_date, UpdateDate,  // ��������
            sys_org_code, SysOrgCode, // ��������
            sys_company_code, SysCompanyCode // ������˾
        );
        pages->addData(dto);
    }
    return pages;

}
// ɾ���ͻ��Ʒ�����
bool CostAttributeService::DeleteCostAttribute(const string& id) {
    CostAttributeDAO dao;
    return dao.deleteCostAttribute(id) == 1;
}

// ����ͻ��Ʒ�����
uint64_t CostAttributeService::ImportCostAttribute(const ImportCostAttributeDTO::Wrapper& dto) {

    CostAttributeDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Id, id,
        CreateName, create_name,
        CreateBy, create_by,
        CreateDate, create_date,
        UpdateName, update_name,
        UpdateBy, update_by,
        UpdateDate, update_date,
        SysOrgCode, sys_org_code,
        SysCompanyCode, sys_company_code,
        KeHuShuXingCode, kehushuxing_code,
        KeHuShuXingName, kehushuxing_name
    );

    CostAttributeDAO dao;
    return dao.importCostAttribute(data);

}

// �����ͻ��Ʒ�����
list<CostAttributeDO> CostAttributeService::ExportCostAttribute() {
    // �����ݿ������пͻ��Ʒ���������
    CostAttributeDAO dao;
    list<CostAttributeDO> data = dao.exportCostAttribute();
    /*for (auto& item : data) {
        std::cout << item.getId();
    }*/
    return data;
}