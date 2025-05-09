#pragma once

#ifndef _LADMOD_DAO_
#define _LADMOD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/lad-mod/LadModDO.h"
#include "../../domain/query/lad-mod/LadModQuery.h"
#include "../../domain/dto/lad-mod/BatchDeleteRequestDto.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class LadModDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    LadModDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const LadModQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������LadModQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const LadModQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const LadModQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<LadModDO> selectWithPage(const LadModQuery::Wrapper& query);
	// ��������
	uint64_t insert(const LadModDO& iObj);
	// �޸�����
	int update(const LadModDO& uObj);
	// ͨ��IDɾ�������ʽ
	int deleteById(oatpp::UInt64 id);
	// ����ɾ�������ʽ
	int batchDelete(const BatchDeleteRequestDto::Wrapper& dto);
	// ��ѯ�����е������ʽ��code��name
	std::list<LadModDO> selectAll();
	// �����������
	uint64_t insert(const list<LadModDO>& data);
};
#endif // !_LadMod_DAO_
