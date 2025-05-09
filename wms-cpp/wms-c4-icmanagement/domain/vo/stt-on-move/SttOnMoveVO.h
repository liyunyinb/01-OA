#pragma once

#ifndef _STT_ON_MOVE_VO_
#define _STT_ON_MOVE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/stt-on-move/SttOnMoveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class SttOnMoveListJsonVO : public JsonVO<SttOnMoveListDTO::Wrapper> {
	DTO_INIT(SttOnMoveListJsonVO, JsonVO<SttOnMoveListDTO::Wrapper>);
};

/*
* ����������JsonVO
*/
class SttOnMoveDetailJsonVO : public JsonVO<SttOnMoveDetailDTO::Wrapper>
{
	DTO_INIT(SttOnMoveDetailJsonVO, JsonVO<SttOnMoveDetailDTO::Wrapper>);
};

/**
 * �������б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SttOnMovePageJsonVO : public JsonVO<SttOnMovePageDTO::Wrapper> {
	DTO_INIT(SttOnMovePageJsonVO, JsonVO<SttOnMovePageDTO::Wrapper>);
};

/*
* ���������̵�����JsonVO
*/
class SttOnMoveInsertTaskJsonVO : public JsonVO<SttOnMoveInsertTaskDTO::Wrapper>
{
	DTO_INIT(SttOnMoveInsertTaskJsonVO, JsonVO<SttOnMoveInsertTaskDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_STT_ON_MOVE_VO_