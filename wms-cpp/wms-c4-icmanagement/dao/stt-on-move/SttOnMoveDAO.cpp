/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/02 16:21:52

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
#include "SttOnMoveDAO.h"
#include "SttOnMoveMapper.h"
#include <sstream>

std::string SttOnMoveDAO::queryConditionBuilder(const SttOnMoveQuery::Wrapper& query, SqlParams& params)
{
	// �ַ����������������ѯ����
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->last_move_start)// �����ƶ�����
	{
		sqlCondition << " AND `last_move` >=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->last_move_start.getValue(""));
	}
	if (query->last_move_end)// �����ƶ�����
	{
		sqlCondition << " AND `last_move` <=?";
		SQLPARAMS_PUSH(params,"s",std::string,query->last_move_end.getValue(""));
	}
	if (query->cktype)// �������
	{
		sqlCondition << " AND `kuctype` =?";
		SQLPARAMS_PUSH(params,"s",std::string,query->cktype.getValue(""));
	}
	if (query->bin_id)// ��λ
	{
		sqlCondition << " AND `ku_wei_bian_ma` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
	}
	if (query->tin_id)// ����
	{
		sqlCondition << " AND `bin_id` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_id.getValue(""));
	}
	if (query->cus_code)// �ͻ�
	{
		sqlCondition << " AND `cus_code` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cus_code.getValue(""));
	}
	if (query->cus_name)// �ͻ�����
	{
		sqlCondition << " AND `zhong_wen_qch` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cus_name.getValue(""));
	}
	if (query->goods_id)// ��Ʒ����
	{
		sqlCondition << " AND `goods_id` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
	}
	if (query->goods_qua_min)// ������Ʒ����
	{
		sqlCondition << " AND `goods_qua` >=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_qua_min.getValue(""));
	}
	if (query->goods_qua_max)// �����Ʒ����
	{
		sqlCondition << " AND `goods_qua` <=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_qua_max.getValue(""));
	}
	if (query->goods_name)// ��Ʒ����
	{
		sqlCondition << " AND `shp_ming_cheng` LIKE CONCAT('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue(""));
	}
	if (query->goods_pro_data_start)// ������������
	{
		sqlCondition << " AND `goods_pro_data` >=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_pro_data_start.getValue(""));
	}
	if (query->goods_pro_data_end)// ������������
	{
		sqlCondition << " AND `goods_pro_data` <=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_pro_data_end.getValue(""));
	}

	return sqlCondition.str();
}

uint64_t SttOnMoveDAO::count(const SttOnMoveQuery::Wrapper& query)// Ŷ����Ǽ�����
{
	SqlParams params;
	string sql = "SELECT COUNT(*) from `wv_stock_stt`";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql,params);
}

std::list<SttOnMoveDO> SttOnMoveDAO::selectWithPage(const SttOnMoveQuery::Wrapper& query)
{
	SqlParams params;
	// ��ѯ���
	string sql = "SELECT last_move,kuctype,ku_wei_bian_ma,bin_id,cus_code,zhong_wen_qch,goods_id,goods_qua,shp_ming_cheng,goods_pro_data,bzhi_qi,goods_unit,stt_sta,`id` FROM `wv_stock_stt` ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	//������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	SttOnMoveMapper mapper;
	// ִ�в�ѯ
	return sqlSession->executeQuery<SttOnMoveDO>(sql,mapper,params);
}

PtrSttOnMoveDO SttOnMoveDAO::selectWithId(string id)
{
	string sql = "SELECT last_move,kuctype,ku_wei_bian_ma,bin_id,cus_code,zhong_wen_qch,goods_id,goods_qua,shp_ming_cheng,goods_pro_data,bzhi_qi,goods_unit,stt_sta,`id` FROM `wv_stock_stt` WHERE `id` = ?";
	PtrSttOnMoveMapper mapper;
	return sqlSession->executeQueryOne<PtrSttOnMoveDO>(sql,mapper,"%s",id);
}
