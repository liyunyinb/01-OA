#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "../wms-c7-reposity/domain/dto/file/FileDTO.h" 
#include "domain/vo/BaseJsonVO.h"

/**
 * ����ʵ��
 */
class FileService
{
public:
	// ��ѯ����
	string queryData();
	// ��������
	bool insertData(string fullpath);
};

#endif // !_SAMPLE_SERVICE_

