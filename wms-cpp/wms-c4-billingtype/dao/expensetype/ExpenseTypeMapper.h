#pragma once
#ifndef _EXPENSETYPEMAPPER_
#define _EXPENSETYPEMAPPER_

#include "Mapper.h"
#include "../../domain/do/expensetype/ExpenseTypeDO.h"

/**
 * �����ֶ�ƥ��ӳ��
 */
class ExpenseTypeMapper : public Mapper<ExpenseTypeDO>
{
public:
	ExpenseTypeDO mapper(ResultSet* resultSet) const override
	{
		ExpenseTypeDO data;
		data.setId(resultSet->getString(1));                   // ���  
		data.setCreate_name(resultSet->getString(2));           // ����������  
		data.setCreate_by(resultSet->getString(3));            // �����˵�¼����  
		data.setCreate_date(resultSet->getString(4));           // ��������  
		data.setUpdate_name(resultSet->getString(5));            // ����������  
		data.setUpdate_by(resultSet->getString(6));             // �����˵�¼����  
		data.setUpdate_date(resultSet->getString(7));           // ��������  
		data.setSys_org_code(resultSet->getString(8));           // ��������  
		data.setSys_company_code(resultSet->getString(9));       // ������˾  
		data.setCost_type_code(resultSet->getString(10));             // ���ô���
		data.setCost_type_name(resultSet->getString(11));           // ��������
		data.setCost_type_del(resultSet->getString(12));       // ͣ��
		
		return data;
	}
};

/**
 * �����ֶ�ƥ��ӳ��-��������ָ�����
 */
class PtrExpenseTypeMapper : public Mapper<PtrExpenseTypeDO>
{
public:
	PtrExpenseTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ExpenseTypeDO>();
		data->setId(resultSet->getString(1));                   // ���  
		data->setCreate_name(resultSet->getString(2));           // ����������  
		data->setCreate_by(resultSet->getString(3));            // �����˵�¼����  
		data->setCreate_date(resultSet->getString(4));           // ��������  // �޸������ȱʧ��create_date�ֶ�  
		data->setUpdate_name(resultSet->getString(5));            // ����������  
		data->setUpdate_by(resultSet->getString(6));             // �����˵�¼����  
		data->setUpdate_date(resultSet->getString(7));           // ��������  
		data->setSys_org_code(resultSet->getString(8));           // ��������  
		data->setSys_company_code(resultSet->getString(9));       // ������˾  
		data->setCost_type_code(resultSet->getString(10));             // ���ô���
		data->setCost_type_name(resultSet->getString(11));           // ��������
		data->setCost_type_del(resultSet->getString(12));       // ͣ
		return data;
	}
};

#endif // !_EXPENSETYPEMAPPER_