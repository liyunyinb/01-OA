#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/03 10:15:23

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _STT_ON_MOVE_D0_
#define _STT_ON_MOVE_D0_
#include "../DoInclude.h"

/*
* ��������ͼʵ������
*/
class SttOnMoveDO
{
	// ����������
	CC_SYNTHESIZE(string, createDate, CreateDate);
	// ����������
	CC_SYNTHESIZE(string,createName,CreateName);
	// ������id
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// Ψһ��ʶ
	CC_SYNTHESIZE(string, id, Id);
	// �������
	CC_SYNTHESIZE(string,kuctype,Kuctype);
	// ��λ
	CC_SYNTHESIZE(string,kuWeiBianMa,KuWeiBianMa);
	// ����
	CC_SYNTHESIZE(string,binId,BinId);
	// ����
	CC_SYNTHESIZE(string,cusCode,CusCode);
	// ��������
	CC_SYNTHESIZE(string,zhongWenQch,ZhongWenQch);
	// ��Ʒ����
	CC_SYNTHESIZE(string,goodsId,GoodsId);
	// ��Ʒ����
	CC_SYNTHESIZE(string,goodsQua,GoodsQua);
	// ��Ʒ����
	CC_SYNTHESIZE(string,shpMingCheng,ShpMingCheng);
	// ��������
	CC_SYNTHESIZE(string,goodsProData,GoodsProData);
	// ������
	CC_SYNTHESIZE(string,bzhiQi,BzhiQi);
	// ��������������������Դ��md_goods��ë��
	CC_SYNTHESIZE(string, yushoutianshu, Yushoutianshu);
	// ��λ
	CC_SYNTHESIZE(string,goodsUnit,GoodsUnit);
	// ״̬
	CC_SYNTHESIZE(string,sttSta,SttSta);
	// �ƶ�״̬
	CC_SYNTHESIZE(string, moveSta, MoveSta);
	// �ƶ�����
	CC_SYNTHESIZE(string, lastMove, LastMove);

public:
	SttOnMoveDO()
	{
		createDate = "";
		createName = "";
		createBy = "";
		id = "";
		kuctype = "";
		kuWeiBianMa = "";
		binId = "";
		cusCode = "";
		zhongWenQch = "";
		goodsId = "";
		goodsQua = "";
		shpMingCheng = "";
		goodsProData = "";
		bzhiQi = "";
		goodsUnit = "";
		yushoutianshu = "";
		sttSta = "";
		moveSta = "";
		lastMove = "";
	}

};

// ��SttOnMoveDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<SttOnMoveDO> PtrSttOnMoveDO;
#endif