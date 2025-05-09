#ifndef _COMDEG_SERVICE_
#define _COMDEG_SERVICE_
#include <list>
#include "domain/dto/comdeg/ComdegDTO.h"
#include "domain/vo/comdeg/ComdegVO.h"
#include "domain/query/comdeg/ComdegQuery.h"
#include "domain/GlobalInclude.h"
/**
 * ��ҳ���ң���ӷ���ʵ��
 */

class ComdegService {

public:
	// ��ҳ��ѯ��������
	ComdegPageDTO::Wrapper listAll(const ComdegQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	ComdegPageDTO::Wrapper getById(uint64_t id);
	// ��������
	uint64_t saveData(const ComdegAddDTO::Wrapper& dto,const PayloadDTO& payload);
};
#endif