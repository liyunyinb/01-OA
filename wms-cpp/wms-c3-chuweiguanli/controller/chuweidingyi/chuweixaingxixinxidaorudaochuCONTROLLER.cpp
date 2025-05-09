#include "stdafx.h"
#include "chuweixaingxixinxidaorudaochuCONTROLLER.h"
#include "../../service/chuweidingyi/xaingxixinxiSERVICE.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "../../../lib-common/include/ExcelComponent.h"
//��ϸ
//																	
//xiangxixinxiJsonVO::Wrapper apixiangxixinxi::execXiangXiXinXiZhanShi(const xiangxixinxiQUERY::Wrapper& weiyiid)
//{
//	// ����һ��Service
//	xiangxixinxiSERVICE service;
//	// ��ѯ����
//	auto result = service.getById(weiyiid);
//	// ��Ӧ���
//	auto jvo = xiangxixinxiJsonVO::createShared();
//	jvo->success(result);
//	
//	return jvo;
//
//}

//��ѯ��ϸ����
xiangxixinxiJsonVO::Wrapper apixiangxixinxi::execXiangXiXinXiZhanShi(const xiangxixinxiQUERY::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	xiangxixinxiSERVICE service;
	// ��ѯ����
	auto result = service.getById(query);
	// ��Ӧ���
	auto jvo = xiangxixinxiJsonVO::createShared();
	jvo->success(result);
	
	return jvo;
	
}



//������λ----�ļ�����---��������·��
StringJsonVO::Wrapper apixiangxixinxi::execDaoChuChuWei(const daochuchuweiDTO::Wrapper& id_zhi, const PayloadDTO& payload)
{
	//	������Ӧ���
	auto jvo = StringJsonVO::createShared();

	if (payload.getCode() != PayloadCode::SUCCESS) {
		return {};
	}
	else {
		//	Service��
		xiangxixinxiSERVICE service;
		auto res = service.daochuchuweiCONTROLLER(id_zhi->biaoshi);
		jvo->init("download_url: " + res, RS_SUCCESS);
	}

	return jvo;

}





//��λ����--���ļ�
StringJsonVO::Wrapper apixiangxixinxi::execDaoRuWenJianOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{

	//  ��ʼ��-----�������֣���ȡ����������
	API_MULTIPART_INIT(container, reader);

	//  ���ö�ȡ��----------��ȡ����-1Ĭ�϶�ȡȫ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	//  ��ȡ����
	request->transferBody(&reader);

	int con = container->count();
	
	for (int file_i = 0; file_i < con; file_i++)
	{
		string filename = "file";
		filename += std::to_string(file_i);
	
		
		//��������
		/* ��ȡ�ļ����� */
		API_MULTIPART_PARSE_FILE_FIELD(container, filename, file);


		std::vector<std::vector<std::string>> data = ExcelComponent::readIntoVector(file->c_str(), file->size(), ZH_WORDS_GETTER("bin.xlsx.sheet.s1"));

		int i = 0;
		string s = "";
		for (auto& row : data) {
			if (i > 2)
			{
				//����dto���ͽ�������
				auto jsdto = xiangxixinxiDTO::createShared();
				//dto��������

				jsdto->cangku = row[0];
				jsdto->bianma = row[1];
				jsdto->tiaoma = row[2];
				jsdto->leixing = row[3];
				jsdto->shuxing = row[4];
				jsdto->chanpinshuxing = row[5];
				jsdto->shangjiacixu = row[6];
				jsdto->quhuocixu = row[7];
				jsdto->kehu = row[8];
				jsdto->zuidamianji = row[9];
				jsdto->tiji = row[10];
				jsdto->zhongliang = row[11];
				jsdto->mianji = row[12];
				jsdto->zuidatiji = row[13];
				jsdto->zuidazhongliang = row[14];
				jsdto->zuidatuopan = row[15];
				jsdto->chang = row[16];
				jsdto->kuan = row[17];
				jsdto->gao = row[18];
				jsdto->tingyong = row[19];
				jsdto->beizhu = row[20];
				jsdto->beizhu1 = row[21];
				jsdto->beizhu2 = row[22];
				jsdto->dongxian = row[23];
				jsdto->ID = row[24];
				jsdto->x = row[25];
				jsdto->y = row[26];
				jsdto->z = row[27];


				//service��������
				xiangxixinxiSERVICE sev;
				s = sev.addchuweiSERVICE(jsdto, payload);
			}
			i++;
		}
		if (s == "")
		{
			return {};
		}
	}
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}





