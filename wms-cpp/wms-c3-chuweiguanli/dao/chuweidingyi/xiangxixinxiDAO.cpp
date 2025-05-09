#include "stdafx.h"
#include "xiangxixinxiDAO.h"
#include "xaingxixinxiMAPPER.h"
#include <sstream>
#include "id/UuidFacade.h"

//��ǰ����ʱ�亯��
std::string getCurrentDateTime() {
	// ��ȡ��ǰʱ���
	auto now = std::chrono::system_clock::now();
	// ��ʱ���ת��Ϊʱ��_t����
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	// ��ʱ��_t����ת��Ϊtm�ṹ��
	std::tm* localTime = std::localtime(&currentTime);

	// ����һ���ַ���������
	std::ostringstream oss;
	// ���������ʽ
	oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");

	// ���ظ�ʽ������ַ���
	return oss.str();
}


std::string xiangxixinxiDAO::xiangxixinxiqueryConditionBuilder(const  xiangxixinxiQUERY::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->weiyiid) {

		sqlCondition << " AND `id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->weiyiid.getValue(""));  
	}

	return sqlCondition.str();
}


// ͨ��ID��ѯ����
std::shared_ptr<BinDO> xiangxixinxiDAO::idchaxun(const xiangxixinxiQUERY::Wrapper& id)
{
	SqlParams params;
	string sql = "SELECT * FROM md_bin";
	sql += xiangxixinxiqueryConditionBuilder(id, params);
	ptrxiangxixinxiMapper mapper;
	return sqlSession->executeQueryOne<std::shared_ptr<BinDO>>(sql, mapper, params);

}



//	����ID��ȡһ��������
std::vector<string> xiangxixinxiDAO::getdataone(string store_code)
{
	std::vector<string> result;
	stringstream sql;

	sql << "SELECT * FROM md_bin  WHERE id = '" << store_code << "'";
	xiangxixinxiMapper mapper;
	string sql_str = sql.str();
	std::list<BinDO> sql_result = sqlSession->executeQuery<BinDO>(sql_str, mapper);

	if (sql_result.empty())
		return result;

	result.push_back(sql_result.begin()->getBinStore());//�ֿ�
	result.push_back(sql_result.begin()->getKuWeiBianMa());
	result.push_back(sql_result.begin()->getKuWeiTiaoMa());
	result.push_back(sql_result.begin()->getKuWeiLeiXing());
	result.push_back(sql_result.begin()->getKuWeiShuXing());
	result.push_back(sql_result.begin()->getCHPShuXing());//��Ʒ����
	result.push_back(sql_result.begin()->getShangJiaCiXu());
	result.push_back(sql_result.begin()->getQuHuoCiXu());
	result.push_back(sql_result.begin()->getSuoShuKeHu());
	result.push_back(sql_result.begin()->getZuiDaMianJi());//������
	result.push_back(sql_result.begin()->getTiJiDanWei());//�����λ
	result.push_back(sql_result.begin()->getZhongLiangDanWei());
	result.push_back(sql_result.begin()->getMianJiDanWei());//�����λ
	result.push_back(sql_result.begin()->getZuiDaTiJi());
	result.push_back(sql_result.begin()->getZuiDaZhongLiang());
	result.push_back(sql_result.begin()->getZuiDaTuoPan());
	result.push_back(sql_result.begin()->getChang());
	result.push_back(sql_result.begin()->getKuan());
	result.push_back(sql_result.begin()->getGao());
	result.push_back(sql_result.begin()->getTingYong());
	result.push_back(sql_result.begin()->getMingXi());//��ע
	result.push_back(sql_result.begin()->getMingXi1());
	result.push_back(sql_result.begin()->getMingXi2());
	result.push_back(sql_result.begin()->getMingXi3());//����
	result.push_back(sql_result.begin()->getLORABqid());//ID
	result.push_back(sql_result.begin()->getXNode());
	result.push_back(sql_result.begin()->getYNode());
	result.push_back(sql_result.begin()->getZNode());

	return result;
}

//	��ȡ���б�����
std::vector<std::vector<std::string>> xiangxixinxiDAO::getdataall()
{
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> header;
	header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.cangku"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.bianma"), ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiaoma"), ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.leixing"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shuxing"),    ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chanpinshuxing"),        ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shangjiacixu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.quhuocixu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kehu"),   ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidamianji"),   ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiji") });
	header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zhongliang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.mianji"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatiji"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidazhongliang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatuopan"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kuan"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.gao") });
	header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tingyong"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizu1"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu2"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.dongxian"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.ID"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.x"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.y"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.z") });
	result.push_back(header);
	stringstream sql;
	sql << "SELECT  * FROM md_bin ";

	xiangxixinxiMapper mapper;
	string sql_str = sql.str();
	auto sql_result = sqlSession->executeQuery<BinDO>(sql_str, mapper);

	for (auto& item : sql_result) {
		std::vector<std::string> row;
		row.push_back(item.getBinStore());//�ֿ�
		row.push_back(item.getKuWeiBianMa());
		row.push_back(item.getKuWeiTiaoMa());
		row.push_back(item.getKuWeiLeiXing());
		row.push_back(item.getKuWeiShuXing());
		row.push_back(item.getCHPShuXing());//��Ʒ����
		row.push_back(item.getShangJiaCiXu());
		row.push_back(item.getQuHuoCiXu());
		row.push_back(item.getSuoShuKeHu());
		row.push_back(item.getZuiDaMianJi());//������
		row.push_back(item.getTiJiDanWei());//�����λ
		row.push_back(item.getZhongLiangDanWei());
		row.push_back(item.getMianJiDanWei());//�����λ
		row.push_back(item.getZuiDaTiJi());
		row.push_back(item.getZuiDaZhongLiang());
		row.push_back(item.getZuiDaTuoPan());
		row.push_back(item.getChang());
		row.push_back(item.getKuan());
		row.push_back(item.getGao());
		row.push_back(item.getTingYong());
		row.push_back(item.getMingXi());//��ע
		row.push_back(item.getMingXi1());
		row.push_back(item.getMingXi2());
		row.push_back(item.getMingXi3());//����
		row.push_back(item.getLORABqid());//ID
		row.push_back(item.getXNode());
		row.push_back(item.getYNode());
		row.push_back(item.getZNode());

		result.emplace_back(row);
	}

	return result;

}


//���봢λ
std::string xiangxixinxiDAO::addchuweiDAO(const BinDO& bindo, const PayloadDTO& payload)
{

	// ����������
	UuidFacade ufid(1);

	// ������32��ID
	std::string ids = ufid.genUuid();
	string::iterator it;     //ָ��string��ĵ���������������Ϊָ��

	int i = 0;
	for (it = ids.begin(); it != ids.end(); it++)
	{
		
		if (*it == '-')
		{
			ids.erase(i,1);          //ɾ��it����һ���ַ�
		}
		i++;
	}
	
	

	//����ʱ��
	string sql_time = getCurrentDateTime();


	SqlParams params;
	//33
	string sql = "INSERT INTO md_bin (id, create_name , create_by , create_date, sys_org_code ,sys_company_code ,\
		ku_wei_bian_ma , ku_wei_tiao_ma , ku_wei_lei_xing , ku_wei_shu_xing , shang_jia_ci_xu , qu_huo_ci_xu ,\
	    suo_shu_ke_hu , ti_ji_dan_wei , zhong_liang_dan_wei , mian_ji_dan_wei , zui_da_ti_ji , zui_da_zhong_liang , \
		zui_da_mian_ji , zui_da_tuo_pan , chang , kuan , gao , ting_yong ,\
		ming_xi , CHP_SHU_XING , ming_xi1 , ming_xi2 , ming_xi3 , LORA_bqid , xnode , ynode , znode ) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	UuidFacade uf;
	auto id = uf.genUuid();
	auto result = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", \
		ids, payload.getUsername() , payload.getRealname(), sql_time ,payload.getOrgcode(),payload.getCompanycode(), \
		bindo.getKuWeiBianMa(), bindo.getKuWeiTiaoMa(), bindo.getKuWeiLeiXing(), bindo.getKuWeiShuXing(), bindo.getShangJiaCiXu(), bindo.getQuHuoCiXu(), \
		bindo.getSuoShuKeHu() , bindo.getTiJiDanWei(),bindo.getZhongLiangDanWei(), bindo.getMianJiDanWei(), bindo.getZuiDaTiJi(), bindo.getZuiDaZhongLiang(), \
		bindo.getZuiDaMianJi(), bindo.getZuiDaTuoPan(), bindo.getChang(), bindo.getKuan(), bindo.getGao(), bindo.getTingYong(),\
		bindo.getMingXi(),  bindo.getCHPShuXing(), bindo.getMingXi1(), bindo.getMingXi2(), bindo.getMingXi3(), bindo.getLORABqid(), \
		bindo.getXNode(), bindo.getYNode(), bindo.getZNode());
	if (result == -1) {
		return "";
	}
	return id;
	
}


