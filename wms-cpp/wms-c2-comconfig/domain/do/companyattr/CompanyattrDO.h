#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_DO_
#define _COMPANYATTR_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class CompanyattrDO
{
	// ���
	//CC_SYNTHESIZE(string, id, Id);
	// ��ҵ���Դ���
	CC_SYNTHESIZE(string, com_type_code, com_type_Code);
	// ��ҵ��������
	CC_SYNTHESIZE(string, com_type_name, com_type_Name);
	//// ����
	//CC_SYNTHESIZE(int, age, Age);
public:
	CompanyattrDO() {
		//id = "";
		com_type_code = "";
		com_type_name = "";
		//age = -1;
	}
};

class CompanyattrIdDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ��ҵ���Դ���
	CC_SYNTHESIZE(string, com_type_code, com_type_Code);
	// ��ҵ��������
	CC_SYNTHESIZE(string, com_type_name, com_type_Name);
	//����������
	CC_SYNTHESIZE(string, create_name, create_Name);
	//�����˵�¼����
	CC_SYNTHESIZE(string, create_by, create_By);
	//����ʱ��
	CC_SYNTHESIZE(string, create_date, create_Date);
	//�޸�������
	CC_SYNTHESIZE(string, update_name, update_Name);
	//�޸��˵�¼����
	CC_SYNTHESIZE(string, update_by, update_By);
	//�޸�ʱ��ʱ��
	CC_SYNTHESIZE(string, update_date, update_Date);
	//��������
	CC_SYNTHESIZE(string, sys_org_code, sys_org_Code);
	//������˾
	CC_SYNTHESIZE(string, sys_company_code, sys_company_Code);
public:
	CompanyattrIdDO() {
		id = "";
		com_type_code = "";
		com_type_name = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
	}
};
// ��CompanyattrDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CompanyattrDO> PtrCompanyattrDO;
#endif // !_Companyattr_DO_
