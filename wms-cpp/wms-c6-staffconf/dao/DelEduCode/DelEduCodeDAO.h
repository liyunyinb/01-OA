#pragma once

#ifndef _DELEDUCODE_DAO_
#define _DELEDUCODE_DAO_


#include"BaseDAO.h"
#include"domain/dto/education/EducationalDTO.h"
#include"domain/do/education/EduCodeDO.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class EducationalDAO : public BaseDAO
{
public:

	// ͨ��IDɾ������
	int deleteById(string id);
	// �޸�����
	int update(const EduCodeDO& uObj);

	uint64_t insertEduCode(const EducationalDTO::Wrapper& dto, const PayloadDTO auth);


	bool importExl(const std::list<EduInfoDO>& iObj);
	std::list<EduCodeDO> exportEduInfo();

};

#endif // !_DELEDUCODE_DAO_





