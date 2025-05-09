#ifndef _BAGOODSTYPE_VO_
#define _BAGOODSTYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/bagoodstype/BaGoodsTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaGoodsTypeJsonVO : public JsonVO<BaGoodsTypeDTO::Wrapper> {
	DTO_INIT(BaGoodsTypeJsonVO, JsonVO<BaGoodsTypeDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaGoodsTypeNamePageJsonVO : public JsonVO<BaGoodsTypeNamePageDTO::Wrapper> {
	DTO_INIT(BaGoodsTypeNamePageJsonVO, JsonVO<BaGoodsTypeNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 