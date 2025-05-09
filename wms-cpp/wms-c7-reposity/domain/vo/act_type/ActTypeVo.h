#pragma once

#ifndef _ACTTYPEVO_H_
#define _ACTTYPEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/act_type/ActTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ҵ���͵Ļ���������ʾJsonVO����������Ӧ���ͻ��ˣ�������¼����ҵ����
 */
class ActTypeBaseJsonVO : public JsonVO<ActTypeBaseDTO::Wrapper>
{
	DTO_INIT(ActTypeBaseJsonVO, JsonVO<ActTypeBaseDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */

class ActTypePageJsonVO : public JsonVO<ActTypePageDTO::Wrapper>
{
	DTO_INIT(ActTypePageJsonVO, JsonVO<ActTypePageDTO::Wrapper>);
};

/**
 * ����һ����ҵ������ϸ��Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
//class ActTypeListJsonVO : public JsonVO<ActTypePageDTO::Wrapper>
//{
//	DTO_INIT(ActTypeListJsonVO, JsonVO<ActTypePageDTO::Wrapper>);
//};

#include OATPP_CODEGEN_END(DTO)
#endif // _ACTTYPEVO_H_