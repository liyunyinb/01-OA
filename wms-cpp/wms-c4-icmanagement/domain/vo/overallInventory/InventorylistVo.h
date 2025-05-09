#pragma once
#ifndef _INVENTORYLIST_VO_
#define _INVENTORYLIST_VO_


#include "../../GlobalInclude.h"
#include "../../dto/overallInventory/InventorylistDto.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class InventorylistDetailVo : public JsonVO<InventorylistDto::Wrapper> {
	DTO_INIT(InventorylistDetailVo, JsonVO<InventorylistDto::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class InventoryJsonPageVO : public JsonVO<InventorylistDto::Wrapper> {
	DTO_INIT(InventoryJsonPageVO, JsonVO<InventorylistDto::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INVENTORY_LISTVO_