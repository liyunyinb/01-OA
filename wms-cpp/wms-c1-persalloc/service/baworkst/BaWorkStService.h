#ifndef _BaWorkSt_SERVICE_
#define _BaWorkSt_SERVICE_
#include <list>
#include "domain/vo/baworkst/BaWorkStVO.h"
#include "domain/query/baworkst/BaWorkStQuery.h"
#include "domain/dto/baworkst/BaWorkStDTO.h"

/**
 * ����״̬����ʵ��
 */
class BaWorkStService
{
public:
	// ��ҳ��ѯ��������
	BaWorkStPageDTO::Wrapper listAll(const BaWorkStQuery::Wrapper& query);
	// ��������
	string saveData(const BaWorkStAddDTO::Wrapper& dto,  const PayloadDTO& payload);
	// �޸�����
	string updateData(const BaWorkStChangeDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_