#ifndef _ADDITION_VO_
#define _ADDITION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/addition-adjustment/AdditionDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AdditionJsonVO : public JsonVO<AdditionDTO::Wrapper> {
	DTO_INIT(AdditionJsonVO, JsonVO<AdditionDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // 
