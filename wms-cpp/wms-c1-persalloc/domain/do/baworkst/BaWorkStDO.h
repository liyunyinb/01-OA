#ifndef _BAWORKST_DO_
#define _BAWORKST_DO_
#include "../DoInclude.h"

/**
 * ����״̬ʵ����
 */
class BaWorkStDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����������
	CC_SYNTHESIZE(string, create_name,CreateName);
	// �����˵�¼����
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// ��������
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// ����������
	CC_SYNTHESIZE(string, update_name, UpdateName);
	//�����˵�¼����
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	//��������
	CC_SYNTHESIZE(string, update_date, UpdateDate);
	//��������
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	//������˾
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	//����״̬����
	CC_SYNTHESIZE(string, work_sta_code,WorkStaCode);
	//����״̬����
	CC_SYNTHESIZE(string, work_sta_name,WorkStaName);
	
public:
	BaWorkStDO() {
		id = "0";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		work_sta_code = "";
		work_sta_name = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<BaWorkStDO> PtrBaWorkStDO;
#endif // !_SAMPLE_DO_