#ifndef _BAGOODSTYPE_VO_
#define _BAGOODSTYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/bagoodstype/BaGoodsTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaGoodsTypePageJsonVO : public JsonVO<BaGoodsTypePageDTO::Wrapper> {
	DTO_INIT(BaGoodsTypePageJsonVO, JsonVO<BaGoodsTypePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 