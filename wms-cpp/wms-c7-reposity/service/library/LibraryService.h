#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/dto/library/LibraryDTO.h" 

/**
 * ����ʵ��
 */
class LibraryService
{
public:
	// �޸�����
	bool updateData(const ModifyLibraryDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id);;
};

#endif // !_SAMPLE_SERVICE_

