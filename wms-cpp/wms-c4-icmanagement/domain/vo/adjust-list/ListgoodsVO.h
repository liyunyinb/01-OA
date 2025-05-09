#pragma once
#ifndef _LISTGOODS_VO_
#define _LISTGOODS_VO_

/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : ListgoodsController.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/26 17:04
    *  @brief    : brief
*****************************************************************************/


#include "../../dto/adjust-list/ListgoodsDTO.h"
#include "domain/query/PageQuery.h"
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸��ϼܻ���JsonVO��������Ӧ���ͻ��˵�Json����
 */
class  ListgoodsadjustJsonVO : public JsonVO<ListgoodsadjustDTO::Wrapper> {
	DTO_INIT(ListgoodsadjustJsonVO, JsonVO<ListgoodsadjustDTO::Wrapper>);
};


/**
 * �ϼܻ�������JsonVO��������Ӧ���ͻ��˵�Json����
 */
class ListgoodsdetailJsonVO : public JsonVO<ListgoodsDetailDTO::Wrapper> {
	DTO_INIT(ListgoodsdetailJsonVO, JsonVO<ListgoodsDetailDTO::Wrapper>);
};

/**
 * �ϼܻ����ҳ�б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ListgoodsPageJsonVO : public JsonVO<ListgoodsPageDTO::Wrapper> {
	DTO_INIT(ListgoodsPageJsonVO, JsonVO<ListgoodsPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_LISTGOODS_VO_#pragma once
