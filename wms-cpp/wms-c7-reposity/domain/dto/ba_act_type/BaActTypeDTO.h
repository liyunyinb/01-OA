#pragma once

#ifndef _BAACTTYPE_DTO_
#define _BAACTTYPE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҵ���ͻ������ݶ���
 */
class BaActTypeDTO : public oatpp::DTO
{
    DTO_INIT(BaActTypeDTO, DTO);

    // ��ҵ���ʹ���
    API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("ba_act_type.field.act_type_code"));

    // ��ҵ��������
    API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("ba_act_type.field.act_type_name"));

    // ҵ�񻷽�
    API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("ba_act_type.field.oper_step_code"));

	// ΨһID
    API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("ba_act_type.field.id"));

};

/**
 * ��ҵ�����������ݶ���
 */
class BaActTypeAddDTO : public oatpp::DTO
{
    DTO_INIT(BaActTypeAddDTO, DTO);

    // ��ҵ���ʹ���
    API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("ba_act_type.field.act_type_code"));

    // ��ҵ��������
    API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("ba_act_type.field.act_type_name"));

    // ҵ�񻷽�
    API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("ba_act_type.field.oper_step_code"));

};



/**
 * ��ҵ������ϸ���ݶ���
 */
class BaActTypeDetailDTO : public oatpp::DTO {
    DTO_INIT(BaActTypeDetailDTO, DTO);

    // ��ҵ���ʹ���
    API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("ba_act_type.field.act_type_code"));

    // ��ҵ��������
    API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("ba_act_type.field.act_type_name"));

    // ҵ�񻷽�
    API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("ba_act_type.field.oper_step_code"));

    // ΨһID
    API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("ba_act_type.field.id"));

    // ����������
    API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("ba_act_type.field.create_name"));

    // �����˵�¼����
    API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("ba_act_type.field.create_by"));

    // ��������
    API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("ba_act_type.field.create_date"));

    // ����������
    API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("ba_act_type.field.update_name"));

    // �����˵�¼����
    API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("ba_act_type.field.update_by"));

    // ��������
    API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("ba_act_type.field.update_date"));

    // ��������
    API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("ba_act_type.field.sys_org_code"));

    // ������˾
    API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("ba_act_type.field.sys_company_code"));
};

/**
 * ��ҵ�����б��ҳ���ݶ���
 */
class BaActTypeListPageDTO : public PageDTO<BaActTypeDTO::Wrapper>
{
    DTO_INIT(BaActTypeListPageDTO, PageDTO<BaActTypeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BAACTTYPE_DTO_
