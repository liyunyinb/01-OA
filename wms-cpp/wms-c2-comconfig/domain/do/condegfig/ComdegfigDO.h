#ifndef _COMDEGFIG_DO_
#define _COMDEGFIG_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ComdegfigDO
{
	// Ψһ����
	CC_SYNTHESIZE(string, id, Id);
	//����������
	CC_SYNTHESIZE(string, createname, CreateName);
	//�����˵�¼����
	CC_SYNTHESIZE(string, createby, CreateBy);
	// ��������
	CC_SYNTHESIZE(string, orgcode, OrgCode);
	// ������˾
	CC_SYNTHESIZE(string, companycode, CompanyCode);
	//����ʱ��
	CC_SYNTHESIZE(string,createdate, CreateDate)
	// ��ҵ�ȼ�����
	CC_SYNTHESIZE(string, degcode, DegCode);
	// ��ҵ�ȼ�����
	CC_SYNTHESIZE(string, degname, DegName);
	// ��ҵ�ȼ�ͣ��
	CC_SYNTHESIZE(string, degdel, DegDel);
public:
	ComdegfigDO(){}
	ComdegfigDO(string id, string createname,string createby,string orgcode,string companycode,string degcode,string degname,string degdel) {
		this->id = id;
		this->createname = createname;
		this->createby = createby;
		this->orgcode = orgcode;
		this->companycode = companycode;
		this->degcode = degcode;
		this->degname = degname;
		this->degdel;
	}
};

// ��ComdegfigDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ComdegfigDO> PtrComdegfigDO;
#endif 