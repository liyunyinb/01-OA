#include "stdafx.h"
#include "SttTaskService.h"
#include "domain/dto/stt-on-move/SttOnMoveDTO.h"
#include "../../dao/stt-task/SttTaskDAO.h"
#include "domain/do/goods-manage/wm_stt_in_goodsDO.h"


uint64_t SttTaskService::insert(const SttOnMoveDetailDTO::Wrapper& sttOnMoveDetailDTO, const PayloadDTO& payload)
{
	// ��װDO����
	Wm_Stt_In_GoodsDO data;
	// �������ݣ�Դ�Զ�����
	ZO_STAR_DOMAIN_DTO_TO_DO(data, sttOnMoveDetailDTO,BinId,bin_id,TinId,tin_id,GoodsId,goods_id,GoodsName,goods_name,GoodsQua,goods_qua,BaseUnit,base_unit,GoodsProDate,goods_pro_data,CusName,cus_name,CusCode,cus_code,SttSta,stt_sta, SysOrgCode,sys_org_code,SysCompanyCode, sys_company_code);

	// ��װDO��������
	// ����create_date
	std::time_t now = std::time(nullptr);
	std::tm tm_now = *std::localtime(&now);
	std::stringstream ssCreateTime;
	ssCreateTime << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S ");

	data.setCreateDate(ssCreateTime.str());

	// ����stt_id
	std::stringstream ssSttId;
	ssSttId << std::put_time(&tm_now, "%Y-%m-%d %H:%M ");

	data.setSttId(ssSttId.str());

	// ����������
	data.setCreateBy(payload.getUsername());

	// �������ǳ�realname
	data.setCreateName(payload.getRealname());
	
	// ������˾������
	data.setSysCompanyCode(payload.getCompanycode());
	data.setSysOrgCode(payload.getOrgcode());

	// �̵�״̬������Ϊ�ƻ���
	data.setSttSta(ZH_WORDS_GETTER("sttTask.val.inPlan"));

	// �̵�����
	data.setSttType("01");
	
	// ����DAO��ִ�в������
	SttTaskDAO dao;
	return dao.insert(data);
}

uint64_t SttTaskService::delData(const string& id, const PayloadDTO& payload)
{
	// ��װDO����
	Wm_Stt_In_GoodsDO data;

	// ƥ���ʶ��
	data.setId(id);
	//�����̵�״̬Ϊ��ɾ��
	data.setSttSta(ZH_WORDS_GETTER("sttTask.val.deleted"));
	// ���������Ϣ
	// ����update_date
	std::time_t now = std::time(nullptr);
	std::tm tm_now = *std::localtime(&now);
	std::stringstream ssUpdateDate;
	ssUpdateDate << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S ");

	data.setUpdateDate(ssUpdateDate.str());

	// �޸�update_by
	data.setUpdateBy(payload.getUsername());

	// �޸�update_name
	data.setUpdateName(payload.getRealname());

	SttTaskDAO dao;
	
	return dao.modifySttSta(data);
}
