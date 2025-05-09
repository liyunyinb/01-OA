#pragma once

#ifndef _BAACTTYPE_VO_
#define _BAACTTYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ba_act_type/BaActTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ�����JsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaActTypeJsonVO : public JsonVO<BaActTypeDTO::Wrapper> {
	DTO_INIT(BaActTypeJsonVO, JsonVO<BaActTypeDTO::Wrapper>);
};

/**
 * �ͻ���ҳ�б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaActTypePageJsonVO : public JsonVO<BaActTypeListPageDTO::Wrapper> {
	DTO_INIT(BaActTypePageJsonVO, JsonVO<BaActTypeListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BAACTTYPE_VO_