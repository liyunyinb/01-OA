#ifndef _BAGOODSTYPE_DO_
#define _BAGOODSTYPE_DO_
#include "../DoInclude.h"

/**
 * ����״̬ʵ����
 */
class BaGoodsTypeDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����������
	CC_SYNTHESIZE(string, create_name, CreateName);
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
	//��Ʒ���Դ���
	CC_SYNTHESIZE(string, goods_type_code, GoodsTypeCode);
	//��Ʒ��������
	CC_SYNTHESIZE(string, goods_type_name, GoodsTypeName);

public:
	BaGoodsTypeDO() {
		id = "0";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		goods_type_code = "";
		goods_type_name = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<BaGoodsTypeDO> PtrBaGoodsTypeDO;
#endif // !_SAMPLE_DO_