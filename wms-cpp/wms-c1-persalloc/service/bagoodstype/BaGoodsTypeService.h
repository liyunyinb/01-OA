#ifndef _BaGoodsType_SERVICE_
#define _BaGoodsType_SERVICE_
#include <list>
#include "domain/vo/bagoodstype/BaGoodsTypeVO.h"
#include "domain/query/bagoodstype/BaGoodsTypeQuery.h"
#include "domain/dto/bagoodstype/BaGoodsTypeDTO.h"

/**
 * ����״̬����ʵ��
 */
class BaGoodsTypeService
{
public:                                     
	// ��ҳ��ѯ��������
	BaGoodsTypeNamePageDTO::Wrapper listAll(const BaGoodsTypeQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_