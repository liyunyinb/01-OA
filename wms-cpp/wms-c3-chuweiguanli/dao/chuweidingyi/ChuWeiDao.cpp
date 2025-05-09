#pragma once
#include "stdafx.h"
#include "ChuWeiDao.h"
#include "ChuWeiMapper.h"
#include <sstream>

// ��ѯ��������
std::string ChuWeiDAO::queryConditionBuilder(const ChuWeiQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	//�ֿ�
	if (query->bin_store) {

		sqlCondition << " AND `bin_store`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_store.getValue(""));
	}
	//��λ����
	if (query->ku_wei_bian_ma) {

		sqlCondition << " AND `ku_wei_bian_ma`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_bian_ma.getValue(""));
	}
	//��λ����
	if (query->ku_wei_tiao_ma) {

		sqlCondition << " AND `ku_wei_tiao_ma`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_tiao_ma.getValue(""));
	}
	//��λ����
	if (query->ku_wei_lei_xing) {

		sqlCondition << " AND `ku_wei_lei_xing`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_lei_xing.getValue(""));
	}
	//x����
	if (query->xnode) {

		sqlCondition << " AND `xnode`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->xnode.getValue(""));
	}
	//y����
	if (query->ynode) {

		sqlCondition << " AND `ynode`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ynode.getValue(""));
	}
	//z����
	if (query->znode) {

		sqlCondition << " AND `znode`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->znode.getValue(""));
	}

	return sqlCondition.str();
}

// ͳ����������
uint64_t ChuWeiDAO::count(const ChuWeiQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM md_bin ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

// ��ҳ��ѯ����
std::list<BinDO> ChuWeiDAO::selectWithPage(const ChuWeiQuery::Wrapper& query)
{
	// �����Ϸ���У��
	if (query->pageIndex < 1 || query->pageSize < 1) {
		throw std::invalid_argument("Invalid page parameters: pageIndex and pageSize must be positive integers");
	}
	SqlParams params;
	string sql = "SELECT id,bin_store,ku_wei_bian_ma,ku_wei_tiao_ma,ku_wei_lei_xing,ku_wei_shu_xing,\
		CHP_SHU_XING,shang_jia_ci_xu,qu_huo_ci_xu,suo_shu_ke_hu,zui_da_ti_ji,zui_da_zhong_liang,\
		zui_da_tuo_pan,chang,kuan,gao,ting_yong,ming_xi,ming_xi1,ming_xi2,ming_xi3,LORA_bqid,\
		xnode,ynode,znode FROM md_bin ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	
	/*// ������ҳ���� 
	//���ַ���ƴ��sql�ķ�ʽ����Ҫ��to_string��uint���͵�pageIndex��pageSizeת��Ϊ�ַ���
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	*/

	// ��������ҳ����ȫ�Ľ�,�ɱ���SQLע�룬�����ݿⲻ֧��LIMIT�������������������ķ�����
	const int offset = (query->pageIndex - 1) * query->pageSize;
	sql += " LIMIT ?,?";  // ʹ��ռλ��  WHERE����ֵ + offset + pageSize

	// �󶨷�ҳ����
	//ʵ��ֵͨ�� SQLPARAMS_PUSH �󶨵� params�������'?'ռλ�����ʲ���to_string
	SQLPARAMS_PUSH(params, "i", int, offset);    // ƫ����
	SQLPARAMS_PUSH(params, "i", int, query->pageSize);  // ÿҳ����

	// ִ�в�ѯ
	ChuWeiMapper mapper;
	return sqlSession->executeQuery<BinDO>(sql, mapper, params);

}

//�޸Ĵ�λ
int ChuWeiDAO::update(const BinDO& uObj)
{
	string sql = "UPDATE `md_bin` SET `bin_store`=?, `suo_shu_ke_hu`=?, \
		`ku_wei_lei_xing`=?, `ku_wei_shu_xing`=?, `CHP_SHU_XING`=?,\
		 `shang_jia_ci_xu`=?, `qu_huo_ci_xu`=?, `zui_da_zhong_liang`=?,\
		 `zui_da_tuo_pan`=?, `chang`=?, `kuan`=?, `gao`=?,\
		 `zui_da_ti_ji`=?, `ting_yong`=?, `ming_xi`=?, `ming_xi1`=?,\
		 `ming_xi2`=?, `ming_xi3`=?, `LORA_bqid`=?, `xnode`=?,\
		 `ynode`=?, `znode`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		uObj.getBinStore(), uObj.getSuoShuKeHu(), uObj.getKuWeiLeiXing(),
		uObj.getKuWeiShuXing(), uObj.getCHPShuXing(), uObj.getShangJiaCiXu(), 
		uObj.getQuHuoCiXu(), uObj.getZuiDaZhongLiang(), uObj.getZuiDaTuoPan(), 
		uObj.getChang(), uObj.getKuan(), uObj.getGao(), 
		uObj.getZuiDaTiJi(), uObj.getTingYong(), uObj.getMingXi(), 
		uObj.getMingXi1(), uObj.getMingXi2(), uObj.getMingXi3(), 
		uObj.getLORABqid(), uObj.getXNode(), uObj.getYNode(), 
		uObj.getZNode(), uObj.getId());
}

//ɾ����λ
int ChuWeiDAO::deleteById(string id)
{
	string sql = "DELETE FROM `md_bin` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}