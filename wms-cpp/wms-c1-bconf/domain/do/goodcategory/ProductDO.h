#pragma once
#ifndef _PRODUCT_DO_
#define _PRODUCT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ProductDO
{
	
	// ��Ʒ����
	CC_SYNTHESIZE(string, categorynum, Categorynum);
	// ��Ʒ��Ŀ����
	CC_SYNTHESIZE(string, categoryname, Categoryname);
	// ��Ʒ����
	CC_SYNTHESIZE(int, categorylevel, Categorylevel);
	//pid
	CC_SYNTHESIZE(int, pid, PID);
	//top_node
	CC_SYNTHESIZE(string, topnode, Topnode);
public:
	ProductDO() {
		categorynum = "";
		categoryname = "";
		categorylevel = -1;
		pid = -1;
		topnode = "";
	}
};

// ��ProductDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<ProductDO> PtrProductDO;
#endif // !_SAMPLE_DO_