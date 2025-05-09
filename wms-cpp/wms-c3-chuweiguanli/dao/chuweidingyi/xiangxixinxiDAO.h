#pragma once
#ifndef _XIANGXIXINXIDAO_
#define _XIANGXIXINXIDAO_
#include "BaseDAO.h"
#include "../../domain/query/chuweidingyi/xiangxixinxiQUERY.h"
#include "../../domain/do/BinDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class xiangxixinxiDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string xiangxixinxiqueryConditionBuilder(const xiangxixinxiQUERY::Wrapper& query, SqlParams& params);
public:
	// ͨ��ID��ѯ����
	std::shared_ptr<BinDO> idchaxun(const xiangxixinxiQUERY::Wrapper& id);

	//	����ID��ȡһ��������
	std::vector<string> getdataone(string store_code);
	//	��ȡ���б�����
	std::vector<std::vector<std::string>> getdataall();

	//���봢λ
	std::string addchuweiDAO(const BinDO& bindo, const PayloadDTO& payload);

};
#endif // !_XIANGXIXINXIDAO_