#ifndef _TIN_TRANSFER_VO_
#define _TIN_TRANSFER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/shengchengtuopanzhuanyi/TinTransferDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TinTransferJsonVO : public JsonVO<TinTransferDTO::Wrapper> {
	DTO_INIT(TinTransferJsonVO, JsonVO<TinTransferDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TinTransferPageJsonVO : public JsonVO<TinTransferPageDTO::Wrapper> {
	DTO_INIT(TinTransferPageJsonVO, JsonVO<TinTransferPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TIN_TRANSFER_VO_