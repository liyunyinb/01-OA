#include "stdafx.h"
#include "InventorylistDAO.h"
#include "InventorylistMapper.h"
#include <sstream>
inline std::string InventorylistDAO::queryConditionBuilder(const InventorylistQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    // �ƶ�����
    if (query->yidongriqi)
    {
        sqlCondition << "AND `bin_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->yidongriqi.getValue(""));
    }
    // �������
    if (query->cktype)
    {
        sqlCondition << " AND `tin_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cktype.getValue(""));
    }
    // ��λ
    if (query->chuwei)
    {
        sqlCondition << " AND `goods_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->chuwei.getValue(""));
    }
    // ����
    if (query->tuopan)
    {
        sqlCondition << " AND `goods_name` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->tuopan.getValue(""));
    }
    // ����
    if (query->huozhu)
    {
        sqlCondition << " AND `goods_pro_data` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->huozhu.getValue(""));
    }
    // ��������
    if (query->huozhumingcheng)
    {
        sqlCondition << " AND `goods_batch` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->huozhumingcheng.getValue(""));
    }
    // ��Ʒ����
    if (query->shangpinbianma)
    {
        sqlCondition << " AND `cus_name` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->shangpinbianma.getValue(""));
    }
    // ��Ʒ����
    if (query->shangpinshuliang)
    {
        sqlCondition << " AND `cus` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->shangpinshuliang.getValue(""));
    }
    // ��Ʒ����
    if (query->shangpinmincheng)
    {
        sqlCondition << " AND `stt_sta` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->shangpinmincheng.getValue(""));
    }
    // ��������
    if (query->shengchanriqi)
    {
        sqlCondition << " AND `stt_sta` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->shengchanriqi.getValue(""));
    }
    return sqlCondition.str();
}
// ͳ����������
uint64_t InventorylistDAO::count(const InventorylistQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM wm_stt_in_goods";
    // ������ѯ����
    sql += queryConditionBuilder(query, params);
    // ִ�в�ѯ
    return sqlSession->executeQueryNumerical(sql, params);
}
// ��ҳ��ѯ���� wm_stt_in_goods
std::list<InventorylistDo> InventorylistDAO::selectWithPage(const InventorylistQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM wm_stt_in_goods";
    // ������ѯ����
    sql += queryConditionBuilder(query, params);
    // ������ҳ����
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
    // ִ�в�ѯ
    InventorylistMapper mapper;
    return sqlSession->executeQuery<InventorylistDo>(sql, mapper, params);
}
// ��ѯ����---����ҳ
std::list<InventorylistDo> InventorylistDAO::selectWithConditions(const InventorylistQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM wm_stt_in_goods";
    // ������ѯ����
    sql += queryConditionBuilder(query, params);
    // ִ�в�ѯ
    InventorylistMapper mapper;
    return sqlSession->executeQuery<InventorylistDo>(sql, mapper, params);
}
// ͨ��������ѯ����
//std::list<InventorylistDo> GoodsManageDAO::selectByName(const string& name)
// {
// 
// }
// ͨ��ID��ѯ����
PtrInventorylistDo InventorylistDAO::selectById(uint64_t id)
{
    return {};
}
// ��������
uint64_t InventorylistDAO::insert(const InventorylistDo& iObj)
{
    return {};
}
// �޸�����
int InventorylistDAO::update(const InventorylistDo& uObj)
{
    if (uObj.getSttSta() == ZH_WORDS_GETTER("review-stt.goods.stt_sta.sta1"))
    {
        string sql = "UPDATE `wm_stt_in_goods` SET `stt_sta`=? WHERE `id`=?";
        return sqlSession->executeUpdate(sql, "%s%s", ZH_WORDS_GETTER("review-stt.goods.stt_sta.sta3"), uObj.getId());
    }
    return 0;
}
// ͨ��IDɾ������
//int InventorylistDAO::deleteById(uint64_t id)
//{
//    return {};
//}