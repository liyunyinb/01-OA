#ifndef _BAWORKST_DAO_
#define _BAWORKST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/baworkst/BaWorkStDO.h"
#include "../../domain/query/baworkst/BaWorkStQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class BaWorkStDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const BaWorkStQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const BaWorkStQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<BaWorkStDO> selectWithPage(const BaWorkStQuery::Wrapper& query);
	// ¼�빤��״̬
	uint64_t insert(const BaWorkStDO& iObj);
	// �޸Ĺ���״̬
	int update(const BaWorkStDO& uObj);
};
#endif // !_BAWORKST_DAO_
