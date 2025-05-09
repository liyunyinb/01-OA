#pragma once

#ifndef _INVENTORY_PVO_
#define _INVENTORY_PVO_

#include "../../GlobalInclude.h"
#include "../../dto/inentorydifference/InventoryPDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �̵�������JsonVO��������Ӧ���ͻ��˵�Json����
 */
class InventoryPJsonVO : public JsonVO<InventoryPDtailDTO::Wrapper> {
	DTO_INIT(InventoryPJsonVO, JsonVO<InventoryPDtailDTO::Wrapper>);
};

/**
 * �̵��������б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class InventoryPPageJsonVO : public JsonVO<InventoryPPageDTO::Wrapper> {
	DTO_INIT(InventoryPPageJsonVO, JsonVO<InventoryPPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INVENTORY_PVO_