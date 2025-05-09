#pragma once

#ifndef _LOADINGFEE_SERVICE_
#define _LOADINGFEE_SERVICE_

#include "../../domain/vo/loading-fee/LoadingFeeVO.h"
#include "../../domain/do/LoadingFeeDO.h"
#include "../../domain/dto/loading-fee/LoadingFeeDTO.h"
#include "../../domain/query/loading-fee/LoadingFeeQuery.h"
#include <list>
/**
 * ���װ���ѷ���ʵ��
 */
class LoadingFeeService
{
public:
	// ��ҳ��ѯ���װ����
	LoadingFeePageDTO::Wrapper pageQueryLoadingFee(const LoadingFeeQuery::Wrapper& query);
	//�������װ����
	list<LoadingFeeDO> DownloadLoadingFee(const LoadingFeeQuery::Wrapper& query);
};

#endif // _LOADINGFEE_SERVICE_