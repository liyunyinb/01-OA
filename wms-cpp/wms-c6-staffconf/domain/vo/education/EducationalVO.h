#pragma once
#ifndef _EDUCATIONAL_H_

#include "../../GlobalInclude.h"
#include"domain/dto/education/EducationalDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


//class EducationalVO : public oatpp::DTO {
//	DTO_INIT(EducationalVO, DTO);
//	//ѧ������
//	API_DTO_FIELD(String, education_code, ZH_WORDS_GETTER("educational_background.field.Education_code"), true, "john");
//	//ѧ������
//	API_DTO_FIELD(String, education_name, ZH_WORDS_GETTER("educational_background.field.Education_name"), true, "1");
//	//����
//	API_DTO_FIELD(String, education_operation, ZH_WORDS_GETTER("educational_background.field.Education_operation"), true, "1");
//};

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */


class EduCodeVO : public oatpp::DTO
{
	DTO_INIT(EduCodeVO, DTO);
	//Ա���ǳ�
	API_DTO_FIELD(String, code, ZH_WORDS_GETTER("educational_background.field.Education_code"), true, "");
	//Ա������
	API_DTO_FIELD(String, nama, ZH_WORDS_GETTER("educational_background.field.Education_name"), true, "");


};

class EducationalJsonVO : public JsonVO<EducationalDTO::Wrapper> {
	DTO_INIT(EducationalJsonVO, JsonVO<EducationalDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EDUCATIONAL_H_


