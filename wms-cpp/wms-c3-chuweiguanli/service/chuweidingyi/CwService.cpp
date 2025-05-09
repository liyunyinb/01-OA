#include "stdafx.h"
#include "CwService.h"
#include "dao/chuweidingyi/CwDAO.h"
#include "domain/GlobalInclude.h"

string GetTimeStr() {
	auto now = std::chrono::system_clock::now();
	auto now_c = std::chrono::system_clock::to_time_t(now);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
	return ss.str();
}

string CwService::addCW(const AddCWDTO::Wrapper dto, const PayloadDTO& payload)
{
	BinDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		BinStore, bin_store,          // DTO��bin_store�ֶ�ӳ�䵽DO
		SuoShuKeHu, suo_shu_ke_hu,     // �����ͻ�
		KuWeiBianMa, ku_wei_bian_ma,   // ��λ����
		KuWeiTiaoMa, ku_wei_tiao_ma,   // ��λ����
		KuWeiLeiXing, ku_wei_lei_xing, // ��λ����
		KuWeiShuXing, ku_wei_shu_xing, // ��λ����
		ShangJiaCiXu, shang_jia_ci_xu, // �ϼܴ���
		QuHuoCiXu, qu_huo_ci_xu,       // ȡ������
		CHPShuXing, CHP_SHU_XING,      // ��Ʒ����
		XNode, xnode,                  // X����
		YNode, ynode,                  // Y����
		ZNode, znode                   // Z����
	);
	data.setCreateName(payload.getRealname());
	data.setCreateBy(payload.getUsername());
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());
	data.setCreateDate(GetTimeStr());
	CwDAO dao;
	return dao.add(data);
}