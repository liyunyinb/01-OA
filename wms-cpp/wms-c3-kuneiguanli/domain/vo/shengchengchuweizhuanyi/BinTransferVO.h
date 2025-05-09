#ifndef _BIN_TRANSFER_VO_
#define _BIN_TRANSFER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/shengchengchuweizhuanyi/BinTransferDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BinTransferJsonVO : public JsonVO<BinTransferDTO::Wrapper> {
	DTO_INIT(BinTransferJsonVO, JsonVO<BinTransferDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BinTransferPageJsonVO : public JsonVO<BinTransferPageDTO::Wrapper> {
	DTO_INIT(BinTransferPageJsonVO, JsonVO<BinTransferPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BIN_TRANSFER_VO_