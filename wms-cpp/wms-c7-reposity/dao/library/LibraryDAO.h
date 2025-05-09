/*
 @Author: nanbowan
*/
#pragma once

#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "domain/do/library/LibraryDO.h"
#include "domain/dto/library/LibraryDTO.h"

/**
 * �����ݿ����ʵ��
 */
class LibraryDAO : public BaseDAO
{
private:
public:
	// �޸�����
	int update(const LibraryDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_SAMPLE_DAO_

