
#pragma once
#ifndef _MOVEGOODS_SERVICE_
#define _MOVEGOODS_SERVICE_
#include <list>
#include "domain/vo/kuneizhuanyi/MoveGoodsVO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class MoveGoodsService
{
public:
	
	// ͨ��ID��ѯ��ϸת��������Ϣ
	MoveGoodsDetailedDTO::Wrapper getDetailedById(const oatpp::String queryID);
	// ͨ��IDɾ������
	bool removeMoveGoods(const vector<string> id,const string usrName);
	// ͨ��ID��ѯ����ת��������Ϣ
	vector<vector<string>> getDownLoadById(const vector<string>& ids);
};

#endif // !_MOVEGOODS_SERVICE_