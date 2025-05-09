#pragma once

#include "domain/GlobalInclude.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ��ʾJsonVO
*/
class MoveGoodsJsonVO : public JsonVO<MoveGoodsDTO::Wrapper> {
	DTO_INIT(MoveGoodsJsonVO, JsonVO<MoveGoodsDTO::Wrapper>);
};

/**
* ��ҳ��ʾJsonVO
*/
class MoveGoodsPageJsonVO : public JsonVO<MoveGoodsPageDTO::Wrapper> {
	DTO_INIT(MoveGoodsPageJsonVO, JsonVO<MoveGoodsPageDTO::Wrapper>);
};

/**
* ��ϸ��ʾJsonVO
*/
class MoveGoodsDetailedJsonVO : public JsonVO<MoveGoodsDetailedDTO::Wrapper> {
	DTO_INIT(MoveGoodsDetailedJsonVO, JsonVO<MoveGoodsDetailedDTO::Wrapper>);
};

/**
* ����JsonVO
*/
class MoveGoodsDownLoadJsonVO : public JsonVO<MoveGoodsDownLoadDTO::Wrapper> {
	DTO_INIT(MoveGoodsDownLoadJsonVO, JsonVO<MoveGoodsDownLoadDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
