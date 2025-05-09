#ifndef _BAGOODSTYPE_DAO_
#define _BAGOODSTYPE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/bagoodstype/BaGoodsTypeDO.h"
#include "../../domain/query/bagoodstype/BaGoodsTypeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class BaGoodsTypeDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const BaGoodsTypeQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const BaGoodsTypeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<BaGoodsTypeDO> selectWithPage(const BaGoodsTypeQuery::Wrapper& query);
};
#endif // !_BAWORKST_DAO_
