#pragma once

#ifndef _UNLOADINGFEE_SERVICE_
#define _UNLOADINGFEE_SERVICE_

#include "../../domain/vo/unloading-fee/UnloadingFeeVO.h"
#include "../../domain/do/UnloadingFeeDO.h"
#include "../../domain/dto/unloading-fee/UnloadingFeeDTO.h"
#include "../../domain/query/unloading-fee/UnloadingFeeQuery.h"
#include <list>
/**
 * ���ж���ѷ���ʵ��
 */
class UnloadingFeeService
{
public:
	// ��ҳ��ѯ���ж����
	UnloadingFeePageDTO::Wrapper pageQueryUnloadingFee(const UnloadingFeeQuery::Wrapper& query);
	//�������ж����
	list<UnloadingFeeDO> DownloadUnloadingFee(const UnloadingFeeQuery::Wrapper& query);
};

#endif // _UNLOADINGFEE_SERVICE_