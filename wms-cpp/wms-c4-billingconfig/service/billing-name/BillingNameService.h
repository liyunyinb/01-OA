#pragma once
#ifndef _BILLING_SERVICE_
#define _BILLING_SERVICE_
#include <list>
//#include "domain/vo/sample/SampleVO.h"
//#include "../../domain/vo/removal-adjustment/RemovalVO.h"
//#include "../../domain/vo/addition-adjustment/AdditionVO.h"
//#include "../../domain/dto/addition-adjustment/AdditionDTO.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../controller/billing-name/BillingNameController.h"
//#include "domain/query/sample/SampleQuery.h"
//#include "../../domain/query/removal-adjustment/RemovalQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
//#include "../../domain/dto/removal-adjustment/RemovalDTO.h"
#include "../../domain/do/billing-name/BillingNameDO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class BillingNameService
{
public:
	// ��ҳ��ѯ��������
	//RemovalPageDTO::Wrapper listAll(const RemovalQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	//RemovalDetailDTO::Wrapper getById(const oatpp::String& id);
	//ͨ���ַ�ID��ѯ��ϸ����
	//RemovalDetailDTO::Wrapper getbyorder_id(const RemovalQuery::Wrapper& query);
	// ��������
	//uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// �޸�����

	bool batchdeleteData(const BillingNameBatchDTO::Wrapper& batchdto);
	bool batchinsertData(const BillingNamefileDTO::Wrapper& batchdto);
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
	list<BillingNameDO> exportData(const BillingNameQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_
