#pragma once

#ifndef _XIANGXIXINXI_
#define _XIANGXIXINXI_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//Ψһ��ʶ
class daochuchuweiDTO :public oatpp::DTO
{
	DTO_INIT(daochuchuweiDTO, DTO);
	//��ʶ
	DTO_FIELD(List<String>, biaoshi);
	DTO_FIELD_INFO(biaoshi)
	{
		info->description= ZH_WORDS_GETTER("chuweixiangxixinxi.bs.bioashi");
	}
};


//��ϸ��Ϣ
class xiangxixinxiDTO : public oatpp::DTO
{
	DTO_INIT(xiangxixinxiDTO, DTO);
	// �ֿ�
	DTO_FIELD(String, cangku);
	DTO_FIELD_INFO(cangku) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.cangku");
	}

	// ��λ����
	DTO_FIELD(String, bianma);
	DTO_FIELD_INFO(bianma) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.bianma");
	}


	// ��λ����
	DTO_FIELD(String, tiaoma);
	DTO_FIELD_INFO(tiaoma) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiaoma");
	}

	// ��λ����
	DTO_FIELD(String, leixing);
	DTO_FIELD_INFO(leixing) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.leixing");
	}

	// ��λ����5
	DTO_FIELD(String, shuxing);
	DTO_FIELD_INFO(shuxing) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shuxing");
	}

	//��Ʒ����6
	DTO_FIELD(String, chanpinshuxing);
	DTO_FIELD_INFO(chanpinshuxing) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chanpinshuxing");
	}

	// �ϼܴ���
	DTO_FIELD(String, shangjiacixu);
	DTO_FIELD_INFO(shangjiacixu) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shangjiacixu");
	}

	// ȡ������ 8
	DTO_FIELD(String, quhuocixu);
	DTO_FIELD_INFO(quhuocixu) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.quhuocixu");
	}

	//�����ͻ�
	DTO_FIELD(String, kehu);
	DTO_FIELD_INFO(kehu) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kehu");
	}

	//������
	DTO_FIELD(String, zuidamianji);
	DTO_FIELD_INFO(zuidamianji) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidamianji");
	}

	// �����λ
	DTO_FIELD(String, tiji);
	DTO_FIELD_INFO(tiji) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiji");
	}


	// ������λ
	DTO_FIELD(String, zhongliang);
	DTO_FIELD_INFO(zhongliang) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zhongliang");
	}

	// �����λ
	DTO_FIELD(String, mianji);
	DTO_FIELD_INFO(mianji) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.minaji");
	}

	// ������14
	DTO_FIELD(String, zuidatiji);
	DTO_FIELD_INFO(zuidatiji) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatiji");
	}

	// �������
	DTO_FIELD(String, zuidazhongliang);
	DTO_FIELD_INFO(zuidazhongliang) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidazhongliang");
	}

	// �������
	DTO_FIELD(String, zuidatuopan);
	DTO_FIELD_INFO(zuidatuopan) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatupan");
	}

	// ��17
	DTO_FIELD(String, chang);
	DTO_FIELD_INFO(chang) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chang");
	}

	// ��
	DTO_FIELD(String, kuan);
	DTO_FIELD_INFO(kuan) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kuan");
	}

	// ��
	DTO_FIELD(String, gao);
	DTO_FIELD_INFO(gao) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.gao");
	}

	// ͣ��
	DTO_FIELD(String, tingyong);
	DTO_FIELD_INFO(tingyong) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tingyong");
	}



	// ��ע
	DTO_FIELD(String, beizhu);
	DTO_FIELD_INFO(beizhu) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu");
	}

	// ��ע1
	DTO_FIELD(String, beizhu1);
	DTO_FIELD_INFO(beizhu1) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu1");
	}

	// ��ע2
	DTO_FIELD(String, beizhu2);
	DTO_FIELD_INFO(beizhu2) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu2");
	}

	// ����
	DTO_FIELD(String, dongxian);
	DTO_FIELD_INFO(dongxian) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.dongxian");
	}

	// ���ӱ�ǩID
	DTO_FIELD(String, ID);
	DTO_FIELD_INFO(ID) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.ID");
	}


	//x����
	DTO_FIELD(String, x);
	DTO_FIELD_INFO(x) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.x");
	}

	//y����
	DTO_FIELD(String, y);
	DTO_FIELD_INFO(y) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.y");
	}

	//z����
	DTO_FIELD(String, z);
	DTO_FIELD_INFO(z) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.z");
	}
};




#include OATPP_CODEGEN_END(DTO)
#endif // !_XIANGXIXINXI_