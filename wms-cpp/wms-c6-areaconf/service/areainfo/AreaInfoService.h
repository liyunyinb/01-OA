#ifndef _AREAINFO_SERVICE_
#define _AREAINFO_SERVICE_
#include "domain/dto/areainfo/AreaInfoDTO.h"
#include "dao/areainfo/AreaInfoDAO.h"
#include "domain/query/areainfo/AreaInfoQuery.h"

class AreaInfoService
{
public:
	// ɾ��������Ϣ
	bool deleteData(const string& id);
	// �޸�����
	bool modifyData(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload);
	// ¼������
	bool addData(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload);
	// ��������
	bool upload(const std::vector<std::vector<std::string>>& vec, const PayloadDTO& payload);
	// ��ȡȫ��������Ϣ
	std::vector<std::vector<std::string>> selectAll();
	// ��ȡ������Ϣ������
	list<shared_ptr<TreeNode>> nameTree();
	// ��ȡ������Ϣ�б�
	AreaInfoPageDTO::Wrapper List(const AreaInfoQuery::Wrapper& query);
};

#endif // !_AREAINFO_SERVICE_
