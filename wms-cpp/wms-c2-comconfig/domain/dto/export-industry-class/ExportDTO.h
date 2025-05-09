#pragma once
#ifndef _EXPORT_DTO_
#define _EXPORT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
* �޸���ҵ�������
*/
class ExportAddDTO :public oatpp::DTO
{
	DTO_INIT(ExportDTO, DTO);

	//��ҵ����Ψһid
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("chengfeng.id"));


	//��ҵ�������
	API_DTO_FIELD_DEFAULT(String, classfl_code, ZH_WORDS_GETTER("chengfeng.code"));

	//��ҵ��������
	API_DTO_FIELD_DEFAULT(String, classfl_name, ZH_WORDS_GETTER("chengfeng.name"));

	//ͣ��
	API_DTO_FIELD_DEFAULT(String, classfl_del, ZH_WORDS_GETTER("chengfeng.del"));
};

/**
 * ��˾��Ϣ�������
 */
class ExportDTO : public ExportAddDTO
{
	DTO_INIT(ExportDTO, ExportAddDTO);
};

/**
 * ��˾��Ϣ��ҳ�������
 */
class ExportPageDTO : public PageDTO<ExportDTO::Wrapper>
{
	DTO_INIT(ExportPageDTO, PageDTO<ExportDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_DTO_