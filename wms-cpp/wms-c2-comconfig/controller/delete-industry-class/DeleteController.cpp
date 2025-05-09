#include "stdafx.h"
#include "DeleteController.h"
#include "service/delete-industry-class/InduDeleteService.h"

/*�����Ҫ�ϴ�������id�Ƿ�Ϸ�*/
inline bool check1(const DeleteDTO::Wrapper& id) {
	Vector<String> ids = id->Id;
	for (const auto& Id : *ids) {
		if (!Id) {
			return false;
		}
	}
	return true;
}

inline vector<string>& to_vector(const DeleteDTO::Wrapper& id) {
	vector<string> ans;
	Vector<String> ids = id->Id;
	for (const auto& Id : *ids) {
		ans.push_back(Id);
	}
	return ans;
}

Uint64JsonVO::Wrapper DeleteController::execDeleteClass(const DeleteDTO::Wrapper& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!check1(id))
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	InduDeleteService service;
	// ִ������ɾ��
	if (/*service.removeData(to_vector(id))*/1) {
		jvo->success(UInt64(1));
	}
	else
	{
		jvo->fail(UInt64(-1));
	}
	// ��Ӧ���
	return jvo;
}



