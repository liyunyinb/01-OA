#pragma once
#include "../DoInclude.h"

/**
 * ��Ʒ�������ݿ�ʵ����
 */
class ShuxingDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	
	//����������
	CC_SYNTHESIZE(string, create_name, Create_name);
	//�����˵�¼����
	CC_SYNTHESIZE(string, create_by, Create_by);
	//��������
	CC_SYNTHESIZE(string, create_date, Create_date);
	//����������
	CC_SYNTHESIZE(string, update_name, Update_name);
	//�����˵�¼����
	CC_SYNTHESIZE(string, update_by, Update_by);
	//��������
	CC_SYNTHESIZE(string, update_date, Update_date);
	//��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//������˾
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	//��Ʒ���Ա���
	CC_SYNTHESIZE(string, goods_type_code, Goods_type_code);
	//��Ʒ��������
	CC_SYNTHESIZE(string, goods_type_name, Goods_type_name);
public:
	ShuxingDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		goods_type_code = "";
		goods_type_name = "";
	}
};


typedef std::shared_ptr<ShuxingDO> PtrShuxingDO;